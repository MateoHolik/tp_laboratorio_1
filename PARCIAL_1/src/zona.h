#ifndef ZONA_H_
#define ZONA_H_

#define TAM_ZONA 20
#define VACIO 0
#define OCUPADO 1
#define TAM_CENSO 100

#define TAM_LOCALIDAD 5

#define EST_ZONA_PENDIENTE "PENDIENTE"
#define EST_ZONA_FINALIZADO "FINALIZADO"

typedef struct
{
    int idZona;
    int idCensista;
    char nombre[51];
    char calle1[51];
    char calle2[51];
    char calle3[51];
    char calle4[51];
    int idLocalidad;
    char estado[51];
    int isEmpty;
}eZona;

typedef struct
{
    int id;
    char nombre[51];
    int isEmpty;
}eLocalidades;


/// @fn int initZona(eZona[], int)
/// @brief esta funcion indica que todas las posiciones del array estan en empty
/// y pone todas las posiciones en TRUE
/// @param listZona
/// @param lenZona
/// @return retorna -1 si hay algun error o 0 si esta bien
int initZona(eZona listZona[], int lenZona);

/// @fn int altaZona(eZona[], int, int, char[], char[], char[], char[], char[], int)
/// @brief genera una nueva zona en espacio con los datos cargados
/// @param listZona
/// @param lenZona
/// @param idZona
/// @param nombre
/// @param calle1
/// @param calle2
/// @param calle3
/// @param calle4
/// @param idLocalidad
/// @return retorna -1 si hay algun error o 0 si esta bien
int altaZona(eZona listZona[], int lenZona, int idZona, char nombre[], char calle1[], char calle2[], char calle3[], char calle4[], int idLocalidad);


/// @fn int mostrarLocalidadesZona(eLocalidades[], int)
/// @brief muestra las loscalidades cargadas
///
/// @param listLocalidad
/// @param lenLocalidad
/// @return -1 en caso que haya salido mal algo o 0 si esta ok
int mostrarLocalidadesZona(eLocalidades listLocalidad[], int lenLocalidad);

/// @fn int mostrarZonas(eZona[], int, eLocalidades[], int)
/// @brief muestra las zonas cargadas
///
/// @param listZona
/// @param lenZona
/// @param listLocalidades
/// @param lenLocalidades
/// @return -1 en caso que haya salido mal algo o 0 si esta ok
int mostrarZonas(eZona listZona[], int lenZona, eLocalidades listLocalidades[], int lenLocalidades);

/// @fn void mostrarZona(eZona, eLocalidades[], int, int)
/// @brief muestra solo una sola zona
///
/// @param listZona
/// @param listLocalidades
/// @param lenLocalidades
/// @param idLocalidad
void mostrarZona(eZona listZona, eLocalidades listLocalidades[], int lenLocalidades, int idLocalidad);

/// @fn int mostrarZonasSinCensista(eZona[], int, eLocalidades[], int)
/// @brief  muestra las zonas que no tienen un censista
///
/// @param listZona
/// @param lenZona
/// @param listLocalidades
/// @param lenLocalidades
/// @return -1 en caso que haya salido mal algo o 0 si esta ok
int mostrarZonasSinCensista(eZona listZona[], int lenZona, eLocalidades listLocalidades[], int lenLocalidades);

/// @fn int mostrarLocalidades(eLocalidades[], int)
/// @brief muestra las localidades
///
/// @param listLocalidad
/// @param lenLocalidad
/// @return -1 en caso que haya salido mal algo o 0 si esta ok
int mostrarLocalidades(eLocalidades listLocalidad[], int lenLocalidad);


/// @fn int buscarZonaId(eZona[], int, int)
/// @brief busca el id de una zona
///
/// @param listZona
/// @param lenZona
/// @param idZona
/// @return retorna i si esta bien o -1 si hay algun error
int buscarZonaId(eZona listZona[], int lenZona, int idZona);

/// @fn int buscarLocalidadId(eLocalidades[], int, int)
/// @brief busca el id de una localidad
///
/// @param listLocalidades
/// @param lenLocalidades
/// @param idLocalidad
/// @return retorna i si esta bien o -1 si hay algun error
int buscarLocalidadId(eLocalidades listLocalidades[], int lenLocalidades, int idLocalidad);


/// @fn int getNuevaZonaId()
/// @brief genera un numero de ID que incrementa +1
///
/// @return retorna el numero de id generado
int getNuevaZonaId();

/// @fn int checkZonaExists(eZona[], int)
/// @brief recorre y busca espacios ocupados
///
/// @param listZona
/// @param lenZona
/// @return retorna 0 si no hay problemas o 1 si ocurrio algun problema
int checkZonaExists(eZona listZona[], int lenZona);


/// @fn int obtenerZonaIndex(eZona[], int)
/// @brief busca la posicion vacia de i  y la retorna
///
/// @param listZona
/// @param lenZona
/// @return retorna i si no hay problemas y -1 si hubo algun error
int obtenerZonaIndex(eZona listZona[], int lenZona);


/// @fn int bajaZona(eZona[], int, int)
/// @brief recorre la lista y le cambia el estado del is.empty a VACIO
///
/// @param listZona
/// @param lenZona
/// @param idZonaBaja
/// @return 0 si esta bien o 1 si hay algun error
int bajaZona(eZona listZona[], int lenZona, int idZonaBaja);


/// @fn int asignarZonaCensista(eZona[], int, int, int)
/// @brief  asigna zona a un censista
///
/// @param listZona
/// @param lenZona
/// @param idZona
/// @param idCensista
/// @return -1 si ocurrio algun problema o 0 si no esta correcto
int asignarZonaCensista(eZona listZona[], int lenZona, int idZona, int idCensista);


/// @fn int cambiaEstadoZona(eZona[], int, int, char[])
/// @brief cambia el estado a la zona (pendiente o finalizada)
///
/// @param listZona
/// @param lenZona
/// @param idZona
/// @param estado
/// @return 0 si esta bien o -1 si hay algun error
int cambiaEstadoZona(eZona listZona[], int lenZona, int idZona, char estado[]);


/// @fn void zonasHardcode(eZona[], int, int)
/// @brief hardcodea los datos de zona
///
/// @param list
/// @param length
/// @param cantidad
void zonasHardcode(eZona list[], int length, int cantidad);

/// @fn void localidadesHardcodeZona(eLocalidades[], int, int)
/// @brief hardcodea los datos de localidades
///
/// @param listLocalidad
/// @param length
/// @param cantidad
void localidadesHardcodeZona(eLocalidades listLocalidad[], int length, int cantidad);
#endif
