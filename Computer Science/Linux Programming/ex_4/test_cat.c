#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFSIZE 512

int main(int argc, char *argv[]) {
	char *infile=argv[1];
	int filedes;
	ssize_t nread;
	char buffer[BUFFSIZE];

	if ((filedes = open(infile, O_RDONLY)) == -1) {
		printf("Couldn't open %s\n", infile);
		return -1;
	}

	while ((nread = read(filedes, buffer, BUFFSIZE))) {
			write(1, buffer, nread);
	}

	close(filedes);

	return 0;
}
