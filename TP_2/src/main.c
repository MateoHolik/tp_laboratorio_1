/*
 ============================================================================
 Name        : Trabajo practico 2
 Author      : Mateo Holik
 ============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "input.h"
#include "ArrayPassenger.h"

#define OCUPADO 1
#define VACIO 0

int main()
{

	setbuf(stdout, NULL);

    Passenger passenger[TAM_PASAJEROS];
    Passenger passengerAux;

    eTipoPasajero tipoPasajero[] =
    {
        {1, "GENERAL"},
        {2, "BUSINESS"},
        {3, "VIP"},
        {4, "DIPLOMATICO"},
    };

    eEstadoVuelo estadoVuelo[] =
    {
        {1, "ACTIVO"},
        {2, "CANCELADO"},
        {3, "DEMORADO"},
    };

    char checkContinuar;
    int flag1 = 0;
    int idBaja;
    int idModificar;
    int indice;
    int opcionModificacion;
    int opcionMenu;

    initPassengers(passenger,TAM_PASAJEROS);

    do
    {
    	opcionMenu = menuPrincipal();
    	flag1=1;

    	switch(opcionMenu)
        {

        case 1:
            system("cls");
            printf("***********************************************************************************************************\n");
            printf("                                    Alta de Pasajero \n");
            printf("***********************************************************************************************************\n");

             inputString(passengerAux.name, "Ingrese el nombre: ","Error, vuelva a ingresa el Nombre: ", 1, 51,0);
             inputString(passengerAux.lastName, "Ingrese el apellido: ","Error, vuelva a ingresa el Nombre: ", 1, 51,0);
             inputNumberFloat(&passengerAux.price, "Ingrese el precio del vuelo: ", "Error, Ingrese el precio nuevamente: ", 1, 1500000 );
             inputString(passengerAux.flycode, "Ingrese el codigo del vuelo: ", "Error, Ingrese el codigo nuevamente: ", 1, 10, 1 );


             printf("\n");

             printTipoDePassanger(tipoPasajero, TAM_TIPO_PASAJERO);

             inputNumberInt(&passengerAux.typePassenger, "Ingrese el TIPO DE PASAJERO de vuelo: ", "Error, Ingrese el tipo de pasajero nuevamente: ", 1, 4);

             printf("\n");

             if (addPassenger(passenger, TAM_PASAJEROS, getNewPassengerId(), passengerAux.name, passengerAux.lastName, passengerAux.price, passengerAux.typePassenger, passengerAux.flycode, ESTADO_VUELO_ACTIVO)==0)
             {
            	 printf("Pasajero cargado con exito.\n\n");

            	 flag1 = 1;
             }

             printPassengers(passenger, TAM_PASAJEROS, tipoPasajero, TAM_TIPO_PASAJERO);

             system("pause");

            break;

        case 2:
            system("cls");

        	printf("\n");

            if(flag1==0 || checkPassengersExists(passenger, TAM_PASAJEROS)==0)
            {
                printf("Error al modificar pasajeros, primero debe dar de alta (Opcion 1.)\n");
                system("pause");
                break;
            }
            else
            {
                system("cls");
                printf("******************************************************************************************************************************\n");
                printf("                                    Menu Modificacion de Pasajeros \n");

                printPassengers(passenger, TAM_PASAJEROS, tipoPasajero, TAM_TIPO_PASAJERO);
            	printf("\n");

            	inputNumberInt(&idModificar, "Ingrese el ID del pasajero a modificar: ", "Error, Ingrese el ID del pasajero: ", 1000, 3000);

            	indice =  findPassengerById(passenger, TAM_PASAJEROS, idModificar);


                if(indice == -1)
                {
                    printf("El codigo del pasajero no existe.\n");
                    system("pause");
                }
                else
                {
                    system("cls");
                    printf("*******************************************************************************************************************************\n");
                    printf("                                    Menu Modificacion de Pasajeros \n");
                    printf("                                                                                                                               ");
                    printf("  ID            Nombre     	     Apellido    	 	  Precio        Codigo De Vuelo	       Tipo De Pasajero    \n");

                    printPassengers(passenger, TAM_PASAJEROS, tipoPasajero, TAM_TIPO_PASAJERO);

                    printf("\n\n");
                    printf("Confirme si el pasajero seleccionado es el que desea modificar:\n\n");

                    checkContinuar=checkContinue();

                    if(checkContinuar=='S')
                    {
                    	system("cls");
                        printf("*******************************************************************************************************************************\n");
                        printf("                                    Menu Modificacion de Pasajeros \n");
                        printf("                                                                                                                               ");
                        printf("  ID            Nombre     	     Apellido    	 	  Precio        Codigo De Vuelo	       Tipo De Pasajero    \n");
                        printf("*******************************************************************************************************************************\n\n");

                        printPassengers(passenger, TAM_PASAJEROS, tipoPasajero, TAM_TIPO_PASAJERO);

                        printf("\n\n");

                        opcionModificacion = menuModificacion();

                        switch(opcionModificacion)
                        {
							case 1:
								inputString(passenger[indice].name,"Ingrese el nombre: ","Error, vuelva a ingresa el Nombre:", 1, 51, 0);
								printf("Nombre modificado con exito:\n");

					             printPassengers(passenger, TAM_PASAJEROS, tipoPasajero, TAM_TIPO_PASAJERO);

							break;

							case 2:
								inputString(passenger[indice].lastName, "Ingrese el apellido: ","Error, vuelva a ingresa el Nombre:", 1, 51, 0);
								printf("Apellido modificado con exito:\n");

					             printPassengers(passenger, TAM_PASAJEROS, tipoPasajero, TAM_TIPO_PASAJERO);

							break;

							case 3:
								inputNumberFloat(&passenger[indice].price, "Ingrese el precio del vuelo: ", "Error, Ingrese el precio del vuelo nuevamente: ", 1, 1500000 );
								printf("Precio modificado con exito:\n");

					             printPassengers(passenger, TAM_PASAJEROS, tipoPasajero, TAM_TIPO_PASAJERO);

							break;

							case 4:

								 inputString(passenger[indice].flycode, "Ingrese el codigo de vuelo: ", "Error, Ingrese el codigo de vuelo: ", 1, 10, 1);
								 printf("Sector cambiado con exito:\n");

					             printPassengers(passenger, TAM_PASAJEROS, tipoPasajero, TAM_TIPO_PASAJERO);

							break;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
            system("pause");

        break;

        case 3:

            system("cls");

            if(checkPassengersExists(passenger, TAM_PASAJEROS)==0)
            {
                printf("Error ! Baja de empleados, primero debe dar de alta empleados.\n");

                system("pause");

              break;
            }
            else
            {
                printf("***********************************************************************************************************\n");
                printf("                                    Menu Baja de Empleados \n");


                printPassengers(passenger, TAM_PASAJEROS, tipoPasajero, TAM_TIPO_PASAJERO);
            	inputNumberInt(&idBaja, "Ingrese el ID del pasajero a dar de baja: ", "Error, Ingrese el ID del pasajero a dar de baja: ", 1000, TAM_PASAJEROS);

            	indice = findPassengerById(passenger, TAM_PASAJEROS, idBaja);

                if(indice == -1)
                {
                    printf("El ID del pasajero no existe\n");

                }
                else
                {
                    printf("Pasajero a dar de baja: \n");

                    printPassenger(passenger[indice], TAM_PASAJEROS, tipoPasajero, TAM_TIPO_PASAJERO);

                    printf("ESTE PASAJERO SE DARA DE BAJA DE FORMA PERMANENTE.\n");

                    checkContinuar = checkContinue();

                    if(checkContinuar=='S')
                    {

                        if(removePassenger(passenger, TAM_PASAJEROS, idBaja)==-1)
                        {
                            printf("No se pudo realizar la baja del pasajero.\n");
                        }
                        else
                        {
                        	printf("La baja se realizo correctamente.\n");
                        }
                    }
                    else
                    {
                        printf("Baja del pasajero cancelada.\n");

                        system("pause");
         break;
                    }
                }
            }

            system("pause");
            break;

        case 4:

            system("cls");

            if(checkPassengersExists(passenger, TAM_PASAJEROS) == 0)
            {
                printf("Error! primero debe dar de alta pasajeros porque no hay informacion en el sistema.\n");

                system("pause");
                break;
            }
            else
            {
                system("cls");
                menuPrincipalReportes(passenger, TAM_PASAJEROS, tipoPasajero, TAM_TIPO_PASAJERO, estadoVuelo, TAM_ESTADO_VUELO );
            }

            system("pause");

        break;

        case 5:
   			system("cls");

   		    pasajerosHardcode(passenger, TAM_PASAJEROS, 7);
   		    printf("Los datos fueron hardcodeados con exito \n");
   			system("pause");
        break;

        case 6:
   			system("cls");
   			printf("Gracias por utilizar TP 2 ");
   			system("pause");

        break;
        }
    }while(opcionMenu != 6);

    return 0;
}
