#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
	int fd;

	if (argc != 2) {
		printf("Usage: %s <file name>\n", argv[0]);
		return -1;
	}

	// umask(0113);
	fd = open(argv[1], O_RDWR | O_CREAT, 0777);
	close(fd);

	return 0;
}
