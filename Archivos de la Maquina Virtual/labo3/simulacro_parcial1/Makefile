CC=gcc-4.1

CFLAGS = -Wall -O3 -std=gnu89 -pedantic-errors
HEADERS = -I./

all: clean cci panel

clean:
	rm -rf *o cci panel

cci : cci.c funciones.c gestiones.c semaforo.c clave.c funciones.h gestiones.h semaforo.h clave.h def_gen.h defsem.h
	$(CC) -o cci cci.c funciones.c gestiones.c semaforo.c clave.c $(CFLAGS) $(HEADERS)

panel : panel.c funciones.c gestiones.c semaforo.c clave.c funciones.h gestiones.h semaforo.h clave.h def_gen.h defsem.h
	$(CC) -o panel panel.c funciones.c gestiones.c semaforo.c clave.c $(CFLAGS) $(HEADERS)


