CC=gcc-4.1

CFLAGS = -Wall -O4 -std=gnu89 -pedantic-errors
HEADERS = -I./
#all : main

main: main.c main.h
	$(CC) $(CFLAGS) -Wall -o main  main.c $(HEADERS)

clean: 
	rm -rf *o main
