CC=gcc-4.1

CFLAGS = -Wall -O3 -std=gnu89 -pedantic-errors
HEADERS = -I./

all: clean p1 p2

clean:
	rm -rf *o p1 p2

p1 : memcomp-sem.p1.c
	$(CC) -o p1 memcomp-sem.p1.c

p2 : memcomp-sem.p2.c
	$(CC) -o p2 memcomp-sem.p2.c
