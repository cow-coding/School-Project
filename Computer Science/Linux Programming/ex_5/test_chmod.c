#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void print_usage(char* prog_name) {
	printf("Default usage: %s -f <file name> -m <mode>\n", prog_name);
	printf("   additional options:\n");
	printf("     -a: add <mode> to original permission\n");
	printf("     -r: remove <mode> from original permission\n");
}

int main(int argc, char *argv[]) {
	struct stat statbuf;		// statbuf : read current mode
	mode_t newmode = -1;		// initialize to -1 when no input to newmode
	char* filename = NULL;		// initialize to NULL when no input to filename
	int opt;			// opt : get return getopt
	int flag_add = 0, flag_rm = 0;	// flag_add, flag_rm : default = 0

	while ((opt = getopt(argc, argv, "m:f:ar")) != -1) {
		switch(opt) {
			case 'm':
				sscanf(optarg, "%o", &newmode);	break;
			case 'f':
				filename = optarg;		break;
			case 'a':
				flag_add = 1;			break;
			case 'r':
				flag_rm = 1;			break;
			default:
				print_usage(argv[0]);
				return -1;
		}
	}

	if ((filename == NULL) || (newmode == -1)) {
		print_usage(argv[0]);
	}

	if (flag_add & flag_rm) {
		printf("couldn't set add and rm at the same time\n");
		return -2;
	}

	if (access(filename, F_OK) != 0) {
		printf("%s is not existed\n", argv[2]);
		return -3;
	}

	/* TO DO LIST */
	/* 1) Read the filename's stat to statbuf using the stat function */
	stat(argv[2], &statbuf);
	/* 2) Change the newmode according to flag_add and flag_rm */
	/*    (hint) flag_add : newmode = statbuf.st_mode | newmode; */
	if (flag_add) {
		newmode = statbuf.st_mode | newmode;
	}

	if (flag_rm) {
		newmode = statbuf.st_mode & ~newmode;
	}
	/* 3) Change the filename's mode using the chmod */
	if (chmod(argv[2], newmode) == -1) {
		perror("mode change failed\n");
		return -3;
	}

	return 0;
}
