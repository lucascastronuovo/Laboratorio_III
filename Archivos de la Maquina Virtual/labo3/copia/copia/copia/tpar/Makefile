CC=gcc-4.1

CFLAGS = -Wall -O3 -std=gnu89 -pedantic-errors
HEADERS = -I./

all: clean archivos

clean:
	rm -rf *o archivos

archivos : main.c gestiones.c productor.c consumidor.c menu_archivos.c gestiones.h productor.h consumidor.h menu_archivos.h
	$(CC) -o archivos main.c gestiones.c productor.c consumidor.c menu_archivos.c $(CFLAGS) $(HEADERS)

