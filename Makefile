CC=gcc
CFLAGS= -lpthread -pipe -m64 -fPIC -g -O3 -fno-exceptions -fstack-protector -Wl,-z,relro -Wl,-z,now -fvisibility=hidden -W -Wall -Wno-unused-parameter -Wno-unused-function -Wno-unused-label -Wpointer-arith -Wformat -Wreturn-type -Wsign-compare -Wmultichar -Wformat-nonliteral -Winit-self -Wuninitialized -Wno-deprecated -Wformat-security -Werror  -c

all: slow_check

slow_check: main.o slow_check.o
	$(CC) main.o slow_check.o -o slow_check -lpthread

main.o: main.c
	$(CC) $(CFLAGS) main.c

slow_check.o: slow_check.c
	$(CC) $(CFLAGS) slow_check.c

clean:
	rm -rf main.o slow_check.o slow_check
