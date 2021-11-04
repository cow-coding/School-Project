CC=gcc
CFLAGS=-O

all: test_stat test_umask test_chmod test_getopt

test_%: test_%.o
	$(CC) -o $@ $<

%.o: %.c
	$(CC) -c -o $@ $<

clean:
	rm -f *.o test_stat test_umask test_chmod test_getopt
