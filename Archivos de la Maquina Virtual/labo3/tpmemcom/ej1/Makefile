CC=gcc-4.1

CFLAGS = -Wall -O3 -std=gnu89 -pedantic-errors
HEADERS = -I./

all: clean jugador pienso

clean:
	rm -rf *o jugador pienso

jugador : jugador.c funciones.c semaforo.c clave.c memcomp.c utiles.c global.c funciones.h semaforo.h clave.h memcomp.h def_gen.h defmemsem.h def.h utiles.h global.h 
	$(CC) -o jugador jugador.c funciones.c semaforo.c clave.c memcomp.c utiles.c global.c $(CFLAGS) $(HEADERS)

pienso : pienso.c funciones.c semaforo.c clave.c memcomp.c utiles.c global.c funciones.h semaforo.h clave.h memcomp.h def_gen.h defmemsem.h def.h utiles.h global.h
	$(CC) -o pienso pienso.c funciones.c semaforo.c clave.c memcomp.c utiles.c global.c $(CFLAGS) $(HEADERS)

