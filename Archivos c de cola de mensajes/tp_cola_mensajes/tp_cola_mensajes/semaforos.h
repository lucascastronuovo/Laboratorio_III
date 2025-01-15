#ifndef _semaforos
#define _semaforos
#include "stdio.h"
#include "stdlib.h"    

key_t creo_clave();

int creo_semaforo();

void inicio_semaforo(int id_semaforo, int valor);

void levanta_semaforo(int id_semaforo);

void espera_semaforo(int id_semaforo);

#endif

