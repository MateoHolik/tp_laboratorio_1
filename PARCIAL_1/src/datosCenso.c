#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "datosCenso.h"

int initDatoCenso(eDatosCenso listCenso[], int lenCenso)
{

	int retorno = -1;
	int i = 0;
	if(listCenso != NULL && lenCenso > 0 && lenCenso <= TAM_CENSO)
	{
		for(int i = 0; i < lenCenso; i++)
		{
			listCenso[i].isEmpty = VACIO;
		}

        if(i == lenCenso)
        {
        	retorno = 0;
        }
	}

return retorno;
}


int altaDatoCenso(eDatosCenso listCenso[], int lenCenso, int idCenso, int idZona, int idCensista, int qCensadosInSitu, int qCensadosVirtual, int qCensadosAusentes)
{
		    int returnValue = -1;
		    int emptyIndex;

		    if(listCenso != NULL && lenCenso > 0 && lenCenso <= 1000)
		    {

		        if(buscarDatoCensoId(listCenso, lenCenso, idCenso) != -1)
		        {
		            printf("El ID ingresado ya esta en uso.\n");
		        }
		        else
		        {

		        	 emptyIndex = obtenerDatoCensoIndex(listCenso, lenCenso);

		            if(emptyIndex != -1)
		            {

		            	listCenso[emptyIndex].idCenso = idCenso ;
		            	listCenso[emptyIndex].idZona = idZona ;
		            	listCenso[emptyIndex].idCensista = idCensista ;
		            	listCenso[emptyIndex].qCensadosInSitu = qCensadosInSitu ;
						listCenso[emptyIndex].qCensadosVirtual = qCensadosVirtual ;
						listCenso[emptyIndex].qCensadosAusentes = qCensadosAusentes ;
		                listCenso[emptyIndex].isEmpty = OCUPADO;

		                returnValue = 0;
		            }
		        }
		    }

		    return returnValue;
		}


int buscarDatoCensoId(eDatosCenso listCenso[], int lenCenso, int idCenso)
{
    int returnValue = -1;

    if(listCenso != NULL && lenCenso > 0 && lenCenso <= 1000)
    {
        for (int i = 0; i < lenCenso; i++)
        {
            if(listCenso[i].idCenso == idCenso)
            {
                returnValue = i;
                break;
            }
        }
    }

    return returnValue;
}


int getNuevoDatoCensoId()
{
	  static int id=1;

	  return id++;
}

int checkDatoCensoExists(eDatosCenso listCenso[], int lenCenso)
{
    int retorno=0;
    int i;

    for(i=0; i<lenCenso; i++)
    {
        if(listCenso[i].isEmpty==OCUPADO)
        {
            retorno=1;
            break;
        }
    }

    return retorno;
}


int obtenerDatoCensoIndex(eDatosCenso listCenso[], int lenCenso)
{
    int retorno = -1;

    if(listCenso != NULL && listCenso > 0 && lenCenso <= TAM_CENSO)
    {
        for (int i = 0; i < lenCenso; i++)
        {
            if(listCenso[i].isEmpty == VACIO)
            {
            	retorno = i;
                break;
            }
        }
    }

    return retorno;
}


int mostrarCensosPendientes(eZona listZona[], int lenZona, eCensista listCensista[], int lenCensista, char estado[])
{
    int i;
    int retorno = -1;

    printf("***********************************\n");
    printf("*Id Zona                Nombre    *\n");
    printf("***********************************\n");

    for(i=0; i < lenZona; i++)
    {
    	if(listZona[i].isEmpty == OCUPADO && listZona[i].idCensista > 0 && strcmp(listZona[i].estado, estado) == 0)
        {
    		mostraCensoPendiente(listZona[i]);
            retorno = 0;
        }
    }

    return retorno;
}

void mostraCensoPendiente(eZona listZona)
{
		printf("%0d     %25s \n", listZona.idZona, listZona.nombre);
}


int altaDatoZona(eDatosCenso listCenso[], int lenCenso, int idCenso, int idZona, int idCensista, int qCensadosInSitu, int qCensadosVirtual, int qCensadosAusentes)
{
	int returnValue = -1;
	int emptyIndex;

	if(listCenso != NULL && lenCenso > 0 && lenCenso <= 1000)
	{

		if(buscarDatoCensoId(listCenso, lenCenso, idCenso) != -1)
		{
			printf("El ID ingresado ya esta en uso.\n");
		}
		else
		{

			 emptyIndex = obtenerDatoCensoIndex(listCenso, lenCenso);

			if(emptyIndex != -1)
			{

				listCenso[emptyIndex].idCenso = idCenso ;
				listCenso[emptyIndex].idZona = idZona ;
				listCenso[emptyIndex].idCensista = idCensista ;
				listCenso[emptyIndex].qCensadosInSitu = qCensadosInSitu ;
				listCenso[emptyIndex].qCensadosVirtual = qCensadosVirtual ;
				listCenso[emptyIndex].qCensadosAusentes = qCensadosAusentes ;
				listCenso[emptyIndex].isEmpty = OCUPADO;

				returnValue = 0;
			}
		}
	}

	return returnValue;
}

void datosCensoHardcode(eDatosCenso list[], int length, int cantidad)
{
	eDatosCenso datos[3] = {

        {getNuevoDatoCensoId(), 1, 1000, 10, 20, 30, OCUPADO},
		{getNuevoDatoCensoId(), 2, 1001, 40, 50, 60, OCUPADO},
    };

	for (int i = 0; i < cantidad; i++)
	{
		list[i] = datos[i];
	}

}

/*
void zonasHardcode(eZona list[], int length, int cantidad)
{
	eZona zonas[7] = {

        {getNuevaZonaId(), "ZONA A1", "CALLE A", "CALLE B", "CALLE C", "CALLE D", 1, EST_ZONA_PENDIENTE, OCUPADO},
		{getNuevaZonaId(), "ZONA A2", "CALLE 1", "CALLE 2", "CALLE 3", "CALLE 4", 2, EST_ZONA_PENDIENTE, OCUPADO},
		{getNuevaZonaId(), "ZONA B1", "CALLE 45", "CALLE 50", "CALLE 35", "CALLE 20", 3, EST_ZONA_PENDIENTE, OCUPADO},
		{getNuevaZonaId(), "ZONA B2", "CALLE 65", "CALLE 54", "CALLE 78", "CALLE 89", 4, EST_ZONA_PENDIENTE, OCUPADO},
		{getNuevaZonaId(), "ZONA C1", "CALLE 45", "CALLE 67", "CALLE 64", "CALLE 23", 5, EST_ZONA_PENDIENTE, OCUPADO},
		{getNuevaZonaId(), "ZONA C2", "CALLE 156", "CALLE AH", "CALLE AB", "CALLE AC", 4, EST_ZONA_PENDIENTE, OCUPADO},
		{getNuevaZonaId(), "ZONA C3", "CALLE AX", "CALLE AZ", "CALLE AF", "CALLE AG", 2, EST_ZONA_PENDIENTE, OCUPADO},
			};

	for (int i = 0; i < cantidad; i++)
	{
		list[i] = zonas[i];
	}
}*/
