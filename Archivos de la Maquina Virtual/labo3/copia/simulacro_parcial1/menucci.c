#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menucci.h"
#include "gestiones.h"



void abrirMenuCCI(){

	int opc=0;
	char lec[20 + 1];
	char esc[20 + 1];
	int a;
	int nrop;
	
	
	while(1){
		
		printf("\n \nIngrese una opción: \n");
		printf("1 --> Leer Panel\n");
		printf("2 --> Escribir Panel\n");
		scanf("%d", &opc);
		
		switch(opc) {
			
			case 1:
				printf("Seleccione Panel: \n");
				scanf("%d", &nrop);
				
				if(nrop==1){				

					a=abrirArchivo("panel1.txt", "r");
					if(a==0){
		
						printf("No se puede Abrir\n");
					}
					else if(a==1){
						while(!feof(arc)){
					
							memset(&lec[0],0x00,sizeof(lec));
							leerArchivo(&lec[0]);
							/*printf("%s\n",&lec[0]);*/
				
								
						}
						cerrarArchivo();
						
					}

				}
				else if(nrop==2){

					a=abrirArchivo("panel2.txt", "r");
					if(a==0){
		
						printf("No se puede Abrir\n");
					}
					else if(a==1){
						while(!feof(arc)){
					
							memset(&lec[0],0x00,sizeof(lec));
							leerArchivo(&lec[0]);
							/*printf("%s\n",&lec[0]);*/
				
								
						}
						cerrarArchivo();
					
					}

				}
				else if(nrop==3){

					a=abrirArchivo("panel3.txt", "r");
					if(a==0){
		
						printf("No se puede Abrir\n");
					}
					else if(a==1){
						while(!feof(arc)){
					
							memset(&lec[0],0x00,sizeof(lec));
							leerArchivo(&lec[0]);
							/*printf("%s\n",&lec[0]);*/
				
								
						}
						cerrarArchivo();
					
					}

				}
				else{
					printf("No se pudo hacer la lectura\n");
				}
				break;
			
	
			case 2:	
				printf("Seleccione Panel: \n");
				scanf("%d", &nrop);
				
				if(nrop==1){

					a=abrirArchivo("panel1.txt", "w");
					if(a==0){
		
						printf("No se puede Abrir\n");
					}
					else if(a==1){
						memset(&esc[0],0x00,sizeof(esc));
						printf("Mensaje:\n");
						scanf("%s", &esc[0]);
						escribirArchivo(&esc[0]);
						
						cerrarArchivo();
					}

				}	
				else if(nrop==2){

					a=abrirArchivo("panel2.txt", "w");
					if(a==0){
		
						printf("No se puede Abrir\n");
					}
					else if(a==1){
						memset(&esc[0],0x00,sizeof(esc));
						printf("Mensaje:\n");
						scanf("%s", &esc[0]);
						escribirArchivo(&esc[0]);
						
						cerrarArchivo();
					}

				}
				else if(nrop==3){

					a=abrirArchivo("panel3.txt", "w");
					if(a==0){
		
						printf("No se puede Abrir\n");
					}
					else if(a==1){
						memset(&esc[0],0x00,sizeof(esc));
						printf("Mensaje:\n");
						scanf("%s", &esc[0]);
						escribirArchivo(&esc[0]);
						
						cerrarArchivo();
					}

				}
				else{
					printf("No se pudo hacer la escritura\n");
				}
				
				break;
				
				
				
			
			case -1:
				printf("Salir\n");
				
				break;

			default:
				printf("Ingrese una opción válida\n");
					

		}


	}



}
