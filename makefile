ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif

all: main.o linkedList.o musicLibrary.o
	$(CC) -o output main.o linkedList.o musicLibrary.o

main.o: main.c linkedList.h musicLibrary.h
	$(CC) -c main.c

linkedList.o: linkedList.c linkedList.h
	$(CC) -c linkedList.c
	
musicLibrary.o: musicLibrary.c musicLibrary.h
	$(CC) -c musicLibrary.c
	
run:
	./output

memcheck:
	valgrind --leak-check=yes ./output

clean:
	rm *.o
	rm *~
