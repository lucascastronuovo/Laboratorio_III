#ifndef _DEFINICIONES_H
#define _DEFINICIONES_H
 


typedef enum
{
	MSG_NADIE,				
	MSG_BANCO,		
	MSG_CAJERO,			
}Destinos;

typedef enum
{
	EVT_NINGUNO,
	EVT_CONSULTA_SALDO, 
	EVT_DEPOSITO,	
	EVT_EXTRACCION, 
	EVT_RTA_SALDO,
	EVT_RTA_SALDO_NOK,
	EVT_RTA_DEPOSITO_OK,
	EVT_RTA_DEPOSITO_NOK,
	EVT_RTA_EXTRACCION_OK,
	EVT_RTA_EXTRACCION_NOK
}Eventos;


#endif