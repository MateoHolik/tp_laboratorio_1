#ifndef REPORTE_H_
#define REPORTE_H_

#include "reporte.h"
#include "censista.h"
#include "datosCenso.h"
#include "zona.h"

#define OCUPADO 1
#define VACIO 0

/// @fn void reporteMostrarCensista(eCensista, int, eFechaNacimientoCensita[], int, eDomicilioCensita[], int, int)
/// @brief
///
/// @param listCensista
/// @param lenCensista
/// @param listFecha
/// @param lenFecha
/// @param listDomicilio
/// @param lenDomicilio
/// @param idCensista
void reporteMostrarCensista(eCensista listCensista, int lenCensista, eFechaNacimientoCensita listFecha[], int lenFecha, eDomicilioCensita listDomicilio[], int lenDomicilio, int idCensista);

/// @fn int reporteListadoCensistas(eCensista[], int, eFechaNacimientoCensita[], int, eDomicilioCensita[], int)
/// @brief
///
/// @param listCensista
/// @param lenCensista
/// @param listFecha
/// @param lenFecha
/// @param listDomicilio
/// @param tamDireccion
/// @return
int reporteListadoCensistas(eCensista listCensista[], int lenCensista, eFechaNacimientoCensita listFecha[], int lenFecha, eDomicilioCensita listDomicilio[], int tamDireccion);

/// @fn int reporteListadoZonas(eZona[], int, eCensista[], int, eLocalidades[], int)
/// @brief
///
/// @param listZona
/// @param lenZona
/// @param listCensista
/// @param lenCensista
/// @param listLocalidades
/// @param lenLocalidades
/// @return

int reporteListadoZonas(eZona listZona[], int lenZona, eCensista listCensista[], int lenCensista, eLocalidades listLocalidades[], int lenLocalidades);

/// @fn void reporteMostrarZona(eZona, eCensista[], int, int, eLocalidades[], int)
/// @brief
///
/// @param listZona
/// @param listCensista
/// @param lenCensista
/// @param idCensista
/// @param listLocalidades
/// @param lenLocalidades
void reporteMostrarZona(eZona listZona, eCensista listCensista[], int lenCensista, int idCensista, eLocalidades listLocalidades[], int lenLocalidades);


#endif /* REPORTE_H_ */
