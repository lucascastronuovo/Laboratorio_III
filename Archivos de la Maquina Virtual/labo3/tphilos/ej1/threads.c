#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "global.h"
#include "funciones.h"


void *funcionThread(void *parametro){

	
	
	int* ptr=(int*)parametro;

	int n, p=0,m=99, i, stop, num, vec[100];
	int jug_num_pen;

	int hp_num_pen = ptr[0];
	
	int id = ptr[2];
	

	static int vec_jug[50];
	





	n= obtenerNumeroAleatorio(500,5000);	
	


	do{
		stop=0;
		num = obtenerNumeroAleatorio(1,99);
		for (i=0;(i<m && stop==0 && p!=0);i++){
			if (vec[i]==num){
				stop=1;
				n=i;
			}
		}
	}while(stop==1);



	vec[p]=num;
	jug_num_pen = vec[p];


	pthread_mutex_lock(&mutex);
	printf("--------\n");
	printf("Hilo %d\n", id);
	printf("Número pensado principal: %d - Número pensado jugador: %d\n", hp_num_pen, jug_num_pen);

	vec_jug[id]++;
	if(hp_num_pen == jug_num_pen){
		ptr[1]=1;
		ptr[2]=id;
	
	}

	printf("Estado: %d\n", ptr[1]);

	usleep(n);
	pthread_mutex_unlock(&mutex);





}



