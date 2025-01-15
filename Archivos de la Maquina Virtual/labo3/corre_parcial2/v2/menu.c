#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include "memcomp.h"
#include "definiciones.h"
#include "global.h"
#include "menu.h"

int menu(int cant, int *n_hormiga){
	
	int opc,i;
	int opc_h=0;
	

	while(opc_h<=0 || opc_h > cant){
		printf("Selecciona la hormiga que juntará el insumo\n\n");
		scanf("%d", &opc_h);
		
	}

	printf("Se eligió a la hormiga %d\n\n", opc_h);
	
	*n_hormiga = opc_h;
	
	printf("Elige que juntará la hormiga\n");
	printf("\n");
	for(i=0;i<CANT_INSUMOS;i++){
		printf("%d- Juntar %s:\n", i+1,&m_insumos[i].descripcion[0]);
	}
	scanf("%d", &opc);
	
	while(opc<=0 || opc > 4){
	
		printf("Elige que juntará la hormiga\n");
		scanf("%d", &opc);
	}
	
	return opc;

}

