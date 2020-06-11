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

int udp_client() {
    int ClientSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (ClientSocket < 0) {
        puts("Socket Create error!");
        return 0;
    }
    sockaddr_in remote_addr;
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    remote_addr.sin_port = htons(10808);
    socklen_t addr_size = sizeof(remote_addr);
    for (;;) {
        puts("Print string to send(QUIT to quit):");
        char buf[MaxBuf];
        std::cin >> buf;
        if (!strcmp(buf, QuitServer)) {
            puts("Good bye.");
            break;
        }
        sendto(ClientSocket, buf, sizeof(buf), 0, (sockaddr *) &remote_addr, addr_size);
        int len = recvfrom(ClientSocket, buf, sizeof(buf), 0, (sockaddr *) &remote_addr, &addr_size);
        buf[len] = '\0';
        std::cout << buf << std::endl;
    }
    close(ClientSocket);
    return 1;
}

int main() {
    udp_client();
}