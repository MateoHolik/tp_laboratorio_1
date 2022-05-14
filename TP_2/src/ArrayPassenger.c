#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"

#define OCUPADO 1
#define VACIO 0

int initPassengers(Passenger list[], int len)
{
	int retorno = -1;
	int i;

	if(len > 0 && list != NULL)
	{
		retorno = 0;
		for(i=0; i < len; i++)
		{
			list[i].isEmpty = 0;
			list[i].id = 0;
		}
	}
return retorno;
}

int addPassenger(Passenger list[], int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[], int statusFlight)
{
	int retorno = -1;
	int emptyIndex;

	if (list != NULL && len > 0 && len <= TAM_PASAJEROS && name != NULL && lastName != NULL)
	{
		if(findPassengerById(list, len, id) != -1)
		{
			printf("El ID ingresado ya esta en uso");
		}
		else
		{
			emptyIndex = getEmptyIndexOfPassengers(list, len);

			if(emptyIndex != -1)
			{
                list[emptyIndex].id = id;
                strcpy(list[emptyIndex].name, name);
                strcpy(list[emptyIndex].lastName, lastName);
                list[emptyIndex].price = price;
                strcpy(list[emptyIndex].flycode, flycode);
                list[emptyIndex].typePassenger = typePassenger;
                list[emptyIndex].statusFlight = statusFlight;
                list[emptyIndex].isEmpty = OCUPADO;

                retorno = 0;
			}
		}
	}
	return retorno;
}

int getEmptyIndexOfPassengers(Passenger list[], int len)
{
    int returnValue = -1;

    if(list != NULL && len > 0 && len <= TAM_PASAJEROS)
    {
        for (int i = 0; i < len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                returnValue = i;
                break;
            }
        }
    }
    return returnValue;
}

int removePassenger(Passenger list[], int len, int id)
{
    int retorno = -1;
    int i;

    for(i = 0; i < len; i++)
    {
        if(list[i].id == id)
        {
        	list[i].isEmpty = VACIO;
            retorno = 0;
        }
    }
    return retorno;
}

int sortPassengersByTipoPasajero(Passenger list[], int lenPassenger)
{
	int retorno=0;

    for(int i=0; i < lenPassenger -1; i++)
    {
        for(int j = i + 1 ; j < lenPassenger; j++)
        {
            if(list[i].isEmpty == OCUPADO)
            {
                    if(list[i].typePassenger > list[j].typePassenger)
                    {
                    	swapPassengers(list, lenPassenger, i, j);
                    }
                    else
                    {
                        if((list[i].typePassenger == list[j].typePassenger) && (stricmp(list[i].lastName,list[j].lastName) > 0))
                        {
                        	swapPassengers(list, lenPassenger, i, j);
                        }
                    }
            }
        }
    }
    return retorno;
}

int sortPassengersByLastName(Passenger list[], int lenPassenger)
{
	int retorno=0;

    for(int i=0; i < lenPassenger -1; i++)
    {
        for(int j = i + 1 ; j < lenPassenger; j++)
        {
            if(list[i].isEmpty == OCUPADO)
            {
                    if(list[i].lastName > list[j].lastName)
                    {
                    	swapPassengers(list, lenPassenger, i, j);
                    }
                    else
                    {
                        if(stricmp(list[i].lastName,list[j].lastName) > 0)
                        {
                        	swapPassengers(list, lenPassenger, i, j);
                        }
                    }
            }
        }
    }
    return retorno;
}

int printPassengers(Passenger list[], int lenght, eTipoPasajero listTipo [], int lenghtTipo)
{
    int i;
    int retorno=-1;

    printf("*******************************************************************************************************************************\n");
    printf("ID            Nombre     	     Apellido     	  Precio        Codigo De Vuelo	       Tipo De Pasajero    \n");
    printf("*******************************************************************************************************************************\n");

    for(i=0; i<lenght; i++)
    {
        if(list[i].isEmpty == OCUPADO)
        {
        	printPassenger(list[i], lenght, listTipo, lenghtTipo);

            retorno=0;
        }
    }

    return retorno;
}

int printPassenger(Passenger list, int lenght, eTipoPasajero listTipo[], int lenghtTipo)
{

	int idTipoPasajero = list.typePassenger;
	int indiceTipoPasajero = findTipoPasajeroById(listTipo, lenghtTipo, idTipoPasajero);

	printf("%2d          %-20s   %-18s  %-20.2f %-3s  	%9d - %-11s\n", list.id, list.name, list.lastName, list.price, list.flycode, list.typePassenger, listTipo[indiceTipoPasajero].name);

	return 0;
}

int printTipoDePassanger(eTipoPasajero tipoPasajero[], int tamPasajeros)
{
    int i;

    printf("ID Tipo De Pasajeros    -      Nombre \n\n");

    for(i=0; i < tamPasajeros; i++)
    {
        printf("%10d         %18s\n", tipoPasajero[i].idTipoPasajero, tipoPasajero[i].name);
    }

    return i;
}

int printPassengersEstadoVuelo(Passenger list[], int lenght, eEstadoVuelo listEstado [], int lenghtEstado)
{
    int i;
    int retorno=-1;

    printf("*******************************************************************************************************************************\n");
    printf("Apellido             Nombre 	          Codigo De Vuelo   Estado Del Vuelo    \n");
    printf("*******************************************************************************************************************************\n");

    for(i=0; i<lenght; i++)
    {
        if(list[i].isEmpty == OCUPADO && list[i].statusFlight == ESTADO_VUELO_ACTIVO)
        {
        	printPassengerEstadoVuelo(list[i], lenght, listEstado, lenghtEstado);

            retorno=0;
        }
    }

    return retorno;
}

int printPassengerEstadoVuelo(Passenger list, int lenght, eEstadoVuelo listEstado[], int lenghtEstado)
{

	int idEstadoVuelo = list.statusFlight;
	int indiceEstadoVuelo = findTipoVueloById(listEstado, lenghtEstado, idEstadoVuelo);

	printf("%-20s %-20s %-12s  %10s \n", list.lastName, list.name,  list.flycode, listEstado[indiceEstadoVuelo].nombre);

	return 0;
}

int findTipoVueloById(eEstadoVuelo list[], int len, int id)
{
    int i;
    int retorno=-1;

    for(i=0; i < len; i++)
    {
        if(list[i].idEstadoVuelo==id)
        {
            retorno=i;
        }
    }

    return retorno;
}

int findPassengerById(Passenger list[], int len, int id)
{
	 int returnValue = -1;

	    if(list != NULL && len > 0 && len <= TAM_PASAJEROS)
	    {
	        for (int i = 0; i < len; i++)
	        {
	            if(list[i].id == id)
	            {
	                returnValue = i;
	                break;
	            }
	        }
	    }

	    return returnValue;
}

int findTipoPasajeroById(eTipoPasajero list[], int len, int id)
{
    int i;
    int retorno=-1;

    for(i=0; i < len; i++)
    {
        if(list[i].idTipoPasajero==id)
        {
            retorno=i;
        }
    }

    return retorno;
}

int checkPassengersExists(Passenger list[], int tam)
{
    int retorno=0;
    int i;
    for(i=0; i<tam; i++)
    {
        if(list[i].isEmpty==OCUPADO)
        {
            retorno=1;
            break;
        }
    }

    return retorno;
}

void calculoPromedioPassenger(Passenger list[], int lenght, eTipoPasajero tipoPasajero[], int tamPasajeros)
{
	int i;
	float promedio;
	float total = 0;
	int contador1 = 0;
	int contador2 = 0;

	for(i = 0; i < lenght; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			total = total + list[i].price;
			contador1 = contador1 + 1;
		}
	}

	promedio = total / contador1;

	for(i = 0; i < lenght; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].price > promedio)
		{
			contador2 = contador2 + 1;
		}
	}

	printf("- El precio total de los pasajes es: %.2f \n", total);
	printf("- El precio promedio de los pasajes es: %.2f \n", promedio);
	printf("- La cantidad de pasajeros que superan el precio promedio es: %d \n", contador2);
}

void swapPassengers(Passenger* list, int len, int i, int j)
{
    Passenger auxPass;

    auxPass = list[i];
    list[i] = list[j];
    list[j] = auxPass;
}

int getNewPassengerId()
{
    static int id=1000;

    return id = id +1;
}

void pasajerosHardcode(Passenger list[], int length, int cantidad)
{
	Passenger pasajeros[7] = {

        {getNewPassengerId(), "Juan", "Lopez", 29993, "ADCA4", 1, ESTADO_VUELO_ACTIVO, OCUPADO},
        {getNewPassengerId(), "Pedro", "Garcia", 44532,"KXDA3", 2, ESTADO_VUELO_ACTIVO, OCUPADO},
        {getNewPassengerId(), "Luis", "Mendez", 47889, "AZCD3", 3,ESTADO_VUELO_CANCELADO, OCUPADO},
        {getNewPassengerId(), "Diego", "Fernandez", 98292, "MKJOL1", 4, ESTADO_VUELO_CANCELADO, OCUPADO},
        {getNewPassengerId(), "Joaquin", "Scaloni", 101928, "IKJM1", 1,ESTADO_VUELO_ACTIVO,  OCUPADO},
        {getNewPassengerId(), "Marcelo", "Lopez", 78654, "LOPO0", 2, ESTADO_VUELO_ACTIVO, OCUPADO},
        {getNewPassengerId(), "Fernando", "Garcia", 23456, "KILA1", 3, ESTADO_VUELO_ACTIVO, OCUPADO},
    };

	for (int i = 0; i < cantidad; i++)
	{
		list[i] = pasajeros[i];
	}
}
