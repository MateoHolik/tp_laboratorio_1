/*
 ============================================================================
 Name        : Trabajo practico 3
 Author      : Mateo Holik
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "TipoPassenger.h"
#include "menu.h"

#define ARCHIVO_CSV "data.csv"
#define ARCHIVO_BIN "data.bin"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout, NULL);

	int opcionMenu = 0;
	int controlMenu;
	int cantidadPasajeros = 0;

    LinkedList* listaPasajeros;
    listaPasajeros = ll_newLinkedList(); //llamo el constructor

    do
      {
    	controlMenu = menuPrincipal(&opcionMenu);

        if(opcionMenu == MENU_PRINCIPAL_Q || opcionMenu == -1)
        {
        	printf("Gracias por utilizar el TP3 \n");
			pausa(MENSAJE_PAUSA);
			exit(EXIT_SUCCESS);
        }

        cantidadPasajeros = ll_len(listaPasajeros);

    	switch(opcionMenu)
    	{
			case 1: //CARGA CSV TXT

				system("cls");

				cantidadPasajeros = controller_loadFromText(ARCHIVO_CSV, listaPasajeros);

				if(cantidadPasajeros > 0)
				{
					printf("Se cargaron %d Pasajeros desde el archivo en modo texto.\n", cantidadPasajeros);
					pausa(MENSAJE_PAUSA);
				}
				else
				{
					printf("Error en el archivo, no se puede cargar los datos de Pasajero.\n");
					pausa(MENSAJE_PAUSA);
				}
			break;

			case 2: //CARGA CSV  BIN

				cantidadPasajeros = controller_loadFromBinary(ARCHIVO_BIN, listaPasajeros);

				if(cantidadPasajeros > 0)
				{
					printf("Se cargaron %d Pasajeros desde el archivo binario.\n", cantidadPasajeros);
				}
				else
				{
					printf("No se puede cargar Pasajero.\n");
				}

				pausa(MENSAJE_PAUSA);

				break;

			case 3: //ALTA PASAJERO

				system("cls");
				printf("****************  ALTA DE PASAJEROS  **************\n");
				printf("***************************************************\n");

				if(controller_addPassenger(listaPasajeros))
				{
					printf("Pasajero cargado correctamente!\n");
				}
				else
				{
					printf("Error en la carga del Pasajero\n");
				}
				pausa(MENSAJE_PAUSA);
			break;

			case 4: //MODIFICACION PASAJERO

				system("cls");
				printf("*******************  MODIFICACION DE PASAJEROS  *******************\n");
				printf("*******************************************************************\n");

				if(cantidadPasajeros == 0)
				{
					printf("No hay Pasajeros cargados\n");
				}
				else
				{
					controller_ListPassenger(listaPasajeros);

					if(controller_editPassenger(listaPasajeros))
					{
						printf("Pasajero modificado con exito! \n");
					}
					else
					{
						printf("Se cancelo la modificacion del Pasajero\n");
					}
				}

				pausa(MENSAJE_PAUSA);
			break;

			case 5: //BAJA PASAJEROS

				if(cantidadPasajeros == 0)
				{
					printf("No hay Pasajeros cargados.\n");
				}
				else
				{
					controller_ListPassenger(listaPasajeros);
					if(controller_removePassenger(listaPasajeros))
					{
						printf("Pasajero dado de baja. \n");
					}
					else
					{
						printf("Se cancelo la baja de Pasajero. \n");
					}
				}

				pausa(MENSAJE_PAUSA);

				break;

			case 6: //LISTADO PASAJEROS

				system("cls");
				if(cantidadPasajeros == 0)
				{
					printf("********************  LISTADO DE PASAJEROS  **************************\n");
					printf("***********************************************************************\n");
					printf("No hay pasajeros cargados\n");
				}
				else
				{
					printf("********************  LISTADO DE PASAJEROS  **************************\n");
					printf("**********************************************************************\n");
					cantidadPasajeros = controller_ListPassenger(listaPasajeros);
					printf("\n");
				}

				pausa(MENSAJE_PAUSA);
			break;

			case 7: //ORDERNAR PASAJEROS

				if(cantidadPasajeros == 0)
				{
					printf("No hay Pasajeros cargados. \n");
				}
				else
				{
					if(!controller_sortPassenger(listaPasajeros))
					{
						printf("Error al ordenar pasajeros.\n");
					}
				}

				pausa(MENSAJE_PAUSA);

			break;

			case 8: //GUARDA CSV
				if(!controller_saveAsText(ARCHIVO_CSV, listaPasajeros))
				{
					printf("No se pudo guardar el archivo de texto. \n");
				}
				else
				{
					printf("Archivo de texto guardado correctamente. \n");
				}

				pausa(MENSAJE_PAUSA);

			break;

			case 9: //GUARDA BIN
				if(!controller_saveAsBinary(ARCHIVO_BIN, listaPasajeros))
				{
					printf("No se pudo guardar el archivo binario. \n");
				}
				else
				{
					printf("Archivo binario guardado correctamente. \n");
				}

				pausa(MENSAJE_PAUSA);

			break;
    	}
      }while(controlMenu == 0);

    return 0;
}

