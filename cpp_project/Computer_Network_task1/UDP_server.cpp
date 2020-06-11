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

int udp_server() {
    int check(0);
    int ServerSocket = socket(PF_INET, SOCK_DGRAM, 0);
    if (ServerSocket < 0) {
        puts("Server Create error!");
        return 0;
    }
    sockaddr_in local_addr;
    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = INADDR_ANY;
    local_addr.sin_port = htons(10808);
    check = bind(ServerSocket, (sockaddr *) &local_addr, sizeof(local_addr));
    if (check < 0) {
        puts("Bind error!");
        return 0;
    }
    char buf[MaxBuf];
    sockaddr_in remote_addr;
    socklen_t addr_size = sizeof(remote_addr);
    for (;;) {
        puts("Server waiting");
        int len = recvfrom(ServerSocket, buf, sizeof(buf), 0, (sockaddr *) &remote_addr, &addr_size);
        if (len < 0) {
            break;
        }
        buf[len] = '\0';
        std::cout << buf << std::endl;
        for (int i = 0; i < len; i++) {
            if (buf[i] >= 'a' && buf[i] <= 'z') {
                buf[i] -= 32;
            }
        }
        std::cout << buf << std::endl;
        sendto(ServerSocket, buf, sizeof(buf), 0, (sockaddr *) &remote_addr, addr_size);
    }
    close(ServerSocket);
    return 1;
}

int main() {
    udp_server();
}