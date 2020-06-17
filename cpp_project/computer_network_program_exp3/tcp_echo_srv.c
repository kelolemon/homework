//
// Created by kelo on 2020/5/28.
//

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <signal.h>
# include <errno.h>
# include <pthread.h>
int sig_to_exit = 0;
int sig_type = 0;

struct para_info {
    int ClientSocket;
    int ServerSocket;
    FILE *input_file;
};

int echo_rep(int ClientSocket, FILE* output) {
    int res, len, pin;
    int f_pin = -1;
    char *buf;
    for (;;) {
        // read the pin
        char *p_pin = (char *)&pin;
        res = read(ClientSocket, p_pin, 4);
        if (res < 0) {
            printf("[srv] read len return %d and errno is %d\n", res, errno);
            if (errno == EINTR){
                if(sig_type == SIGINT) return f_pin;
                return f_pin;
            }
        }
        if (res == 0) return f_pin;
        int pin_now = res;
        while (pin_now < 4) {
            p_pin += res;
            res = read(ClientSocket, (int *)p_pin, 4 - pin_now);
            pin_now = pin_now + res;
        }
        printf("(%u) read the network %d pin %d len\n",(unsigned int )pthread_self(), pin, pin_now);
        pin = ntohl(pin);
        printf("(%u) read the %d pin\n", (unsigned int )pthread_self(), pin);
        if (f_pin == -1) f_pin = pin;
        // read the data len
        char *p_len = (char *)&len;
        res = read(ClientSocket, p_len, 4);
        if (res < 0) {
            printf("[srv] read len return %d and errno is %d\n", res, errno);
            if (errno == EINTR){
                if(sig_type == SIGINT) return f_pin;
                return f_pin;
            }
        }
        if (res == 0) return f_pin;
        int len_now = res;
        while (len_now < 4) {
            p_len += res;
            res = read(ClientSocket, (int *)p_len, 4 - len_now);
            len_now = len_now + res;
        }

        printf("(%u) read the network %d len %d lens %d pin\n",(unsigned int )pthread_self(),  len, len_now, pin);
        len = ntohl(len);
        printf("(%u) read the %d len %d pin\n", (unsigned int )pthread_self(), len, pin);
        // read data len end
        // begin to read data
        buf = (char *) malloc((len + 1) * sizeof(char ));
        int left = len;
        char *ptr = buf;
        for (;;) {
            res = read(ClientSocket, ptr, left);
            if (res < 0) {
                printf("[srv] read len return %d and errno is %d\n", res, errno);
                if (errno == EINTR){
                    if(sig_type == SIGINT) {
                        free(buf);
                        return f_pin;
                    }
                    free(buf);
                    break;
                }
            }
            if (res == 0 || res == left) break;
            left -= res;
            ptr += res;
        }
        // read data end.
        printf("(%u) read the %s data\n", (unsigned int )pthread_self(), buf);
        fprintf(output, "[echo_rqt](%u) %s\n", (unsigned int )pthread_self(), buf);
        fflush(output);
        // write pin
        pin = htonl(pin);
        res = write(ClientSocket, &pin, 4);
        printf("(%u)write the %d pin\n",(unsigned int )pthread_self(), ntohl(pin));
        if (res < 0) {
            puts("write error!");
            return f_pin;
        }
        // write data len
        int n_len = htonl(len);
        res = write(ClientSocket, &n_len, 4);
        printf("(%u)write the %d len\n", (unsigned int )pthread_self(), len);
        if (res < 0) {
            puts("write error!");
            return f_pin;
        }
        // write data
        left = len;
        ptr = buf;
        for (;;) {
            res = write(ClientSocket, ptr, left);
            if (res < 0) {
                if (errno == EINTR){
                    if(sig_type == SIGINT) {
                        free(buf);
                        return f_pin;
                    }
                    free(buf);
                    break;
                }
            }
            if (res == 0 || res == left) break;
            left -= res;
            ptr += res;
        }
        printf("(%u) write the %s data\n", (unsigned int )pthread_self(), buf);
        free(buf);
    }
}

void sig_int(int signal) {
    sig_type = signal;
    sig_to_exit = 1;
    printf("[srv](%u) SIGINT is coming!\n", (unsigned int )pthread_self());
}

void sig_pipe(int signal) {
    sig_type = signal;
    printf("[srv](%u) SIGPIPE is coming!\n", (unsigned int )pthread_self());
    sleep(10000);
}

void signal_init() {
    // install pipe
    struct sigaction sig_act_pipe, old_sig_act_pipe;
    sig_act_pipe.sa_handler = sig_pipe;
    sigemptyset(&sig_act_pipe.sa_mask);
    sig_act_pipe.sa_flags = SA_RESTART;
    sigaction(SIGPIPE, &sig_act_pipe, &old_sig_act_pipe);
    // install int
    struct sigaction sig_act_int, old_sig_act_int;
    sig_act_int.sa_handler = sig_int;
    sigemptyset(&sig_act_int.sa_mask);
    sig_act_int.sa_flags = 0;
    sigaction(SIGINT, &sig_act_int, &old_sig_act_int);
}

FILE* get_file(int x) {
    char filename[30];
    sprintf(filename, "stu_srv_res_%d.txt", x);
    fprintf(stdout, "[srv](%u) %s is opened!\n", (unsigned int )pthread_self(), filename);
    return fopen(filename, "w");
}
int v[10000];
void *thread_func(void *para) {
    pthread_detach(pthread_self());
    struct para_info paraInfo;
    paraInfo = *(struct para_info*) para;
    FILE *input = paraInfo.input_file;
    int ClientSocket = paraInfo.ClientSocket;
    int ServerSocket = paraInfo.ServerSocket;
    printf("%d %d begin to muti thread", ClientSocket, ServerSocket);
    char filename[30];
    sprintf(filename, "stu_srv_res_%u.txt", (unsigned int )pthread_self());
    FILE* child_file = fopen(filename, "w");
    fprintf(stdout, "[srv](%u) %s is opened!\n", (unsigned int )pthread_self(), filename);
    fprintf(child_file, "child process is created!\n");
    fflush(input);
    fprintf(stdout, "begin to read the info\n");
    int pin = echo_rep(ClientSocket, child_file);
    fprintf(stdout, "end to read the info\n");
    char newname[20];
    sprintf(newname, "stu_srv_res_%d.txt", pin);
    rename(filename, newname);
    fprintf(child_file, "[srv](%u) res file rename done!\n", (unsigned int )pthread_self());
    fflush(child_file);
    fprintf(child_file, "[srv](%u) connfd is closed!\n", (unsigned int )pthread_self());
    fflush(child_file);
    fprintf(child_file, "[srv](%u) child process is going to exit!\n", (unsigned int )pthread_self());
    fflush(child_file);
    fclose(child_file);
    fprintf(stdout, "[srv](%u) %s is closed!\n", (unsigned int )pthread_self(), newname);
    close(ClientSocket);
    fclose(input);
    pthread_exit(NULL);
}

int step = 0;
pthread_t p[10];

void tcp_server(char *addr, char *port) {
    signal_init();
    FILE* input = fopen("stu_srv_res_p.txt", "w");
    fprintf(stdout, "stu_srv_res_p.txt is opened!\n");
    int res;
    char *ret;
    char ipv4_cli_addr[20];
    int ServerSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (ServerSocket < 0) {
        puts("Create Socket error!");
        return;
    }
    struct sockaddr_in srv_addr, cli_addr;
    struct in_addr ipv4_srv_addr;
    srv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, addr, (void *)&ipv4_srv_addr);
    srv_addr.sin_addr = ipv4_srv_addr;
    srv_addr.sin_port = htons(strtol(port, &ret, 10));
    socklen_t addr_size = sizeof(struct sockaddr_in);
    fprintf(input, "[srv](%u) server[%s:%s] is initializing!\n", (unsigned int )pthread_self(), addr, port);
    fflush(input);
    res = bind(ServerSocket, (struct sockaddr*) &srv_addr, sizeof(srv_addr));
    if (res < 0) {
        puts("Bind error!");
        return;
    }
    res = listen(ServerSocket, 8);
    if (res < 0) {
        puts("Listen error!");
        return;
    }
    pthread_t pthread;
    for (;!sig_to_exit;) {
        int ClientSocket = accept(ServerSocket, (struct sockaddr*) &cli_addr, &addr_size);
        if (ClientSocket == -1 && errno == EINTR) break;
        if (ClientSocket < 0) break;
        inet_ntop(AF_INET, (void *) &cli_addr.sin_addr, ipv4_cli_addr, 16);
        fprintf(input, "[srv](%u) client[%s:%d] is accepted!\n", (unsigned int )pthread_self(), ipv4_cli_addr, ntohs(cli_addr.sin_port));
        fflush(input);
        struct para_info* paraInfo = (struct para_info *) malloc(sizeof(struct para_info));
        (*paraInfo).input_file = input;
        (*paraInfo).ClientSocket = ClientSocket;
        (*paraInfo).ServerSocket = ServerSocket;
        printf("============%d entering=============\nClientSocket%d : %d\n", step, ClientSocket, (*paraInfo).ClientSocket);
        pthread_create(&pthread, NULL, thread_func, (void *) paraInfo);
    }
    close(ServerSocket);
    fprintf(input, "[srv](%u) listenfd is closed!\n", (unsigned int )pthread_self());
    fflush(input);
    fprintf(input, "[srv](%u) server is exiting\n", (unsigned int )pthread_self());
    fflush(input);
    fclose(input);
    fprintf(stdout, "[srv](%u) stu_srv_res_p.txt is closed!\n", (unsigned int )pthread_self());
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage:%s <IP> <PORT>\n", argv[0]);
        return 0;
    }
    tcp_server(argv[1], argv[2]);
    return 0;
}
