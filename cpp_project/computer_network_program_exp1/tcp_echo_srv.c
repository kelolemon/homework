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

void echo_rep(int ClientSocket) {
    int res,len;
    char *buf;
    for (;;) {
        // read the data len
        res = read(ClientSocket, &len, 4);
        if (res < 0) {
            printf("[srv] read len return %d and errno is %d\n", res, errno);
            if (errno == EINTR){
                if(sig_type == SIGINT) return;
                continue;
            }
        }
        if (res == 0) return;
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
                        return;
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
        printf("[echo_rqt] %s\n", buf);
        // write data len
        res = write(ClientSocket, &len, 4);
        if (res < 0) {
            puts("write error!");
            return;
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
                        return;
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
    printf("[srv] SIGINT is coming!\n");
}

void sig_pipe(int signal) {
    sig_type = signal;
    printf("[srv] SIGPIPE is coming!\n");
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

void tcp_server(char *addr, char *port) {
    signal_init();
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
    printf("[srv] server[%s:%s] is initializing!\n", addr, port);
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
        printf("[srv] client[%s:%d] is accepted!\n", ipv4_cli_addr, ntohs(cli_addr.sin_port));
        echo_rep(ClientSocket);
        close(ClientSocket);
        printf("[srv] connfd is closed!\n");
    }
    close(ServerSocket);
    printf("[srv] listenfd is closed!\n");
    printf("[srv] server is exiting\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage:%s <IP> <PORT>\n", argv[0]);
        return 0;
    }
    tcp_server(argv[1], argv[2]);
    return 0;
}