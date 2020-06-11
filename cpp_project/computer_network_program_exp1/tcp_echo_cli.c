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

# define MAX_CMD_STR 100

int echo_rqt(int ClientSocket) {
    char buf[MAX_CMD_STR + 1];
    int res;
    for(;fgets(buf, MAX_CMD_STR, stdin);) {
        if (strncmp(buf, "exit", 4) == 0) {
            return 0;
        }
        // process data
        int len = (int )strlen(buf);
        buf[len - 1] = '\0';
        // write length
        write(ClientSocket, &len, 4);
        // write data.
        char *ptr = buf;
        int left = len;
        for (;;) {
            res = write(ClientSocket, ptr, left);
            if (res == 0) break;
            if (res == -1) {
                return 0;
            }
            left -= res;
            ptr += res;
        }
        // read length
        res = read(ClientSocket, &len, 4);
        if (res < 0) {
            puts("read error!");
            return 0;
        }
        // read data
        ptr = buf;
        left = len;
        for (;;) {
            res = read(ClientSocket, ptr, left);
            if (res == 0) break;
            if (res == -1) {
                return 0;
            }
            left -= res;
            ptr += res;
        }
        printf("[echo_rep] %s\n", buf);
    }
    return 0;
}

void tcp_client(char *addr, char *port) {
    int res;
    char *ret;
    int ClientSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (ClientSocket < 0) {
        puts("Client create error!");
        return;
    }
    struct sockaddr_in srv_addr, cli_addr;
    struct in_addr ipv4_srv_addr;
    srv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, addr, (void *)&ipv4_srv_addr);
    srv_addr.sin_addr = ipv4_srv_addr;
    srv_addr.sin_port = htons(strtol(port, &ret, 10));
    socklen_t addr_size = sizeof(struct sockaddr_in);
    for (;;) {
        res = connect(ClientSocket, (struct sockaddr *) &srv_addr, sizeof(srv_addr));
        if (res == -1 && errno == EINTR) continue;
        if (res == -1) {
            return;
        }
        printf("[cli] server[%s:%s] is connected!\n", addr, port);
        res = echo_rqt(ClientSocket);
        if (res == 0) break;
    }
    close(ClientSocket);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage:%s <IP> <PORT>\n", argv[0]);
        return 0;
    }
    tcp_client(argv[1], argv[2]);
    return 0;
}