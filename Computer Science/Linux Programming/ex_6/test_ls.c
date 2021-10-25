#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

void ls_dir(char* dir_path) {
	DIR* dirp;
	struct dirent* entry;

	if ((dirp=opendir(dir_path)) == NULL) {
		perror("Directory cannot be opened\n");
	}

	while ((entry=readdir(dirp)) != NULL)
		printf("%s\t", entry->d_name);

	printf("\n");
	closedir(dirp);
}

void ls_dir_l(char* dir_path) {
	DIR* dirp;
	struct dirent* entry;
	struct stat buf;
	char prev_dir[512];
	if (getcwd(prev_dir, 512) == NULL) /* save current pwd */
		perror("getcwd error");
	if ((dirp = opendir(dir_path)) == NULL) /* open dir */
		perror("Directory cannot be opened");
	if (chdir(dir_path) != 0) /* change dir */
		perror("Cannot enter directory");
	while ((entry = readdir(dirp)) != NULL) { /* read dir */
		if (stat(entry->d_name, &buf) == -1)
			perror("Couldn't stat");
		printf("%3.o\t", (unsigned int)buf.st_mode & 0777);
		printf("%d\t", (unsigned int)buf.st_nlink);
		printf("%5.d\t", (unsigned int)buf.st_uid);
		printf("%5.d\t", (unsigned int)buf.st_gid);
		printf("%d\t", (unsigned int)buf.st_size);
		printf("%s\n", entry->d_name);
	}
	chdir(prev_dir);
}

int main(int argc, char* argv[]) {
	int c;
	int flag_l = 0;

	while ((c = getopt(argc, argv, "l")) != -1) {
		switch (c) {
		case 'l':
			flag_l = 1;
			break;
		default:
			break;
		}
	}

	if (optind == argc) { /* list dir_entry of current dir ('./') */
		if (flag_l) ls_dir_l("./");
		else ls_dir("./");
	}else {
		for (int i = optind; i < argc; i++) {
			printf("%s:\n", argv[i]);
			if (flag_l) ls_dir_l(argv[i]);
			else ls_dir(argv[i]);
		}
	}
	return 0;
}
