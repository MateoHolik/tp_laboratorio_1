
#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#define TAM_PASAJEROS 2000
#define TAM_TIPO_PASAJERO 4
#define TAM_ESTADO_VUELO 3
#define NOMBRE_MAXIMO 51
#define COD_VUELO_MAXIMO 10
#define ESTADO_VUELO_ACTIVO 1
#define ESTADO_VUELO_CANCELADO 2

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}Passenger;


typedef struct
{
    int idTipoPasajero;
    char name[20];
}eTipoPasajero;

typedef struct
{
	int idEstadoVuelo;
 	char nombre[10];
}eEstadoVuelo;

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(Passenger list[], int len);

/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addPassenger(Passenger list[], int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight);

/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger list[], int len,int id);

/// @fn int findTipoVueloById(eEstadoVuelo[], int, int)
/// @brief
///
/// @param list
/// @param len
/// @param id
/// @return
int findTipoVueloById(eEstadoVuelo list[], int len, int id);

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger list[], int len, int id);

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengersByTipoPasajero(Passenger list[], int lenPassenger);

/// @fn int printPassenger(Passenger*, int)
/// @brief Muestra por pantalla el tipo de pasajero
///
/// @param list
/// @param lenght
/// @return la posicion del array en i
int printTipoDePassanger(eTipoPasajero tipoPasajero[], int tamPasajeros);

/// @fn int findPassengerById(Passenger, int, int)
/// @brief busca el tipo de pasajero por ID
///
/// @param list
/// @param len
/// @param id
/// @return -1 en caso de error o el ID encontrado en la posicion de i
int findTipoPasajeroById(eTipoPasajero list[], int len, int id);


/// @fn int getEmptyIndexOfPassengers(Passenger[], int)
/// @brief obtiene el indice vacio y coloca el isEmpty en 0
///
/// @param list
/// @param len
/// @return -1 si hay algun error o la posicion de i
int getEmptyIndexOfPassengers(Passenger list[], int len);

/// @fn int getNewPassengerId()
/// @brief genera un numero de ID automatico comenzando por el 1000
///
/// @return el numero de ID generado
int getNewPassengerId();

/// @fn int printPassengers(Passenger[], int, eTipoPasajero[], int)
/// @brief recorre la lista de pasajeros e imprime las posiciones que estan siendo ocupadas
///
/// @param list
/// @param lenght
/// @param listTipo
/// @param lenghttipo
/// @return -1 si hay algun error o 0 si esta bien
int printPassengers(Passenger list[], int lenght, eTipoPasajero listTipo [], int lenghttipo);

/// @fn int printPassenger(Passenger, int, eTipoPasajero[], int)
/// @brief imprime un solo pasajero
///
/// @param list
/// @param lenght
/// @param listTipo
/// @param lenghtTipo
/// @return 0
int printPassenger(Passenger list, int lenght, eTipoPasajero listTipo [], int lenghtTipo);

/// @fn int printPassengerEstadoVuelo(Passenger, int, eEstadoVuelo[], int)
/// @brief
///
/// @param list
/// @param lenght
/// @param listEstado
/// @param lenghtEstado
/// @return 0
int printPassengerEstadoVuelo(Passenger list, int lenght, eEstadoVuelo listEstado[], int lenghtEstado);

/// @fn int printPassengersEstadoVuelo(Passenger[], int, eEstadoVuelo[], int)
/// @brief
///
/// @param list
/// @param lenght
/// @param listEstado
/// @param lenghtEstado
/// @return la posicion del array en i
int printPassengersEstadoVuelo(Passenger list[], int lenght, eEstadoVuelo listEstado [], int lenghtEstado);

/// @fn int checkPassengersExists(Passenger[], int)
/// @brief
///
/// @param list
/// @param tam
/// @return
int checkPassengersExists(Passenger list[], int tam);

/// @fn void swapPassengers(Passenger*, int, int, int)
/// @brief swapea las posiciones
///
/// @param list
/// @param len
/// @param i
/// @param j
void swapPassengers(Passenger* list, int len, int i, int j);

/// @fn void pasajerosHardcode(Passenger[], int, int)
/// @brief se encuentran los pasajeros hardcodeados
///
/// @param list
/// @param length
/// @param cantidad
void pasajerosHardcode(Passenger list[], int length, int cantidad);

/// @fn int sortPassengersByLastName(Passenger[], int)
/// @brief ordena los pasajeros por apellido
///
/// @param list
/// @param lenPassenger
/// @return
int sortPassengersByLastName(Passenger list[], int lenPassenger);

/// @fn void calculoPromedioPassenger(Passenger[], int, eTipoPasajero[], int)
/// @brief
///
/// @param list
/// @param lenght
/// @param tipoPasajero
/// @param tamPasajeros
void calculoPromedioPassenger(Passenger list[], int lenght, eTipoPasajero tipoPasajero[], int tamPasajeros);

#endif /* ARRAYPASSENGER_H_ */
