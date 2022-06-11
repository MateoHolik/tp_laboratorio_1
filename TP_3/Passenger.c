#include "Passenger.h"

Passenger* Passenger_new()
{
	Passenger* auxPassenger;

    auxPassenger = (Passenger*)malloc(sizeof(Passenger));

    return auxPassenger;
}

Passenger* Passenger_newParametrosDatos(int* id, char nombre[], char apellido[], float* precio, int* tipoPasajero, char codigoVuelo[])
{
	Passenger* auxPassenger = Passenger_new();

    if(auxPassenger != NULL
       && (!Passenger_setId(auxPassenger, *id)
       || !Passenger_setNombre(auxPassenger, nombre)
	   || !Passenger_setApellido(auxPassenger, apellido)
       || !Passenger_setPrecio(auxPassenger, *precio)
	   || !Passenger_setTipoPasajero(auxPassenger, *tipoPasajero)
       || !Passenger_setCodigoVuelo(auxPassenger, codigoVuelo)))
    {
    	Passenger_delete(auxPassenger);

    	auxPassenger = NULL;
    }

    return auxPassenger;
}


int Passenger_getId(Passenger* this, int* id)
{
    int retorno = 0;

    if(this != NULL)
    {
        *id = this->id;
        retorno = 1;
    }

    return retorno;
}

int Passenger_setId(Passenger* this, int id)
{
    int retorno = 0;

    if(this != NULL && id > 0 && id <= 2000) //FALTA DEFINE ID ID MINIMO Y MAXIMO
    {
        this->id = id;
        retorno = 1;
    }

    return retorno;
}

int Passenger_getNombre(Passenger* this, char* nombre)
{
    int retorno = 0;

    if(this != NULL && this->nombre !=NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 1;
    }

    return retorno;
}

int Passenger_setNombre(Passenger* this, char* nombre)
{
    int retorno = 0;

    if(this != NULL && this->nombre !=NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 1;
    }

    return retorno;

}


int Passenger_getApellido(Passenger* this, char* apellido)
{
    int retorno = 0;

    if(this != NULL && this->apellido !=NULL)
    {
        strcpy(apellido, this->apellido);
        retorno = 1;
    }

    return retorno;
}

int Passenger_setApellido(Passenger* this, char* apellido)
{
    int retorno = 0;

    if(this != NULL && this->nombre !=NULL && apellido != NULL)
    {
        strcpy(this->apellido, apellido);
        retorno = 1;
    }

    return retorno;

}

int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo)
{
    int retorno = 0;

    if(this != NULL && this->codigoVuelo !=NULL)
    {
        strcpy(codigoVuelo, this->codigoVuelo);
        retorno = 1;
    }

    return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo)
{
    int retorno = 0;

    if(this != NULL && this->nombre !=NULL && codigoVuelo != NULL)
    {
        strcpy(this->codigoVuelo, codigoVuelo);
        retorno = 1;
    }

    return retorno;

}

int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero)
{
    int retorno = 0;


    if(this != NULL)
    {
        *tipoPasajero = this->tipoPasajero;
        retorno = 1;
    }

    return retorno;
}

int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero)
{
    int retorno = 0;

    if(this != NULL && tipoPasajero > 0 && tipoPasajero <= 8) //FALTA DEFINE ID ID MINIMO Y MAXIMO
    {
        this->tipoPasajero = tipoPasajero;
        retorno = 1;
    }

    return retorno;
}


int Passenger_getPrecio(Passenger* this, float* precio)
{
    int retorno = 0;

    if(this != NULL)
    {
        *precio = this->precio;
        retorno = 1;
    }

    return retorno;
}

int Passenger_setPrecio(Passenger* this, float precio)
{
    int retorno = 0;

    if(this != NULL && precio > 0 && precio <=5000000) //FALTA DEFINE ID ID MINIMO Y MAXIMO
    {
        this->precio = precio;
        retorno = 1;
    }

    return retorno;
}

void Passenger_delete(Passenger* this)
{
    free(this);
}

int Passenger_getNextId(LinkedList* pArrayListPassenger)
{
    int idPassenger = -1;
    int cantidadPassenger = 0;
    int i;
    int contador = 0;

    Passenger* auxPassenger;

    if(pArrayListPassenger != NULL)
    {
    	cantidadPassenger = ll_len(pArrayListPassenger);

        if(cantidadPassenger > 0)
        {
            for(i = 0; i < cantidadPassenger; i++)
            {
            	auxPassenger = (Passenger*)ll_get(pArrayListPassenger, i); //puntero a funcion

                if(auxPassenger != NULL)
                {
                    if(contador == 0)
                    {
                    	idPassenger = auxPassenger->id;
                    }
                    else
                    {
                        if(auxPassenger->id > idPassenger && auxPassenger->id < 2000) //falta DEFINE
                        {
                        	idPassenger = auxPassenger->id;
                        }
                    }

                    contador++;
                }
            }
        }

        if(contador > 0)
        {
        	idPassenger++;
        }
        else
        {
        	idPassenger = 1;
        }
    }

    return idPassenger;
}

int pasajeroComparadoPorId(void* pasajero1, void* pasajero2)
{
	int retorno;
	int comparacion;

	Passenger* auxPassenger1 = (Passenger*)pasajero1;
	Passenger* auxPassenger2 = (Passenger*)pasajero2;

	if(auxPassenger1 != NULL && auxPassenger2  != NULL)
	{
		comparacion = auxPassenger1 -> id - auxPassenger2 -> id;
		if(comparacion > 0)
		{
			retorno = 1;
		}
		else
		{
			if(comparacion < 0)
			{
				retorno = -1;
			}
			else retorno = 0;
		}
	}
	return retorno;
}

int pasajeroComparadoPorNombre(void* pPassenger1, void* pPassenger2)
{
	int retorno;

	Passenger* auxPassenger1 = (Passenger*) pPassenger1;
	Passenger* auxPassenger2 = (Passenger*) pPassenger2;

	if(auxPassenger1 != NULL && auxPassenger2 != NULL)
	{
		retorno = strcmp(auxPassenger1->nombre, auxPassenger2->nombre);
	}

	return retorno;
}

int pasajeroComparadoPorTipoDePasajero(void* pasajero1, void* pasajero2)
{
	int retorno;
	int comparacion;

	Passenger* auxPassenger1 = (Passenger*)pasajero1;
	Passenger* auxPassenger2 = (Passenger*)pasajero2;

	if(auxPassenger1 != NULL && auxPassenger2  != NULL)
	{
		comparacion = auxPassenger1 ->tipoPasajero - auxPassenger2 ->tipoPasajero;

		if(comparacion > 0)
		{
			retorno = 1;
		}
		else
		{
			if(comparacion < 0)
			{
				retorno = -1;
			}
			else
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}


void mostrarPasajero(Passenger* this)
{
	int id;
	char nombre[PASSENGER_MAX_NOMBRE];
	char apellido[PASSENGER_MAX_NOMBRE];
	float precio;
	int tipoPasajero;
	char auxTipoPasajero[150];

    if(this!= NULL && Passenger_getId(this,&id)
    			   && Passenger_getNombre(this, nombre)
    		       && Passenger_getApellido(this, apellido)
    			   && Passenger_getPrecio(this,&precio)
				   && Passenger_getTipoPasajero(this,&tipoPasajero))
    {
    	convertirTipoPasajeroToChar(tipoPasajero, auxTipoPasajero);
        printf("%-4d %-15s %-15s %-14.2f %-12s \n", id, nombre, apellido, precio, auxTipoPasajero);
    }
    else
    {
        printf("No hay pasajeros para mostrar\n");
    }
}

int mostrarPasajeroConCabecera(Passenger* this)
{
	int retorno = -1;
	int id;
	char nombre[PASSENGER_MAX_NOMBRE];
	char apellido[PASSENGER_MAX_NOMBRE];
	float precio;
	int tipoPasajero;
	char auxTipoPasajero[150];

    if(this!= NULL && Passenger_getId(this,&id)
    			   && Passenger_getNombre(this, nombre)
    		       && Passenger_getApellido(this, apellido)
    			   && Passenger_getPrecio(this,&precio)
				   && Passenger_getTipoPasajero(this,&tipoPasajero))
    {
    	convertirTipoPasajeroToChar(tipoPasajero, auxTipoPasajero);
    	printf("**************************************************************************************\n");
    	printf("ID	 NOMBRE 	APELLIDO 	PRECIO	 TIPO DE PASAJERO 	\n");
        printf("%-4d 	 %-10s     %-10s	%7.2f  	%-10s 	 \n", id, nombre, apellido, precio, auxTipoPasajero);
        printf("**************************************************************************************\n");
        retorno = 1;
    }
    return retorno;
}



int convertirTipoPasajeroToChar(int typePassengerInt, char typePassengerChar[])
{
	int retorno = -1;

	if(typePassengerInt == 1)
	{
		strcpy(typePassengerChar,"General");
		retorno = 0;
	}
	else if(typePassengerInt == 2)
	{
		strcpy(typePassengerChar,"Business");
		retorno = 0;
	}
	else if(typePassengerInt == 3)
	{
		strcpy(typePassengerChar,"First Class");
		retorno = 0;
	}
	else if(typePassengerInt == 4)
	{
		strcpy(typePassengerChar,"Vip");
		retorno = 0;
	}

	return retorno;
}


/*int convertirTipoPasajeroToInt(int typePassengerInt, char typePassengerChar[])
{
	//char general;
	int retorno = -1;

	if(typePassengerInt == 1)
	{
		strcpy(typePassengerChar,"General");
		retorno = 0;
	}
	else if(typePassengerInt == 2)
	{
		strcpy(typePassengerChar,"Business");
		retorno = 0;
	}
	else if(typePassengerInt == 3)
	{
		strcpy(typePassengerChar,"Firs Class");
		retorno = 0;
	}
	else if(typePassengerInt == 4)
	{
		strcpy(typePassengerChar,"Vip");
		retorno = 0;
	}

	return retorno;
}*/

