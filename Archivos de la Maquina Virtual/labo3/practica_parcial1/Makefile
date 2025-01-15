CC=gcc-4.1

CFLAGS = -Wall -O3 -std=gnu89 -pedantic-errors
HEADERS = -I./

all: clean mcdonald cliente

clean:
	rm -rf *o mcdonald cliente

mcdonald : mcdonald.c funciones.c gestiones.c gestiones_fun.c semaforo.c clave.c funciones.h gestiones.h gestiones_fun.h semaforo.h clave.h defprac.h defsem.h
	$(CC) -o mcdonald mcdonald.c funciones.c gestiones.c gestiones_fun.c semaforo.c clave.c $(CFLAGS) $(HEADERS)

cliente : cliente.c gestiones.c gestiones_fun.c semaforo.c clave.c gestiones.h gestiones_fun.h semaforo.h clave.h defprac.h defsem.h
	$(CC) -o cliente cliente.c gestiones.c gestiones_fun.c semaforo.c clave.c $(CFLAGS) $(HEADERS)
