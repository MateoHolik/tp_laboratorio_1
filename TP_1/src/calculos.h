#ifndef CALCULOS_H_
#define CALCULOS_H_

/// @fn int CalcularPrecioKm(int, float, float*)
/// @brief calcula el precio del kilometro
///
/// @param
/// @param
/// @param
/// @return retorna el valor por puntero
int CalcularPrecioKm(int , float , float*);

/// @fn int CalcularValorPorcentaje(float, float, float*)
/// @brief calcula el porcentaje(tarjeta de credito/debito) del valor ingresado
///
/// @param precio
/// @param porcentaje
/// @param resultado
/// @return retorna el valor por puntero
int CalcularValorPorcentaje(float precio, float porcentaje, float* resultado);

/// @fn int CalcularConversionMoneda(float, float, float*)
/// @brief tranforma el valor ingresado al precio del bitcoin
///
/// @param precioBtc
/// @param precioIngresado
/// @param resultado
/// @return retorna el valor en bitcoins por puntero
int CalcularConversionMoneda(float precioBtc, float precioIngresado, float* resultado);

#endif /* CALCULOS_H_ */
