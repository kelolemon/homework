//
// Created by kelo on 2020/5/9.
//

# include <cstdio>
# include <cstring>
# include <sys/types.h>
# include <sys/socket.h>
# include <cmath>
# include <iostream>
# include <netinet/in.h>
# include <unistd.h>
# include <arpa/inet.h>
# define ConnectionEstablished "Server connected"
# define ConnectionEnd "Good bye."
# define MaxBuf 200
# define QuitServer "QUIT"
int tcp_server() {
    int check(0);
    int ServerSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (ServerSocket < 0) {
        puts("Create socket error!");
        return 0;
    }
    sockaddr_in local_addr;
    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    local_addr.sin_port = htons(10808);
    check = bind(ServerSocket, (sockaddr*) &local_addr, sizeof(local_addr));
    if (check < 0) {
        printf("Bind error: %s!", strerror(errno));
        return 0;
    }
    check = listen(ServerSocket, 5);
    if (check < 0) {
        puts("Listen error!");
    }

    sockaddr_in remote_addr;
    socklen_t addr_size = sizeof(remote_addr);
    int ClientSocket = accept(ServerSocket, (sockaddr*) &remote_addr, &addr_size);
    if (ClientSocket < 0) {
        printf("Accept error: %s!", strerror(errno));
        return 0;
    }
    send(ClientSocket, ConnectionEstablished, sizeof(ConnectionEstablished), 0);
    char buf[MaxBuf];
    for (int len = recv(ClientSocket, buf, MaxBuf, 0); len > 0; len = recv(ClientSocket, buf, MaxBuf, 0)) {
        buf[len] = '\0';
        if (!strcmp(buf, QuitServer)) {
            send(ClientSocket, ConnectionEnd, sizeof(ConnectionEnd), 0);
            break;
        }
        std::cout << buf << std::endl;
        for (int i = 0; i < len; i++) {
            if (buf[i] >= 'a' && buf[i] <= 'z') {
                buf[i] -= 32;
            }
        }
        std::cout << buf << std::endl;
        send(ClientSocket, buf, sizeof(buf), 0);
        std::cout << "Successfully Sent" << std::endl;
    }
    close(ServerSocket);
    close(ClientSocket);
    return 1;
}

int main() {
    tcp_server();
}