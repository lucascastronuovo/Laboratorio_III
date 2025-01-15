#include <pthread.h>
#include "global.h"

insumos *m_insumos=0;

estados *m_estados=0;

hormigas *h_hormigas;

Destinos destinos;

Eventos eventos;

pthread_mutex_t mutex;

int* inicializado;
