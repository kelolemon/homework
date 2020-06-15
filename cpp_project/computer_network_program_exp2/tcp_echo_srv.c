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

int sig_to_exit = 0;
int sig_type = 0;

int echo_rep(int ClientSocket, FILE* output) {
    int res, len, pin;
    int f_pin = -1;
    char *buf;

    for (;;) {
        // read the pin
        res = read(ClientSocket, &pin, 4);
        pin = ntohl(pin);
        if (f_pin == -1) f_pin = pin;
        if (res < 0) {
            printf("[srv] read len return %d and errno is %d\n", res, errno);
            if (errno == EINTR){
                if(sig_type == SIGINT) return f_pin;
                return f_pin;
            }
        }
        if (res == 0) return f_pin;
        // read the data len
        res = read(ClientSocket, &len, 4);
        len = ntohl(len);
        if (res < 0) {
            printf("[srv] read len return %d and errno is %d\n", res, errno);
            if (errno == EINTR){
                if(sig_type == SIGINT) return f_pin;
                return f_pin;
            }
        }
        if (res == 0) return f_pin;
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
        fprintf(output, "[echo_rqt](%d) %s\n", getpid(), buf);
        fflush(output);
        // write pin
        pin = htonl(pin);
        res = write(ClientSocket, &pin, 4);
        if (res < 0) {
            puts("write error!");
            return f_pin;
        }
        // write data len
        int n_len = htonl(len);
        res = write(ClientSocket, &n_len, 4);
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
            if (res == 0) break;
            left -= res;
            ptr += res;
        }
        free(buf);
    }
}

void sig_int(int signal) {
    sig_type = signal;
    sig_to_exit = 1;
    printf("[srv](%d) SIGINT is coming!\n", getpid());
}

void sig_pipe(int signal) {
    sig_type = signal;
    printf("[srv](%d) SIGPIPE is coming!\n", getpid());
    sleep(10000);
}

void sig_child(int signal) {
    sig_type = signal;
    pid_t child_pid;
    printf("[srv](%d) SIGCHLD is coming!\n", getpid());
    int state;
    while ((child_pid = waitpid(-1, &state, WNOHANG)) > 0) {
        printf("[srv](%d) server child(%d) terminated.\n", getpid(), child_pid);
    }
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
    // install child
    struct sigaction sig_act_child, old_sig_act_child;
    sig_act_child.sa_handler = sig_child;
    sigemptyset(&sig_act_child.sa_mask);
    sig_act_child.sa_flags = SA_RESTART;
    sigaction(SIGCHLD, &sig_act_child, &old_sig_act_child);
}

FILE* get_file(int x) {
    char filename[30];
    sprintf(filename, "stu_srv_res_%d.txt", x);
    fprintf(stdout, "[srv](%d) %s is opened!\n", getpid(), filename);
    return fopen(filename, "w");
}

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
    fprintf(input, "[srv](%d) server[%s:%s] is initializing!\n", getpid(), addr, port);
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
    for (;!sig_to_exit;) {
        int ClientSocket = accept(ServerSocket, (struct sockaddr*) &cli_addr, &addr_size);
        if (ClientSocket == -1 && errno == EINTR) break;
        if (ClientSocket < 0) break;
        inet_ntop(AF_INET, (void *) &cli_addr.sin_addr, ipv4_cli_addr, 16);
        fprintf(input, "[srv](%d) client[%s:%d] is accepted!\n", getpid(), ipv4_cli_addr, ntohs(cli_addr.sin_port));
        fflush(input);
        pid_t pid;
        if ((pid = fork()) == 0) {
            char filename[30];
            sprintf(filename, "stu_srv_res_%d.txt", getpid());
            FILE* child_file = fopen(filename, "w");
            fprintf(stdout, "[srv](%d) %s is opened!\n", getpid(), filename);
            fprintf(child_file, "child process is created!\n");
            fflush(input);
            close(ServerSocket);
            fprintf(child_file, "[srv](%d) listenfd is closed!\n", getpid());
            int pin = echo_rep(ClientSocket, child_file);
            char newname[20];
            sprintf(newname, "stu_srv_res_%d.txt", pin);
            rename(filename, newname);
            fprintf(child_file, "[srv](%d) res file rename done!\n", getpid());
            fflush(child_file);
            fprintf(child_file, "[srv](%d) connfd is closed!\n", getpid());
            fflush(child_file);
            fprintf(child_file, "[srv](%d) child process is going to exit!\n", getpid());
            fflush(child_file);
            fclose(child_file);
            fprintf(stdout, "[srv](%d) %s is closed!\n", getpid(), newname);
            close(ClientSocket);
            fclose(input);
            exit(0);
        } else {
            waitpid(pid, NULL, 0);
            close(ClientSocket);
        }
    }
    close(ServerSocket);
    fprintf(input, "[srv](%d) listenfd is closed!\n", getpid());
    fflush(input);
    fprintf(input, "[srv](%d) server is exiting\n", getpid());
    fflush(input);
    fclose(input);
    fprintf(stdout, "[srv](%d) stu_srv_res_p.txt is closed!\n", getpid());
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage:%s <IP> <PORT>\n", argv[0]);
        return 0;
    }
    tcp_server(argv[1], argv[2]);
    return 0;
}
