#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "TipoPassenger.h"
#include <string.h>

#define PASSENGER_MAX_NOMBRE 128
#define PASAJEROS_MAX_Q 2000

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[5];
}Passenger;

/// fn Passenger Passenger_new*()
/// @brief genera une espacio en la memoria mediante la funcion malloc
///
/// @return el espacio de un pasajero
Passenger* Passenger_new();

/// @fn Passenger Passenger_newParametrosDatos*(int*, char[], char[], float*, int*, char[])
/// @brief controla que los datos del pasajero esten cargados correctamente
///
/// @param id
/// @param nombre
/// @param apellido
/// @param precio
/// @param tipoPasajero
/// @param codigoVuelo
/// @return el pasajero con los datos cargados
Passenger* Passenger_newParametrosDatos(int* id, char nombre[], char apellido[], float* precio, int* tipoPasajero, char codigoVuelo[]);

/// @fn void Passenger_delete()
/// @brief libera la posicion eliminada
///
void Passenger_delete();

/// @fn int Passenger_getNextId(LinkedList*)
/// @brief genera un id y corrobora que sea correcto
///
/// @param pArrayListPassenger
/// @return id passenger
int Passenger_getNextId(LinkedList* pArrayListPassenger);


/// @fn int Passenger_setId(Passenger*, int)
/// @brief carga el campo de la estructura
///
/// @param this
/// @param id
/// @return 0 si ocurrio un error o 1 si esta bien
int Passenger_setId(Passenger* this,int id);

/// @fn int Passenger_getId(Passenger*, int*)
/// @brief toma el id de la estructura
///
/// @param this
/// @param id
/// @return 0 si ocurrio un error o 1 si esta bien
int Passenger_getId(Passenger* this,int* id);


/// @fn int Passenger_setNombre(Passenger*, char*)
/// @brief carga el nombre en la estructura
///
/// @param this
/// @param nombre
/// @return 0 si ocurrio un error o 1 si esta bien
int Passenger_setNombre(Passenger* this,char* nombre);

/// @fn int Passenger_getNombre(Passenger*, char*)
/// @brief toma el nombre de la estructura
///
/// @param this
/// @param nombre
/// @return 0 si ocurrio un error o 1 si esta bien
int Passenger_getNombre(Passenger* this,char* nombre);


/// @fn int Passenger_setApellido(Passenger*, char*)
/// @brief carga el apellido en la estructura
///
/// @param this
/// @param apellido
/// @return 0 si ocurrio un error o 1 si esta bien
int Passenger_setApellido(Passenger* this,char* apellido);

/// @fn int Passenger_getApellido(Passenger*, char*)
/// @brief toma el apellido de la estructura
///
/// @param this
/// @param apellido
/// @return 0 si ocurrio un error o 1 si esta bien
int Passenger_getApellido(Passenger* this,char* apellido);


/// @fn int Passenger_setCodigoVuelo(Passenger*, char*)
/// @brief carga el codigoVuelo en la estructura
///
/// @param this
/// @param codigoVuelo
/// @return 0 si ocurrio un error o 1 si esta bien
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);

/// @fn int Passenger_getCodigoVuelo(Passenger*, char*)
/// @brief toma el codigoVuelo en la estructura
///
/// @param this
/// @param codigoVuelo
/// @return 0 si ocurrio un error o 1 si esta bien
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);


/// @fn int Passenger_setTipoPasajero(Passenger*, int)
/// @brief carga el tipoPasajero en la estructura
///
/// @param this
/// @param tipoPasajero
/// @return 0 si ocurrio un error o 1 si esta bien
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);

/// @fn int Passenger_getTipoPasajero(Passenger*, int*)
/// @brief toma el tipoPasajero en la estructura
///
/// @param this
/// @param tipoPasajero
/// @return 0 si ocurrio un error o 1 si esta bien
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);


/// @fn int Passenger_setPrecio(Passenger*, float)
/// @brief carga el precio en la estructura
///
/// @param this
/// @param precio
/// @return 0 si ocurrio un error o 1 si esta bien
int Passenger_setPrecio(Passenger* this,float precio);

/// @fn int Passenger_getPrecio(Passenger*, float*)
/// @brief toma el precio en la estructura
///
/// @param this
/// @param precio
/// @return 0 si ocurrio un error o 1 si esta bien
int Passenger_getPrecio(Passenger* this,float* precio);


/// @fn void mostrarPasajero(Passenger*)
/// @brief muestra un pasajero
///
/// @param this
void mostrarPasajero(Passenger* this);

/// @fn int mostrarPasajeroConCabecera(Passenger*)
/// @brief muestra un pasajero con la cabecera de datos
///
/// @param this
/// @return
int mostrarPasajeroConCabecera(Passenger* this);

/// @fn int pasasjeroComparadoPorId(void*, void*)
/// @brief compara los id de pasajeros
///
/// @param pasajero1
/// @param pasajero2
/// @return retorna 1 si es mayor a 0 o -1 si es menor a 0 o 0 si es igual
int pasajeroComparadoPorId(void* pasajero1, void* pasajero2);

/// @fn int pasajeroComparadoPorNombre(void*, void*)
/// @brief
///
/// @param pPassenger1
/// @param pPassenger2
/// @return retorna el valor de strcmp
int pasajeroComparadoPorNombre(void* pPassenger1, void* pPassenger2);

/// @fn int pasajeroComparadoPorTipoDePasajero(void*, void*, Passenger*)
/// @brief compara los pasajeros por tipo de pasajero
///
/// @param pasajero1
/// @param pasajero2
/// @param this
/// @return 1 si es mayor que 0, -1 si es menor que 0 o 0 si es igual
int pasajeroComparadoPorTipoDePasajero(void* pasajero1, void* pasajero2);

/// @fn int convertirTipoPasajeroToChar(int, char[])
/// @brief convierte el dato tipoPasajero(INT) a CHAR
///
/// @param typePassengerInt
/// @param typePassengerChar
/// @return 0 si esta correcto o -1 si ocurrio algun problema
int convertirTipoPasajeroToChar(int typePassengerInt, char typePassengerChar[]);

//int convertirTipoPasajeroToInt(int typePassengerInt, char typePassengerChar[]);

#endif /* PASSENGER_H_ */
