CC=gcc-4.1

CFLAGS = -Wall -O3 -std=gnu89 -pedantic-errors
HEADERS = -I./

all: clean archivos

clean:
	rm -rf *o archivos

archivos : main.c gestiones.c productor.c consumidor.c gestiones.h productor.h consumidor.h
	$(CC) -o archivos main.c gestiones.c productor.c consumidor.c $(CFLAGS) $(HEADERS)

