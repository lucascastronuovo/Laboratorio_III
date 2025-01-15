#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "global.h"
#include "funciones.h"


void *funcionThread(void *parametro){

	struct tipo_juego *ptr = (struct tipo_juego*)parametro;

	int num_pens = *ptr->numero_pensado;
	int est_ac = *ptr->estado_acierto;

	
	printf("Numero pensado desde hilo %d y estado acierto desde hilo %d\n", num_pens, est_ac);



}
