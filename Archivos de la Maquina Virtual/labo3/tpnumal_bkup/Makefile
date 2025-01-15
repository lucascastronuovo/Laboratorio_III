CC=gcc-4.1

CFLAGS = -Wall -O3 -std=gnu89 -pedantic-errors
HEADERS = -I./

all: clean numalea

clean:
	rm -rf *o numalea

numalea : numalea.c funciones.c funciones.h def.h
	$(CC) -o numalea numalea.c funciones.c $(CFLAGS) $(HEADERS)


