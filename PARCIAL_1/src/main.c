/*
 ============================================================================
 Name        : Parcial 1
 Author      : Mateo Holik
 ============================================================================
*/
#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "censista.h"
#include "datosCenso.h"
#include "zona.h"
#include "reporte.h"
#include "input.h"

#define OCUPADO 1
#define VACIO 0

int main()
{
	setbuf(stdout, NULL);

    int opcionMenu;
    int idZona;
    int indiceZonaAux;
    int idCensista;
    int idCenso;
    int qCensadosInSitu;
    int qCensadosVirtual;
    int qCensadosAusentes;

    opcionMenu = 0;

    eCensista censista[TAM_CENSISTA];
    eZona zona[TAM_ZONA];
    eDomicilioCensita domicilioCensista[TAM_CENSISTA];
    eFechaNacimientoCensita fechaNacimientoCensista[TAM_CENSISTA];
    eDatosCenso datosCenso[TAM_ZONA];
    eLocalidades localidades[TAM_LOCALIDAD];

    initCensista(censista, TAM_CENSISTA);
    initZona(zona, TAM_ZONA);
    initCensistaDomicilio(domicilioCensista, TAM_CENSISTA);
    initCensistaFechaNacimiento(fechaNacimientoCensista, TAM_CENSISTA);
    initDatoCenso(datosCenso, TAM_ZONA);

    censistasHardcode(censista, TAM_CENSISTA, 7);
    censistasDomiciliosHardcode(domicilioCensista, TAM_CENSISTA, 7);
    censistasFechasNacimientoHardcode(fechaNacimientoCensista, TAM_CENSISTA, 7);
    zonasHardcode(zona, TAM_ZONA, 7);
    localidadesHardcodeZona(localidades, TAM_LOCALIDAD, 5);
    //datosCensoHardcode(datosCenso, TAM_ZONA, 2);

    do
    {
    	 opcionMenu = menuPrincipal();
    	 switch(opcionMenu)
        {
        case 1:
        	system("cls");

            menuCensista(censista , TAM_CENSISTA,  fechaNacimientoCensista, TAM_CENSISTA, domicilioCensista, TAM_CENSISTA);

        break;

        case 2:
            system("cls");
            menuZonas(zona, TAM_ZONA, localidades, TAM_LOCALIDAD, censista , TAM_CENSISTA);

            break;

        case 3:
        	system("cls");

            if(checkCensistaExists(censista, TAM_CENSISTA) == 0 && checkZonaExists(zona, TAM_ZONA) == 0)
               {
                   printf("Error! primero debe ingresar al menos un Censista y una Zona.\n");

                   system("pause");
                   break;
               }
               else
               {
               	if( mostrarCensosPendientes(zona, TAM_ZONA, censista, TAM_CENSISTA, EST_ZONA_PENDIENTE) == 0 )
               	{
                   	inputNumberInt(&idZona, "Ingrese el ID de la zona que desea cargar: ", "Error, Ingrese el ID de la zona que desea cargar: ", 1, 25);

                   	indiceZonaAux = buscarZonaId(zona, TAM_ZONA, idZona);
                   	idCensista = zona[indiceZonaAux].idCensista;

                   	inputNumberInt(&qCensadosInSitu, "Ingrese la cantidad de Censados In Situ: ", "Error, Ingrese la cantidad de Censados In Situ: ", 1, 100);
                   	inputNumberInt(&qCensadosVirtual, "Ingrese la cantidad de Censados Virtual: ", "Error, Ingrese la cantidad de Censados Virtual: ", 1, 100);
                   	inputNumberInt(&qCensadosAusentes, "Ingrese la cantidad de Censados Ausentes: ", "Error, Ingrese la cantidad de Censados Ausentes: ", 1, 100);

                   	idCenso = getNuevoDatoCensoId();

                       if(altaDatoCenso(datosCenso, TAM_ZONA, idCenso, idZona, idCensista, qCensadosInSitu, qCensadosVirtual, qCensadosAusentes)==0)
                        {
                       	cambiaEstadoCensista(censista, TAM_CENSISTA, idCensista, EST_CENSISTA_LIBERADO);
                       	cambiaEstadoZona(zona, TAM_ZONA, idZona, EST_ZONA_FINALIZADO);

           				printf("\n");
                       	printf("Datos del censo cargado con exito.\n\n");
           				printf("El ID del censo quedo registrado con el nro: %d \n\n", idCenso);
                        }

               	}
               	else
               	{
                   	printf("No se registran datos pendientes para cargar el Censo.\n\n");
               	}
               }

			system("pause");
			break;
        case 4:

            system("cls");
            if(checkDatoCensoExists(datosCenso, TAM_ZONA) == 0)
               {
                   printf("Error! primero debe procesar datos del censo.\n");

                   system("pause");
                   break;
               }
               else
               {
                   menuReportes(censista, TAM_CENSISTA, zona, TAM_ZONA, domicilioCensista, TAM_CENSISTA, fechaNacimientoCensista, TAM_CENSISTA,
                   				datosCenso, TAM_ZONA, localidades, TAM_LOCALIDAD);
               }


            system("pause");
        break;


        case 5:

			system("cls");
			printf("Gracias por utilizar Parcial \n\n");
			system("pause");
        break;
        }


    }
   while(opcionMenu!=5);

   return 0;
}
