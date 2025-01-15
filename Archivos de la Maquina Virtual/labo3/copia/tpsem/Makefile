CC=gcc-4.1

CFLAGS = -Wall -O3 -std=gnu89 -pedantic-errors
HEADERS = -I./

all: clean carga reserva

clean:
	rm -rf *o carga reserva

carga : carga.c semaforo.c semaforo.h clave.c clave.h gestiones.c gestiones.h funciones.c funciones.h defsem.h
	$(CC) -o carga carga.c semaforo.c clave.c gestiones.c funciones.c $(CFLAGS) $(HEADERS)


reserva: reserva.c semaforo.c semaforo.h clave.c clave.h gestiones.c gestiones.h defsem.h
	$(CC) -o reserva reserva.c semaforo.c clave.c gestiones.c $(CFLAGS) $(HEADERS)


