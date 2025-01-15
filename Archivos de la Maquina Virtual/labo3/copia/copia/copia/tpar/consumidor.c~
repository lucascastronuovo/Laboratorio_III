#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestiones.h"
#include "consumidor.h"


void consumir(){

	
	char direccion[20];
	char modo[20];
	char lec[20];
	int a;
	


	memset(&direccion[0],0x00,sizeof(direccion));
	memset(&modo[0],0x00,sizeof(modo));
	memset(&lec[0],0x00,sizeof(lec));	

	strcpy(&direccion[0], "producto.txt");
	strcpy(&modo[0], "r");
	a=abrirArchivo(&direccion[0], &modo[0]);

	if(a==0){
		
		printf("No se puede Abrir\n");
	}
	else{
		if(a==1){

			while(!feof(arc)){
					
				memset(&lec[0],0x00,sizeof(lec));
				leerArchivo(&lec[0]);
				printf("Se consumió: %s\n",&lec[0]);
				
								
			}
		
			cerrarArchivo(&modo[0]);
		
		}
		
	}



}
