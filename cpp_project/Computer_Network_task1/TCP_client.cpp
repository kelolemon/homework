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
# define MaxBuf 200
# define QuitServer "QUIT"
# define ConnectionEnd "Good bye."
int tcp_client() {
    int check(0);
    int ClientSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (ClientSocket < 0) {
        puts("Socket create error!");
        return 0;
    }
    sockaddr_in remote_addr;
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    remote_addr.sin_port = htons(10808);
    check = connect(ClientSocket, (sockaddr *) &remote_addr, sizeof(remote_addr));
    if (check < 0) {
        puts("Connect error!");
        return 0;
    }
    char buf[MaxBuf];
    int len = recv(ClientSocket, buf, MaxBuf, 0);
    buf[len] = '\0';
    std::cout << buf << std::endl;
    for (;;) {
        puts("Print string to send(QUIT to quit the connect):");
        std::cin >> buf;
        send(ClientSocket, buf, sizeof(buf), 0);
        len = recv(ClientSocket, buf, MaxBuf, 0);
        buf[len] = '\0';
        std::cout << buf << std::endl;
        if (!strcmp(buf, ConnectionEnd)) {
            break;
        }
    }
    close(ClientSocket);
    return 1;
}

int main(){
    tcp_client();
}