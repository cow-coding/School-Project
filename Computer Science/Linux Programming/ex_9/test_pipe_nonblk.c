#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>

#define BUFSIZE 64

int main() {
	int ptc_fd[2];	/* Parent to Child pipe */
	int ctp_fd[2];	/* Child to Parent pipe */
	char buf[BUFSIZE];

	if (pipe(ptc_fd) == -1) {
		perror("parent to child pipe");
		return 0;
	}

	if (pipe(ctp_fd) == -1) {
		perror("child to parent pipe");
		return 0;
	}

	if (fcntl(ptc_fd[0], F_SETFL, O_NONBLOCK) == -1 ||
		fcntl(ptc_fd[1], F_SETFL, O_NONBLOCK) == -1 ||
		fcntl(ctp_fd[0], F_SETFL, O_NONBLOCK) == -1 ||
		fcntl(ctp_fd[1], F_SETFL, O_NONBLOCK) == -1) {
		perror("fcntl: nonblock");
		return 0;
	}

	switch(fork()) {
		case -1:
			perror("fork");
			return 0;

		case 0:
			close(ptc_fd[1]);
			close(ctp_fd[0]);
			while (write(ctp_fd[1], "Hello, I'm child.", BUFSIZE) == -1) {
				if (errno == EAGAIN) {
					printf("child : pipe is full\n");
					sleep(1);
				}
				else {
					perror("write call");
					return 0;
				}
			}

			while (read(ptc_fd[0], buf, BUFSIZE) == -1) {
				if (errno == EAGAIN) {
					printf("child : pipe is empty\n");
					sleep(1);
				}
				else {
					perror("read call");
					return 0;
				}
			}
			printf("Message from parent: %s\n", buf);
			return 0;
			
		default:
			close(ptc_fd[0]);
			close(ctp_fd[1]);
			while(read(ctp_fd[0], buf, BUFSIZE) == -1) {
				if(errno == EAGAIN){
					printf("parent : pipe is empty\n");
					sleep(1);
				}else {
					perror("read call");
					return 0;
				}
			}
			printf("Message from child: %s\n", buf);
			sleep(5);
			while(write(ptc_fd[1], "Hello, I'm your parent.", BUFSIZE) == -1) {
				if (errno == EAGAIN) {
					printf("parent : pipe ist full");
					sleep(1);
				}
				else {
					perror("write call");
					return 0;
				}
			}
			wait(NULL);
			return 0;
	}
}
