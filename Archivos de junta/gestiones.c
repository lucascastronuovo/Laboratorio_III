#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestiones.h"




int abrirArchivo(char *direccion, char *modo){
	
	

	if((arc=fopen(direccion, modo))==NULL){
		
		
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

	
	fscanf(arc,"%s",lec);


}




void escribirArchivo(char *esc) {
	
	
	
	fprintf(arc,"%s",esc);  /*ver si sacar el \n o no*/		



}



void renombrarArchivo(char *na, char *nn){


	rename(na, nn);


}


void replazarLineaArchivo(int delete_line) {
    FILE *arcAux;
    char filechar[40] = "paneles.txt";
    char c;
    //int delete_line; 
	int temp = 1;
 
	
    //printf("Enter file name: ");
    //scanf("%s", filechar);
    //arc = fopen(filechar, "r");
    //c = getc(arc);

	/*
    //print the contents of file .
    while (c != EOF)
    {
        printf("%c", c);
        c = getc(arc);
    }
    printf(" \n Enter line number to be deleted and replaced");
    scanf("%d", &delete_line);
    //take arc to start point.
    rewind(arc);
	*/

    //open replica.c in write mode
    auxArc = fopen("replica.c", "w");
    c = getc(arc);
    while (c != EOF)
    {
        if (c == 'n')
        {
            temp++;
        }
        //till the line to be deleted comes,copy the content to other
        if (temp != delete_line)
        {
            putc(c, auxArc);
        }
        else
        {
            while ((c = getc(arc)) != 'n')
            {
            }
            //read and skip the line ask for new text
            printf("Enter new text");
            //flush the input stream
            fflush(stdin);
            putc('n', auxArc);
            //put 'n' in new file
            while ((c = getchar()) != 'n')
                putc(c, auxArc);
            //take the data from user and place it in new file
            fputs("n", auxArc);
            temp++;
        }
        //continue this till EOF is encountered
        c = getc(arc);
    }
    fclose(arc);
    fclose(auxArc);
    remove(filechar);
    rename("replica.c", filechar);
    //arc = fopen(filechar, "r");
    //reads the character from file
    //c = getc(arc);
    //until last character of file is encountered
	/*
    while (c != EOF)
    {
        printf("%c", c);
        //all characters are printed
        c = getc(arc);
    }
	*/
    //fclose(arc);
}




