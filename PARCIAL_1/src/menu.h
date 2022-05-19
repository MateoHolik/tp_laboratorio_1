
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "censista.h"
#include "zona.h"
#include "datosCenso.h"
#include "reporte.h"
#include <string.h>
#include <ctype.h>

/// @fn int menuPrincipal()
/// @brief miestra el menu principal
///
/// @return la opcion ingresada por el usuario
int menuPrincipal();

/// @fn int menuCensista(eCensista*, int, eFechaNacimientoCensita*, int, eDomicilioCensita*, int)
/// @brief da de alta, modifica y baja a los censistas
///
/// @param listCensista
/// @param lenCensista
/// @param listFechaNacimiento
/// @param lenFechaNicimientoCensista
/// @param listDomicilio
/// @param lenDomicilioCensista
/// @return 0 en caso de que este correcto o 1 si hay algun error
int menuCensista(eCensista* listCensista, int lenCensista, eFechaNacimientoCensita* listFechaNacimiento, int lenFechaNicimientoCensista, eDomicilioCensita* listDomicilio, int lenDomicilioCensista);

/// @fn int menuZonas(eZona*, int, eLocalidades*, int, eCensista*, int)
/// @brief da de alta, modifica y baja a las zonas
///
/// @param listZona
/// @param lenZona
/// @param listLocalidad
/// @param lenLocalidad
/// @param listCensista
/// @param lenCensista
/// @return 0 en caso de que este correcto o 1 si hay algun error
int menuZonas(eZona* listZona, int lenZona, eLocalidades* listLocalidad, int lenLocalidad, eCensista* listCensista, int lenCensista);

/// @fn int menuModificacionCensista()
/// @brief muestra las opciones de modificacion del censista
///
/// @return devuelve la opcion seleccionada por el usuario
int menuModificacionCensista();

/// @fn int menuModificacionZonas()
/// @brief muestra las opciones de modificacion de zonas
///
/// @return retorna la opcion seleccionada por el usuario
int menuModificacionZonas();

/// @fn int menuReportes(eCensista[], int, eZona[], int, eDomicilioCensita[], int, eFechaNacimientoCensita[], int, eDatosCenso[], int, eLocalidades[], int)
/// @brief  muestra las opciones de reportes y
/// le pide al usuario que seleccione a cual desea integrar
///
/// @param listCensista
/// @param lenCensista
/// @param listZona
/// @param lenZona
/// @param listDomicilioCensista
/// @param lenDomicilioCensista
/// @param listFechaNacimientoCensista
/// @param lenFecNacimientoCensista
/// @param listDatosCenso
/// @param tamDatosCenso
/// @param listLocalidades
/// @param lenLocalidades
/// @return retorna 0 en caso que este correcto
int menuReportes(eCensista listCensista[], int lenCensista , eZona listZona[], int lenZona,
					eDomicilioCensita listDomicilioCensista[], int lenDomicilioCensista,
					eFechaNacimientoCensita listFechaNacimientoCensista[], int lenFecNacimientoCensista,
					eDatosCenso listDatosCenso[], int tamDatosCenso, eLocalidades listLocalidades[], int lenLocalidades);
#endif /* MENU_H_ */
