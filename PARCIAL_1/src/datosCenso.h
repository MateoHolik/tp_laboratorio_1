#ifndef DATOSCENSO_H_
#define DATOSCENSO_H_

#include "zona.h"
#include "censista.h"

#define VACIO 0
#define OCUPADO 1
#define TAM_CENSO 100


typedef struct
{
    int idCenso;
    int idZona;
    int idCensista;
    int qCensadosInSitu;
    int qCensadosVirtual;
    int qCensadosAusentes;
    int isEmpty;
}eDatosCenso;

/// @fn int initDatoCenso(eDatosCenso[], int)
/// @brief esta funcion indica que todas las posiciones del array estan en empty
/// y pone todas las posiciones en TRUE
///
/// @param listCenso
/// @param lenCenso
/// @return retorna -1 si hay algun error o 0 si esta bien
int initDatoCenso(eDatosCenso listCenso[], int lenCenso);


/// @fn int altaDatoCenso(eDatosCenso[], int, int, int, int, int, int, int)
/// @brief carga con datos del censo cada campo de las estructura
///
/// @param listCenso
/// @param lenCenso
/// @param idCenso
/// @param idZona
/// @param idCensista
/// @param qCensadosInSitu
/// @param qCensadosVirtual
/// @param qCensadosAusentes
/// @return retorna -1 si hay algun error o 0 si esta bien
int altaDatoCenso(eDatosCenso listCenso[], int lenCenso, int idCenso, int idZona, int idCensista, int qCensadosInSitu, int qCensadosVirtual, int qCensadosAusentes);


/// @fn int buscarDatoCensoId(eDatosCenso[], int, int)
/// @brief recorre la lista de censista y busca la posicion en la que esta el id
///
/// @param listCenso
/// @param lenCenso
/// @param idCenso
/// @return retorna i si esta bien o -1 si hay algun error
int buscarDatoCensoId(eDatosCenso listCenso[], int lenCenso, int idCenso);


/// @fn int getNuevoDatoCensoId()
/// @brief genera un numero de ID que incrementa +1
///
/// @return retorna el numero de id generado
int getNuevoDatoCensoId();


/// @fn int checkDatoCensoExists(eDatosCenso[], int)
/// @brief recorre la lista de datos censo y busca que la posicion no este ocupada
///
/// @param listCenso
/// @param lenCenso
/// @return 0 si esta bien o 1 si esta ocupada la posicion
int checkDatoCensoExists(eDatosCenso listCenso[], int lenCenso);


/// @fn int obtenerDatoCensoIndex(eDatosCenso[], int)
/// @brief recorre la lista de dato del censo y retorna la posicion "vacia"
///
/// @param listCenso
/// @param lenCenso
/// @return la posicion d i si esta bien  o -1 si ocurrio un error o algo no salio bien
int obtenerDatoCensoIndex(eDatosCenso listCenso[], int lenCenso);


/// @fn int mostrarCensosPendientes(eZona[], int, eCensista[], int, char[])
/// @brief busca las posiciones ocupadas y las muestra
///
/// @param listZona
/// @param lenZona
/// @param listCensista
/// @param lenCensista
/// @param estado
/// @return 0 si no hubo ningun problema o 1 si hubo algun problema
int mostrarCensosPendientes(eZona listZona[], int lenZona, eCensista listCensista[], int lenCensista, char estado[]);


/// @fn void mostraCensoPendiente(eZona)
/// @brief muestra por pantalla el id de la zona y el nombre
///
/// @param listZona
void mostraCensoPendiente(eZona listZona);

//void zonasHardcode(eZona list[], int length, int cantidad)
#endif
