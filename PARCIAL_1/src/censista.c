#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "censista.h"

int initCensista(eCensista listCensista[], int lenCensista)
{
	int retorno = -1;
	int i = 0;
	if(listCensista != NULL && lenCensista > 0 && lenCensista <= TAM_CENSISTA)
	{
		for(int i = 0; i < lenCensista; i++)
		{
			listCensista[i].isEmpty = VACIO;
		}

        if(i == lenCensista)
        {
        	retorno = 0;
        }
	}

return retorno;
}

int initCensistaDomicilio(eDomicilioCensita listDomicilio[], int lenDomicilio)
{
	int retorno = -1;
	int i = 0;
	if(listDomicilio != NULL && lenDomicilio > 0 && lenDomicilio <= TAM_CENSISTA)
	{
		for(int i = 0; i < lenDomicilio; i++)
		{
			listDomicilio[i].isEmpty = VACIO;
		}

        if(i == lenDomicilio)
        {
        	retorno = 0;
        }
	}

return retorno;
}

int initCensistaFechaNacimiento(eFechaNacimientoCensita listFecha[], int lenFecha)
{
	int retorno = -1;
	int i = 0;
	if(listFecha != NULL && lenFecha > 0 && lenFecha <= TAM_CENSISTA)
	{
		for(int i = 0; i < lenFecha; i++)
		{
			listFecha[i].isEmpty = VACIO;
		}

        if(i == lenFecha)
        {
        	retorno = 0;
        }
	}

return retorno;
}


int altaCensista(eCensista listCensista[], int lenCensita, int id, char nombre[],  char apellido[], int edad, char estado[])
{
    int returnValue = -1;
    int emptyIndex;

    if(listCensista != NULL && lenCensita > 0 && lenCensita <= 1000
        && nombre != NULL && nombre != NULL )
    {

        if(buscarCensistaId(listCensista, lenCensita, id) != -1)
        {
            printf("El ID ingresado ya esta en uso.\n");
        }
        else
        {
        	 emptyIndex = obtenerCensistaIndex(listCensista, lenCensita);

            if(emptyIndex != -1)
            {
            	listCensista[emptyIndex].id = id;
                strcpy(listCensista[emptyIndex].nombre, nombre);
                strcpy(listCensista[emptyIndex].apellido, apellido);
                listCensista[emptyIndex].edad = edad;
                strcpy(listCensista[emptyIndex].estado, estado);
                listCensista[emptyIndex].isEmpty = OCUPADO;

                returnValue = 0;
            }
        }
    }

    return returnValue;
}

int altaDomicilioCensita(eDomicilioCensita listDomicilio[], int lenDomicilio, int idDomicilio, int idCensista, char direccion[])
{
    int returnValue = -1;
    int emptyIndex;

    if(listDomicilio != NULL && lenDomicilio > 0 && lenDomicilio <= 1000
        && direccion != NULL && direccion != NULL )
    {

        if(buscarDomicilioCensistaId(listDomicilio, lenDomicilio, idDomicilio) != -1)
        {
            printf("El ID ingresado ya esta en uso.\n");
        }
        else
        {

        	emptyIndex = obtenerCensistaDomicilioIndex(listDomicilio, lenDomicilio);

            if(emptyIndex != -1)
            {

            	listDomicilio[emptyIndex].idDomicilio = idDomicilio;
            	listDomicilio[emptyIndex].idCensista = idCensista;
                strcpy(listDomicilio[emptyIndex].direccion,direccion);
                listDomicilio[emptyIndex].isEmpty = OCUPADO;
                returnValue = 0;
            }
        }
    }

    return returnValue;
}

int altaCensistaFechaNacimiento(eFechaNacimientoCensita listFecha[], int lenFecha, int idFechaNacimiento, int idCensista, char fechaNacimiento[])
{
    int returnValue = -1;
    int emptyIndex;

    if(listFecha != NULL && lenFecha > 0 && lenFecha <= 1000
        && fechaNacimiento != NULL && fechaNacimiento != NULL )
    {

        if(buscarFechaNacimientoCensistaId(listFecha, lenFecha, idFechaNacimiento) != -1)
        {
            printf("El ID ingresado ya esta en uso.\n");
        }
        else
        {
        	emptyIndex = obtenerCensistaFechaNacimiento(listFecha, lenFecha);

            if(emptyIndex != -1)
            {
            	listFecha[emptyIndex].idFechaNacimiento = idFechaNacimiento;
            	listFecha[emptyIndex].idCensista = idCensista;
                strcpy(listFecha[emptyIndex].fechaNacimiento,fechaNacimiento);
                listFecha[emptyIndex].isEmpty = OCUPADO;
                returnValue = 0;
            }
        }
    }

    return returnValue;
}


int obtenerCensistaIndex(eCensista listCensista[], int lenCensista)
{
    int retorno = -1;

    if(listCensista != NULL && lenCensista > 0 && lenCensista <= TAM_CENSISTA)
    {
        for (int i = 0; i < lenCensista; i++)
        {
            if(listCensista[i].isEmpty == VACIO)
            {
            	retorno = i;
                break;
            }
        }
    }

    return retorno;
}

int obtenerCensistaDomicilioIndex(eDomicilioCensita listDomicilio[], int lenDomicilio)
{
    int retorno = -1;

    if(listDomicilio != NULL && lenDomicilio > 0 && lenDomicilio <= TAM_CENSISTA)
    {
        for (int i = 0; i < lenDomicilio; i++)
        {
            if(listDomicilio[i].isEmpty == VACIO)
            {
            	retorno = i;
                break;
            }
        }
    }

    return retorno;
}

int obtenerCensistaFechaNacimiento(eFechaNacimientoCensita listFecha[], int lenFecha)
{
    int retorno = -1;

    if(listFecha != NULL && lenFecha > 0 && lenFecha <= TAM_CENSISTA)
    {
        for (int i = 0; i < lenFecha; i++)
        {
            if(listFecha[i].isEmpty == VACIO)
            {
            	retorno = i;
                break;
            }
        }
    }

    return retorno;
}


int getNuevoCensistaId()
{
    static int id=1000;

    return id++;
}

int getNuevoDomicilioCensistaId()
{
    static int id=1;

    return id++;
}

int getNuevoFechaNacimientoCensistaId()
{
    static int id=1;

    return id++;
}


int buscarCensistaId(eCensista listCensista[], int lenCensista, int id)
{
    int returnValue = -1;

    if(listCensista != NULL && lenCensista > 0 && lenCensista <= 2000)
    {
        for (int i = 0; i < lenCensista; i++)
        {
            if(listCensista[i].id == id)
            {
                returnValue = i;
                break;
            }
        }
    }
    return returnValue;
}

int buscarDomicilioCensistaId(eDomicilioCensita listDomicilio[], int lenDomicilio, int idCensista)
{
    int returnValue = -1;

    if(listDomicilio != NULL && lenDomicilio > 0 && lenDomicilio <= 1000)
    {
        for (int i = 0; i < lenDomicilio; i++)
        {
            if(listDomicilio[i].idCensista == idCensista)
            {
                returnValue = i;
                break;
            }
        }
    }
    return returnValue;
}

int buscarFechaNacimientoCensistaId(eFechaNacimientoCensita listFecha[], int lenFecha, int idCensista)
{
    int returnValue = -1;

    if(listFecha != NULL && lenFecha > 0 && lenFecha <= 1000)
    {
        for (int i = 0; i < lenFecha; i++)
        {
            if(listFecha[i].idCensista == idCensista)
            {
                returnValue = i;
                break;
            }
        }
    }
    return returnValue;
}


int mostrarCensistas(eCensista listCensista[], int lenCensista, eFechaNacimientoCensita listFecha[], int lenFecha, eDomicilioCensita listDomicilio[], int tamDireccion)
{
    int i;
    int retorno=-1;

    printf("***********************************************************************************************************************\n");
    printf("* ID         Nombre              Apellido              Edad            Fecha De Nacimiento            Direccion       *\n");
    printf("***********************************************************************************************************************\n");

    for(i=0; i < lenCensista; i++)
    {
    	if(listCensista[i].isEmpty == OCUPADO && (strcmp(listCensista[i].estado, EST_CENSISTA_ACTIVO) == 0 || strcmp(listCensista[i].estado, EST_CENSISTA_LIBERADO) == 0))
        {
    		mostrarCensista(listCensista[i], lenCensista, listFecha, lenFecha, listDomicilio, tamDireccion, listCensista[i].id);
            retorno=0;
        }
    }
    return retorno;
}


void mostrarCensista(eCensista listCensista, int lenCensista, eFechaNacimientoCensita listFecha[], int lenFecha, eDomicilioCensita listDomicilio[], int lenDomicilio, int idCensista)
{

	int indiceFechaDeNacimiento = 0;
	indiceFechaDeNacimiento = buscarFechaNacimientoCensistaId(listFecha, lenFecha, idCensista);

	int indiceDomicilio = buscarDomicilioCensistaId(listDomicilio, lenDomicilio, idCensista);


		printf("%d         %-10s          %-20s   %-13d  %-30s %-20s \n", listCensista.id, listCensista.nombre, listCensista.apellido,
					listCensista.edad, listFecha[indiceFechaDeNacimiento].fechaNacimiento, listDomicilio[indiceDomicilio].direccion);

}

int mostrarCensistasPorEstado(eCensista listCensista[], int lenCensista, char estado[])
{
    int i;
    int retorno=-1;

    printf("***************************************************\n");
    printf("* ID           Nombre              Apellido       *\n");
    printf("***************************************************\n");

    for(i=0; i < lenCensista; i++)
    {
    	if(listCensista[i].isEmpty == OCUPADO && strcmp(listCensista[i].estado, estado) == 0)
        {
    		mostrarCensistaPorEstado(listCensista[i], lenCensista, listCensista[i].id);
            retorno=0;
        }
    }
    return retorno;
}

void mostrarCensistaPorEstado(eCensista listCensista, int lenCensista, int idCensista)
{
		printf("%d           %-15s     %-13s \n", listCensista.id, listCensista.nombre, listCensista.apellido);
}


int checkCensistaExists(eCensista listCensista[], int lenCensista)
{
    int retorno=0;
    int i;

    for(i=0; i<lenCensista; i++)
    {
        if(listCensista[i].isEmpty==OCUPADO)
        {
            retorno=1;
            break;
        }
    }
    return retorno;
}


int bajaCensista(eCensista listCensista[], int lenCensista, int idCensistaBaja)
{
    int retorno = -1;
    int i;

    for(i = 0; i < lenCensista; i++)
    {
        if(listCensista[i].id == idCensistaBaja)
        {
        	listCensista[i].isEmpty = VACIO;
            retorno = 0;
        }
    }
    return retorno;
}


int cambiaEstadoCensista(eCensista listCensista[], int lenCensista, int idCensista, char estado[])
{
    int retorno = -1;
    int i;

    for(i = 0; i < lenCensista; i++)
    {
        if(listCensista[i].id == idCensista)
        {
        	strcpy(listCensista[i].estado, estado);
            retorno = 0;
        }
    }
    return retorno;
}


void censistasHardcode(eCensista list[], int length, int cantidad)
{
	eCensista censistas[8] = {

        {getNuevoCensistaId(), "Juan", "Lopez", 20, EST_CENSISTA_ACTIVO, OCUPADO},
        {getNuevoCensistaId(), "Pedro", "Garcia", 35, EST_CENSISTA_ACTIVO, OCUPADO},
        {getNuevoCensistaId(), "Luis", "Mendez", 45, EST_CENSISTA_ACTIVO, OCUPADO},
        {getNuevoCensistaId(), "Diego", "Fernandez", 29, EST_CENSISTA_LIBERADO, OCUPADO},
        {getNuevoCensistaId(), "Joaquin", "Scaloni", 30, EST_CENSISTA_LIBERADO, OCUPADO},
        {getNuevoCensistaId(), "Marcelo", "Lopez", 56, EST_CENSISTA_LIBERADO, OCUPADO},
        {getNuevoCensistaId(), "Fernando", "Garcia", 45, EST_CENSISTA_ACTIVO, OCUPADO},
    };

	for (int i = 0; i < cantidad; i++)
	{
		list[i] = censistas[i];
	}
}

void censistasDomiciliosHardcode(eDomicilioCensita list[], int length, int cantidad)
{
	eDomicilioCensita domicilios[8] = {

        {getNuevoDomicilioCensistaId(), 1000, "calle 6", OCUPADO},
		{getNuevoDomicilioCensistaId(), 1001, "calle 8", OCUPADO},
		{getNuevoDomicilioCensistaId(), 1002, "calle 1", OCUPADO},
		{getNuevoDomicilioCensistaId(), 1003, "calle 5", OCUPADO},
		{getNuevoDomicilioCensistaId(), 1004, "calle 15", OCUPADO},
		{getNuevoDomicilioCensistaId(), 1005, "calle 19", OCUPADO},
		{getNuevoDomicilioCensistaId(), 1006, "calle 25", OCUPADO},
    };

	for (int i = 0; i < cantidad; i++)
	{
		list[i] = domicilios[i];
	}
}

void censistasFechasNacimientoHardcode(eFechaNacimientoCensita list[], int length, int cantidad)
{
	eFechaNacimientoCensita fechas[8] = {

        {getNuevoFechaNacimientoCensistaId(), 1000, "10/11/1970", OCUPADO},
		{getNuevoFechaNacimientoCensistaId(), 1001, "15/12/1980", OCUPADO},
		{getNuevoFechaNacimientoCensistaId(), 1002, "18/01/1990", OCUPADO},
		{getNuevoFechaNacimientoCensistaId(), 1003, "16/04/2000", OCUPADO},
		{getNuevoFechaNacimientoCensistaId(), 1004, "05/10/1960", OCUPADO},
		{getNuevoFechaNacimientoCensistaId(), 1005, "09/08/1967", OCUPADO},
		{getNuevoFechaNacimientoCensistaId(), 1006, "10/08/1977", OCUPADO},
    };

	for (int i = 0; i < cantidad; i++)
	{
		list[i] = fechas[i];
	}
}
