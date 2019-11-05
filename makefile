ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif

all: main.o linkedList.o
	$(CC) -o output main.o linkedList.o

main.o: main.c linkedList.h
	$(CC) -c main.c

linkedList.o: linkedList.c linkedList.h
	$(CC) -c linkedList.c

run:
	./output

memcheck:
	valgrind --leak-check=yes ./output

clean:
	rm *.o
	rm *~
