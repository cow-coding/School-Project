#include "msg_header.h"

int msgid;

void int_handler(int signo) {
	msgctl(msgid, IPC_RMID, NULL);
}

int main() {
	//int msgid;
	struct msg_entry msg;
	struct sigaction act;

	sigfillset(&act.sa_mask);
	act.sa_handler = int_handler;
	sigaction(SIGINT, &act, NULL);

	if ((msgid = msgget(IPC_PRIVATE, IPC_CREAT | QPERM)) == -1) {
		perror("msgget");
		exit(1);
	}

	switch (fork()) {
		case -1:
			perror("fork");
			exit(1);
		case 0:
			msg.mtype = 1;
			strcpy(msg.mtext, "message type 1 from child\n");

			if (msgsnd(msgid, (void*)&msg, MAXLEN, IPC_NOWAIT) == -1) {
				perror("msgsnd");
				exit(1);
			}
			return 0;
		default:
			msgrcv(msgid, &msg, MAXLEN, 0, 0);
			printf("Received Message = %s\n", msg.mtext);
			//msgctl(msgid, IPC_RMID, NULL);
			wait(NULL);
	}
	return 0;
}

