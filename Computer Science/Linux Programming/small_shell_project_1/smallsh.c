#include "smallsh.h"

static char inpbuf[MAXBUF];
static char tokbuf[2 * MAXBUF];
static char* ptr = inpbuf;
static char* tok = tokbuf;

static char special[] = { ' ', '\t', '&', ';', '\n', '\0' };
static char* exitCode = "exit";

int userin(char* p) {
	int c, count;
	ptr = inpbuf;
	tok = tokbuf;

	printf("%s", p);
	count = 0;

	while (1) {
		if ((c = getchar()) == EOF)
			return EOF;
		if (count < MAXBUF)
			inpbuf[count++] = c;
		if (c == '\n' && count < MAXBUF) {
			inpbuf[count] = '\0';
			return count;
		}
		if (c == '\n' || count >= MAXBUF) {
			printf("smallsh: input line too long\n");
			count = 0;
			printf("%s", p);
		}
	}
}

int gettok(char** outptr) {
	int type;
	*outptr = tok;
	while (*ptr == ' ' || *ptr == '\t')
		ptr++;

	*tok++ = *ptr;
	switch (*ptr++) {
		case '\n':
			type = EOL;
			break;
		case '&':
			type = AMPERSAND;
			break;
		case ';':
			type = SEMICOLON;
			break;
		default:
			type = ARG;
			while (inarg(*ptr))
				*tok++ = *ptr++;
	}
	*tok++ = '\0';
	return type;
}

int inarg(char c) {
	char* wrk;

	for (wrk = special; *wrk; wrk++) {
		if (c == *wrk)
			return 0;
	}

	return 1;
}

void procline() {
	char* arg[MAXARG + 1];
	int toktype, type;
	int narg = 0;
	for (;;) {
		switch (toktype = gettok(&arg[narg])) {
			case ARG:
				if (narg < MAXARG)
					narg++;
				break;
			case EOL:
			case SEMICOLON:
			case AMPERSAND:
				if (toktype == AMPERSAND) type = BACKGROUND;
				else type = FOREGROUND;
				if (narg != 0) {
					arg[narg] = NULL;

					runcommand(arg, type);
				}
				if (toktype == EOL) return;
				narg = 0;
				break;
		}
	}
}

int runcommand(char** cline, int where) {
	pid_t pid;
	int status;
	int redirect;
	int fd;
	char* newline[MAXARG + 1];

	if (strcmp(*cline, "exit") == 0) exit(0);

	if (strcmp(*cline, "cd") == 0) {
		if (chdir(cline[1]) == -1) {
			perror(*cline);
			return -1;
		}else return 0;
	}

	switch (pid = fork()) {
		case -1:
			perror("smallsh");
			return -1;
		case 0:
			if ((redirect = isredirect(cline)) != -1) {
				char *file = cline[redirect+1];

				if (cline[redirect+1] == NULL) {
					printf("syntax error: set redirection file\n");
					exit(-1);
				}
				
				fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
				dup2(fd, 1);

				for (int i = 0; i < redirect; i++) newline[i] = cline[i];
				newline[redirect] = '\0';
				cline = newline;
			}

			execvp(*cline, cline);
			perror(*cline);
			exit(1);
	}

	/* following is the code of parent */
	if (where == BACKGROUND) {
		printf("[Process id] %d\n", pid);
		return 0;
	}

	if (waitpid(pid, &status, 0) == -1)
		return -1;
	else
		return status;
}

int isredirect(char **cline) {
	for (int i = 0; cline[i] != NULL; i++) {
		if (strcmp(cline[i], ">") == 0) return i;
	}

	return -1;
}
