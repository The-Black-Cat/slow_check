CC=gcc
CFLAGS=-c -Wall

all: slow_check

slow_check: main.o slow_check.o
	$(CC) main.o slow_check.o -o slow_check

main.o: main.c
	$(CC) $(CFLAGS) main.c

slow_check.o: slow_check.c
	$(CC) $(CFLAGS) slow_check.c

clean:
	rm -rf main.o slow_check.o slow_check
