#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "definiciones.h"

void escribir_archivo(char *fp, char *str)
{
    FILE *f;

    f = fopen(fp, "a+");
    if (f == NULL)
    {
        printf("No se pudo abrir archivo %s\n", fp);
        exit(0);
    }

    fprintf(f, str);

    fclose(f);
}

void leer_archivo(char *fp, char *str, int size, fpos_t *pos)
{
    FILE *f;
    fpos_t position;

    f = fopen(fp, "r+");
    if (f == NULL)
    {
        printf("No se pudo abrir archivo %s\n", fp);
        printf("Esperamos archivo...\n");
    }
    else
    {
        if (*pos != (fpos_t)NULL)
        {
            fsetpos(f, pos);
        }

        fgets(str, size, f);

        if (feof(f))
        {
            memset(str, 0x00, sizeof(LARGO));
        }

        fgetpos(f, &position);

        *pos = position;

        fclose(f);
    }
}

void borrar_archivo(char *fp)
{
    remove(fp);
}

void renombrar_archivo(char *fp, char *nfp)
{
    rename(fp, nfp);
}