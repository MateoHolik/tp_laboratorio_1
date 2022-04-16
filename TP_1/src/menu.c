#include "menu.h"
#include "input.h"

int MenuPrincipal()
{
    int opcion;

    opcion = 0;
    system("cls");
    printf("***********************************************************************************************************\n");
    printf("                                    Menu Principal \n");
    printf("***********************************************************************************************************\n");
    printf("1. Ingresar Kilometros \n");
    printf("2. Ingresar Precio de Vuelos \n");
    printf("3. Calcular todos los costos \n");
    printf("4. Informar Resultados \n");
    printf("5. Carga forzada de datos \n");
    printf("6. Salir\n");

    inputNumberInt(&opcion, "Ingrese una opcion: ", "Error, ingrese una opcion: ", 1, 6);

    return opcion;
}

int InformeDeResultados(int inputCantidadKm, float latamPrecioTd, float latamPrecioTc,
						float latamPrecioBtc, float inputLatamPrecio, float latamPrecioKm,
						float aerolineasPrecioTd, float aerolineasPrecioTc, float aerolineasPrecioBtc,
						float inputAerolineasPrecio, float aerolineasPrecioKm , float diferenciaPrecio,
						int banderaPrecio, int banderaPrecioAerolineas, int banderaPrecioLatam)
{
    printf("KMs Ingresados: %d km \n\n", inputCantidadKm);
    printf("Precio Aerolineas: %.2f $  \n", inputAerolineasPrecio);
    printf("a) Precio con tarjeta de debito: $ %.2f \n", aerolineasPrecioTd);
    printf("b) Precio con tarjeta de credito: $ %.2f \n", aerolineasPrecioTc);
    printf("c) Precio pagando con Bitcoin: %.8f BTC \n", aerolineasPrecioBtc);
    printf("d) Mostrar precio unitario: $ %.2f  \n", aerolineasPrecioKm);
    printf("\n");
    printf("Precio Latam: $ %.2f  \n", inputLatamPrecio);
    printf("a) Precio con tarjeta de debito: $ %.2f \n", latamPrecioTd);
    printf("b) Precio con tarjeta de credito: $ %.2f \n", latamPrecioTc);
    printf("c) Precio pagando con Bitcoin: %.8f BTC \n", latamPrecioBtc);
    printf("d) Mostrar precio unitario: $ %.2f  \n\n", latamPrecioKm);
    printf("La diferencia de precio es: $ %.2f \n\n", diferenciaPrecio);

    if (banderaPrecioAerolineas == 0)
    {
		printf("(*) No se ingreso precio de vuelo Aerolineas \n");
    }

    if (banderaPrecioLatam == 0)
    {
    	printf("(*) No se ingreso precio de vuelo Latam \n");
    }

	return 0;
}

int MenuVuelos()
{
    int opcion;

    opcion = 0;
    system("cls");
    printf("***********************************************************************************************************\n");
    printf("                                    Menu Precio Vuelos \n");
    printf("***********************************************************************************************************\n");
    printf("1. Ingresar Precio de Aerolineas \n");
    printf("2. Ingresar Precio de Latam \n");
    printf("3. Volver al menu principal \n");

    inputNumberInt(&opcion, "Ingrese una opcion: ", "Error, ingrese una opcion: ", 1, 3);

    return opcion;
}
