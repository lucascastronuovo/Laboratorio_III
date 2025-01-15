#include <stdlib.h>
#include "definiciones.h"
#include "funciones.h"

int obtenerAleatorio()
{
    return rand() % (HASTA - DESDE + 1) + DESDE;
}

void obtenerArrayAleatorio(int *arr, int size)
{
    int i = 0;
    for (i = 0; i < size; i++)
    {
        arr[i] = obtenerAleatorio();
    }
}