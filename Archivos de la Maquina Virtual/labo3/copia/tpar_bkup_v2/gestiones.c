#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestiones.h"


void abrirMenu(){

	int opc=0;
	int a;
	int n;
	char direccion[20];
	char modo[20];
	char esc[20];
	
	


	
	
	char lec[20];
	

	
	while(opc != -1){

		printf("\n \nIngrese una opción: \n");
		printf("1 --> Escribir Archivo\n");
		printf("2 --> Leer Archivo\n");
		printf("-1 --> Salir\n");
		scanf("%d", &opc);
		
		switch(opc) {
			
			case 1:
		

				

			
				

				memset(&direccion[0],0x00,sizeof(direccion));
				memset(&modo[0],0x00,sizeof(modo));

				strcpy(&direccion[0], "producto.txt");
				strcpy(&modo[0], "w");
				

				a=abrirArchivo(&direccion[0], &modo[0]);
			
				for(n=1;n<11;n++){
					
					memset(&esc[0],0x00,sizeof(esc));
					printf("PRODUCTO-%02d\n",n);
					scanf("%s", &esc[0]);
					escribirArchivo(&esc[0], n);	
								
				
				}
			
				cerrarArchivo(&modo[0]);
				

				




				


				
				break;
			
	
			case 2:	
				
			
				
				
				memset(&direccion[0],0x00,sizeof(direccion));
				memset(&modo[0],0x00,sizeof(modo));				
				
				strcpy(&direccion[0], "producto.txt");
				strcpy(&modo[0], "r");
				
				a=abrirArchivo(&direccion[0], &modo[0]);
				
				while(!feof(arc)){
					
					memset(&lec[0],0x00,sizeof(lec));
					leerArchivo(&lec[0], a);
					printf("Se consumió: %s\n",&lec[0]);
			
					
				}
				
				cerrarArchivo(&modo[0]);
				
				break;
				
				
				
			
			case -1:
				printf("Salir\n");
				
				break;

			default:
				printf("Ingrese una opción válida\n");
					

		}


	}



}


int abrirArchivo(char *direccion, char *modo){
	
	
/*
	memset(direccion,0x00,sizeof(direccion));
	memset(modo,0x00,sizeof(modo));
*/
	if((arc=fopen(direccion, modo))==NULL){
		
		
		return 0;
		
	}
	else{
		
		return 1;

	}
	
	

}

void cerrarArchivo(char *modo) {
	
	/*if(modo=="w"){*/
		
		fclose(arc);
	/*}*/
	/*else{
		
		fclose(arclec);
	}*/

}

void leerArchivo(char *lec, int a) {

	if(a==1){
	
		fscanf(arc,"%s\n",lec);

	}
	else{
		printf("No se puede Abrir\n");
	}

	



}




void escribirArchivo( char *esc, int n) {
	
	
	
	fprintf(arc,"%s-%02d\n",esc,n);		



}

/*
int producir(FILE *pro,int n){
	
	char nompro[20];

	
	
		printf("PRODUCTO-%02d\n",n);
		scanf("%s", nompro);

		fprintf(pro,"%s-%02d\n",nompro,n);		


	return 0;
}

int consumir(FILE *con){

	char nomcon[20];
		
	
		
		while(!feof(con)){
			
			fscanf(con,"%s\n",nomcon);
			printf("Se consumió: %s\n",nomcon);
			

		}
		
	

	return 0;
}

*/

