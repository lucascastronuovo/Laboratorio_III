#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "productor.h"
#include "consumidor.h"


void abrirMenu(){

	int opc=0;

	
	while(opc != -1){

		printf("\n \nIngrese una opción: \n");
		printf("1 --> Escribir Archivo\n");
		printf("2 --> Leer Archivo\n");
		printf("-1 --> Salir\n");
		scanf("%d", &opc);
		
		switch(opc) {
			
			case 1:
		
				producir();
				
				break;
			
	
			case 2:	
				consumir();
				
				break;
				
				
				
			
			case -1:
				printf("Salir\n");
				
				break;

			default:
				printf("Ingrese una opción válida\n");
					

		}


	}



}
