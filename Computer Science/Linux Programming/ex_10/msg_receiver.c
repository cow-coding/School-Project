#include "msg_header.h"

int msgid;

void int_handler(int signo) {
	msgctl(msgid, IPC_RMID, NULL);
}

int main() {
    key_t key;
//    int msgid;
    struct msg_entry msg;
    int msglen;
    
    key = ftok("msg_header.h", 1);
    msgid = msgget(key, IPC_CREAT | QPERM);
    
    struct sigaction act;
    sigfillset(&act.sa_mask);
    act.sa_handler = int_handler;
    sigaction(SIGINT, &act, NULL);
    
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }
    
    while ((msglen = msgrcv(msgid, &msg, MAXLEN, 0, 0)) > 0) {
        printf("Received Message = %s\n", msg.mtext);
    }
    
    return 0;
}

