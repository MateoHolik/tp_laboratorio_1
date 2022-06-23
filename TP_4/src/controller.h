#include "../inc/LinkedList.h"
#include "input.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto) binario.
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger);

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger);

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger);

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger);

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger);


/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);

/// @fn int buscarIndexPorPassengerID(LinkedList*, int)
/// @brief
///
/// @param pArrayListPassenger
/// @param id
/// @return la posicion de i encontrada o -1
int buscarIndexPorPassengerID(LinkedList* pArrayListPassenger, int id);

