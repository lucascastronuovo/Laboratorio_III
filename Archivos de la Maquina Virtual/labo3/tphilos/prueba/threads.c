#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "global.h"
#include "funciones.h"


void *funcionThread(void *parametro){

	
	
	int* ptr=(int*)parametro;
	int n = *ptr;
	int p=0,m=99, i, stop, num, vec[100];
	int jug_num_pen;

	int hp_num_pen = ptr[0];
	
	for(i=0;i<1000;i++){
		
		n++;

	}

	/*pthread_mutex_lock(&mutex);*/
	printf("--------\n");
	printf("numero %d\n", n);
	
	/*pthread_mutex_unlock(&mutex);*/
	sleep(2);




}



void *funcionThread2(void *parametro){

	
	
	int* ptr=(int*)parametro;
	int n = *ptr;
	int p=0,m=99, i, stop, num, vec[100];
	int jug_num_pen;

	int hp_num_pen = ptr[0];
	
	for(i=0;i<1000;i++){
		
		n--;

	}

	printf("--------\n");
	printf("numero %d\n", n);
	

	sleep(2);




}
