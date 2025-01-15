#include <pthread.h>
#include "global.h"


insumo *insumos=0;

hormiga *datos_threads=0;

Destinos destinos;

Eventos eventos;

pthread_mutex_t mutex;


