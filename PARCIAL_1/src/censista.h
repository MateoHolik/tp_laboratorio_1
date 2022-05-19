#ifndef CENSISTA_H_
#define CENSISTA_H_

#define TAM_CENSISTA 20
#define VACIO 0
#define OCUPADO 1

#define EST_CENSISTA_ACTIVO "ACTIVO"
#define EST_CENSISTA_INACTIVO "INACTIVO"
#define EST_CENSISTA_LIBERADO "LIBERADO"

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    int edad;
    char estado[10];
    int isEmpty;
}eCensista;

typedef struct
{
    int idDomicilio;
    int idCensista;
    char direccion[101];
    int isEmpty;
}eDomicilioCensita;

typedef struct
{
    int idFechaNacimiento;
    int idCensista;
    char fechaNacimiento[10];
    int isEmpty;
}eFechaNacimientoCensita;

/// @fn int initCensista(eCensista[], int)
/// @brief esta funcion indica que todas las posiciones del array estan en empty
/// y coloca isEmpty en true
///
/// @param listCensista
/// @param lenCensista
/// @return retorna -1 si hay algun error o 0 si esta bien
int initCensista(eCensista listCensista[], int lenCensista);

/// @fn int initCensistaDomicilio(eDomicilioCensita[], int)
/// @brief esta funcion indica que todas las posiciones del array estan en empty
/// y coloca isEmpty en true
/// @param listDomicilio
/// @param lenDomicilio
/// @return retorna -1 si hay algun error o 0 si esta bien
int initCensistaDomicilio(eDomicilioCensita listDomicilio[], int lenDomicilio);

/// @fn int initCensistaFechaNacimiento(eFechaNacimientoCensita[], int)
/// @brief esta funcion indica que todas las posiciones del array estan en empty
/// y coloca isEmpty en true
/// @param listFecha
/// @param lenFecha
/// @return retorna -1 si hay algun error o 0 si esta bien
int initCensistaFechaNacimiento(eFechaNacimientoCensita listFecha[], int lenFecha);


/// @fn int altaCensista(eCensista[], int, int, char[], char[], int, char[])
/// @brief genera un nuevo censista en espacio con los datos cargados
///
/// @param listCensista
/// @param lenCensita
/// @param id
/// @param nombre
/// @param apellido
/// @param edad
/// @param estado
/// @return retorna -1 si hay algun error o 0 si esta bien
int altaCensista(eCensista listCensista[], int lenCensita, int id, char nombre[],  char apellido[], int edad, char estado[]);

/// @fn int altaCensistaFechaNacimiento(eFechaNacimientoCensita[], int, int, int, char[])
/// @brief agrega en una lista de Censistas los
/// valores recibidos por parametro en la primer posicion
///
/// @param listFecha
/// @param lenFecha
/// @param idFechaNacimiento
/// @param idCensista
/// @param fechaNacimiento
/// @return retorna -1 si hay algun error o 0 si esta bien
int altaCensistaFechaNacimiento(eFechaNacimientoCensita listFecha[], int lenFecha, int idFechaNacimiento, int idCensista, char fechaNacimiento[]);

/// @fn int altaDomicilioCensita(eDomicilioCensita[], int, int, int, char[])
/// @brief agrega en una lista de Censistas los
/// valores recibidos por parametro en la primer posicion
///
/// @param listDomicilio
/// @param lenDomicilio
/// @param idDomicilio
/// @param idCensista
/// @param direccion
/// @return retorna -1 si hay algun error o 0 si esta bien
int altaDomicilioCensita(eDomicilioCensita listDomicilio[], int lenDomicilio, int idDomicilio, int idCensista, char direccion[]);


/// @fn int obtenerCensistaIndex(eCensista[], int)
/// @brief recorre la lista de censista y retorna la posicion "vacia"
///
/// @param listCensista
/// @param lenCensista
/// @return -1 si hay algun error o la posicion de i
int obtenerCensistaIndex(eCensista listCensista[], int lenCensista);

/// @fn int obtenerCensistaDomicilioIndex(eDomicilioCensita[], int)
/// @brief recorre la lista de censista y retorna la posicion "vacia"
///
/// @param listDomicilio
/// @param lenDomicilio
/// @return -1 si hay algun error o la posicion de i
int obtenerCensistaDomicilioIndex(eDomicilioCensita listDomicilio[], int lenDomicilio);

/// @fn int obtenerCensistaFechaNacimiento(eFechaNacimientoCensita[], int)
/// @brief recorre la lista de censista y retorna la posicion "vacia"
///
/// @param listFecha
/// @param lenFecha
/// @return -1 si hay algun error o la posicion de i
int obtenerCensistaFechaNacimiento(eFechaNacimientoCensita listFecha[], int lenFecha);


/// @fn int getNuevoCensistaId()
/// @brief genera un numero de ID que incrementa +1
///
/// @return retorna el numero de id generado
int getNuevoCensistaId();

/// @fn int getNuevoDomicilioCensistaId()
/// @brief genera un numero de ID que incrementa +1
///
/// @return retorna el numero de id generado
int getNuevoDomicilioCensistaId();

/// @fn int getNuevoFechaNacimientoCensistaId()
/// @brief genera un numero de ID que incrementa +1
///
/// @return retorna el numero de id generado
int getNuevoFechaNacimientoCensistaId();


/// @fn int buscarCensistaId(eCensista[], int, int)
/// @brief recorre la lista de censista y busca la posicion en la que esta el id
///
/// @param listCensista
/// @param lenCensista
/// @param id
/// @return retorna i en la posicion del id cuando lo encuentre
int buscarCensistaId(eCensista listCensista[], int lenCensista, int id);

/// @fn int buscarFechaNacimientoCensistaId(eFechaNacimientoCensita[], int, int)
/// @brief recorre la lista de fecha de nacimiento censista y busca la posicion en la que esta el id
///
/// @param listFecha
/// @param lenFecha
/// @param id
/// @return retorna i en la posicion del id cuando lo encuentre
int buscarFechaNacimientoCensistaId(eFechaNacimientoCensita listFecha[], int lenFecha, int id);

/// @fn int buscarDomicilioCensistaId(eDomicilioCensita[], int, int)
/// @brief recorre la lista del domicilio del censista y busca la posicion en la que esta el id
///
/// @param listDomicilio
/// @param lenDomicilio
/// @param id
/// @return retorna i en la posicion del id cuando lo encuentre
int buscarDomicilioCensistaId(eDomicilioCensita listDomicilio[], int lenDomicilio, int id);


/// @fn int mostrarCensistas(eCensista[], int, eFechaNacimientoCensita[], int, eDomicilioCensita[], int)
/// @brief muestra los censitas cargados
///
/// @param listCensista
/// @param lenCensista
/// @param listFecha
/// @param lenFecha
/// @param listDomicilio
/// @param tamDireccion
/// @return -1 en caso que haya salido mal algo o 0 si esta ok
int mostrarCensistas(eCensista listCensista[], int lenCensista, eFechaNacimientoCensita listFecha[], int lenFecha, eDomicilioCensita listDomicilio[], int tamDireccion);

/// @fn void mostrarCensista(eCensista, int, eFechaNacimientoCensita[], int, eDomicilioCensita[], int, int)
/// @brief muestra un solo censista
///
/// @param listCensista
/// @param lenCensista
/// @param listFecha
/// @param lenFecha
/// @param listDomicilio
/// @param lenDomicilio
/// @param idCensista
void mostrarCensista(eCensista listCensista, int lenCensista, eFechaNacimientoCensita listFecha[], int lenFecha, eDomicilioCensita listDomicilio[], int lenDomicilio, int idCensista);

/// @fn int mostrarCensistasPorEstado(eCensista[], int, char[])
/// @brief muestra a los censistas cargados y su estado actual
///
/// @param listCensista
/// @param lenCensista
/// @param estado
/// @return -1 en caso que haya salido mal algo o 0 si esta ok
int mostrarCensistasPorEstado(eCensista listCensista[], int lenCensista, char estado[]);

/// @fn void mostrarCensistaPorEstado(eCensista, int, int)
/// @brief
///
/// @param listCensista
/// @param lenCensista
/// @param idCensista
void mostrarCensistaPorEstado(eCensista listCensista, int lenCensista, int idCensista);


/// @fn int checkCensistaExists(eCensista[], int)
/// @brief recorre la lista de censista y busca que la posicion no este ocupada
///
/// @param listCensista
/// @param lenCensista
/// @return 0 si esta bien o 1 si no encontro posicion o algo salio mal
int checkCensistaExists(eCensista listCensista[], int lenCensista);


/// @fn int bajaCensista(eCensista[], int, int)
/// @brief recorre la lista y le cambia el estado del is.empty a VACIO
///
/// @param listCensista
/// @param lenCensista
/// @param idCensistaBaja
/// @return 0 si esta bien o 1 si hay algun error
int bajaCensista(eCensista listCensista[], int lenCensista, int idCensistaBaja);


/// @fn int cambiaEstadoCensista(eCensista[], int, int, char[])
/// @brief cambia el estado del censista (activo liberado o finalizado)
///
/// @param listCensista
/// @param lenCensista
/// @param idCensista
/// @param estado
/// @return 0 si esta bien o 1 si hay algun error
int cambiaEstadoCensista(eCensista listCensista[], int lenCensista, int idCensista, char estado[]);


/// @fn void censistasHardcode(eCensista[], int, int)
/// @brief hardcodea datos de censistas
///
/// @param list
/// @param length
/// @param cantidad
void censistasHardcode(eCensista list[], int length, int cantidad);

/// @fn void censistasDomiciliosHardcode(eDomicilioCensita[], int, int)
/// @brief hardcodea datos del domicilio del censista
///
/// @param list
/// @param length
/// @param cantidad
void censistasDomiciliosHardcode(eDomicilioCensita list[], int length, int cantidad);

/// @fn void censistasFechasNacimientoHardcode(eFechaNacimientoCensita[], int, int)
/// @brief  harcodea datos de la fecha de nacimiento del censista
///
/// @param list
/// @param length
/// @param cantidad
void censistasFechasNacimientoHardcode(eFechaNacimientoCensita list[], int length, int cantidad);

//int checkFechaNacimientoCensistExists(eFechaNacimientoCensita listFecha[], int lenFecha);
//int checkDomicilioCensistaExists(eDomicilioCensita listDomicilio[], int lenDomicilio);

#endif
