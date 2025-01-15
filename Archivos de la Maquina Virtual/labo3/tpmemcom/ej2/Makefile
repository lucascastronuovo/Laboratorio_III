CC=gcc-4.1

CFLAGS = -Wall -O3 -std=gnu89 -pedantic-errors
HEADERS = -I./

all: clean peaje autos

clean:
	rm -rf *o peaje autos

peaje : peaje.c funciones.c gestiones.c semaforo.c clave.c memcomp.c funciones.h gestiones.h semaforo.h clave.h memcomp.h def_gen.h defmemsem.h def.h
	$(CC) -o peaje peaje.c funciones.c gestiones.c semaforo.c clave.c memcomp.c $(CFLAGS) $(HEADERS)

autos : autos.c funciones.c semaforo.c clave.c memcomp.c funciones.h semaforo.h clave.h memcomp.h def_gen.h defmemsem.h def.h
	$(CC) -o autos autos.c funciones.c semaforo.c clave.c memcomp.c $(CFLAGS) $(HEADERS)

