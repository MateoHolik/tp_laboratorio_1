/*
 ============================================================================
 Name        : TP2.c
 Author      : Mateo Holik
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#include "arrayEmplyees.h"
#include "validaciones.h"

#define LENEMP 1000
#define LENSEC 5

int main()
{
	setbuf(stdout,NULL);
	int opcion;
    char  requestedName[51];
    char  requestedLastName[51];
    float requestedSalary;
    int requestedSector;

    int validacionNombre;
    int validacionApellido;
    int validacionSueldo;
    int validacionElegirSector;

    validacionNombre = 0;
    validacionApellido = 0;
    validacionSueldo = 0;
    validacionElegirSector = 0;


    Employee employees[LENEMP];
    Sectors sectors[LENSEC];

    InitEmployees(employees,LENEMP);

    MostrarSectores(sectors,LENSEC);


       do{
           printf("- - - M E N U   P R I N C I P A L - - -\n");
           printf("1- ALTA\n");
           printf("2- MODIFICAR\n");
           printf("3- BAJA\n");
           printf("4- INFORMAR\n");
           printf("5- SALIR\n");

           PedirInt(&opcion, "Seleccione una opcion ","Reintente ingresar la opcion", 1, 5);

           switch(opcion)
           {
               case 1:

            	   system("cls");
            	   do
            	   {
                	   validacionNombre = PedirString(requestedName,"Ingrese el nombre del empleado",
                			   	   	   	  "X X X Nombre incorrecto, respete el rango de letras [mininmo 2 - maximo 20] X X X \n", 2, 20);
            	   }while(validacionNombre == -1);

            	   do
            	   {
                	   validacionApellido = PedirString(requestedLastName,"Ingrese el apellido del empleado",
                			   	   	   	   	"X X X ERROR apellido invalido, respete el rango de letras[min 2 - max 20] X X X \n", 2, 20);
            	   }while(validacionApellido == -1);

            	   do
              	   {
            		   validacionSueldo = PedirFloat(&requestedSalary,"Ingrese el salario del empleado",
            		               		  "X X X ERROR salario incorrecto, reingrese el salario, dentro del rango [min 1 - max 5000000] X X X \n", 1, 5000000);
            	   }while(validacionSueldo == -1);

            	   do
            	   {
            		 validacionElegirSector = ChooseSector(&requestedSector,"Elija el sector al que pertenece el empleado",
            		              			  "X X X ERROR invalida, rango [1-5] X X X \n", 1, 5, sectors, LENSEC);
            	   }while(validacionElegirSector == -1);


            	   if((validacionNombre != 0) && (validacionApellido != 0) && (validacionSueldo != 0) && (validacionElegirSector != 0))
            	   {

						AddEmployee(employees, LENEMP, GenerarIdEmpleado(), requestedName, requestedLastName, requestedSalary, requestedSector, sectors, LENSEC);
            	   }
				break;

               case 2:
            	   system("cls");

            	   if(BuscarEmpleadosCargados(employees, LENEMP) == 0)
            	   {

            		   printf("X X X Es necesario cargar empleados al sistema para acceder a esta lista X X X \n\n");
            	   }
            	   else
            	   {
            		   ModifyEmployee(employees, LENEMP, sectors, LENSEC);
            	   }
               break;

               case 3:
            	   system("cls");
            	   if(BuscarEmpleadosCargados( employees, LENEMP) == 0)
            	   {
            		   printf("X X X Es necesario cargar empleados al sistema para poder darlos de baja X X X \n\n");
            	   }
            	   else
            	   {
            		   RemoveEmployee(employees, LENEMP, sectors, LENSEC);
            	   }
               break;

               case 4:

            	   	 if(BuscarEmpleadosCargados( employees, LENEMP) == 0)
                     {

            	   	 printf("X X X Es necesario cargar empleados al sistema para poder informarlos X X X \n\n");
                     }
                     else
                     {
                    	 Informar(employees,LENEMP,sectors,LENSEC);
                     }
                     system("pause");
                     break;

               case 5:
            	   system("cls");
            	   printf("Gracias por usar nuestro sistema de carga");
               break;
           }

       }while (opcion != 5);

       return 0;
   }
