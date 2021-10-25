#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	mode_t dir_mode = 0755;
	int c;

	while((c = getopt(argc, argv, "m:")) != -1) {
		switch(c) {
			case 'm':
				sscanf(optarg, "%o", &dir_mode);
				break;
			default:
				printf("Default usage: %s <dir name> [options]\n", argv[0]);
				return 0;
		}
	}

	if (optind == argc) { /* no dir_name argument */
		printf("Default usage: %s <dir name> [options]\n", argv[0]);
		return 0;
	}

	for (int index = optind; index < argc; index++) {
		if (mkdir(argv[index], dir_mode) == 0)
			printf("%s: mkdir succeeded\n", argv[index]);
		else
			perror("mkdir failed");
	}

	return 0;
}
