CC=gcc-4.1

CFLAGS = -Wall -O3 -std=gnu89 -pedantic-errors -pthread
HEADERS = -I./

all: clean pienso_numero

clean:
	rm -rf *o pienso_numero

pienso_numero : pienso_numero.c global.c threads.c funciones.c global.h threads.h funciones.h
	$(CC) -o pienso_numero pienso_numero.c global.c threads.c funciones.c $(CFLAGS) $(HEADERS)


