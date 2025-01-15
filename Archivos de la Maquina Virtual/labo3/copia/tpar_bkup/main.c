#include <stdio.h>
#include "gestiones.h"

int main(int argc, char *argv[]){
	
	FILE *pro;
	FILE *con;
	char nompro[20];

	int n,s;
	if((pro=fopen("producto.txt","w"))==NULL){
		
		printf("No se puede Abrir\n");
	}
	else{
		for(n=1;n<11;n++){
			printf("PRODUCTO-%02d\n",n);
			scanf("%s", nompro);		
			
			producir(pro, n,&nompro[0]);
			
		}

		
	}
	
	fclose(pro);

	for(s=1;s<=3;s++){
	
		printf("-------------\n");	
	}
	
	if((con=fopen("producto.txt","r"))==NULL){
		
		printf("No se puede Abrir\n");
	}
	else{
		
		consumir(con);

	}
	
	fclose(con);
	
	return 0;


}
