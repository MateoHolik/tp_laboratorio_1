#include <string.h>
#include "Controller.h"
#include "parser.h"
#include "Passenger.h"
#include "menu.h"
#include "input.h"

int totalPasajerosVip(LinkedList* this)
{
    int retorno = -1;
    int cantidad = 0;
    LinkedList* tipoPasajeroVip;

    if(this != NULL)
    {
    	tipoPasajeroVip = ll_newLinkedList(); //crea el constructor
    	tipoPasajeroVip = ll_filter(this, pasajero_filtroVip);

    	cantidad = ll_count(tipoPasajeroVip, pasajero_filtroVip);

    	printf("Cantidad de pasajeros vip: %d \n", cantidad);

    }
    return retorno;
}

int pasajero_filtroVip(void* this)
{
    int returnAux = 0;
    Passenger* listPasajeros;
    int pasajeroVip = 3;
    /*
    1. Business
    2. Primer Clase
    3. VIP
    4. Diplomatico
    */

    if(this != NULL)
    {
    	listPasajeros = (void*)this;

        if(listPasajeros -> tipoPasajero == pasajeroVip)
        {
            returnAux = 1;
        }


    }
    return returnAux;
}


int ll_count(LinkedList* this, int (*fn)(void* element))
{
	int contador = 0;
	int valor;
	int largo;
	void* pElement;

	if(this != NULL && *fn != NULL)
	{
		largo = ll_len(this);

		for (int i = 0; i < largo; i++)
		{
			pElement = ll_get(this, i);
			valor = fn(pElement);

			if (valor != -1)
			{
				contador = contador + valor;
			}
		}
	}

	return contador;
}






/*////////////////////////////////////////////////////////////////////////////////////////////*/



















int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
    int retorno = 0;

    FILE* archivo = NULL;

    if(pArrayListPassenger != NULL && path != NULL)
    {
    	archivo = fopen(path, "r");

        if(archivo != NULL)
        {
        	retorno = parser_PassengerFromText(archivo, pArrayListPassenger);
        }
    }

    fclose(archivo);

    return retorno;
}



int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
    int retorno = 0;

    FILE* archivo = NULL;

    if(pArrayListPassenger != NULL && path != NULL)
    {
    	archivo = fopen(path, "rb");

        if(archivo != NULL)
        {
        	retorno = parser_PassengerFromBinary(archivo, pArrayListPassenger);
        }
    }

    fclose(archivo);

    return retorno;
}


int controller_addPassenger(LinkedList* pArrayListPassenger)
{
    int retorno = 0;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[4];

    Passenger* auxPassenger = NULL;

    if(pArrayListPassenger != NULL)
    {
        id = Passenger_getNextId(pArrayListPassenger);

        if(id != -1
           && !inputString(nombre, "Ingrese Nombre: ", "Error, Ingrese Nombre: ", 1,  51, 0)
		   && !inputString(apellido, "Ingrese Apellido: ", "Error, Ingrese Apellido: ", 1,  51, 0)
		   && !inputNumberFloat(&precio, "Ingrese el Precio del vuelo: ", "Error, Ingrese Precio del vuelo: ", 1, 1000000)
		   && !inputStringAlpha(codigoVuelo, "Ingrese Codigo de Vuelo: ", "Error, Ingrese Codigo de Vuelo: ", 1,  10))
        {

        	menuTipoPasajero(&tipoPasajero);


        	auxPassenger = Passenger_newParametrosDatos(&id, nombre, apellido, &precio, &tipoPasajero, codigoVuelo);

            if(auxPassenger != NULL && ll_add(pArrayListPassenger, (Passenger*)auxPassenger) == 0)
            {
            	retorno = 1;
            }
        }
    }

    return retorno;

}


int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 1;
	//int controlMenu;
	int idPasajero;
	int indexPassenger;
	int idPassengerMax;

	int opcionMenu;


	Passenger* auxPassenger = Passenger_new();
	Passenger* auxPassengerModificado;


	if(pArrayListPassenger != NULL && auxPassenger != NULL)
	{
		idPassengerMax = Passenger_getNextId(pArrayListPassenger) - 1;

        printf("\n");

        if(idPassengerMax > 0 && !inputNumberInt(&idPasajero, "Ingrese el ID del pasajero que desea modificar: ", "Error, Reingrese el ID nuevamente:", 1, idPassengerMax))
        {
			indexPassenger = buscarIndexPorPassengerID(pArrayListPassenger, idPasajero);

			if(indexPassenger != -1)
			{
				auxPassenger = (Passenger*)ll_get(pArrayListPassenger, indexPassenger);

				if(auxPassenger != NULL)
				{

					auxPassengerModificado = Passenger_newParametrosDatos(&auxPassenger->id,auxPassenger-> nombre,auxPassenger-> apellido,
																		  &auxPassenger->precio, &auxPassenger-> tipoPasajero, auxPassenger->codigoVuelo);
					do
					{
						system("cls");

						if(mostrarPasajeroConCabecera(auxPassengerModificado) == 0)
						{
							break;
						}

						checkContinue();


						menuEdicion(&opcionMenu);

						switch (opcionMenu)
						{
							case 1: //nombre
								inputString(auxPassengerModificado->nombre,"Ingrese el nombre: ","Error, Ingrese el nombre: ", 1, PASSENGER_MAX_NOMBRE,54);
								Passenger_setNombre(auxPassengerModificado, auxPassengerModificado -> nombre);

								ll_set(pArrayListPassenger, indexPassenger, (Passenger*)auxPassengerModificado);
								mostrarPasajeroConCabecera(auxPassengerModificado);

							break;

							case 2: //apellido
								inputString(auxPassengerModificado->apellido ,"Ingrese el apellido","Error, Ingrese el apellido", 1, PASSENGER_MAX_NOMBRE,54);
								Passenger_setApellido(auxPassengerModificado, auxPassengerModificado -> apellido);

								ll_set(pArrayListPassenger, indexPassenger, (Passenger*)auxPassengerModificado);
								mostrarPasajeroConCabecera(auxPassengerModificado);
							break;

							case 3: //precio
								inputNumberFloat(&auxPassengerModificado->precio,"Ingrese el precio","Error, Ingrese el precio", 1, 2000000);
								Passenger_setPrecio(auxPassengerModificado, auxPassengerModificado -> precio);

								ll_set(pArrayListPassenger, indexPassenger, (Passenger*)auxPassengerModificado);
								mostrarPasajeroConCabecera(auxPassengerModificado);

							break;

							case 4: //tipo de pasajero
								inputNumberInt(&auxPassengerModificado->tipoPasajero,"Ingrese el tipo de pasajero","Error, Ingrese el tipo de pasajero", 1, 4);
								Passenger_setTipoPasajero(auxPassengerModificado, auxPassengerModificado -> tipoPasajero);

								ll_set(pArrayListPassenger, indexPassenger, (Passenger*)auxPassengerModificado);
								mostrarPasajeroConCabecera(auxPassengerModificado);

							break;

							case 5: // salir
								//controlMenu = 1;
								pausa(MENSAJE_PAUSA);
							break;
						}

						if(opcionMenu < MENU_EDICION_Q)
						{
							pausa(MENSAJE_PAUSA);
						}

					}while(opcionMenu == 6);
				}
			}
			else
			{
				printf("El ID del pasajero es inexistente.");
			}
        }
	}
    return retorno;
}


int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int idPassengerMax;
	int idPassenger;
	int indexPassenger;

	Passenger* auxPassenger = Passenger_new();

	if(pArrayListPassenger != NULL && auxPassenger != NULL)
	{
		idPassengerMax = Passenger_getNextId(pArrayListPassenger)- 1;
		printf("\n");

		if(idPassengerMax > 0)
		{
			inputNumberInt(&idPassenger, "Ingrese el ID del pasajero a dar de baja: ", "Error, reingrese el ID:", 1, 1000);
			indexPassenger = buscarIndexPorPassengerID(pArrayListPassenger, idPassenger);

			if(indexPassenger != -1)
			{
				auxPassenger = (Passenger*)ll_get(pArrayListPassenger, indexPassenger);

				if(auxPassenger != NULL)
				{
					mostrarPasajeroConCabecera(auxPassenger);
					inputContinuar("Confirma la baja del Pasajero? (S)i / (N)o: ");

					if(ll_remove(pArrayListPassenger, indexPassenger) == 0)
					{
						retorno = 1;
						Passenger_delete(auxPassenger); //free
						auxPassenger = NULL;
					}
				}
			}
			else
			{
				printf("El ID del pasajero es inexistente: \n");
			}
		}
	}
    return retorno;
}


int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int cantidadPasajeros;
	int i;

	if(pArrayListPassenger != NULL)
	{
		retorno = 1;

		Passenger* auxPassenger;

		cantidadPasajeros = ll_len(pArrayListPassenger);

		printf("%s %8s  	   %10s	   %8s   %12s \n","ID", "NOMBRE", "APELLIDO", "PRECIO", "TIPO PASAJERO");
		printf("*******************************************************************************************\n");

		for(i=0; i < cantidadPasajeros; i++)
		{
			auxPassenger = (Passenger*)ll_get(pArrayListPassenger, i);
			mostrarPasajero(auxPassenger);
		}
	}

	    return retorno;
}


int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int controlMenu;
	int opcionMenu = 0;

	int opcionDeOrdenamiento=0;

	if(pArrayListPassenger != NULL)
	{
		if(ll_len(pArrayListPassenger) > 0)
		{
			do
			{
				controlMenu = menuOrdenamiento(&opcionMenu);

				if(opcionMenu >= 1 && opcionMenu < MENU_ORDENAMIENTO_Q)
				{
					inputNumberInt(&opcionDeOrdenamiento, "Ingrese el orden de los datos: (1)Asc - (0)Desc: ", "Error reingrese el orden: ", 0, 1);

					printf("Se estan ordenando los Pasajeros, aguarde un momento por favor. \n");

					switch(opcionMenu)
					{
						case 1: //ORDENA POR ID
							if(ll_sort(pArrayListPassenger, pasajeroComparadoPorId, opcionDeOrdenamiento) == 0)
							{
								controller_ListPassenger(pArrayListPassenger);
								printf("Los datos fueron ordenados por ID.\n");
							}

						break;

						case 2: //ORDENAR POR NOMBRE

							if(ll_sort(pArrayListPassenger,pasajeroComparadoPorNombre , opcionDeOrdenamiento) == 0)
							{
								controller_ListPassenger(pArrayListPassenger);
								printf("Los datos fueron ordenados por nombre.\n");
							}

						break;

						case 3: //ORDENAR POR TIPO DE PASAJERO
							if(ll_sort(pArrayListPassenger, pasajeroComparadoPorTipoDePasajero , opcionDeOrdenamiento) == 0)
							{
								controller_ListPassenger(pArrayListPassenger);
								printf("Los datos fueron ordenados por Tipo De Pasajero.\n");
							}

						break;

					}
				}
				else
				{
					if(opcionMenu == MENU_ORDENAMIENTO_Q)
					{
						retorno = 1;
						break;
					}
				}
			}while(controlMenu == 0);
		}
	}

    return retorno;
}


int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* archivo;
	archivo = NULL;

	int retorno = 0;
	int cantidadPassengers;
	int i;

	Passenger* auxPassenger;

	if(pArrayListPassenger != NULL && path != NULL)
	{
		cantidadPassengers = ll_len(pArrayListPassenger);

		archivo = fopen(path, "w");

		if(archivo != NULL && cantidadPassengers > 0 && cantidadPassengers <= PASAJEROS_MAX_Q)
		{
			fprintf(archivo, "id, nombre, apellido, precio, tipopasajero, codigovuelo \n");

			for(i = 0; i < cantidadPassengers; i++)
			{
				auxPassenger = (Passenger*)ll_get(pArrayListPassenger, i);

				if(auxPassenger == NULL
						|| fprintf(archivo, "%d, %s, %s, %f, %d, %s \n",
						auxPassenger->id, 					//int
						auxPassenger->nombre, 				//char
						auxPassenger->apellido, 			// char
						auxPassenger->precio,				// float
						auxPassenger->tipoPasajero,			//int
						auxPassenger->codigoVuelo) == -1)   //char
				{
					break;
				}
			}
		}

		if(i > 0 && i == cantidadPassengers)
		{
			retorno = 1;
		}
	}

	fclose(archivo);

    return retorno;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* archivo;
	archivo = NULL;

	int retorno = 0;
	int cantidadPassengers;
	int i;

	Passenger* auxPassenger;

	if(pArrayListPassenger != NULL )
	{
		cantidadPassengers = ll_len(pArrayListPassenger);

		archivo = fopen(path, "wb");

		if(archivo != NULL && cantidadPassengers > 0 && cantidadPassengers < PASAJEROS_MAX_Q)
		{
			for(i = 0; i < cantidadPassengers; i++)
			{
				auxPassenger = (Passenger*)ll_get(pArrayListPassenger, i);

				if(auxPassenger == NULL || fwrite((Passenger*)auxPassenger, sizeof(Passenger), 1, archivo) != 1)
				{
					break;
				}
			}
		}

		if(i > 0 && i == cantidadPassengers)
		{
			retorno = 1;
		}
	}

	fclose(archivo);

    return retorno;
}

int buscarIndexPorPassengerID(LinkedList* pArrayListPassenger, int id)
{
	int retorno = -1;
	int cantidadPassengers;

	Passenger* auxPassenger;

	if(pArrayListPassenger != NULL)
	{
		cantidadPassengers = ll_len(pArrayListPassenger); //comparison beetwen pointer and integer(for)

		if(cantidadPassengers > 0)
		{
			for(int i = 0; i < cantidadPassengers; i++)
			{
				auxPassenger = ll_get(pArrayListPassenger, i);

				if(auxPassenger != NULL && auxPassenger->id == id)
				{
					retorno = i;
					break;
				}
			}
		}
	}

	return retorno;
}
