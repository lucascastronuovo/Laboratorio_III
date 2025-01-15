#ifndef _DEFINICIONES
#define _DEFINICIONES
#include "stdio.h"
#include "stdlib.h"    


#define CANT_CLIENTES 100

typedef struct cliente_banco cliente;
struct cliente_banco
{		
	int 	codigo_cliente;			
	int 	saldo;						
};

typedef enum{
	MSG_NADIE,
	MSG_BANCO,
	MSG_CAJERO
}Destinos;

typedef enum{
	EVT_NINGUNO,
	EVT_CONSULTA_SALDO,
	EVT_DEPOSITO,
	EVT_EXTRACCION,
	EVT_RTA_SALDO,
	EVT_RTA_SALDO_NOK,
	EVT_RTA_SALDO_OK,
	EVT_RTA_DEPOSITO_NOK,
	EVT_RTA_DEPOSITO_OK,
	EVT_RTA_EXTRACCION_NOK,
	EVT_RTA_EXTRACCION_OK
}Eventos;

#endif

