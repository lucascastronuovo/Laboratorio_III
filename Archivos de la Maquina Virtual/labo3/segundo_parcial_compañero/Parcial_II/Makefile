CC=gcc-13

CFLAGS = -Wall -O3 -std=gnu89 -pedantic-errors
HEADERS = -I./

all: clean reina obreras

reina: reina.c
	$(CC) $(CFLAGS) -o reina reina.c colas.c shm.c semaforos.c clave.c funciones.c $(HEADERS)

obreras: obreras.c
	$(CC) $(CFLAGS) -o obreras obreras.c colas.c shm.c semaforos.c clave.c funciones.c $(HEADERS) -pthread

clean:
	rm -rf *o reina obreras