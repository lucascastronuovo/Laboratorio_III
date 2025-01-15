#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestiones.h"
#include "defprac.h"




int abrirArchivo(char *direccion, char *modo){
	
	

	if((arc=fopen(&direccion[0], &modo[0]))==NULL){
		
		
		return 0;
		
	}
	else{
		
		return 1;

	}
	
	

}

void cerrarArchivo() {
			
		
	fclose(arc);
	
}

void leerArchivo(char *lec) {

	
	fscanf(arc,"%s",&lec[0]);



}

void leerArchivoConEspacios(char *lec, int tam){


	fgets(&lec[0],tam,arc);


}


void escribirArchivo(char *esc) {
	
	
	
	fprintf(arc,"%s",&esc[0]);	



}



void renombrarArchivo(char *na, char *nn){


	rename(&na[0], &nn[0]);


}


void obtenerLineaArchivo(char *linea,int tam_linea ,int num_linea){

	int seg_ley=1;
	int cont_linea=1;

	do{	
		
		fgets(&linea[0],tam_linea,arc);

		if(feof(arc)){
			seg_ley=0;
			printf("No se encontró la línea %d\n", num_linea);
		}
		else if(cont_linea==num_linea){
			
			seg_ley=0;
		}
		cont_linea++;
	
	}while(seg_ley==1);
	
	
}

void obtenerUltimaLineaArchivo(char *linea,int tam_linea){

	int seg_ley=1;
	int cont_linea=1;

	do{	
		
		fgets(&linea[0],tam_linea,arc);

		if(feof(arc)){
			seg_ley=0;
		}	
		
		cont_linea++;
	
	}while(seg_ley==1);
	
	
}



void reemplazarLineaArchivo(char *nueva_linea,int num_linea,char *direccion){

	FILE *temp;

	
	char temp_direccion[LARGO] = "temp___";
	char buffer[LARGO];
	

	int seg_ley=1;
	int cont_linea=1;
	int a;
	
	strcat(temp_direccion, &direccion[0]);
	
	temp=fopen(temp_direccion, "w");
	a=abrirArchivo(&direccion[0],"r");


	if(temp==NULL || a==0){
		printf("No se puede abrir\n");	
	}
	else{	
	
		do{
			fgets(buffer,LARGO ,arc);	
			
			if(feof(arc)){
				seg_ley=0;			
			}
			else if(cont_linea==num_linea){
				fputs(&nueva_linea[0], temp);
			}
			else{
				fputs(buffer,temp);			
			}
			
			cont_linea++;
		}while(seg_ley==1);
	fclose(temp);
	cerrarArchivo();		

		remove(&direccion[0]);
		rename(temp_direccion, &direccion[0]);
	}
	



}






