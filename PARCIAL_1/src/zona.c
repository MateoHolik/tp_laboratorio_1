#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "zona.h"


int altaZona(eZona listZona[], int lenZona, int idZona, char nombre[], char calle1[], char calle2[], char calle3[], char calle4[], int idLocalidad)
{
	int returnValue = -1;
	int emptyIndex;
	int idCensista = 0;

	if(listZona != NULL && lenZona > 0 && lenZona <= 1000
		&& nombre != NULL && nombre != NULL )
	{

		if(buscarZonaId(listZona, lenZona, idZona) != -1)
		{
			printf("El ID ingresado ya esta en uso.\n");
		}
		else
		{
			 emptyIndex = obtenerZonaIndex(listZona, lenZona);

			if(emptyIndex != -1)
			{

				listZona[emptyIndex].idZona = idZona ;
				listZona[emptyIndex].idCensista = idCensista ;
				strcpy(listZona[emptyIndex].nombre, nombre);
				strcpy(listZona[emptyIndex].calle1, calle1);
				strcpy(listZona[emptyIndex].calle2, calle2);
				strcpy(listZona[emptyIndex].calle3, calle3);
				strcpy(listZona[emptyIndex].calle4, calle4);
				listZona[emptyIndex].idLocalidad = idLocalidad;
				listZona[emptyIndex].isEmpty = OCUPADO;

				returnValue = 0;
			}
		}
	}

	return returnValue;
}


int initZona(eZona listZona[], int lenZona)
{

	int retorno = -1;
	int i = 0;
	if(listZona != NULL && lenZona > 0 && lenZona <= TAM_ZONA)
	{
		for(int i = 0; i < lenZona; i++)
		{
			listZona[i].isEmpty = VACIO;
		}

        if(i == lenZona)
        {
        	retorno = 0;
        }
	}

return retorno;
}


int mostrarLocalidadesZona(eLocalidades listLocalidad[], int lenLocalidad)
{
    int retorno=-1;

    printf("*************************************************\n");
    printf("* ID Localidad                           Nombre * \n");
    printf("*************************************************\n");

    for(int i=0; i < lenLocalidad; i++)
    {
    	if(listLocalidad[i].isEmpty == OCUPADO)
        {
        	printf("%8d           %28s \n", listLocalidad[i].id, listLocalidad[i].nombre);
            retorno=0;
        }
    }
    return retorno;

}

int mostrarZonas(eZona listZona[], int lenZona, eLocalidades listLocalidades[], int lenLocalidades)
{
    int i;
    int retorno = -1;

    printf("****************************************************************************************************************\n");
    printf("*Id Zona   Nombre           calle 1        calle 2        calle 3         calle 4          Localidad           * \n");
    printf("****************************************************************************************************************\n");

    for(i=0; i < lenZona; i++)
    {
    	if(listZona[i].isEmpty == OCUPADO)
        {
    		mostrarZona(listZona[i], listLocalidades, lenLocalidades, listZona[i].idLocalidad);
            retorno=0;
        }
    }

    return retorno;

}


void mostrarZona(eZona listZona, eLocalidades listLocalidades[], int lenLocalidades, int idLocalidad)
{
	int indiceLocalidades = 0;
	indiceLocalidades = buscarLocalidadId(listLocalidades, lenLocalidades, idLocalidad);

		printf("%0d          %-15s  %-10s     %-10s     %-10s      %-9s    %5d - %-10s     \n",
				listZona.idZona, listZona.nombre, listZona.calle1,  listZona.calle2,  listZona.calle3, listZona.calle4,
				listZona.idLocalidad, listLocalidades[indiceLocalidades].nombre);
}


int mostrarZonasSinCensista(eZona listZona[], int lenZona, eLocalidades listLocalidades[], int lenLocalidades)
{
    int i;
    int retorno=-1;

    printf("****************************************************************************************************************\n");
    printf("*Id Zona      Nombre      calle 1        calle 2        calle 3         calle 4          Localidad            * \n");
    printf("****************************************************************************************************************\n");

    for(i=0; i < lenZona; i++)
    {
    	if(listZona[i].isEmpty == OCUPADO && listZona[i].idCensista == 0)
        {
    		mostrarZona(listZona[i], listLocalidades, lenLocalidades, listZona[i].idLocalidad);
            retorno=0;
        }
    }

    return retorno;
}

int mostrarLocalidades(eLocalidades listLocalidad[], int lenLocalidad)
{
   // int i;
    int retorno=-1;

    printf("*****************\n");
    printf("* IDLocalidad                            Nombre * \n");
    printf("*****************\n");

    for(int i=0; i < lenLocalidad; i++)
    {
    	if(listLocalidad[i].isEmpty == OCUPADO)
        {
        	//mostrarCliente(listLocalidad[i]);
        	printf("%8d           %28s \n", listLocalidad[i].id, listLocalidad[i].nombre);
            retorno=0;
        }
    }

    return retorno;

}

int buscarZonaId(eZona listZona[], int lenZona, int idZona)
{
    int returnValue = -1;

    if(listZona != NULL && lenZona > 0 && lenZona <= 1000)
    {
        for (int i = 0; i < lenZona; i++)
        {
            if(listZona[i].idZona == idZona)
            {
                returnValue = i;
                break;
            }
        }
    }

    return returnValue;
}

int buscarLocalidadId(eLocalidades listLocalidades[], int lenLocalidades, int idLocalidad)
{
    int returnValue = -1;

    if(listLocalidades != NULL && lenLocalidades > 0 && lenLocalidades <= 5)
    {
        for (int i = 0; i < lenLocalidades; i++)
        {
            if(listLocalidades[i].id == idLocalidad)
            {
                returnValue = i;
                break;
            }
        }
    }

    return returnValue;
}


int getNuevaZonaId()
{
	  static int id=1;
	  return id++;
}


int checkZonaExists(eZona listZona[], int lenZona)
{
    int retorno=0;
    int i;

    for(i=0; i<lenZona; i++)
    {
        if(listZona[i].isEmpty==OCUPADO)
        {
            retorno=1;
            break;
        }
    }

    return retorno;
}


int obtenerZonaIndex(eZona listZona[], int lenZona)
{
    int retorno = -1;

    if(listZona != NULL && listZona > 0 && lenZona <= TAM_ZONA)
    {
        for (int i = 0; i < lenZona; i++)
        {
            if(listZona[i].isEmpty == VACIO)
            {
            	retorno = i;
                break;
            }
        }
    }

    return retorno;
}


int bajaZona(eZona listZona[], int lenZona, int idZonaBaja)
{
    int retorno = -1;
    int i;

    for(i = 0; i < lenZona; i++)
    {
        if(listZona[i].idZona == idZonaBaja)
        {
        	listZona[i].isEmpty = VACIO;
            retorno = 0;
        }
    }
    return retorno;

}


int asignarZonaCensista(eZona listZona[], int lenZona, int idZona, int idCensista)
{
    int retorno = -1;
    int i;

    for(i = 0; i < lenZona; i++)
    {
        if(listZona[i].idZona == idZona)
        {
        	listZona[i].idCensista = idCensista;
            retorno = 0;
        }
    }
    return retorno;

}

int cambiaEstadoZona(eZona listZona[], int lenZona, int idZona, char estado[])
{
    int retorno = -1;
    int i;

    for(i = 0; i < lenZona; i++)
    {
        if(listZona[i].idZona== idZona)
        {
        	strcpy(listZona[i].estado, estado);
            retorno = 0;
        }
    }
    return retorno;
}

void zonasHardcode(eZona list[], int length, int cantidad)
{
	eZona zonas[7] = {

        {getNuevaZonaId(), 1000, "ZONA A1", "CALLE A", "CALLE B", "CALLE C", "CALLE D", 1, EST_ZONA_PENDIENTE, OCUPADO},
		{getNuevaZonaId(), 1001, "ZONA A2", "CALLE 1", "CALLE 2", "CALLE 3", "CALLE 4", 2, EST_ZONA_PENDIENTE, OCUPADO},
		{getNuevaZonaId(), 1002, "ZONA B1", "CALLE 45", "CALLE 50", "CALLE 35", "CALLE 20", 3, EST_ZONA_PENDIENTE, OCUPADO},
		{getNuevaZonaId(), 1003, "ZONA B2", "CALLE 65", "CALLE 54", "CALLE 78", "CALLE 89", 4, EST_ZONA_PENDIENTE, OCUPADO},
		{getNuevaZonaId(), 1004, "ZONA C1", "CALLE 45", "CALLE 67", "CALLE 64", "CALLE 23", 5, EST_ZONA_PENDIENTE, OCUPADO},
		{getNuevaZonaId(), 0, "ZONA C2", "CALLE 156", "CALLE AH", "CALLE AB", "CALLE AC", 4, EST_ZONA_PENDIENTE, OCUPADO},
		{getNuevaZonaId(), 0, "ZONA C3", "CALLE AX", "CALLE AZ", "CALLE AF", "CALLE AG", 2, EST_ZONA_PENDIENTE, OCUPADO},
			};

	for (int i = 0; i < cantidad; i++)
	{
		list[i] = zonas[i];
	}
}

void localidadesHardcodeZona(eLocalidades listLocalidad[], int length, int cantidad)
{
	eLocalidades localidad[5] = {
        {1,"Adrogue", OCUPADO},
        {2,"Avellaneda", OCUPADO},
        {3,"Banfield", OCUPADO},
        {4,"Lanus", OCUPADO},
        {5,"San Vicente", OCUPADO}
    };

	for (int i = 0; i < cantidad; i++)
	{
		listLocalidad[i] = localidad[i];
	}

}
