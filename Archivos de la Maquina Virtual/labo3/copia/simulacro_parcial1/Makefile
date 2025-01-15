CC=gcc-4.1

CFLAGS = -Wall -O3 -std=gnu89 -pedantic-errors
HEADERS = -I./

all: clean cci paneles

clean:
	rm -rf *o cci paneles

cci : cci.c menucci.c gestiones.c menucci.h gestiones.h
	$(CC) -o cci cci.c menucci.c gestiones.c $(CFLAGS) $(HEADERS)

paneles: paneles.c gestiones.c semaforo.c clave.c gestiones.h semaforo.h clave.h defsim.h
	$(CC) -o paneles paneles.c gestiones.c semaforo.c clave.c $(CFLAGS) $(HEADERS)
