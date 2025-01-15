CC=gcc-4.1

CFLAGS = -Wall -O3 -std=gnu89 -pedantic-errors -pthread
HEADERS = -I./

all: clean bingo_threads

clean:
	rm -rf *o bingo_threads

bingo_threads : BingoThreads.c
	$(CC) -o bingo_threads BingoThreads.c $(CFLAGS) $(HEADERS)


