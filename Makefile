%.o: %.c
	gcc -c $<

main: main.c test.o array.o test_array.o
	gcc -o main main.c \
			test.o \
			array.o test_array.o

test: main
	./main

clean:
	rm -f main *.o

.PHONY: clean
