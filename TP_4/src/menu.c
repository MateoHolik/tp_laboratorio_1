#include "menu.h"

int menuPrincipal(int* opcion)
{
    int retorno = -1;

    system("cls");

    printf("********************************************************************************\n");
    printf("*                                MENU PRINCIPAL                                *\n");
    printf("********************************************************************************\n");
    printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).    \n");
    printf("2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).  \n");
    printf("3. Alta de pasajero                                                             \n");
    printf("4. Modificar datos de pasajero                                                  \n");
    printf("5. Baja de pasajero                                                             \n");
    printf("6. Listar pasajeros                                                             \n");
    printf("7. Ordenar pasajeros                                                            \n");
    printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).      \n");
    printf("9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario).    \n");
    printf("10. Salir del programa                                                          \n\n");



    if(!inputNumberInt(opcion, "Elija una opcion del menu: ", "Error, Elija una opcion del menu: ", 1, MENU_PRINCIPAL_Q))
    {
    	retorno = 0;
    }

    return retorno;
}

int menuOrdenamiento(int* opcion)
{
    int retorno = -1;

    system("cls");

    printf("*********************************************\n");
    printf("*         MENU PARA ORDENAR LOS DATOS       *\n");
    printf("*********************************************\n");
    printf("1. Ordenar por ID                             \n");
    printf("2. Ordenar por Nombre                         \n");
    printf("3. Ordenar por Tipo De Pasajero               \n");
    printf("4. Volver al menu principal                   \n\n");

    if(!inputNumberInt(opcion, "Elija una opcion del menu: ", "Error, Elija una opcion del menu: ", 1, MENU_ORDENAMIENTO_Q))
    {
    	retorno = 0;
    }

    return retorno;
}

int menuTipoPasajero(int* opcionTipoPasajero)
{
	int retorno = -1;
	char auxTipoPasajeroChar[152];

    system("cls");

    printf("*********************************************\n");
    printf("*          OPCIONES TIPO PASAJERO           *\n");
    printf("*********************************************\n");
    printf("1. Business     \n");
    printf("2. Primer Clase \n");
    printf("3. VIP          \n");
    printf("4. Diplomatico\n\n");

    if(!inputNumberInt(opcionTipoPasajero, "Ingres Tipo De Pasajero: ", "Error reingrese Tipo De Pasajero.", 1, 4))
    {
    	convertirTipoPasajeroToChar(opcionTipoPasajero, auxTipoPasajeroChar);
    	retorno = 0;
    }
	return retorno;
}

int menuEdicion(int* opcion)
{
    int retorno = -1;
    printf("****************************************************\n");
    printf("*         MODIFICACION DE DATOS PASAJERO        *\n");
    printf("****************************************************\n");
    printf("1. Editar Nombre             \n");
    printf("2. Editar Apllido            \n");
    printf("3. Editar Precio             \n");
    printf("4. Editar Tipo de Pasajero   \n");
    printf("5. Volver al Menu Principal  \n");


    if(!inputNumberInt(opcion, "Elija una opcion del menu: ", "Error, Elija una opcion del menu: ", 1, MENU_EDICION_Q))
    {
    	retorno = 0;
    }

    return retorno;
}
