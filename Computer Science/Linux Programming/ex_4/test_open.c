#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define PERMS 0644
char *workfile="junk";

int main() {
	int filedes;

	// TO DO : if file exist return error
	if ((filedes = open(workfile, O_WRONLY | O_CREAT | O_EXCL, PERMS)) == -1) {
		printf("Couldn't open %s\n", workfile);
		return -1;
	}else printf("Open file %s succeed!\n", workfile);

	close(filedes);

	return 0;
}

