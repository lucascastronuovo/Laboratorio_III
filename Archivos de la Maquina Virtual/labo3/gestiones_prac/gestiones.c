#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestiones.h"
#include "defprac.h"


FILE* abrirArchivo3(char *direccion, char *modo){

	FILE *fp;

	if((fp=fopen(&direccion[0], &modo[0]))==NULL){
		
		
		return 0x00;
		
	}
	else{

		return fp;
	
	}
		
	



}

void abrirArchivo2(FILE **fp,char *direccion, char *modo){
	
	

	if((*fp=fopen(&direccion[0], &modo[0]))==NULL){
		
		
		printf("No se pudo abrir el archivo\n");
		
	}
	
	

}

int abrirArchivo(char *direccion, char *modo){
	
	

	if((arc=fopen(&direccion[0], &modo[0]))==NULL){
		
		
		return 0;
		
	}
	else{
		
		return 1;

	}
	
	

}

void cerrarArchivo2(FILE *fp) {
			
		
	fclose(fp);
	
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

void escribirArchivo2(FILE *fp,char *esc) {
	
	
	
	fprintf(fp,"%s",&esc[0]);	



}

void escribirArchivo(char *esc) {
	
	
	
	fprintf(arc,"%s",&esc[0]);	



}



void renombrarArchivo(char *nom_ant, char *nom_nue){


	rename(&nom_ant[0], &nom_nue[0]);


}

void eliminarArchivo(char *direccion){


	remove(&direccion[0]);

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

	

	
	char temp_direccion[LARGO] = "temp___";
	char buffer[LARGO];
	

	int seg_ley=1;
	int cont_linea=1;
	int a;
	
	strcat(temp_direccion, &direccion[0]);
	
	temp=abrirArchivo3(temp_direccion, "w");
	a=abrirArchivo(&direccion[0],"r");


	if(temp==0x00 || a==0){
		printf("No se puede abrir\n");	
	}
	else{	
	
		do{
			leerArchivoConEspacios(buffer, LARGO);
			
			if(feof(arc)){
				seg_ley=0;			
			}
			else if(cont_linea==num_linea){
				escribirArchivo2(temp, &nueva_linea[0]);
			}
			else{
				escribirArchivo2(temp, buffer);			
			}
			
			cont_linea++;
		}while(seg_ley==1);
	cerrarArchivo2(temp);
	cerrarArchivo();		

		eliminarArchivo(&direccion[0]);
		renombrarArchivo(temp_direccion, &direccion[0]);
	}
	



}






