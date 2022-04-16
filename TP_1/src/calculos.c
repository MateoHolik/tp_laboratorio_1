#include "calculos.h"

int CalcularPrecioKm(int cantidadKm, float precio, float* resultado)
{
	float calculo;

	calculo = precio / cantidadKm;
	*resultado = calculo;

	return 0;
}

int CalcularValorPorcentaje(float precio, float porcentaje, float* resultado)
{
	float calculo;

	calculo = precio * porcentaje / 100;

	 *resultado = calculo;
	return 0;
}

int CalcularConversionMoneda(float precioBtc, float precioIngresado, float* resultado)
{
	float calculo;

	calculo = precioIngresado / precioBtc;

	*resultado = calculo;

	return 0;
}
