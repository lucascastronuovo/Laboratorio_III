CC=gcc-4.1

CFLAGS = -Wall -O3 -std=gnu89 -pedantic-errors -pthread
HEADERS = -I./

all: clean jugadores carrera

clean:
	rm -rf *o jugadores carrera

jugadores : jugadores.c funciones.c colas.c global.c clave.c memcomp.c utiles.c threads.c funciones.h colas.h global.h clave.h memcomp.h utiles.h threads.h definiciones.h
	$(CC) -o jugadores jugadores.c funciones.c colas.c global.c clave.c memcomp.c utiles.c threads.c $(CFLAGS) $(HEADERS)

carrera : carrera.c funciones.c colas.c global.c clave.c memcomp.c utiles.c threads.c funciones.h colas.h global.h clave.h memcomp.h utiles.h threads.h definiciones.h
	$(CC) -o carrera carrera.c funciones.c colas.c global.c clave.c memcomp.c utiles.c threads.c $(CFLAGS) $(HEADERS)

