#include "tipoPassenger.h"
#include "Passenger.h"
#include "input.h"

eTipoPasajero* tipoPasajero_new()
{
	eTipoPasajero* auxTipoPasajero;

	auxTipoPasajero = malloc(sizeof(eTipoPasajero));

    if(auxTipoPasajero == NULL)
    {
        printf("No hay espacio en memoria de Tipo De Pasajero");
        return 0;
    }

    return auxTipoPasajero;
}

eTipoPasajero* tipoPasajero_newParametros(int* pIdTipoPasajero, char pTipo[])
{
	eTipoPasajero* auxTipoPasajero;
	auxTipoPasajero = tipoPasajero_new();

	tipoPasajero_setIdtipoPasajero(auxTipoPasajero,*pIdTipoPasajero);
	tipoPasajero_setTipoPasajero(auxTipoPasajero, pTipo);

    return auxTipoPasajero;
}

int tipoPasajero_getIdtipoPasajero(eTipoPasajero* this, int* pIdTipoPasajero)
{
	int retorno = 0;

	if(this!=NULL)
    {
		*pIdTipoPasajero= this->idTipoPasajero;
        retorno = 1;
    }

    return retorno;
}

int tipoPasajero_setIdtipoPasajero(eTipoPasajero* this, int pIdTipoPasajero)
{
	int retorno = 0;

	if(this!=NULL)
    {
		this->idTipoPasajero = pIdTipoPasajero;
        retorno = 1;
    }

    return retorno;

}

int tipoPasajero_getTipoPasajero(eTipoPasajero* this, char* pTipo)
{
	int retorno = 0;

	if(this!=NULL)
    {
    	strcpy(pTipo,this->tipoPasajero);
    	retorno = 1;
    }
	return retorno;

}

int tipoPasajero_setTipoPasajero(eTipoPasajero* this, char* pTipo)
{
	int retorno = 0;

	if(this!=NULL)
    {
		strcpy(this->tipoPasajero , pTipo);
        retorno = 1;
    }

    return retorno;
}

int altaTipoPasajero(LinkedList* pArrayListTipoPassenger) //llama a los de abajo
{
	 int retorno = 0;
	 int id;

	 char tipoPasajero[50];


	 eTipoPasajero* auxTipoPasajero = NULL;

	    if(pArrayListTipoPassenger != NULL)
	    {
	        id = Passenger_getNextId(pArrayListTipoPassenger);

	        if(id != -1 && !inputString(tipoPasajero, "Ingrese Tipo de Pasajero: ", "Error, Ingrese Tipo de Pasajero: ", 1, 4, 0))
	        {
	            if(auxTipoPasajero != NULL && ll_add(pArrayListTipoPassenger, (Passenger*)auxTipoPasajero) == 0)
	            {
	            	retorno = 1;
	            }
	        }
	    }

	return retorno;
}

int printTipoDePassanger(eTipoPasajero tipoPasajero[], int tamPasajeros)
{
    int i;

    printf("ID Tipo De Pasajeros    -      Nombre \n\n");

    for(i=0; i < tamPasajeros; i++)
    {
        printf("%10d         %18s\n", tipoPasajero[i].idTipoPasajero, tipoPasajero[i].tipoPasajero);
    }

    return i;
}
