#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "definiciones.h"
#include "semaforos.h"
#include "funciones.h"
#include "archivos.h"

int main(int argc, char *argv[])
{
    int flg = -1;
    int vuelo = 0;
    int pasajeros = 0;
    char destino[20 + 1];
    char str[60 + 1];
    int id_semaforo = creo_semaforo();

    srand(time(0));

    while (flg != 0)
    {
        flg = obtenerAleatorio();
        vuelo = obtenerAleatorio();
        pasajeros = obtenerAleatorio() + 1;
        memset(destino, 0x00, sizeof(destino));
        memset(str, 0x00, sizeof(str));

        if (vuelo == 0)
        {
            strcpy(destino, "BUENOS AIRES");
        }
        else if (vuelo == 1)
        {
            strcpy(destino, "NUEVA YORK");
        }
        else if (vuelo == 2)
        {
            strcpy(destino, "MADRID");
        }
        else if (vuelo == 3)
        {
            strcpy(destino, "PARIS");
        }
        else if (vuelo == 4)
        {
            strcpy(destino, "LONDRES");
        }
        else if (vuelo == 5)
        {
            strcpy(destino, "LISBOA");
        }
        else if (vuelo == 6)
        {
            strcpy(destino, "CARACAS");
        }
        else if (vuelo == 7)
        {
            strcpy(destino, "BOGOTA");
        }
        else if (vuelo == 8)
        {
            strcpy(destino, "MONTEVIDEO");
        }
        else if (vuelo == 9)
        {
            strcpy(destino, "RIO DE JANEIRO");
        }
        else if (vuelo == 10)
        {
            strcpy(destino, "SANTIAGO DE CHILE");
        }

        sprintf(str, OUT_FORMAT, vuelo, destino, pasajeros);
        printf(str);

        espera_semaforo(id_semaforo);
        /* inicio de seccion critica */
        escribir_archivo(FILE_PATH, str);
        /* fin de seccion critica */
        levanta_semaforo(id_semaforo);
    }

    return 0;
}
