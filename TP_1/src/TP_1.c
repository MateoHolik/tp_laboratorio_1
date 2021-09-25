/*
 ============================================================================
 Name        : Trabajo practico numero 1
 Author      : Mateo Ezequiel Holik
 Division	 : F
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "biblioteca.h"

int main(void)
{
	setbuf(stdout, NULL);

	int opcion;

	float numeroIngresado1;
	float numeroIngresado2;

	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
	float resultadoDivision;
	float resultadoFactorial1;
	float resultadoFactorial2;

	int retornoControlDivision;

	char calculos;
	numeroIngresado1 = 0;
	numeroIngresado2 = 0;
	do
	{
		printf("1. Ingresar 1er operando %.2lf\n", numeroIngresado1);

		printf("2. Ingresar 2do operando %.2lf \n", numeroIngresado2);

		printf("3. Calcular todas las operaciones \n");
		printf("	a) Calcular la suma (A+B)\n");
		printf("	b) Calcular la resta (A-B)\n");
		printf("	c) Calcular la division (A/B)\n");
		printf("	d) Calcular la multiplicacion (A*B)\n");
		printf("	e) Calcular el factorial (A!)\n");

		printf("4. Informar resultados \n");

		printf("5. Salir \n");

		opcion = CargarNumeroInt("Ingrese una opcion del menu: \n");

		system("cls");


		switch(opcion)
		{
			case 1:
				numeroIngresado1 = CargarNumeroFlotante("Ingrese el primer operando: \n");
				system("cls");
			break;

			case 2:
				numeroIngresado2 = CargarNumeroFlotante("Ingrese el 2do operando: ");
				system("cls");

			break;

			case 3:
				printf("Ingrese la operacion que desea realizar: ");

				scanf("%c", &calculos);

				if(numeroIngresado1 == 0 && numeroIngresado2 == 0)
				{
					printf("Error, no se ingresaron valores\n");
					system("cls");
				}
				else
				{
					SumarNumeros(numeroIngresado1, numeroIngresado2, &resultadoSuma);

					RestarNumeros(numeroIngresado1, numeroIngresado2, &resultadoResta);

					MultiplicarNumeros(numeroIngresado1, numeroIngresado2,&resultadoMultiplicacion);

					retornoControlDivision = DividirNumeros(numeroIngresado1, numeroIngresado2, &resultadoDivision);

					CalcularFactorial(numeroIngresado1, &resultadoFactorial1);

					CalcularFactorial(numeroIngresado2, &resultadoFactorial2 );
					system("cls");
					printf("\n********************\n");
					printf("Se realizaron los calculos");
					printf("\n********************\n");


				}

			break;

			case 4:
				system("cls");
				if(numeroIngresado1 == 0 && numeroIngresado2 == 0)
				{
					printf("Error, no se ingresaron valores\n");
				}
				else
				{
					printf("\n********************\n");
					printf("Suma %.2lf \n", resultadoSuma);
					printf("Resta %.2lf \n", resultadoResta);
					printf("Multiplicacion %.2lf \n", resultadoMultiplicacion);

					if (retornoControlDivision == 0)
					{
						printf("Division %.2lf \n", resultadoDivision);

					}
					else
					{
						printf("Error, no se puede dividir por 0 \n\n");

					}

					printf("Factorial del primer numero ingresado:  %.2lf \n", resultadoFactorial1);
					printf("Factorial del segundo numero ingresado: %.2lf \n", resultadoFactorial2);
}					printf("\n********************\n");

			break;

			case 5:
				system("cls");
				printf("Gracias por elegirnos como su calculadora. \n\n");
			break;
		}

	}while(opcion != 5);

	return EXIT_SUCCESS;
}
