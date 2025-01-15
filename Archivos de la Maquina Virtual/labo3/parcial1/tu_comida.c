#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "def_gen.h"
#include "gestiones.h"
#include "funciones.h"
#include "semaforo.h"

struct paneles {

	int nro_panel;
	char mensaje[LARGO];

};





int main(int argc, char *argv[]){
	
	int nro_menu;
	int postre;
	int precio;
	char cant_ord[LARGO];
	int cant_ord_int;
	int precio_total_int;
	char precio_total[LARGO];
	int id_semaforo;
 
	id_semaforo =  crearSemaforo();
	iniciarSemaforo(id_semaforo, VERDE);

	if(argc == 1){
		
		





		while(1){
			printf("Menús:\n");
			printf("Menú A: $1000:\n");	
			printf("Menú B: $2000\n");
			printf("Menú C: $3000\n");

			srand(time(NULL));

			nro_menu = obtenerNumeroAleatorio(1,3);
			memset(&cant_ord[0],0x00,sizeof(cant_ord));
			memset(&precio_total[0],0x00,sizeof(precio_total));



			switch(nro_menu){
		
				case 1:
					precio=1000;
			
			
					printf("Postre?: (SI=1) (NO=0) \n");
					scanf("%d", &postre);
			
					if(postre==1){
						precio=precio+200;
					}
					else if(postre==0){

						precio=precio;
					}
					else{
						printf("No se ha ingresado una opción correcta\n");
					}			
					printf("Precio: %d\n", precio);

					esperarSemaforo(id_semaforo);
					arc=abrirArchivo("ordenes.txt","r");
					obtenerLineaArchivo(arc,&cant_ord[0],sizeof(cant_ord) ,2);
					cant_ord_int= atoi(cant_ord)+1;
			
					obtenerLineaArchivo(arc,&precio_total[0],sizeof(precio_total) ,3);
					precio_total_int=atoi(precio_total)+precio;
			
					snprintf(&cant_ord[0],sizeof(cant_ord),"%d\n",cant_ord_int);
					snprintf(&precio_total[0],sizeof(precio_total),"%d\n",precio_total_int);
					cerrarArchivo(arc);
			
					reemplazarLineaArchivo(arc,&cant_ord[0],2,"ordenes.txt");
					reemplazarLineaArchivo(arc,&precio_total[0],3,"ordenes.txt");
					levantarSemaforo(id_semaforo);
			
					break;
				case 2:
					precio=2000;

					esperarSemaforo(id_semaforo);
					printf("Postre?: (SI=1) (NO=0) \n");
					scanf("%d", &postre);
			
					if(postre==1){
						precio=precio+200;
					}
					else if(postre==0){

						precio=precio;
					}
					else{
						printf("No se ha ingresado una opción correcta\n");
					}
					printf("Precio: %d\n", precio);
					arc=abrirArchivo("ordenes.txt","r");
					obtenerLineaArchivo(arc,&cant_ord[0],sizeof(cant_ord) ,7);
					cant_ord_int= atoi(cant_ord)+1;
			
					obtenerLineaArchivo(arc,&precio_total[0],sizeof(precio_total) ,8);
					precio_total_int=atoi(precio_total)+precio;
			
					snprintf(&cant_ord[0],sizeof(cant_ord),"%d\n",cant_ord_int);
					snprintf(&precio_total[0],sizeof(precio_total),"%d\n",precio_total_int);
					cerrarArchivo(arc);
					reemplazarLineaArchivo(arc,&cant_ord[0],7,"ordenes.txt");
					reemplazarLineaArchivo(arc,&precio_total[0],8,"ordenes.txt");
					levantarSemaforo(id_semaforo);
					break;
				case 3:
					precio=3000;

			
					printf("Postre?: (SI=1) (NO=0) \n");
					scanf("%d", &postre);
			
					if(postre==1){
						precio=precio+200;
					}
					else if(postre==0){

						precio=precio;
					}
					else{
						printf("No se ha ingresado una opción correcta\n");
					}

					printf("Precio: %d\n", precio);
					esperarSemaforo(id_semaforo);
					arc=abrirArchivo("ordenes.txt","r");
					obtenerLineaArchivo(arc,&cant_ord[0],sizeof(cant_ord) ,12);
					cant_ord_int= atoi(cant_ord)+1;
			
					obtenerLineaArchivo(arc,&precio_total[0],sizeof(precio_total) ,13);
					precio_total_int=atoi(precio_total)+precio;
			
					snprintf(&cant_ord[0],sizeof(cant_ord),"%d\n",cant_ord_int);
					snprintf(&precio_total[0],sizeof(precio_total),"%d\n",precio_total_int);
					cerrarArchivo(arc);
					reemplazarLineaArchivo(arc,&cant_ord[0],12,"ordenes.txt");
					reemplazarLineaArchivo(arc,&precio_total[0],13,"ordenes.txt");
					levantarSemaforo(id_semaforo);
					break;
		


			}
	
	
		}

			}
	else{
		
		printf("Error: Se han ingresados parámetros\n");
	
	}

	return 0;


}
