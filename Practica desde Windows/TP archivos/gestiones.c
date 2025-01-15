#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestiones.h"

void abrirMenu(){
    int opc=0;
    int a;
    int n;
    char direccion [20];
    char modo [20];
    char esc[20];
    /*FILE *arcesc;*/
    /*char direccion [20];
    char modo [20];*/
    
    char lec[20];
    /*FILE *arclec;*/
    
    while (opc!= -1){
        printf("\n \nIngrese una opción: \n");
        printf("1 --> Escribir Archivo\n");
        printf("2 --> Leer Archivo\n");
        printf("-1 --> Salir\n");
        scanf("%d", &opc);
        switch(opc) {
            case 1:
            /*arcesc (FILE *)malloc(sizeof (FILE)); */

                memset(&direccion [0], 0x00, sizeof(direccion));
                memset(&modo [0], 0x00, sizeof(modo));
                strcpy(&direccion[0], "producto.txt"); 
                strcpy(&modo [0], "w");
                a=abrirArchivo(&direccion [0], &modo [0]);
                for (n=1;n<11;n++) {


                    memset(&esc[0], 0x00, sizeof(esc));
                    printf("PRODUCT0-%02d\n", n);
                    scanf("%s", &esc[0]);
                    escribirArchivo(&esc[0], n, a);
                }
           
                cerrarArchivo (&modo [0]);
                /*free (arcesc);*/
                break;

                case 2:

                /*arclec=(FILE *)malloc(sizeof (FILE)); */
                memset(&direccion [0], 0x00, sizeof(direccion));
                memset(&modo [0], 0x00, sizeof(modo));
                strcpy(&direccion[0], "producto.txt");
                strcpy(&modo [0], "r");
                a=abrirArchivo(&direccion[0], &modo [0]);
                while (!feof (arclec)) {
                
                    memset(&lec[0], 0x00, sizeof (lec)); leerArchivo (&lec[0], a);
                    printf("Se consumió: %s\n", &lec[0]);
                }
                cerrarArchivo(&modo[0]);
                /*free (arclec);*/
                break;
                
                case -1:
                    printf("Salir\n");
                    break;

                default:
                    printf("Ingrese una opción válida\n");
        }       

    }


}