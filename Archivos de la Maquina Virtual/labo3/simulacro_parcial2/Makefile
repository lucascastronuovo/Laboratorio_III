CC=gcc-4.1

CFLAGS = -Wall -O3 -std=gnu89 -pedantic-errors -pthread
HEADERS = -I./

all: clean carrera jugadores

clean:
	rm -rf *o carrera jugadores

carrera : carrera.c global.c funciones.c colas.c clave.c global.h funciones.h colas.h def_cola.h clave.h
	$(CC) -o carrera carrera.c global.c funciones.c colas.c clave.c $(CFLAGS) $(HEADERS)

jugadores : jugadores.c global.c threads.c funciones.c colas.c clave.c global.h threads.c funciones.h colas.h def_cola.h clave.h
	$(CC) -o jugadores jugadores.c global.c threads.c funciones.c colas.c clave.c $(CFLAGS) $(HEADERS)


