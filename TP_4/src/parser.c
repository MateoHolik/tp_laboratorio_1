#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "Passenger.h"
#include "input.h"

int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[5];

	int contador = 0;
	char buffer[6][50];

	    Passenger* auxPassenger;

	    if(pFile != NULL && pArrayListPassenger != NULL)
	    {
	        while(!feof(pFile))
	        {
	            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]) == 6
	               && inputStringToInt(buffer[0], &id)
	               && buffer[1] != NULL
				   && strcpy(nombre,buffer[1])
	               && strcpy(apellido,buffer[2])
				   && inputStringToFloat(buffer[3], &precio)

				   && strcpy(codigoVuelo,buffer[5]))
	            {

	            	inputStringToInt(buffer[4], &tipoPasajero);

	            	auxPassenger = Passenger_newParametrosDatos(&id, buffer[1], buffer[2], &precio, &tipoPasajero, codigoVuelo);

	                if(auxPassenger != NULL && ll_len(pArrayListPassenger) < PASAJEROS_MAX_Q
	                   && ll_add(pArrayListPassenger, (Passenger*)auxPassenger) == 0)
	                {
	                	contador++;
	                }
	            }
	        }
	    }
	    return contador;
}


int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

    int contador = 0;
    Passenger auxPassenger1;
    Passenger* auxPassenger2 = NULL;

    if(pFile != NULL && pArrayListPassenger != NULL)
    {
        while(!feof(pFile))
        {
            if(fread((Passenger*)&auxPassenger1, sizeof(Passenger), 1, pFile) == 1)
            {
            	auxPassenger2 = Passenger_newParametrosDatos(&(auxPassenger1.id),
            			auxPassenger1.nombre, auxPassenger1.apellido, &(auxPassenger1.precio),
						&(auxPassenger1.tipoPasajero), auxPassenger1.codigoVuelo );


                if(auxPassenger2 != NULL
                   && ll_len(pArrayListPassenger) < PASAJEROS_MAX_Q
                   && ll_add(pArrayListPassenger, (Passenger*)auxPassenger2) == 0)
                {
                	contador++;
                }
            }
        }
    }

    return contador;
}
