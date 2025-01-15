CC=gcc-4.1

CFLAGS = -Wall -O3 -std=gnu89 -pedantic-errors
HEADERS = -I./
all : clean banco cajero

banco: banco.c definiciones.h semaforos.c semaforos.h memoria.c memoria.h clave.c clave.h colas.c colas.h
	$(CC) -o banco banco.c clave.c semaforos.c memoria.c colas.c $(HEADERS) $(CFLAGS) 

cajero: cajero.c definiciones.h semaforos.c semaforos.h memoria.c memoria.h clave.c clave.h colas.c colas.h
	$(CC) -o cajero cajero.c clave.c semaforos.c memoria.c colas.c $(HEADERS) $(CFLAGS) 

clean: 
	rm -rf *o banco cajero
