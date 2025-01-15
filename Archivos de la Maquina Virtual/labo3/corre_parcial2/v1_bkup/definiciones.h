#ifndef _DEFI_H
#define _DEFI_H

#define ROJO 0
#define VERDE 1
#define CLAVE_BASE 33
#define CANT_INSUMOS 4

typedef struct t_insumos insumos;
struct t_insumos{

	char descripcion[50];
	int cant_insumo;


};

typedef struct t_estados estados;
struct t_estados{

	int cant_hormigas;
	

};


#endif
