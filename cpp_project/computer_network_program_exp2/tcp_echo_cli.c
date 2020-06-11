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

FILE* read_file_pin(int pin) {
    char filename[30];
    sprintf(filename, "td%d.txt", pin);
    return fopen(filename, "r");
}

int echo_rqt(int ClientSocket, int pin, FILE* output_file) {
    FILE* file = read_file_pin(pin);
    char buf[MAX_CMD_STR + 1];
    int res;
    for(;fgets(buf, MAX_CMD_STR, file);) {
        // write pin
        write(ClientSocket, &pin, 4);
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
        // read pin
        res = read(ClientSocket, &pin, 4);
        if (res < 0) {
            puts("read error! 1");
            return 0;
        }
        // read length
        res = read(ClientSocket, &len, 4);
        if (res < 0) {
            puts("read error! 2");
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
        fprintf(output_file, "[echo_rep](%d) %s\n", getpid(), buf);
    }
    return 0;
}

FILE* get_file_pin(int pin) {
    char filename[30];
    sprintf(filename, "stu_cli_res_%d.txt", pin);
    return fopen(filename, "w");
}

void tcp_client(char *addr, char *port, int pin) {
    FILE* file = get_file_pin(pin);
    fprintf(stdout, "[cli](%d) stu_cli_res_%d.txt is created!\n",getpid(), pin);
    fprintf(file, "[cli](%d) child process %d is created!\n", getpid(), pin);
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
        fprintf(file, "[cli](%d) server[%s:%s] is connected!\n", getpid(), addr, port);
        res = echo_rqt(ClientSocket, pin, file);
        if (res == 0) break;
    }
    fprintf(file, "[cil](%d) connfd is closed!\n", getpid());
    if (pin == 0) {
        fprintf(file, "[cli](%d) parent process is going to exit!\n", getpid());
    } else {
        fprintf(file, "[cli](%d) child process is going to exit!\n", getpid());
    }
    fclose(file);
    char filename[30];
    sprintf(filename, "stu_cli_res_%d.txt", pin);
    fprintf(stdout, "%s is closed!\n", filename);
    close(ClientSocket);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage:%s <IP> <PORT> <MAX_PROCESS>\n", argv[0]);
        return 0;
    }
    char *ret;
    int pin;
    pid_t pid;
    int tot_process = (int )strtol(argv[3], &ret, 10);
    for (pin = 1; pin < tot_process; pin++) {
        pid = fork();
        if (pid == -1) {
            puts("Create process error!");
            return 1;
        }
        if (pid == 0) { // child process
            break;
        }
    }
    if (pin < tot_process) {
        tcp_client(argv[1], argv[2], pin);
    }
    if (pin == tot_process) {
        pin = 0;
        tcp_client(argv[1], argv[2], pin);
    }
    return 0;
}
