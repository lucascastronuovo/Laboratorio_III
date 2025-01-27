#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestiones.h"
#include "def_gen.h"


FILE* abrirArchivo(char *direccion, char *modo){

	FILE *fp;

	if((fp=fopen(&direccion[0], &modo[0]))==NULL){
		
		
		return 0x00;
		
	}
	else{

		return fp;
	
	}
		
	



}


void cerrarArchivo(FILE *fp) {
			
		
	fclose(fp);
	
}



void leerArchivo(FILE *fp,char *lec) {

	
	fscanf(fp,"%s",&lec[0]);



}



void leerArchivoConEspacios(FILE *fp,char *lec, int tam){


	fgets(&lec[0],tam,fp);


}



void escribirArchivo(FILE *fp,char *esc) {
	
	
	
	fprintf(fp,"%s",&esc[0]);	



}

void renombrarArchivo(FILE *fp,char *nom_ant, char *nom_nue){


	
	
	char buffer[LARGO];
	

	FILE *temp;
	
	
	
	temp=abrirArchivo(&nom_nue[0], "w");
	fp=abrirArchivo(&nom_ant[0],"r");


	if(temp==0x00 || fp==0x00){
		printf("No se puede abrir\n");	
	}
	else{	
	
		do{	
			memset(&buffer[0],0x00,sizeof(buffer));
			leerArchivoConEspacios(fp,buffer, LARGO);			
			escribirArchivo(temp, &buffer[0]);			
			
			

		}while(!feof(fp));

	cerrarArchivo(temp);
	cerrarArchivo(fp);		

	eliminarArchivo(&nom_ant[0]);

	}


}



void eliminarArchivo(char *direccion){


	remove(&direccion[0]);

}



void obtenerLineaArchivo(FILE *fp,char *linea,int tam_linea ,int num_linea){

	int seg_ley=1;
	int cont_linea=1;

	do{	
		
		leerArchivoConEspacios(fp,&linea[0],tam_linea);

		if(feof(fp)){
			seg_ley=0;
			
		}
		else if(cont_linea==num_linea){
			
			seg_ley=0;
		}
		cont_linea++;
	
	}while(seg_ley==1);
	
	
}

void obtenerUltimaLineaArchivo(FILE *fp,char *linea,int tam_linea){

	int seg_ley=1;
	int cont_linea=1;

	do{	
		
		leerArchivoConEspacios(fp,&linea[0],tam_linea);

		if(feof(fp)){
			seg_ley=0;
		}	
		
		cont_linea++;
	
	}while(seg_ley==1);
	
	
}



void reemplazarLineaArchivo(FILE *fp,char *nueva_linea,int num_linea,char *direccion){

	

	
	char temp_direccion[LARGO] = "temp___";
	char buffer[LARGO];
	

	int seg_ley=1;
	int cont_linea=1;

	FILE *temp;
	
	strcat(temp_direccion, &direccion[0]);
	
	temp=abrirArchivo(&temp_direccion[0], "w");
	fp=abrirArchivo(&direccion[0],"r");


	if(temp==0x00 || fp==0x00){
		printf("No se puede abrir\n");	
	}
	else{	
	
		do{
			leerArchivoConEspacios(fp,&buffer[0], LARGO);
			
			if(feof(fp)){
				seg_ley=0;			
			}
			else if(cont_linea==num_linea){
				escribirArchivo(temp, &nueva_linea[0]);
			}
			else{
				escribirArchivo(temp, &buffer[0]);			
			}
			
			cont_linea++;
		}while(seg_ley==1);

	cerrarArchivo(temp);
	cerrarArchivo(fp);		

	
	renombrarArchivo(fp,&temp_direccion[0],&direccion[0]);


	}
	



}






