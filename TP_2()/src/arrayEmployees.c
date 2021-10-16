/*
 * arrayEmployees.c
 *
 *  Created on: 11 oct. 2021
 *  Author: Mateo Holik
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#include "arrayEmplyees.h"
#include "validaciones.h"

#define EMPTY 1
#define OCCUPIED 0

int InitEmployees(Employee* employees, int lengthEmp)
{
	int i;
    for(i = 0; i < lengthEmp; i++)
    {
        employees[i].isEmpty = EMPTY;
    }
    return 0;
}

int RemoveEmployee(Employee* employees, int lengthEmp, Sectors* sectors, int lengthSec)
{
    int idEmployee;
    int retorno;
    int index;
    char confirm;

    retorno = 0;

    PrintEmployees(employees,lengthEmp,sectors,lengthSec);
    printf("Ingrese legajo del empleado que desea eliminar: ");
    scanf("%d",&idEmployee);

    index = FindEmployeeById(employees,lengthEmp,idEmployee);

    if(index == -1)
    {
        printf("No se ha encontrado ningun empleado con ese ID\n");
        system("pause");

        retorno = -1;
    }
    else
    {
        system("cls");
        printf("- - -EMPLEADO A ELIMINAR - - -\n\n");
        printf("%12s %12s %12s %8s %12s\n", "Nombre", "Apellido", "Nro legajo", "Sector", "Sueldo");
        printf("  - - - -    - - - -   - - - -   - - - -   - - - -   - - - -  \n");

        PrintEmployee(employees[index],sectors,lengthSec);
        printf("Confirma la eliminacion?\n");
        fflush(stdin);
        printf("Confirme s para(SI) o n para(NO) : ");
        scanf("%c", &confirm);

        if(confirm == 's')
        {
            employees[index].isEmpty = EMPTY;
            retorno = 0;
            printf("X X X Empleado eliminado del sistema X X X \n\n");
        }
        else
        {
        	retorno = -1;
        }
    }
    return retorno;
}

int FindEmployeeById(Employee* employees, int lengthEmp,int id)
{
    int index;

    index = -1;

    for(int i=0 ; i < lengthEmp; i++)
    {
        if(employees[i].id == id)
        {
            index=i;
        }
    }
    return index;
}

int AddEmployee(Employee* employees, int lengthEmp, int id, char name[],char lastName[],float salary,int sector, Sectors* sectors, int lengthSec){

	int validacion;
    int index;

    validacion = 0;

    index = FindEmptyIndex(employees, lengthEmp);

    employees[index].id = id;
    strcpy(employees[index].name,name);
    strcpy(employees[index].lastName,lastName);
    employees[index].salary = salary;
    employees[index].sector = sector;
    employees[index].isEmpty = OCCUPIED;

    system("cls");
    printf(" - - - DATOS INGRESADOS DEL EMPLEADO - - -  \n");

    printf("%12s %12s %12s %8s %12s\n", "Nombre", "Apellido", "ID", "Sector", "Sueldo");
    printf("  - - - -    - - - -   - - - -   - - - -   - - - -   - - - -  \n");

    PrintEmployee(employees[index],sectors,lengthSec);

	printf("- - - El empleado fue cargado en el sistema con exito - - - \n\n");

    return validacion;
}

int PrintEmployees(Employee* employees, int lengthEmp, Sectors* sectors, int lengthSec)
{
	int i;
    system("cls");

        printf("- - - LISTA DE EMPLEADOS INGRESADOS AL SISTEMA - - -\n");

        printf("%12s %12s %12s %8s %12s\n", "Nombre", "Apellido", "ID", "Sector", "Sueldo");
        printf("  - - - -    - - - -   - - - -   - - - -   - - - -   - - - -  \n");

        for(i = 0; i < lengthEmp; i++)
        {
            if(employees[i].isEmpty == OCCUPIED)
            {
                PrintEmployee(employees[i],sectors,lengthSec);
            }
        }

    return 0;
}


int SortEmployeesByLastName(Employee* employees, int lengthEmp, int order)
{
    int retorno;
    retorno = 0;

    for(int i = 0; i < lengthEmp +1; i++)
    {
        for(int j = i +1; j < lengthEmp; j++)
        {
            if(employees[i].isEmpty == OCCUPIED)
            {
                if(order == 1)
                {
                    if(employees[i].lastName > employees[j].lastName)
                    {
                    	Burbujeo(employees, lengthEmp, i, j);
                    }
                    else
                    {
                        if((employees[i].lastName == employees[j].lastName) && (stricmp(employees[i].name,employees[j].name)>0))
                        {
                        	Burbujeo(employees,lengthEmp,i,j);
                        }
                    }
                }
                else if(order==2)
                {
                		if(employees[i].lastName < employees[j].lastName)
                		{
                			Burbujeo(employees,lengthEmp,i,j);
                		}
                		else
                		{
                			if((employees[i].sector== employees[j].sector)&&(stricmp(employees[i].lastName,employees[j].lastName)<0))
                			{
                				Burbujeo(employees,lengthEmp,i,j);
                			}
                		}
                }
            }
        }
    }
    return retorno;
}


int FindEmptyIndex(Employee* employees, int lengthEmp)
{
    int index;

    index = -1;

    for(int i = 0; i < lengthEmp; i++)
    {
        if(employees[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }
    return index;
}


int GenerarIdEmpleado()
{
    static int id = 1000;

    return id++;
}


int ReportsMenu()
{
    int option;

    system("cls");
    printf("- - - MENU de Informes - - - \n\n");
    printf("1- Lista de empleados por orden alfabetico\n");
    printf("2- Lista de total y promedio de salarios\n");
    printf("\nIngrese opcion: ");
    scanf("%d",&option);

    return option;
}


int Informar(Employee* employees, int lengthEmp, Sectors* sectors, int lengthSec){

    int validation;
    validation = 0;

    switch(ReportsMenu())
    {
        case 1:
            SortingMenu(employees, lengthEmp);
            printf("- - - EMPLEADOS ORDENADOS ALFABETICAMENTE - - -\n\n");
            PrintEmployees(employees,lengthEmp,sectors,lengthSec);
        break;

        case 2:
        	InformarSalarios(employees,lengthEmp);
        break;

        default:
            printf("Opcion invalida");
            system("pause");
            validation=-1;
        break;
    }
    return validation;
}


int ModifyEmployee(Employee* employees, int lengthEmp, Sectors* sectors, int lengthSec)
{
    int validation;
    int index;
    int opcion;
    int idEmployee;

    validation = 0;

    PrintEmployees(employees, lengthEmp, sectors, lengthSec);

    printf("Ingrese ID del empleado que desea modificar: ");
    scanf("%d", &idEmployee);

    index = FindEmployeeById(employees, lengthEmp, idEmployee);

    if(index == 0)
    {
    	opcion = MenuDeModificacion();

        switch(opcion)
        {
            case 1:
                ModifyNameEmployee(employees, lengthEmp, sectors, lengthSec,index);
            break;

            case 2:
                ModifyLastNameEmployee(employees, lengthEmp, sectors, lengthSec, index);
            break;

            case 3:
                ModifySalaryEmployee(employees, lengthEmp, sectors, lengthSec, index);
            break;

            case 4:
                ModifySectorEmployee(employees, lengthEmp, sectors, lengthSec, index);
            break;

            default:
                printf("Opcion Invalida\n");
            break;
        }
    }
    else
     {
    	if(index == -1)
    	{
            printf("No se encontro ningun empleado cargado con ese ID\n");
            validation = -1;
    	}
     }
    return validation;
}


int ModifyNameEmployee(Employee* employees, int lengthEmp, Sectors* sectors, int lengthSec, int index)
{
	char auxName[25];
    char confirm;
    int validation;

    validation= PedirString(auxName,"Ingrese el NUEVO nombre del empleado","Nombre invalido, cantidad de caracteres [min 2 - max 50]",2,50);

    if(validation==1)
    {
        system("cls");

        printf("- - -  EMPLEADO QUE DESEA MODIFICAR - - - \n\n");
        printf("%12s %12s %12s %8s %12s\n", "Nombre", "Apellido", "Nro legajo", "Sector", "Sueldo");
        printf("  - - - -    - - - -   - - - -   - - - -   - - - -   - - - -  \n");

        PrintEmployee(employees[index], sectors, lengthSec);

        printf("Confirma NUEVO nombre: %s? s/n\n",auxName);
        fflush(stdin);
        scanf("%c",&confirm);

        if(confirm =='s')
        {
            strcpy(employees[index].name, auxName);
            validation = 0;
        }
        else
        {
            validation = -1;
        }
    }
    else
    {
        validation = -1;
    }
    return validation;
}


int ModifyLastNameEmployee(Employee* employees, int lengthEmp, Sectors* sectors, int lengthSec, int index){

	char auxLastName[51];
    char confirm;
    int validation;

    validation = PedirString(auxLastName,"Ingrese el NUEVO apellido del empleado","Apellido invalido, cantidad de caracteres [min 2 - max 50]",2,50);

    if(validation == 1)
    {
        system("cls");

        printf(" - - - EMPLEADO A MODIFICAR - - -\n\n");
        printf("%12s %12s %12s %8s %12s\n", "Nombre", "Apellido", "Nro legajo", "Sector", "Sueldo");
        printf("  - - - -    - - - -   - - - -   - - - -   - - - -   - - - -  \n");

        PrintEmployee(employees[index],sectors,lengthSec);

        printf("Confirma el cambio del apellido: %s? s/n\n",auxLastName);
        fflush(stdin);
        scanf("%c",&confirm);

        if(confirm == 's')
        {
            strcpy(employees[index].lastName, auxLastName);
            validation = 0;
        }
        else
        {
            validation = -1;
        }
    }
    else
    {
        validation = -1;
    }

    return validation;
}

int ModifySalaryEmployee(Employee* employees, int lengthEmp, Sectors* sectors, int lengthSec, int index)
{
    float auxSalary;
    int validation;
    char confirm;

    validation = PedirFloat(&auxSalary,"Ingrese el NUEVO salario del empleado","Salario invalido, rango [min 1 - max 999999]",1,100000);

    if(validation == 1)
    {
        system("cls");

        printf("- - - EMPLEADO A MODIFICAR - - -\n\n");
        printf("%12s %12s %12s %8s %12s\n", "Nombre", "Apellido", "Nro legajo", "Sector", "Sueldo");
        printf("  - - - -    - - - -   - - - -   - - - -   - - - -   - - - -  \n");

        PrintEmployee(employees[index],sectors,lengthSec);

        printf("Confirma la modificacion del salario? %.2f? s/n\n", auxSalary);
        fflush(stdin);
        scanf("%c",&confirm);

        if(confirm == 's')
        {
            employees[index].salary = auxSalary;
            validation = 0;
        }
        else
        {
            validation = -1;
        }
    }
    else
    {
        validation = -1;
    }

    return validation;
}

int ModifySectorEmployee(Employee* employees, int lengthEmp, Sectors* sectors, int lengthSec, int index)
{
    int auxIdSector;
    int validacion;
    char confirmacion;

    auxIdSector = 0;

    printf("AUXILIAR SECTORS ID (le mando a): %d\n\n", auxIdSector);
    validacion = ChooseSector(&auxIdSector, "Seleccione el nuevo sector", "ERROR reingrese el sector,opciones de  [0-5]", 0, 5, sectors, lengthSec);

    if(validacion == 1)
    {
        system("cls");

        printf("- - - EMPLEADO A MODIFICAR - - - \n\n");
        printf("%12s %12s %12s %8s %12s\n", "Nombre", "Apellido", "Nro legajo", "Sector", "Sueldo");
        printf("  - - - -    - - - -   - - - -   - - - -   - - - -   - - - -  \n");

        PrintEmployee(employees[index],sectors,lengthSec);

        printf("AUXILIAR SECTORS ID(recibo): %d\n\n", auxIdSector);
        printf("Confirma el cambio del sector: %s? s/n\n", sectors[auxIdSector-1].description);
        fflush(stdin);
        scanf("%c", &confirmacion);

        if(confirmacion == 's')
        {
            employees[index].sector = auxIdSector;
            validacion = 0;
        }
        else
        {
        	validacion = -1;
        }
    }
    else
    {
    	validacion = -1;
    }
    return validacion;
}

int BuscarEmpleadosCargados(Employee employees[], int lenEmp)
{
    int retorno;
    int i;

    retorno = 0;

    for(i = 0; i < lenEmp; i++)
    {
        if(employees[i].isEmpty == OCCUPIED)
        {
            retorno = 1;
            break;
        }
    }
    return retorno;
}

int PrintEmployee(Employee employee, Sectors* sectors, int lengthSec)
{
    int index;

    index = GetSectorDescription(employee.sector,sectors,lengthSec);

    printf("%12s %12s %12d %10s %12.2f\n", employee.name, employee.lastName, employee.id, sectors[index].description, employee.salary);

    return 0;
}

int ChooseSector(int* entrada,char mensaje[],char mensajeError[], int valorMin, int valorMax, Sectors* sectors, int lengthSec)
{
    int retorno;
    int isInt;
    int numeroValidado;
    char auxNum[10];

    retorno = 0;
    isInt = 0;
    numeroValidado = 0;

    system("cls");
    PrintSectors(sectors,lengthSec);
    printf("\n%s : ", mensaje);
    scanf("%s", auxNum);

    isInt = ValidarInt(auxNum);

    if(isInt)
    {
        numeroValidado = atoi(auxNum);
        if(numeroValidado < valorMin || numeroValidado > valorMax)
        {
            printf("%s : ", mensajeError);
            scanf("%s", auxNum);
            retorno = -1;
        }
        else
        {
            *entrada = numeroValidado;
            retorno = 1;
        }
    }
    else
    {
        printf("ERROR ingrese numeros unicamente.\n");
        retorno = -1;
    }
    return retorno;
}

int GetSectorDescription(int idEmployee, Sectors* sectors, int lengthSec)
{
    int index;
    int i;

    index = -1;

    for(i = 0; i < lengthSec; i++)
    {
        if(idEmployee == sectors[i].id)
        {
            index = i;
        break;
        }
    }
    return index;
}

void InformarSalarios(Employee* employees, int lengthEmp)
{
	int i;
	float promedioSueldos;
	float acumuladorSueldos;
	int contadorSuperaPromedio;
	int contadorEmpleados;

	promedioSueldos = 0;
	acumuladorSueldos = 0;
	contadorSuperaPromedio = 0;
	contadorEmpleados = 0;

    for(i = 0; i < lengthEmp; i++)
    {
        if(employees[i].isEmpty == OCCUPIED)
        {
           acumuladorSueldos += employees[i].salary;
            contadorEmpleados = contadorEmpleados + 1;
        }
    }

    promedioSueldos = acumuladorSueldos / contadorEmpleados;

    for(i = 0; i < lengthEmp; i++)
    {
        if(employees[i].isEmpty == OCCUPIED)
        {
            if(employees[i].salary > promedioSueldos)
            {
                contadorSuperaPromedio = contadorSuperaPromedio + 1;
            }
        }
    }

    system("cls");
    printf("- - - L I S T A D O - - -\n\n");
    printf("TOTAL sueldos: %.2f\n\n", acumuladorSueldos);
    printf("PROMEDIO de sueldos: %.2f\n\n", promedioSueldos);
    printf("La cantidad de empleados que supera el promedio es: %d\n\n", contadorSuperaPromedio);
}

int MenuDeModificacion()
{
    int opcionIngresada;

    system("cls");
    printf("Que desea modificar? \n");
    printf("1- Nombre\n");
    printf("2- Apellido\n");
    printf("3- Salario\n");
    printf("4- Sector\n");

    printf("Ingrese opcion: ");
    scanf("%d",&opcionIngresada);

    return opcionIngresada;
}


int SortingMenu(Employee* employees, int lengthEmp)
{
    int order;

    system("cls");
    printf("Ordenar de:\n");
    printf("1- A-Z\n");
    printf("2- Z-A\n");
    printf("\nIngrese la opcion de ordenamiento deseada: ");
    scanf("%d",&order);

    SortEmployeesByLastName(employees, lengthEmp, order);

    return order;
}


void PrintSectors(Sectors* sectors, int lengthSec)
{
	int i;
    system("cls");
    printf("- - - SECTORES - - -\n\n");

    for(i = 0; i < lengthSec; i++)
    {
        if(sectors[i].id > 0)
        {
            printf("%d %4s\n",sectors[i].id, sectors[i].description);
        }
    }
}

void MostrarSectores(Sectors* sectors,int lengthSec)
{
    Sectors auxSectors[]=
    {
    {1,"RRHH"},
    {2,"Ventas"},
    {3,"Produccion"},
    {4,"Finanzas"},
    {5,"Planta"},
    };

    for(int i=0; i < lengthSec; i++)
    {
        sectors[i] = auxSectors[i];
    }
}

void Burbujeo(Employee* employees, int lenEmp, int i, int j)
{
    Employee auxEmp;

    auxEmp=employees[i];
    employees[i] = employees[j];
    employees[j] = auxEmp;
}
