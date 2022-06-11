#ifndef editorial_H_INCLUDED
#define editorial_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <string.h>


typedef struct
{
    int idTipoPasajero;
    char tipoPasajero[50];
}eTipoPasajero;

eTipoPasajero* tipoPasajero_new();
eTipoPasajero* tipoPasajero_newParametros(int* pIdTipoPasajero, char pTipo[]);



int altaTipoPasajero();


int controller_addtipoPassenger(LinkedList* pArrayListTipoPassenger);
int printTipoDePassanger(eTipoPasajero tipoPasajero[], int tamPasajeros);

int tipoPasajero_getIdtipoPasajero(eTipoPasajero* this, int* pIdTipoPasajero);
int tipoPasajero_setIdtipoPasajero(eTipoPasajero* this, int pIdTipoPasajero);

int tipoPasajero_getTipoPasajero(eTipoPasajero* this, char* pTipo);
int tipoPasajero_setTipoPasajero(eTipoPasajero* this, char* pTipo);



#endif
