#include "menu.h"
#include "ArrayPassenger.h"

int menuPrincipal()
{
    int opcion;

    opcion = 0;
    system("cls");
    printf("***********************************************************************************************************  \n");
    printf("                                    Menu Principal                                                           \n");
    printf("***********************************************************************************************************\n\n");
    printf("1) Alta Pasajero \n");
    printf("2) Modificar Pasajero\n");
    printf("3) Baja Pasajero\n");
    printf("4) Informar\n");
    printf("5) Cargado datos hardcode de pasajeros\n");
    printf("6) Salir \n\n");

    inputNumberInt(&opcion, "Ingrese una opcion: ", "Error, ingrese una opcion: ", 1, 6);

    return opcion;
}


int menuModificacion()
{
    int opcion;
    printf("***********************************************************************************************************  \n");
    printf("                            Opciones disponibles para modificar del pasajero                                  \n");
    printf("***********************************************************************************************************\n\n");
    printf("1) Modificar Nombre\n");
    printf("2) Modificer apellido\n");
    printf("3) Modificar precio de vuelo\n");
    printf("4) Modificer codigo de vuelo\n\n");

    inputNumberInt(&opcion, "Ingrese opcion que desea modificar: ", "Error, ingrese una opcion valida: ", 1, 5);

    return opcion;
}



int menuPrincipalReportes(Passenger* listPassenger, int lenPassenger, eTipoPasajero* listTipoPasajero, int lenTipoPasajero, eEstadoVuelo* listaEstadoVuelo, int lenEstadoVuelo )
{

    int validation = 0;
    int opcionMenu = 0;

    printf("***********************************************************************************************************\n");
    printf("                                    Menu de Reportes \n");
    printf("***********************************************************************************************************\n");
    printf("1. Listado de los pasajeros ordenados numericamente por Tipo de pasajero.\n");
    printf("2. Listado de los pasajeros ordenados alfabéticamente por Apellido\n");
    printf("3. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio. \n");
    printf("4. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’ \n");

    inputNumberInt(&opcionMenu, "Ingrese una opcion: ", "Error, ingrese una opcion: ", 1, 4);

    switch(opcionMenu)
    {
        case 1:

        	sortPassengersByTipoPasajero(listPassenger, lenPassenger);

        	printf("*******************************************************************************************************************************\n");
            printf("                            Pasajeros ordenados numericamente por tipo de pasajero                         \n");

            printPassengers(listPassenger, TAM_PASAJEROS, listTipoPasajero, TAM_TIPO_PASAJERO);
        break;

        case 2:

        	sortPassengersByLastName(listPassenger, lenPassenger);

        	printf("*******************************************************************************************************************************\n");
            printf("                                  Pasajeros por orden alfabetico  \n");

            printPassengers(listPassenger, TAM_PASAJEROS, listTipoPasajero, TAM_TIPO_PASAJERO);
        break;

        case 3:


        	printf("*******************************************************************************************************************************\n");
            printf("                                           Calculo de pasajes                                              \n");

            calculoPromedioPassenger( listPassenger, TAM_PASAJEROS, listTipoPasajero, TAM_TIPO_PASAJERO);
        break;

        case 4:
        	printf("*******************************************************************************************************************************\n");
            printf("                              Listado de pasajeros por codigo y estado de vuelo                             \n");

            printPassengersEstadoVuelo( listPassenger,  TAM_PASAJEROS, listaEstadoVuelo, TAM_ESTADO_VUELO);

            break;

        default:

            printf("Opcion invalida..!");

            system("pause");

            validation = -1;

         break;
    }
    return validation;
}
