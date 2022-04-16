#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/// @fn int menuPrincipal()
/// @brief imprime por pantalla el menu principal de opciones
///
/// @return retorna la opcion seleccionada por el usuario
int MenuPrincipal();

/// @fn int InformeDeResultados(int, float, float, float, float, float, float, float, float, float, float, float)
/// @brief Imprime por pantalla todos los reslutados del programa
///
/// @param inputCantidadKm
/// @param latamPrecioTd
/// @param latamPrecioTc
/// @param latamPrecioBtc
/// @param inputLatamPrecio
/// @param latamPrecioKm
/// @param aerolineasPrecioTd
/// @param aerolineasPrecioTc
/// @param aerolineasPrecioBtc
/// @param inputAerolineasPrecio
/// @param aerolineasPrecioKm
/// @param diferenciaPrecio
int InformeDeResultados(int inputCantidadKm, float latamPrecioTd, float latamPrecioTc, float latamPrecioBtc, float inputLatamPrecio,
						float latamPrecioKm,float aerolineasPrecioTd, float aerolineasPrecioTc,
						float aerolineasPrecioBtc,float inputAerolineasPrecio,float aerolineasPrecioKm,
						float diferenciaPrecio,int banderaPrecio, int banderaPrecioAerolineas, int banderaPrecioLatam);

/// @fn int MenuVuelos()
/// @brief la funcion se encarga de imprimir el submenu de opciones e indicar que opcion fue la aplicada
///
/// @return retorna la opcion ingresada
int MenuVuelos();

#endif /* MENU_H_ */
