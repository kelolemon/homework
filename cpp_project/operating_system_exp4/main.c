# include <stdio.h>
# include <unistd.h>
# include <sys/msg.h>
# include <string.h>
# include <errno.h>
# define MSG_KEY 114514
# define MAX_BUF 2550

struct msg_st {
    long msg_type;
    char msg[MAX_BUF];
};

void server_process(int msg_queue_id) {
    struct msg_st data;
    data.msg_type = 1; // server type
    pid_t my_pid = getpid();
    sprintf(data.msg, "hello client, my pid is %d", (int) my_pid);
    int res = msgsnd(msg_queue_id, (void *)&data, sizeof(struct msg_st), IPC_NOWAIT); // write the msg into queue
    if (res < 0) {
        puts("sever send message error!");
        printf("errno=%d [%s]\n",errno,strerror(errno));
    }
    data.msg_type = 2; // client type
    res = msgrcv(msg_queue_id, &data, sizeof(struct msg_st), data.msg_type, IPC_NOWAIT); // read the msg from queue
    if (res < 0) {
        if (errno != 42) {
            puts("sever receive message error!");
            printf("errno=%d [%s]\n",errno,strerror(errno));
        }
        for(;res <0 && (int) errno == 42;) {
            res = msgrcv(msg_queue_id, &data, sizeof(struct msg_st), data.msg_type, IPC_NOWAIT); // read the msg from queue
            if (res < 0 && errno != 42) {
                puts("sever receive message error!");
                printf("errno=%d [%s]\n",errno,strerror(errno));
                break;
            }
        }
    }
    printf("server read the message:(%s) from the client\n", data.msg);
}

void client_process(int msg_queue_id) {
    struct msg_st data;
    data.msg_type = 2; // client type
    pid_t my_pid = getpid();
    sprintf(data.msg, "hello server, my pid is %d", (int) my_pid);
    int res = msgsnd(msg_queue_id, &data, sizeof(struct msg_st), 0); // write the msg into queue
    if (res < 0) {
        puts("sever send message error!");
        printf("errno=%d [%s]\n",errno,strerror(errno));
    }
    data.msg_type = 1; // server type
    res = msgrcv(msg_queue_id, &data, sizeof(struct msg_st), data.msg_type, 0); // read the msg from queue
    if (res < 0) {
        if (errno != 42) {
            puts("client receive message error!");
            printf("errno=%d [%s]\n",errno,strerror(errno));
        }
        for(;res < 0 && (int) errno == 42;) {
            res = msgrcv(msg_queue_id, &data, sizeof(struct msg_st), data.msg_type, IPC_NOWAIT); // read the msg from queue
            if (res < 0 && errno != 42) {
                puts("client receive message error!");
                printf("errno=%d [%s]\n",errno,strerror(errno));
                break;
            }
        }
    }
    printf("client read the message:(%s) from the server\n", data.msg);
}

int main() {
    pid_t pid1 = fork(); // creat server process
    pid_t pid2 = fork(); // creat client process
    int msg_queue_id = msgget(MSG_KEY, IPC_EXCL);
    if (msg_queue_id < 0) {
        msg_queue_id = msgget(MSG_KEY, IPC_CREAT | 0666);
        if (msg_queue_id < 0) {
            puts("create msg queue error!");
            return 1;
        }
    }
    if (pid1 > 0 && pid2 == 0) server_process(msg_queue_id);
    if (pid2 > 0 && pid1 == 0) client_process(msg_queue_id);
    return 0;
}
