#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "censista.h"
#include "zona.h"
#include "reporte.h"

void reporteMostrarCensista(eCensista listCensista, int lenCensista, eFechaNacimientoCensita listFecha[], int lenFecha, eDomicilioCensita listDomicilio[], int lenDomicilio, int idCensista)
{

	int indiceFechaDeNacimiento = 0;
	indiceFechaDeNacimiento = buscarFechaNacimientoCensistaId(listFecha, lenFecha, idCensista);

	int indiceDomicilio = buscarDomicilioCensistaId(listDomicilio, lenDomicilio, idCensista);


		printf("%d         %-10s          %-10s     %10d             %-25s      %-10s    %-10s \n", listCensista.id, listCensista.nombre, listCensista.apellido,
					listCensista.edad, listFecha[indiceFechaDeNacimiento].fechaNacimiento, listDomicilio[indiceDomicilio].direccion,
					listCensista.estado);

}


int reporteListadoCensistas(eCensista listCensista[], int lenCensista, eFechaNacimientoCensita listFecha[], int lenFecha, eDomicilioCensita listDomicilio[], int tamDireccion)
{
    int i;
    int retorno=-1;


    printf("*****************************************************************************************************************************\n");
    printf("* ID         Nombre              Apellido              Edad            Fecha De Nacimiento            Direccion     Estado  *\n");
    printf("*****************************************************************************************************************************\n");

    for(i=0; i < lenCensista; i++)
    {
    	if(listCensista[i].isEmpty == OCUPADO)
        {
    		reporteMostrarCensista(listCensista[i], lenCensista, listFecha, lenFecha, listDomicilio, tamDireccion, listCensista[i].id);
            retorno=0;
        }
    }

    return retorno;

}


int reporteListadoZonas(eZona listZona[], int lenZona, eCensista listCensista[], int lenCensista, eLocalidades listLocalidades[], int lenLocalidades)
{
    int i;
    int retorno=-1;

    printf("*************************************************************************************************************************************************\n");
    printf("*Id Zona    Nombre      calle 1        calle 2        calle 3         calle 4          Localidad            ID       Apellido           Nombre  * \n");
    printf("*************************************************************************************************************************************************\n");

    for(i=0; i < lenZona; i++)
    {
    	if(listZona[i].isEmpty == OCUPADO)
        {
    		reporteMostrarZona(listZona[i], listCensista, lenCensista, listZona[i].idCensista, listLocalidades, lenLocalidades);
            retorno=0;
        }
    }

    return retorno;
}


void reporteMostrarZona(eZona listZona, eCensista listCensista[], int lenCensista, int idCensista, eLocalidades listLocalidades[], int lenLocalidades)
{
	int indiceCensista = 0;
	char apellido[51];
	char nombre[51];

	int idLocalidad = listZona.idLocalidad;
	int indiceLocalidades = buscarLocalidadId(listLocalidades, lenLocalidades, idLocalidad);

	indiceCensista = buscarCensistaId(listCensista, lenCensista, idCensista);

	// controla que sea 0 el id asi lo coloca en (sin asignar)
	if (idCensista == 0)
	{
		strcpy(apellido, "Sin asignar");
		strcpy(nombre, "");
	}
	else
	{
		//Funcion strcpy variable de destino, le coloca la variable origen (char)
		strcpy(apellido, listCensista[indiceCensista].apellido);
		strcpy(nombre, listCensista[indiceCensista].nombre);

	}

		printf("%0d   	    %-10s  %-10s     %-10s     %-10s      %-10s   %5d - %-10s      %-5d     %-15s    %-15s \n",
				listZona.idZona, listZona.nombre, listZona.calle1,  listZona.calle2,
				listZona.calle3, listZona.calle4, listZona.idLocalidad, listLocalidades[indiceLocalidades].nombre, listZona.idCensista,
				apellido, nombre);
}





//d
int reporteCensistaMasCenso(eDatosCenso listaDatos[], int lenDatos, eCensista listaCensista[], int lenCensista, eZona listaZonas[], int lenZonas)
{
	  int banderaMasCantidad;
	  int ZonaMasCantidad;
	  int indiceZona = 0;
	  banderaMasCantidad = 0;

	  // Informar el censista cuya zona fue la más censada (total censados presencial y virtual)

	  for (int i = 0; i < lenDatos; i++)
	  {
	      if ((listaDatos[i].idZona> ZonaMasCantidad || banderaMasCantidad == 0))
	      {
	    	 ZonaMasCantidad = listaDatos[i].idZona;
	    	 banderaMasCantidad = banderaMasCantidad + (listaDatos[i].qCensadosInSitu + listaDatos[i].qCensadosVirtual);
		}
	  }


	  if (banderaMasCantidad == 0)
	  {
		  printf("No hay datos");
	  }
	  else
	  {
		    for(int j=0; j < lenDatos; j++)
		    {
		    	if(listaDatos[j].isEmpty == OCUPADO && listaDatos[j].idZona == ZonaMasCantidad)
		        {

		    		indiceZona = buscarZonaId(listaZonas, lenZonas, listaDatos[j].idZona);
		        	printf("El censista %s tuvo la zona de %s como la mas censada de  \n", listaCensista[j].apellido, listaZonas[indiceZona].nombre);
		        	break;
		        }
		    }

	  }
	  return banderaMasCantidad;
}



//c
int reporteLocalidadMasCasasAusetes (eDatosCenso listaDatos[], int lenDatos, eLocalidades listaLocalidades[], int lenLocalidades, eZona listaZonas[], int lenZonas)
{
	  int banderaMasCantidad;
	  int ZonaMasCantidad;

	  banderaMasCantidad = 0;

	  for (int i = 0; i < lenDatos; i++)
	  {
	      if ((listaDatos[i].idZona> ZonaMasCantidad || banderaMasCantidad == 0))
	      {
	    	 ZonaMasCantidad = listaDatos[i].idZona;
	    	 banderaMasCantidad = banderaMasCantidad + listaDatos[i].qCensadosAusentes;
		}
	  }


	  if (banderaMasCantidad == 0)
	  {
		  printf("No hay datos\n");
	  }
	  else
	  {
		    for(int j=0; j < lenDatos; j++)
		    {
		    	if(listaDatos[j].isEmpty == OCUPADO && listaDatos[j].idZona == ZonaMasCantidad)
		        {

		        	printf("Zona con mas ausentes %s  \n", listaZonas[j].nombre);
		        	break;
		        }
		    }

	  }
	  return banderaMasCantidad;
}


//a
int reporteCensistaActivoZonaPendiente(eCensista listaCensista[], int lenCensista, eZona listaZonas[], int lenZonas)
{
	  int cantidadCensista;
	  int retorno = -1;
	  cantidadCensista = 0;

	  for(int i=0; i< lenZonas; i++)
	     {
	         if(strcmp(listaZonas[i].estado, EST_ZONA_PENDIENTE) == 0)
	         {
	             for (int k = 0; i < lenCensista; k++)
	             {
	                 if(listaCensista[k].id == listaZonas[i].idCensista && strcmp(listaCensista[k].estado, EST_CENSISTA_ACTIVO) == 0)
	                 {
	                	 cantidadCensista++;
	                 }
	             }
	             retorno = 0;
	         }
	     }
	  printf("cantidad de censistas en estado Activo con zona Pendiente %d  \n", cantidadCensista);
	  return retorno;
}



//e
/*int informarPromedio(eDatosCenso listDatosCenso[], int lenDatosCenso, eZona listZona[], int lenZona)
{
	int retorno = -1;
	int contadorZona= 0;
	float promedio = 0;
	int acumulador;

	// 500(P /10(z


       if (acumulador > 0)
             {
             	promedio = acumulador / contadorZona;
         		printf("Promedio  de censoses %.2f \n ",  promedio);
         		retorno = 0;
             }

         }
    return retorno;

}*/






