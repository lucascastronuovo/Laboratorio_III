#include <pthread.h>
#include "global.h"

resultado *m_resultado=0;

pateador *pateadores;

Destinos destinos;

Eventos eventos;

pthread_mutex_t mutex;

int* inicializado;
