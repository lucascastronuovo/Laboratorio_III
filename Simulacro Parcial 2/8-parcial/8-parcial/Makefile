CC = gcc-4.1

CFLAGS = -Wall -pthread -O4 -std=gnu89
HEADERS = -I./

all : player race

player : player.c 
	$(CC) -o player player.c $(CFLAGS) $(HEADERS)

race : race.c 
	$(CC) -o race race.c $(CFLAGS) $(HEADERS)

clean : rm -f ./player ./race
