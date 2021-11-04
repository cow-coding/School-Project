#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	struct stat buf;

	if (argc != 2) {
		printf("Usage: %s <file name>\n", argv[0]);
		return -1;
	}

	stat(argv[1], &buf);

	printf("Program: %s\n", argv[1]);
	printf("Mode: %lo\n", (unsigned long)buf.st_mode);
	printf("UID: %d\n", (int)buf.st_uid);
	printf("Size: %d\n", (int)buf.st_size);
	printf("Mod-time: %d\n", (int)buf.st_mtime);

	return 0;
}
