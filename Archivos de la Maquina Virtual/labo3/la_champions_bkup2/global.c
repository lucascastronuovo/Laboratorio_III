#include <pthread.h>
#include "global.h"

pateador *pateadores;

Destinos destinos;

Eventos eventos;

pthread_mutex_t mutex;

int* inicializado;
