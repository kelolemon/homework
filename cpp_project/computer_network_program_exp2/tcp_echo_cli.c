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

int sig_type;
int sig_to_exit;

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

FILE* read_file_pin(int pin) {
    char filename[30];
    sprintf(filename, "td%d.txt", pin);
    return fopen(filename, "r");
}

int echo_rqt(int ClientSocket, int pin, FILE* output_file) {
    FILE* file = read_file_pin(pin);
    char buf[MAX_CMD_STR + 1];
    int res;
    printf("begin to enter the loop\n");
    for(;fgets(buf, MAX_CMD_STR, file);) {
        if (strncmp(buf, "exit", 4) == 0) {
            printf("break the loop\n");
            break;
        }
        // write pin
        pin = htonl(pin);
        res = write(ClientSocket, &pin, 4);
        printf("%d net work write %d len\n", pin, res);
        // process data
        int len = (int )strlen(buf);
        buf[len - 1] = '\0';
        // write length
        int n_len = htonl(len);
        write(ClientSocket, &n_len, 4);
        printf("%d len write %d\n", len, pin);
        // write data.
        char *ptr = buf;
        int left = len;
        for (;;) {
            res = write(ClientSocket, ptr, left);
            printf("%s data write %d\n", ptr, pin);
            if (res == 0 || res == left) break;
            if (res == -1) {
                return 0;
            }
            left -= res;
            ptr += res;
        }
        // read pin
        printf("wait to read pin\n");
        res = read(ClientSocket, &pin, 4);
        pin = ntohl(pin);
        if (res < 0) {
            puts("read error! 1");
            return 0;
        }
        printf("wait to read length\n");
        // read length
        res = read(ClientSocket, &len, 4);
        len = ntohl(len);
        if (res < 0) {
            puts("read error! 2");
            return 0;
        }
        printf("wait to read data\n");
        // read data
        ptr = buf;
        left = len;
        for (;;) {
            res = read(ClientSocket, ptr, left);
            if (res == 0 || res == left) break;
            if (res == -1) {
                return 0;
            }
            left -= res;
            ptr += res;
        }
        fprintf(output_file, "[echo_rep](%d) %s\n", getpid(), buf);
        fflush(output_file);
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
    fflush(file);
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
        fflush(file);
        res = echo_rqt(ClientSocket, pin, file);
        if (res == 0) break;
    }
    fprintf(file, "[cil](%d) connfd is closed!\n", getpid());
    fflush(file);
    if (pin == 0) {
        fprintf(file, "[cli](%d) parent process is going to exit!\n", getpid());
        fflush(file);
    } else {
        fprintf(file, "[cli](%d) child process is going to exit!\n", getpid());
        fflush(file);
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
    signal_init();
    char *ret;
    int pin;
    pid_t pid;
    int tot_process = (int )strtol(argv[3], &ret, 10);
    for (pin = 1; pin < tot_process; pin++) {
        pid = fork();
        if (pid == -1) {
            puts("Create process error!");
            return 0;
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
