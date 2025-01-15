CC=gcc-4.1

CFLAGS = -Wall -O3 -std=gnu89 -pedantic-errors
HEADERS = -I./

all: clean tu_comida sist_con

clean:
	rm -rf *o tu_comida sist_con

tu_comida : tu_comida.c funciones.c gestiones.c semaforo.c clave.c funciones.h gestiones.h semaforo.h clave.h def_gen.h defsem.h
	$(CC) -o tu_comida tu_comida.c funciones.c gestiones.c semaforo.c clave.c $(CFLAGS) $(HEADERS)

sist_con : sist_con.c funciones.c gestiones.c semaforo.c clave.c funciones.h gestiones.h semaforo.h clave.h def_gen.h defsem.h
	$(CC) -o sist_con sist_con.c funciones.c gestiones.c semaforo.c clave.c $(CFLAGS) $(HEADERS)
