#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "archivos.h"
#include "semaforos.h"
#include "definiciones.h"

int main(int argc, char *argv[])
{
    int i = 0;
    fpos_t pos = (fpos_t)NULL;
    int vuelo = -1;
    int pasajeros = 0;
    char destino[20 + 1];
    char str[LARGO];
    char log[12 + 1];
    int id_semaforo = creo_semaforo();
    int pasajeros_1000 = 0;
    int pasajeros_1001 = 0;
    int pasajeros_1002 = 0;
    int pasajeros_1003 = 0;
    int pasajeros_1004 = 0;
    int pasajeros_1005 = 0;
    int pasajeros_1006 = 0;
    int pasajeros_1007 = 0;
    int pasajeros_1008 = 0;
    int pasajeros_1009 = 0;
    int pasajeros_1010 = 0;

    inicia_semaforo(id_semaforo, VERDE);
    while (1)
    {
        espera_semaforo(id_semaforo);
        /* inicio de seccion critica */
        do
        {
            memset(str, 0x00, sizeof(str));
            leer_archivo(FILE_PATH, str, 60, &pos);
            printf("%s", str);
            if (str[0] == 0x00)
            {
                memset(log, 0x00, sizeof(log));
                sprintf(log, LOG_PATH, i);
                renombrar_archivo(FILE_PATH, log);
                i++;
            }
            else
            {
                sscanf(str, OUT_FORMAT, &vuelo, destino, &pasajeros);
                /* printf("%d %d\n", vuelo, pasajeros); */
                sleep(1);
                if (vuelo == 0)
                {
                    pasajeros_1000 += pasajeros;
                }
                else if (vuelo == 1)
                {
                    pasajeros_1001 += pasajeros;
                }
                else if (vuelo == 2)
                {
                    pasajeros_1002 += pasajeros;
                }
                else if (vuelo == 3)
                {
                    pasajeros_1003 += pasajeros;
                }
                else if (vuelo == 4)
                {
                    pasajeros_1004 += pasajeros;
                }
                else if (vuelo == 5)
                {
                    pasajeros_1005 += pasajeros;
                }
                else if (vuelo == 6)
                {
                    pasajeros_1006 += pasajeros;
                }
                else if (vuelo == 7)
                {
                    pasajeros_1007 += pasajeros;
                }
                else if (vuelo == 8)
                {
                    pasajeros_1008 += pasajeros;
                }
                else if (vuelo == 9)
                {
                    pasajeros_1009 += pasajeros;
                }
                else if (vuelo == 10)
                {
                    pasajeros_1010 += pasajeros;
                }
            }
        } while (str[0] != 0x00);

        /* fin de seccion critica */
        levanta_semaforo(id_semaforo);

        printf("-------------------\n");
        printf("VUELO\tPASAJEROS\n");
        printf("1000\t%d\n", pasajeros_1000);
        printf("1001\t%d\n", pasajeros_1001);
        printf("1002\t%d\n", pasajeros_1002);
        printf("1003\t%d\n", pasajeros_1003);
        printf("1004\t%d\n", pasajeros_1004);
        printf("1005\t%d\n", pasajeros_1005);
        printf("1006\t%d\n", pasajeros_1006);
        printf("1007\t%d\n", pasajeros_1007);
        printf("1008\t%d\n", pasajeros_1008);
        printf("1009\t%d\n", pasajeros_1009);
        printf("1010\t%d\n", pasajeros_1010);
        printf("-------------------\n");

        usleep(ESPERA);
    }
    return 0;
}