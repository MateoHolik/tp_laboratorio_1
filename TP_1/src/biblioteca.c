/*
 * Calculo.C
 *
 *  Created on: 5 sep. 2021
 *      Author: mateo
 */
#include "biblioteca.h"

#ifndef CALCULO_C_
#define CALCULO_C_

int CargarNumeroInt(char mensaje[])
{
	char numeroIngresado[16];
	int validacionInt;
	int numeroInt;
	 do
	 {
		 printf("%s", mensaje);
		 fflush(stdin);
		 scanf("%[^\n]", numeroIngresado);
		 validacionInt = ValidarNumeroInt(numeroIngresado);

	 }while(validacionInt==0);

	 numeroInt = atoi(numeroIngresado);

	 return numeroInt;
}

float CargarNumeroFlotante(char mensaje[])
{
		char numeroIngresado[16];
		int validacionFloat;
		float numeroFloat;
		 do
		 {
			 printf("%s", mensaje);
			 fflush(stdin);
			 scanf("%[^\n]", numeroIngresado);
			 validacionFloat = ValidarNumeroFloat(numeroIngresado);

		 }while(validacionFloat==0);

		 numeroFloat = atof(numeroIngresado);

		 return numeroFloat;
}

int ValidarNumeroInt(char numeroIngresado[])
{
	int retorno;
	int i;
	int valida;
	for (i = 0; i < strlen(numeroIngresado); i++)
	        {

	            if (!isdigit(numeroIngresado[i]))
	            {
	            	valida = 1;
	            }


	        }
	if(valida == 1)
	{
		printf("Error, numero no valido \n");
		retorno = 0;
	}
	else
	{
		retorno = 1;
	}
	return retorno;

}

int ValidarNumeroFloat(char numeroIngresado[])
{
	int retorno;
	int i;
	int valida;
	for (i = 0; i < strlen(numeroIngresado); i++)
	        {
	         	 if (!isdigit(numeroIngresado[i]))
	         	 {
	            	valida = 1;
	         	 }
	        }

	if(valida == 1)
	{
		printf("Error, numero no valido \n");
		retorno = 0;
	}
	else
	{
		retorno = 1;
	}
	return retorno;
}

void SumarNumeros (float numeroIngresado1, float numeroIngresado2, float* resultado)
{
	float suma;

	suma = numeroIngresado1 + numeroIngresado2;

	*resultado = suma;
}

void RestarNumeros(float numeroIngresado1, float numeroIngresado2, float* resultado)
{
	float resta;

	resta = numeroIngresado1 - numeroIngresado2;

	*resultado = resta;
}


void MultiplicarNumeros(float numeroIngresado1, float numeroIngresado2, float* resultado)
{
	float multiplicacion;

	multiplicacion = numeroIngresado1 * numeroIngresado2;

	*resultado = multiplicacion;
}

int DividirNumeros(float numeroIngresado1, float numeroIngresado2, float* resultado)
{
	float division;
	int retornoControl;

	if(numeroIngresado2 == 0)
	{
		retornoControl = 1;
	}
	else
	{
		division = numeroIngresado1 / numeroIngresado2;
		retornoControl = 0;
	}

	*resultado = division;

	return retornoControl;
}


void CalcularFactorial(float numeroIngresado, float* resultado)
{
  int i;
  float factorial;

  factorial = 1;

  for (i = numeroIngresado; i > 1; i--)
  {
	factorial = factorial * i;
  }

  *resultado = factorial;
}

#endif /* CALCULO_C_ */
