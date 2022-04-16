/*
 ============================================================================
 Name        : TP_1
 Author      : Mateo Holik
 ============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "calculos.h"
#include "input.h"

#define TD_DESCUENTO -10
#define TC_INTERES 25
#define PRECIO_BTC 4524779

#define CANTIDAD_KM 7090
#define AEROLINES_PRECIO 162965
#define LATAM_PRECIO 159339


int main()
{
	setbuf(stdout, NULL);

    int opcionMenu;
    int opcionMenuPrecios;

    float resultadoFloat;
    float diferenciaDePrecio;

    int inputCantidadKm;
    float resultadoPrecioKm;

    float inputAerolineasPrecio = 0;
    float aerolineasPrecioKm = 0;
    float aerolineasPrecioTD = 0;
    float aerolineasPrecioTC = 0;
    float aerolineasPrecioBtc = 0;

    float inputLatamPrecio = 0;
    float latamPrecioKm = 0;
    float latamPrecioTD = 0;
    float latamPrecioTC = 0;
    float latamPrecioBtc = 0;

    float valorCalculoPorcentaje;
    float valorBtc;

    int banderaKm;
    int banderaPrecio;
    int banderaCalculo;
    int banderaPrecioAerolineas = 0;
    int banderaPrecioLatam = 0;

    banderaKm = 0;
    banderaPrecio = 0;
    banderaCalculo = 0;
    inputCantidadKm = 0;
    do
    {
    	opcionMenu = MenuPrincipal();

    	 switch(opcionMenu)
        {

        case 1:
            system("cls");
            printf("***********************************************************************************************************\n");
            printf("                                    Gestion Kilometros \n");
            printf("***********************************************************************************************************\n\n");
            inputNumberInt(&inputCantidadKm, "Ingresar la cantidad de kilómetros [hasta 30.000]: ", "Error, Ingresar la cantidad de kilómetros [hasta 30.000]: ", 0, 30000);

            printf("Ud ingreso %d KM", inputCantidadKm);
            printf("\n");

            banderaKm = 1;

             system("pause");
        break;

        case 2:
        	system("cls");

        	 do
			 {
				 opcionMenuPrecios = MenuVuelos();
				 switch(opcionMenuPrecios)
				 {
					case 1:
						inputNumberFloat(&inputAerolineasPrecio, "Ingrese el precio vuelo Aerolineas [hasta 2.000.000]: ", "Error, Ingrese el precio vuelo Aerolineas [hasta $2.000.000]: ", 1, 2000000 );
						printf("Ud ingreso $ %.2f precio vuelo Aerolineas \n\n", inputAerolineasPrecio);
						banderaPrecioAerolineas = 1;
						banderaPrecio = 1;
						system("pause");
					break;

					case 2:
						inputNumberFloat(&inputLatamPrecio, "Ingrese el precio vuelo Latam [hasta $2.000.000]: ", "Error, Ingrese el precio vuelo Latam [hasta $2.000.000]: ", 1, 2000000 );
						printf("Ud ingreso $ %.2f precio vuelo Latam \n\n", inputLatamPrecio);
						banderaPrecioLatam = 1;
						banderaPrecio = 1;
						system("pause");
					break;
				}
			 }while( opcionMenuPrecios != 3);


/*
        	opcionMenuPrecios = MenuVuelos();

			switch(opcionMenuPrecios)
			{
				case 1:
					inputNumberFloat(&inputAerolineasPrecio, "Ingrese el precio vuelo Aerolineas [hasta 2.000.000]: ", "Error, Ingrese el precio vuelo Aerolineas [hasta $2.000.000]: ", 1, 2000000 );
					printf("Ud ingreso $ %.2f precio vuelo Aerolineas \n", inputAerolineasPrecio);
					banderaPrecioAerolineas = 1;
					banderaPrecio = 1;
				break;

				case 2:
					inputNumberFloat(&inputLatamPrecio, "Ingrese el precio vuelo Latam [hasta $2.000.000]: ", "Error, Ingrese el precio vuelo Latam [hasta $2.000.000]: ", 1, 2000000 );
					printf("Ud ingreso $ %.2f precio vuelo Latam \n", inputLatamPrecio);
					banderaPrecioLatam = 1;
					banderaPrecio = 1;
				break;
			}

                printf("\n");

                system("pause");*/
        break;

        case 3:
            system("cls");

             printf("**********************************************************************************************************\n");
             printf("                                    Calcular Costos \n");
             printf("**********************************************************************************************************\n\n");

			if (banderaKm == 0 && banderaPrecio == 0)
			{
				printf("ERROR KM Y PRECIO NO INGRESADO !!!! \n\n");
			}
			else
			{
				if (banderaKm == 0)
				{
					printf("ERROR KM NO INGRESADO !!!! \n\n");
				}
				else
				{
					if (banderaPrecio == 0)
					{
						printf("ERROR PRECIO NO INGRESADO !!!! \n\n");
					}
					else
					{
						//Latam
						valorCalculoPorcentaje = TD_DESCUENTO;
						CalcularValorPorcentaje(inputLatamPrecio, valorCalculoPorcentaje, &resultadoFloat);
						latamPrecioTD = (inputLatamPrecio + resultadoFloat);

						valorCalculoPorcentaje = TC_INTERES;
						CalcularValorPorcentaje(inputLatamPrecio, valorCalculoPorcentaje, &resultadoFloat);
						latamPrecioTC = (inputLatamPrecio + resultadoFloat);

						valorBtc = PRECIO_BTC;
						CalcularConversionMoneda(valorBtc, inputLatamPrecio, &resultadoFloat);
						latamPrecioBtc = resultadoFloat;

						CalcularPrecioKm(inputCantidadKm, inputLatamPrecio, &resultadoPrecioKm);
						latamPrecioKm = resultadoPrecioKm;

						//Aerolineas
						valorCalculoPorcentaje = TD_DESCUENTO;
						CalcularValorPorcentaje(inputAerolineasPrecio, valorCalculoPorcentaje, &resultadoFloat);
						aerolineasPrecioTD = (inputAerolineasPrecio + resultadoFloat);

						valorCalculoPorcentaje = TC_INTERES;
						CalcularValorPorcentaje(inputAerolineasPrecio, valorCalculoPorcentaje, &resultadoFloat);
						aerolineasPrecioTC = (inputAerolineasPrecio + resultadoFloat);

						valorBtc = PRECIO_BTC;
						CalcularConversionMoneda(valorBtc, inputAerolineasPrecio, &resultadoFloat);
						aerolineasPrecioBtc = resultadoFloat;

						CalcularPrecioKm(inputCantidadKm, inputAerolineasPrecio, &resultadoPrecioKm);
						aerolineasPrecioKm = resultadoPrecioKm;

						if(inputLatamPrecio > inputAerolineasPrecio)
						{
							diferenciaDePrecio = inputLatamPrecio - inputAerolineasPrecio;
						}
						else
						{
							diferenciaDePrecio = inputAerolineasPrecio - inputLatamPrecio;
						}

		                banderaCalculo = 1;

		                if (banderaPrecioAerolineas == 0)
		                {
		            		printf("(*) No se ingreso precio de vuelo Aerolineas \n\n");
		                }

		                if (banderaPrecioLatam == 0)
		                {
		                	printf("(*) No se ingreso precio de vuelo Latam \n\n");
		                }

		                printf("Se procesaron los calculos de costos correctamente!\n\n");

					}
				}
			}
			system("pause");

		break;

        case 4:
            system("cls");
            printf("***********************************************************************************************************\n");
            printf("                                    Informe De Resultados \n");
            printf("***********************************************************************************************************\n");
            printf("\n");

            if(banderaCalculo == 0)
            {
                printf("***********************************************************************************************************\n");
                printf("                                    !!! ERROR !!! \n");
                printf("                                                                                                           \n");
                printf(" Para visualizar los resultados debe ejecutar la opcion 3.(Calcular Costos) \n");
                printf("***********************************************************************************************************\n\n");
            }
            else
            {
            	InformeDeResultados(inputCantidadKm, latamPrecioTD,  latamPrecioTC,
            						latamPrecioBtc,  inputLatamPrecio, latamPrecioKm,
									aerolineasPrecioTD,  aerolineasPrecioTC, aerolineasPrecioBtc,
									inputAerolineasPrecio, aerolineasPrecioKm ,diferenciaDePrecio,
									banderaPrecio, banderaPrecioAerolineas, banderaPrecioLatam);
            }

            system("pause");

        break;

        case 5:

			system("cls");
            system("cls");
            printf("***********************************************************************************************************\n");
            printf("                                    Informe De Resultados - Carga Forzada \n");
            printf("***********************************************************************************************************\n");
            printf("\n");
			inputCantidadKm = CANTIDAD_KM ;
			inputAerolineasPrecio = AEROLINES_PRECIO ;
			inputLatamPrecio =  LATAM_PRECIO ;
			banderaPrecioAerolineas = 1;
			banderaPrecioLatam = 1;

            //Latam
            valorCalculoPorcentaje = TD_DESCUENTO;
            CalcularValorPorcentaje(inputLatamPrecio, valorCalculoPorcentaje, &resultadoFloat);
            latamPrecioTD = (inputLatamPrecio - resultadoFloat);

            valorCalculoPorcentaje = TC_INTERES;
            CalcularValorPorcentaje(inputLatamPrecio, valorCalculoPorcentaje, &resultadoFloat);
            latamPrecioTC = (inputLatamPrecio - resultadoFloat);

            valorBtc = PRECIO_BTC;
            CalcularConversionMoneda(valorBtc, inputLatamPrecio, &resultadoFloat);
            latamPrecioBtc = resultadoFloat;

            CalcularPrecioKm(inputCantidadKm, inputLatamPrecio, &resultadoFloat);
            latamPrecioKm = resultadoFloat;

            //Aerolineas
            valorCalculoPorcentaje = TD_DESCUENTO;
            CalcularValorPorcentaje(inputAerolineasPrecio, valorCalculoPorcentaje, &resultadoFloat);
            aerolineasPrecioTD = (inputAerolineasPrecio + resultadoFloat);

            valorCalculoPorcentaje = TC_INTERES;
            CalcularValorPorcentaje(inputAerolineasPrecio, valorCalculoPorcentaje, &resultadoFloat);
            aerolineasPrecioTC = (inputAerolineasPrecio + resultadoFloat);

            valorBtc = PRECIO_BTC;
            CalcularConversionMoneda(valorBtc, inputAerolineasPrecio, &resultadoFloat);
            aerolineasPrecioBtc = resultadoFloat;

            CalcularPrecioKm(inputCantidadKm, inputAerolineasPrecio, &resultadoFloat);
            aerolineasPrecioKm = resultadoFloat;

            if(inputLatamPrecio > inputAerolineasPrecio)
             {
             	diferenciaDePrecio = inputLatamPrecio - inputAerolineasPrecio;
             }
            else
             {
             	diferenciaDePrecio = inputAerolineasPrecio - inputLatamPrecio;
             }

        	InformeDeResultados(inputCantidadKm, latamPrecioTD, latamPrecioTC,
        						latamPrecioBtc, inputLatamPrecio, latamPrecioKm,
								aerolineasPrecioTD, aerolineasPrecioTC, aerolineasPrecioBtc,
								inputAerolineasPrecio, aerolineasPrecioKm, diferenciaDePrecio,
								banderaPrecio, banderaPrecioAerolineas, banderaPrecioLatam);
        	banderaKm = 0;
        	banderaPrecioAerolineas = 0;
        	banderaPrecioLatam = 0;
        	banderaCalculo = 0;
        	banderaPrecio = 0;

			system("pause");

		break;

        case 6:
        	system("cls");
			printf("Gracias por utilizar T1 \n\n");
			system("pause");
        break;

       }

    }while( opcionMenu != 6);

    return 0;
}
