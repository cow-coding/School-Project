all: print_func

print_func: main.o func_one.o func_two.o
	gcc -o print_func main.o func_one.o func_two.o
main.o: header.h main.c
	gcc -c main.c
func_one.o: header.h func_one.o
	gcc -c func_one.c
func_two.o: header.h func_two.o
	gcc -c func_two.c
clean:
	rm -f *.o print_func
