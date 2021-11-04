#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	int i;

	for(i=1; i < argc; i++) {
		if (rmdir(argv[i]) == 0)
			printf("rmdir %s succeeded\n", argv[i]);
		else
			perror("rmdir failed\n");
	}

	return 0;
}
