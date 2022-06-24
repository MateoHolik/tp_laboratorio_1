#ifndef MENU_H_
#define MENU_H_

#include "input.h"
#include "Passenger.h"

#define MENU_PRINCIPAL_Q 11
#define MENU_ORDENAMIENTO_Q 4
#define MENU_EDICION_Q 5


/** \brief menu principal del programa.
*
* \param opcion int* Opcion elegida del menu.
* \return int error retorna -1 sino retorna la opcion elegida en el menu.
*/
int menuPrincipal(int* opcion);

/** \brief menu de ordenamiento del arreglo.
*
* \param opcion int* Opcion elegida del menu.
* \return int error retorna -1 sino retorna la opcion elegida en el menu.
*
*/
int menuOrdenamiento(int* opcion);

/** \brief menu de edicion para un Pasajero
*
* \param opcion int* Opcion elegida del menu.
* \return int error retorna -1 sino retorna la opcion elegida en el menu.
*/
int menuEdicion(int* opcion);

/// @fn int menuTipoPasajero(int*)
/// @brief menu para el tipo de pasajero
///
/// @param opcionTipoPasajero
/// @return retorna 0 si esta bien o -1 si hubo algun error
int menuTipoPasajero(int* opcionTipoPasajero);

#endif /* MENU_H_ */
