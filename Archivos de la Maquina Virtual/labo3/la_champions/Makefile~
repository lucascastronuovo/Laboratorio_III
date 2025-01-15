CC=gcc-4.1

CFLAGS = -Wall -O3 -std=gnu89 -pedantic-errors -pthread
HEADERS = -I./

all: clean arbitro pateadores

clean:
	rm -rf *o arbitro pateadores

arbitro : arbitro.c global.c colas.c clave.c memcomp.c funciones.c utiles.c eventos.c global.h colas.h clave.h memcomp.h funciones.h utiles.h eventos.h definiciones.h
	$(CC) -o arbitro arbitro.c global.c colas.c clave.c memcomp.c funciones.c utiles.c eventos.c $(CFLAGS) $(HEADERS)

pateadores : pateadores.c global.c colas.c clave.c memcomp.c funciones.c utiles.c threads.c global.h colas.h clave.h memcomp.h funciones.h utiles.h threads.h definiciones.h
	$(CC) -o pateadores pateadores.c global.c colas.c clave.c memcomp.c funciones.c utiles.c threads.c $(CFLAGS) $(HEADERS)

