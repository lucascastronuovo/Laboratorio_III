CC=gcc-4.1

CFLAGS = -Wall -O3 -std=gnu89 -pedantic-errors
HEADERS = -I./

all: clean carga reserva

carga: carga.c
	$(CC) -o carga carga.c archivos.c semaforos.c clave.c funciones.c $(CFLAGS) $(HEADERS)

reserva: reserva.c
	$(CC) -o reserva reserva.c archivos.c semaforos.c clave.c funciones.c $(CFLAGS) $(HEADERS)

clean:
	rm -rf *o carga reserva
