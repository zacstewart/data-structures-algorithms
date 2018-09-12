%.o: %.c
	gcc -c $<

main: main.c test.o array.o test_array.o list.o test_list.o stack.o test_stack.o queue.o test_queue.o
	gcc -o main main.c \
			test.o \
			array.o test_array.o \
			list.o test_list.o \
			stack.o test_stack.o \
			queue.o test_queue.o

test: main
	./main

clean:
	rm -f main *.o

.PHONY: clean
