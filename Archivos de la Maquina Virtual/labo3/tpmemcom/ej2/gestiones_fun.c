#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestiones_fun.h"
#include "gestiones.h"
#include "defprac.h"


void escribir(char *direccion,char *modo,char *esc){

	arc=abrirArchivo(&direccion[0],&modo[0]);
	
	if(arc==0x00){
		printf("No se puede abrir\n");	
	}
	else if(&modo[0]=="r"){
		printf("Se indico lectura cuando se quiere escribir\n");	
	}
	else{
		escribirArchivo(arc,&esc[0]);

		cerrarArchivo(arc);
		
	}


}

void leer(char *direccion, char *modo){

	char lec[LARGO];	
	
	arc=abrirArchivo(&direccion[0],&modo[0]);
	
	if(arc==0x00){
		printf("No se puede abrir\n");	
	}
	else if(&modo[0]=="w"){
		printf("Se indico escritura cuando se quiere leer\n");	
	}
	else{
		while(!feof(arc)){
					
			memset(&lec[0],0x00,sizeof(lec));
			leerArchivo(arc,&lec[0]);
			printf("%s",&lec[0]);
				
								
		}

		cerrarArchivo(arc);
		
	}

}

void leerConEspacios(char *direccion, char *modo){

	char lec[LARGO];	
	
	arc=abrirArchivo(&direccion[0],&modo[0]);
	
	if(arc==0x00){
		printf("No se puede abrir\n");	
	}
	else if(&modo[0]=="w"){
		printf("Se indico escritura cuando se quiere leer\n");	
	}
	else{
		while(!feof(arc)){
					
			memset(&lec[0],0x00,sizeof(lec));
			leerArchivoConEspacios(arc,&lec[0],sizeof(lec));
			printf("%s",&lec[0]);
				
								
		}

		cerrarArchivo(arc);
		
	}

}


void ultimaLinea(char *direccion,char *modo,char *linea){
	
	int seg_ley=1;
	int cont_linea=1;


	arc=abrirArchivo(&direccion[0],&modo[0]);
		
	if(arc==0x00){
		printf("No se puede abrir\n");		
	}
	else{
		memset(&linea[0],0x00,sizeof(linea));
		
		do{	
		
			leerArchivoConEspacios(arc,&linea[0],LARGO);

			if(feof(arc)){
				seg_ley=0;
			}	
		
			cont_linea++;
	
		}while(seg_ley==1);

		
		cerrarArchivo(arc);	
		
	}	


}

void lineaEspecifica(char *direccion,char *modo,char *linea,int num_linea){

	arc=abrirArchivo(&direccion[0],&modo[0]);
		
	if(arc==0x00){
		printf("No se puede abrir\n");		
	}
	else{
		memset(&linea[0],0x00,sizeof(linea));
		obtenerLineaArchivo(arc,&linea[0],sizeof(linea), num_linea);
		
		cerrarArchivo(arc);	
		
	}

}


