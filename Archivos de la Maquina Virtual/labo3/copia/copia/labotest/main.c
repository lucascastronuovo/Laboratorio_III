#include "stdlib.h"
#include "stdio.h"
#include "main.h"

void mostrar(){

}

int main(int incant,char *szarg[])
{
	int x=0;
	x = atoi(szarg[2]);
	printf("Estudiante %s Edad %d Primer Letra %c ", szarg[1], x,szarg[1][0]);
	mostrar();
	/*casa casita;*/

	return 0;
	
}


