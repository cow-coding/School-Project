#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void int_handler(int a) {
	printf("\nSIGINT caught\n");
}

int main() {
	struct sigaction act;

	sigfillset(&act.sa_mask);
	act.sa_handler = int_handler;
	sigaction(SIGINT, &act, NULL);

	printf("int_handler() for SIGINT is registered\n");

	for (int i = 0; i < 4; i++) {
		sigprocmask(SIG_SETMASK, &act.sa_mask, NULL);
		printf("sleep call #%d\n", i);
		sleep(2);
		sigprocmask(SIG_UNBLOCK, &act.sa_mask, NULL);
	}

	return 0;
}
