#include "menu.h"
#include "censista.h"
#include "datosCenso.h"

int flagAltaCensista;

int menuPrincipal()
{
    int opcion;

    system("cls");
    printf("***********************************************************************************************************\n");
    printf("                                    Menu Principal \n");
    printf("***********************************************************************************************************\n");
    printf("1) ABM DE CENSISTA \n");
    printf("2) GESTION DE ZONAS \n");
    printf("3) COMPLETAR DATOS DEL CENSO \n");
    printf("4) REPORTES \n");
    printf("5) SALIR \n");

    inputNumberInt(&opcion, "Ingrese una opcion: ", "Error, ingrese una opcion: ", 1, 5);

    return opcion;
}


int menuCensista(eCensista* listCensista, int lenCensista, eFechaNacimientoCensita* listFechaNacimiento, int lenFechaNicimientoCensista, eDomicilioCensita* listDomicilio, int lenDomicilioCensista)
{
    int validation=0;
    int opcionMenu = 0;
    int idModificar;
    char checkContinuar;
    int opcionModificacion;
    int indiceAux=0;
    int idBaja;

    int idCensista;
    int idDomicilioCensista;
    int idFechaNacimientoCensista;

    eCensista censistaAux;
    eDomicilioCensita domicilioCensistaAux;
    eFechaNacimientoCensita fechaNacimientoCensistaAux;

    flagAltaCensista = 1;
    printf("***********************************************************************************************************\n");
    printf("*                                   Menu ABM Censista                                                     *\n");
    printf("***********************************************************************************************************\n");
    printf("1- Alta de Censista \n");
    printf("2- Modificar Censista\n");
    printf("3- Baja de Censista \n");
    printf("4- Volver al Menu Principal \n");

    inputNumberInt(&opcionMenu, "Ingrese una opcion: ", "Error, ingrese una opcion: ", 1, 4);

    switch(opcionMenu)
    {
    	case 1:
    		 	system("cls");


    		 	printf("***********************************************************************************************************\n");
                printf("                                    Alta de Censista \n");
                printf("***********************************************************************************************************\n");
                inputString(censistaAux.nombre, "Ingrese el nombre: ","Error, vuelva a ingresa el Nombre:", 1, 51);
                inputString(censistaAux.apellido, "Ingrese el Apellido: ","Error, vuelva a ingresa el Apellido:", 1, 51);
                inputNumberInt(&censistaAux.edad, "Ingrese la Edad: ","Error, vuelva a ingresa la Edad:", 1, 99);
                inputStringAlpha(fechaNacimientoCensistaAux.fechaNacimiento, "Ingrese la fecha Nacimiento (dd/mm/yyyy) : ","Error, vuelva a ingresa la fecha Nacimiento  (dd/mm/yyyy) :", 1, 11);
                inputStringAlpha(domicilioCensistaAux.direccion, "Ingrese el domicilio: ","Error, vuelva a ingresa el domicilio:", 1, 51);

                idCensista = getNuevoCensistaId();

                 if (altaCensista(listCensista, lenCensista, idCensista,censistaAux.nombre, censistaAux.apellido, censistaAux.edad, EST_CENSISTA_LIBERADO )==0)
                 {
                    idDomicilioCensista = getNuevoDomicilioCensistaId();
                    idFechaNacimientoCensista = getNuevoFechaNacimientoCensistaId();

                    altaCensistaFechaNacimiento(listFechaNacimiento, TAM_CENSISTA, idFechaNacimientoCensista, idCensista, fechaNacimientoCensistaAux.fechaNacimiento);
                    altaDomicilioCensita(listDomicilio, TAM_CENSISTA, idDomicilioCensista, idCensista, domicilioCensistaAux.direccion);

                    mostrarCensistas(listCensista, TAM_CENSISTA, listFechaNacimiento, TAM_CENSISTA, listDomicilio, TAM_CENSISTA);

					printf("\n");
                	printf(" cargado con exito.\n\n");
					printf("El ID del censista es: %d \n\n", idCensista);
					flagAltaCensista = 1;
                 }

           system("pause");
        break;
    	case 2:
    		system("cls");
    		if(checkCensistaExists(listCensista, lenCensista)==0)
				{
					printf("Error ! Modificacion del censista, no hay clientes cargados.\n");
					system("pause");
					break;
				}
				else
				{
					system("cls");
					printf("**********************************************************************************************************************\n");
					printf("*                                   Menu Modificacion de Censista                                                    *\n");

					mostrarCensistas(listCensista, TAM_CENSISTA, listFechaNacimiento, TAM_CENSISTA, listDomicilio, TAM_CENSISTA);

					printf("\n");
					inputNumberInt(&idModificar, "Ingrese el ID del censista a modificar: ", "Error, Ingrese el ID del censista a modificar: ", 1000, 2000);

					indiceAux = buscarCensistaId(listCensista, lenCensista, idModificar);

					if(indiceAux==-1)
					{
						printf("El ID del censista no existe.\n");
						system("pause");
					}
					else
					{
						system("cls");

					    printf("***********************************************************************************************************************\n");
					    printf("* ID         Nombre              Apellido              Edad            Fecha De Nacimiento            Direccion       *\n");
					    printf("***********************************************************************************************************************\n");

						mostrarCensista(listCensista[indiceAux], TAM_CENSISTA, listFechaNacimiento, TAM_CENSISTA, listDomicilio, TAM_CENSISTA, idModificar);
						printf("\n\n");
						printf("Confirme si el censista seleccionado es el que desea modificar:\n\n");

						checkContinuar = checkContinue();

						if(checkContinuar=='S')
						{
							system("cls");

							printf("\n\n");
							opcionModificacion = menuModificacionCensista();
							switch(opcionModificacion)
							{

							case 1:

								inputString(listCensista[indiceAux].nombre, "Ingrese nombre: ","Error, vuelva a ingresar el nombre:", 1, 51);

								printf("Nombre modificado con exito \n");
							    printf("***********************************************************************************************************************\n");
							    printf("* ID         Nombre              Apellido              Edad            Fecha De Nacimiento            Direccion       *\n");
							    printf("***********************************************************************************************************************\n");

								mostrarCensista(listCensista[indiceAux], TAM_CENSISTA, listFechaNacimiento, TAM_CENSISTA, listDomicilio, TAM_CENSISTA, idModificar);
							break;

							case 2:

								inputString(listCensista[indiceAux].apellido, "Ingrese apellido: ","Error, vuelva a ingresar el apellido:", 1, 51);


								printf("Apellido modificado con exito \n");
							    printf("***********************************************************************************************************************\n");
							    printf("* ID         Nombre              Apellido              Edad            Fecha De Nacimiento            Direccion       *\n");
							    printf("***********************************************************************************************************************\n");

								mostrarCensista(listCensista[indiceAux], TAM_CENSISTA, listFechaNacimiento, TAM_CENSISTA, listDomicilio, TAM_CENSISTA, idModificar);
							break;

							case 3:

								inputNumberInt(&listCensista[indiceAux].edad, "Ingrese la edad: ","Error, vuelva a ingresa la edad:", 1, 99);

								printf("Edad modificada con exito\n");
							    printf("***********************************************************************************************************************\n");
							    printf("* ID         Nombre              Apellido              Edad            Fecha De Nacimiento            Direccion       *\n");
							    printf("***********************************************************************************************************************\n");

								mostrarCensista(listCensista[indiceAux], TAM_CENSISTA, listFechaNacimiento, TAM_CENSISTA, listDomicilio, TAM_CENSISTA, idModificar);
							break;
							case 4:

								inputStringAlpha(listFechaNacimiento[indiceAux].fechaNacimiento, "Ingrese la fecha de nacimiento: ","Error, vuelva a ingresa fecha de nacimiento:", 1, 11);

								printf("Fecha de nacimiento modificada con exito\n");
							    printf("***********************************************************************************************************************\n");
							    printf("* ID         Nombre              Apellido              Edad            Fecha De Nacimiento            Direccion       *\n");
							    printf("***********************************************************************************************************************\n");

								mostrarCensista(listCensista[indiceAux], TAM_CENSISTA, listFechaNacimiento, TAM_CENSISTA, listDomicilio, TAM_CENSISTA, idModificar);
							break;
							case 5:
								inputStringAlpha(listDomicilio[indiceAux].direccion, "Ingrese la Direccion: ","Error, vuelva a ingresa la Direccion:", 1, 100);

								printf("Direccion modificada con exito\n");
							    printf("***********************************************************************************************************************\n");
							    printf("* ID         Nombre              Apellido              Edad            Fecha De Nacimiento            Direccion       *\n");
							    printf("***********************************************************************************************************************\n");

								mostrarCensista(listCensista[indiceAux], TAM_CENSISTA, listFechaNacimiento, TAM_CENSISTA, listDomicilio, TAM_CENSISTA, idModificar);
							break;

							case 6:
					    		system("cls");
					    	menuPrincipal();
							}
						}
						else
						{
							break;
						}

					}
				}
				system("pause");

    	break;
    	case 3:
    	{
    		system("cls");

    		if(checkCensistaExists(listCensista, lenCensista)==0)
			{
				printf("Error! Baja de Censistas, no hay Censistas cargados.\n");
				system("pause");
				break;
			}
			else
			{
				printf("**********************************************************************************************************************\n");
				printf("*                             	           Menu Baja de Censistas 													 *\n");

				mostrarCensistas(listCensista, TAM_CENSISTA, listFechaNacimiento, TAM_CENSISTA, listDomicilio, TAM_CENSISTA);
				printf("\n");
				inputNumberInt(&idBaja, "Ingrese el ID del Censistas a dar de baja: ", "Error, Ingrese el ID del Censistas a dar de baja: ", 1000, 2000);

				indiceAux = buscarCensistaId(listCensista, lenCensista, idBaja);

				if(indiceAux==-1)
				{
					printf("El ID de Censistas no existe\n");

				}
				else
				{
					//mostrarCensista(listCensista[indiceAux], lenCensista, listFechaNacimiento, lenCensista, listDomicilio, lenCensista, idBaja);

				    printf("***********************************************************************************************************************\n");
				    printf("* ID         Nombre              Apellido              Edad            Fecha De Nacimiento            Direccion       *\n");
				    printf("***********************************************************************************************************************\n");

					mostrarCensista(listCensista[indiceAux], lenCensista, listFechaNacimiento, lenCensista, listDomicilio, lenCensista, idBaja);

					printf("Este Censista se dara de baja de forma permanente? \n");
					checkContinuar=checkContinue();
					if(checkContinuar=='S')
					{
						//if(bajaCensista(listCensista, lenCensista, idBaja)==-1)
						if (cambiaEstadoCensista(listCensista, lenCensista, idBaja, EST_CENSISTA_INACTIVO) == -1)
						{
							printf("No se pudo realizar la baja del Censista .\n");
						}
						else
						{
							printf("La baja del Censistas se realizo correctamente.\n");
						}
					}
					else
					{
						printf("Baja del cliente se cancelo.\n");
						system("pause");
						break;
					}
				}
			}

			system("pause");
			break;
    	}

    	case 4:
    		system("cls");
    		menuPrincipal();
    }

    return validation;
}


int menuZonas(eZona* listZona, int lenZona, eLocalidades* listLocalidades, int lenLocalidades, eCensista* listCensista, int lenCensista)
{

    int validation=0;
    int opcionMenu = 0;
    int idModificar;
    char checkContinuar;
    int opcionModificacion;
    int indiceAux=0;
    int idBaja;
    int idCensista;

    int idZona;

    eZona zonaAux;

    flagAltaCensista = 1;
    printf("***********************************************************************************************************\n");
    printf("*                                   Menu ABM ZONA                                                         *\n");
    printf("***********************************************************************************************************\n");
    printf("1- Alta de Zona \n");
    printf("2- Modificar Zona\n");
    printf("3- Baja de Zona \n");
    printf("4- Asignacion de Zona \n");
    printf("5- Volver al Menu Principal \n");

    inputNumberInt(&opcionMenu, "Ingrese una opcion: ", "Error, ingrese una opcion: ", 1, 5);


    switch(opcionMenu)
    {
    	case 1:
    		 	system("cls");

    		 	printf("***********************************************************************************************************\n");
                printf("*                                    Alta de ZONA                                                         *\n");
                printf("***********************************************************************************************************\n");
                inputStringAlpha(zonaAux.nombre, "Ingrese el nombre de la Zona: ","Error, Ingrese el nombre de la Zona:", 1, 51);
                inputStringAlpha(zonaAux.calle1, "Ingrese el nombre de la Calle 1: ","Error, Ingrese el nombre de la Calle 1:", 1, 51);
                inputStringAlpha(zonaAux.calle2, "Ingrese el nombre de la Calle 2: ","Error, Ingrese el nombre de la Calle 2:", 1, 51);
                inputStringAlpha(zonaAux.calle3, "Ingrese el nombre de la Calle 3: ","Error, Ingrese el nombre de la Calle 3:", 1, 51);
                inputStringAlpha(zonaAux.calle4, "Ingrese el nombre de la Calle 4: ","Error, Ingrese el nombre de la Calle 4:", 1, 51);

                mostrarLocalidades(listLocalidades, lenLocalidades);


                inputNumberInt(&zonaAux.idLocalidad, "Ingrese la localidad: ","Error, vuelva a ingresa la localidad:", 1, 5);

                idZona = getNuevaZonaId();

                if( altaZona(listZona, lenZona, idZona, zonaAux.nombre,  zonaAux.calle1,  zonaAux.calle2,  zonaAux.calle3, zonaAux.calle4,  zonaAux.idLocalidad)==0)
                 {
                    mostrarZonas(listZona, lenZona, listLocalidades, lenLocalidades);

					printf("\n");
                	printf("Zona cargada con exito.\n\n");
					printf("El ID de la zona es: %d \n\n", idZona);
					flagAltaCensista = 1;
                 }

                 system("pause");
        break;


    	case 2:
    		system("cls");
    		if(checkZonaExists(listZona, lenZona)==0)
				{
					printf("Error ! Modificacion de la zona, no hay zona cargadas.\n");
					system("pause");
					break;
				}
				else
				{
					system("cls");
					printf("***********************************************************************************************************\n");
					printf("*                                   Menu Modificacion de Zona                                             *\n");


					mostrarZonas(listZona, lenZona, listLocalidades, lenLocalidades);


					printf("\n");
					inputNumberInt(&idModificar, "Ingrese el ID de la zona a modificar: ", "Error, Ingrese el ID de la zona a modificar: ", 1, 8);


					indiceAux = buscarZonaId(listZona, lenZona, idModificar);

					if(indiceAux==-1)
					{
						printf("El ID de la zona no existe.\n");
						system("pause");
					}
					else
					{
						system("cls");

					    printf("****************************************************************************************************************\n");
					    printf("*Id Zona   Nombre           calle 1        calle 2        calle 3         calle 4          Localidad           * \n");
					    printf("****************************************************************************************************************\n");

						mostrarZona(listZona[indiceAux], listLocalidades, lenLocalidades, listZona[indiceAux].idLocalidad);

						printf("\n\n");
						printf("Confirme si la zona seleccionada es el que desea modificar:\n\n");

						checkContinuar = checkContinue();

						if(checkContinuar=='S')
						{
							system("cls");
						    printf("****************************************************************************************************************\n");
						    printf("*Id Zona   Nombre           calle 1        calle 2        calle 3         calle 4          Localidad           * \n");
						    printf("****************************************************************************************************************\n");

						    mostrarZona(listZona[indiceAux], listLocalidades, lenLocalidades, listZona[indiceAux].idLocalidad);

							printf("\n\n");
							opcionModificacion = menuModificacionZonas();
							switch(opcionModificacion)
							{

							case 1:
								inputStringAlpha(listZona[indiceAux].nombre, "Ingrese nombre: ","Error, vuelva a ingresar el nombre:", 1, 51);

								printf("Nombre modificado con exito \n");
							    printf("****************************************************************************************************************\n");
							    printf("*Id Zona   Nombre           calle 1        calle 2        calle 3         calle 4          Localidad           * \n");
							    printf("****************************************************************************************************************\n");

							    mostrarZona(listZona[indiceAux], listLocalidades, lenLocalidades, listZona[indiceAux].idLocalidad);
							break;

							case 2:

								inputStringAlpha(listZona[indiceAux].calle1, "Ingrese la calle 1: ","Error, vuelva a ingresar la calle 1:", 1, 51);

								printf("Calle 1 modificado con exito \n");
							    printf("****************************************************************************************************************\n");
							    printf("*Id Zona   Nombre           calle 1        calle 2        calle 3         calle 4          Localidad           * \n");
							    printf("****************************************************************************************************************\n");

							    mostrarZona(listZona[indiceAux], listLocalidades, lenLocalidades, listZona[indiceAux].idLocalidad);
							break;

							case 3:

								inputStringAlpha(listZona[indiceAux].calle2, "Ingrese la calle 2: ","Error, vuelva a ingresar la calle 2:", 1, 51);

							    printf("****************************************************************************************************************\n");
							    printf("*Id Zona   Nombre           calle 1        calle 2        calle 3         calle 4          Localidad           * \n");
							    printf("****************************************************************************************************************\n");

							    mostrarZona(listZona[indiceAux], listLocalidades, lenLocalidades, listZona[indiceAux].idLocalidad);
								printf("Calle 2 modificada con exito \n");
							break;
							case 4:

								inputStringAlpha(listZona[indiceAux].calle3, "Ingrese la calle 3: ","Error, vuelva a ingresar la calle 3:", 1, 51);

							    printf("****************************************************************************************************************\n");
							    printf("*Id Zona   Nombre           calle 1        calle 2        calle 3         calle 4          Localidad           * \n");
							    printf("****************************************************************************************************************\n");

							    mostrarZona(listZona[indiceAux], listLocalidades, lenLocalidades, listZona[indiceAux].idLocalidad);
								printf("Calle 3 modificada con exito \n");
							break;
							case 5:

								inputStringAlpha(listZona[indiceAux].calle4, "Ingrese la calle 4: ","Error, vuelva a ingresar la calle 4:", 1, 51);

							    printf("****************************************************************************************************************\n");
							    printf("*Id Zona   Nombre           calle 1        calle 2        calle 3         calle 4          Localidad           * \n");
							    printf("****************************************************************************************************************\n");

								mostrarZona(listZona[indiceAux], listLocalidades, lenLocalidades, listZona[indiceAux].idLocalidad);
								printf("Calle 4 modificada con exito \n");
							break;
							case 6:
					    		system("cls");
					    		menuPrincipal();
							break;

							}
						}
						else
						{
							break;
						}
					}
				}
				system("pause");
    	break;
    	case 3:
    	{
    		system("cls");

    		if(checkZonaExists(listZona, lenZona)==0)
			{
				printf("Error ! Baja de zonas, no hay zonas cargadas.\n");
				system("pause");
				break;
			}
			else
			{
				printf("**************************************************************************************************************\n");
				printf("                                    Menu Baja de Zonas \n");

				mostrarZonas(listZona, lenZona, listLocalidades, lenLocalidades);

				printf("\n");
				inputNumberInt(&idBaja, "Ingrese el ID de la zona a dar de baja: ", "Error, Ingrese el ID de la zona a dar de baja: ", 0, 20);

				indiceAux=buscarZonaId(listZona, lenZona, idBaja);

				if(indiceAux==-1)
				{
					printf("El ID de la zona no existe\n");

				}
				else
				{

				    printf("****************************************************************************************************************\n");
				    printf("*Id Zona   Nombre           calle 1        calle 2        calle 3         calle 4          Localidad           * \n");
				    printf("****************************************************************************************************************\n");

					mostrarZona(listZona[indiceAux], listLocalidades, lenLocalidades, listZona[indiceAux].idLocalidad);

					printf("Esta zona se dara de baja de forma permanente? \n");

					checkContinuar=checkContinue();

					if(checkContinuar=='S')
					{

						if(bajaZona(listZona, lenZona, idBaja))
						{
							printf("No se pudo realizar la baja del cliente.\n");
						}
						else
						{
							printf("La baja se realizo correctamente.\n");
						}
					}
					else
					{
						printf("Baja del cliente se cancelo.\n");
						system("pause");
						break;
					}
				}
			}

			system("pause");
			break;
    	}

    	case 4:
			system("cls");
			printf("***********************************************************************************************************\n");
			printf("                                    Menu Asignacion Censista a Zona \n");

            if(checkCensistaExists(listCensista, lenCensista) == 0)
               {
                   printf("Error! primero debe ingresar Censitas.\n");

                   system("pause");
                   break;
               }
               else
               {
       			mostrarZonasSinCensista(listZona, lenZona, listLocalidades, lenLocalidades);
       			inputNumberInt(&idZona, "Ingrese el ID ZONA para asignar Censista: ", "Error, Ingrese el ID ZONA para asignar Censista: ", 0, 20);

       			system("cls");

       			indiceAux=buscarZonaId(listZona, lenZona, idZona);

       			if(indiceAux==-1)
       			{
       				printf("El ID de la zona no existe\n");

       			}
       			else
       			{

       				printf("**************************************************************************************************************************************************************\n");
       				printf("  ID             Nombre     	     Apellido    	   Edad 			Fecha de nacimiento  		Direccion                Localidad                \n");
       				printf("**************************************************************************************************************************************************************\n");
       				mostrarZona(listZona[indiceAux], listLocalidades, lenLocalidades, listZona[indiceAux].idLocalidad);
       				printf("\n\n");
       				printf("Seleccione un censista para asociar a la zona \n\n");
       				mostrarCensistasPorEstado(listCensista, TAM_CENSISTA, EST_CENSISTA_LIBERADO);
       				inputNumberInt(&idCensista, "Ingrese el ID del Censista: ", "Error, Ingrese el ID del Censista: ", 1000, 2000);

       				printf("Este Censista se asignara a la Zona seleccionada: \n");

       				checkContinuar=checkContinue();

       				if(checkContinuar=='S')
       				{

       					if(asignarZonaCensista(listZona, lenZona, idZona, idCensista))
       					{
       						printf("No se pudo realizar la asiganacion de zona .\n");
       					}
       					else
       					{
       						cambiaEstadoCensista(listCensista, TAM_CENSISTA, idCensista, EST_CENSISTA_ACTIVO);
       						printf("La asignacion se realizo correctamente.\n");
       					}
       				}
       				else
       				{
       					printf("La asignacion fue cancelada. \n");
       					system("pause");
       					break;
       				}
       			}

       			printf("\n");
               }




    	break;

    	case 5:
    		system("cls");
    		menuPrincipal();
    }

    return validation;
}


int menuModificacionCensista()
{
    int opcion;
    printf("***********************************************************************************************************\n");
    printf("*				Opciones disponibles para modificar el Censista                                           *\n");
    printf("***********************************************************************************************************\n");
    printf("1- Modificar Nombre \n");
    printf("2- Modificar Apellido\n");
    printf("3- Modificar  Edad \n");
    printf("4- Modificar Fecha de Nacimiento\n");
    printf("5- Modificar Direccion \n");
    printf("6- Salida \n");

    inputNumberInt(&opcion, "Ingrese una opcion: ", "Error, ingrese una opcion: ", 1, 8);

    return opcion;
}

int menuModificacionZonas()
{
    int opcion;
    printf("***********************************************************************************************************\n");
    printf("				Opciones disponibles para modificar La Zona                         \n");
    printf("***********************************************************************************************************\n");
    printf("1- Modificar Nombre \n");
    printf("2- Modificar Calle 1\n");
    printf("3- Modificar Calle 2\n");
    printf("4- Modificar Calle 3\n");
    printf("5- Modificar Calle 4\n");
    printf("6- Salida \n");

    inputNumberInt(&opcion, "Ingrese una opcion: ", "Error, ingrese una opcion: ", 1, 5);

    return opcion;
}


int menuReportes(eCensista listCensista[], int lenCensista , eZona listZona[], int lenZona,
					eDomicilioCensita listDomicilioCensista[], int lenDomicilioCensista,
					eFechaNacimientoCensita listFechaNacimientoCensista[], int lenFecNacimientoCensista,
					eDatosCenso listDatosCenso[], int tamDatosCenso, eLocalidades listLocalidades[], int lenLocalidades)
{

    int validation=0;
    int opcionMenu = 0;

    printf("***********************************************************************************************************\n");
    printf("                                    Menu de Reportes \n");
    printf("***********************************************************************************************************\n");
    printf("1- Listado de Censistas \n");
    printf("2- Listado de Zonas \n");
    printf("3- cantidad de censistas en estado Activo con zona Pendiente. \n");
    printf("4- \n");
    printf("5- nombre y zona con mas casas ausentes \n");
    printf("6- informar censista cuya zona fue mas censada\n");
    printf("7- Promedio de censos por censista/zona \n");

    inputNumberInt(&opcionMenu, "Ingrese una opcion: ", "Error, ingrese una opcion: ", 1, 7);

    switch(opcionMenu)
    {
        case 1:
        	system("cls");
            printf("****************************************************************************************************************************\n");
            printf("*                                    		1- Listado de Censistas                                                     *\n");

            if(reporteListadoCensistas(listCensista, lenCensista, listFechaNacimientoCensista, lenFecNacimientoCensista, listDomicilioCensista, lenDomicilioCensista))
            {
            	printf("No hay Censistas ingresados");
            }
            printf("\n");
        break;
        case 2:
        	system("cls");
        	printf("***************************************************************************************\n");
            printf("*                                    Listado de zonas 								*\n");

            if(reporteListadoZonas(listZona, lenZona, listCensista, lenCensista, listLocalidades, lenLocalidades))
            {
            	printf("No hay zonas ingresados");
            }

            printf("\n");
        break;

        case 3:
        	printf("***************************************************************************************\n");
            printf("*                 cantidad de censistas en estado Activo con zona Pendiente.          *\n");

            reporteCensistaActivoZonaPendiente(listCensista, lenCensista, listZona, lenZona);
        break;

        case 4:
        	printf("***************************************************************************************\n");
            printf("*                                     								*\n");

        break;

        case 5:
        	//no tengo localidad en la estructura de datos  asi que lo hice por zona con mas ausentes
        	printf("***************************************************************************************\n");
            printf("*              c.   nombre y zona con mas casas ausentes                			*\n");
            reporteLocalidadMasCasasAusetes (listDatosCenso, tamDatosCenso, listLocalidades, lenLocalidades, listZona, lenZona);
        break;

        case 6:
        	printf("***************************************************************************************\n");
            printf("*                      informar censista cuya zona fue mas censada	                 *\n");
            reporteCensistaMasCenso(listDatosCenso, tamDatosCenso, listCensista,  lenCensista, listZona,  lenZona);

        break;

        case 7:

        	printf("***************************************************************************************\n");
            printf("*                            Promedio de censos por censista/zona						*\n");

            //informarPromedio(listDatosCenso,  tamDatosCenso, listZona, lenZona);
            printf("\n");

        break;

    }
    return validation;
}
