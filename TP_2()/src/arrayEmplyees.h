/*
 * arrayEmployees.h
 *
 *  Created on: 11 oct. 2021
 *  Author: Mateo Holik
 */

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;

typedef struct
{
    int id;
    char description[51];
} Sectors;

/***
 * @brief  pregunta al usuario cual es el orden de ordenamiento que desea
 * @param employees
 * @param lengthEmp
 * @return retorna el orden mediante el cual el usuario quiere ordenar el menu 1 o 2
 */
int SortingMenu(Employee* employees, int lengthEmp);


/**
 * @brief busca si hay algun empleado cargado al sistema
 * @param employees
 * @param lenEmp
 * @return retorna 1 si no enconto nada o i si encontro una posicion cargada
 */
int BuscarEmpleadosCargados(Employee employees[], int lenEmp);


/**
* \brief  indica si las posiciones del array estan vacias
* \param  list Employee*
* \param  lengthEmp
* \return retorna-1 si existe un error o 0 si esta bien  */
int InitEmployees(Employee* employees, int lenEmp);


/**
* \brief  agrega al empleado cargado al sistema
*
* \param  list*
* \param  lengthEmp
* \param  id
* \param  name[]
* \param  lastName[]
* \param  salary
* \param  sector
* \param  list*
* \param  lengthSec
* \return retorna-1 si existe un error o 0 si esta bien*/
int AddEmployee(Employee* employees, int lenEmp, int id, char name[],char lastName[],float salary,int sector, Sectors* sectors, int lengthSec);


/**
* \brief busca un empleado en el sistema mediante el ID
* \param  list*
* \param  lengthEmp
* \param  id
* \return retorna la posicion o -1 si no encuentra nada*/
int FindEmployeeById(Employee* employees, int lenEmp, int id);


/** \brief Borra al empleado seleccionado del sistemA
* \param list*
* \param len
* \param id
* \return  retorna -1 si hay un error o 0 si esta bien*/
int RemoveEmployee(Employee* employees, int lenEmp, Sectors* sectors, int lenSec);


/***
 * @fn int PrintEmployees(Employee*, int, Sectors*, int)
 * @brief mustra la lista de empleados cargados en el sistema hasta el momento
 * @param employees
 * @param lenEmp
 * @param sectors
 * @param lenSec
 * @return retorna 0
 */
int PrintEmployees(Employee* employees, int lenEmp, Sectors* sectors, int lenSec);


/***
 * @fn int SortEmployeesByName(Employee*, int, int)
 * @brief  acomoda los empleados alfabeticamente por su apellido
 * @param employees
 * @param lenEmp
 * @param order
 * @return
 */
int SortEmployeesByLastName(Employee* employees, int lenEmp, int order);


/**
* \brief Muestra un menu con las opciones de ordenamiento a seleccionar
* \param
* \return retorna la opcion ingresada*/
int ReportsMenu();


/**
* \brief Muestra el menu con las opciones de modificacion de datos
* \param
* \return retorna la opcion ingresada*/
int MenuDeModificacion();


/**
* \brief muestra los distintos sectores de la empresa
* \param  list*
* \param  lengthSec
*/
void MostrarSectores(Sectors* sectors,int LENSEC);


/**
* \brief  recibe un empleado y lo muestra por pantalla.
*
*
* \return retorna 0 si esta bien*/
int PrintEmployee(Employee employee, Sectors* sectors, int lenSec);


/**
* \brief  recibe el vector de sectores y lo muestra por pantalla.
*
* \param  list**/
void PrintSectors(Sectors* sectors, int lenSec);


/**
* \brief  busca un indice vacio
*
*
* \return retorna un indice si lo encotnro, si fallo retorna -1*/
int FindEmptyIndex(Employee* employees, int lenEmp);


/**
* \brief  genera un numero de ID random
*
* \param  list*
* \param  lengthEmp
* \param  id*
* \param  requestedRandomId*
* \return retorna 0 si esta bien  si fallo retorna -1*/
int GenerarIdEmpleado();


/**
* \brief  recibe un id y encuentra el sector del mismo
*
* \param  lists*
* \param  empleado
* \param  id*
* \param  index
*
* \return retorna el sector si funciono, si fallo retorna -1*/
int GetSectorDescription(int idEmployee, Sectors* sectors, int lenSec);


/**
* \brief  permite modificar un empleado cargado en el sistema
*
* \param  list*
* \param  lengthEmp
* \param  list*
* \param  lengthSec
* \param  idEmpleado*
* \param  index
*
* \return retorna 0 si funciono o -1 si fallo*/
int ModifyEmployee(Employee* employees, int len, Sectors* sectors, int lenSec);


/**
* \brief  recibe el id de un empleado y pide un nombre nuevo para reemplazar el cargado previamente
*
* \param  list*
* \param  lengthEmp
* \param  list*
* \param  lengthSec
* \param  idEmpleado
* \param  auxName
* \param  confirm
*
* \return retorna 0 si esta bien sino retorna -1*/
int ModifyNameEmployee(Employee* employees, int lenEmp, Sectors* sectors, int lenSec, int index);


/**
* \brief  recibe el id de un empleado y pide un apellido para reemplazar el cargado previamente
*
* \param  list*
* \param  lengthEmp
* \param  list*
* \param  lengthSec
* \param  idEmpleado
* \param  auxLastName
* \param  confirm
*
* \return retorna 0 si esta bien sino retorna -1*/
int ModifyLastNameEmployee(Employee* employees, int lenEmp, Sectors* sectors, int lenSec, int index);


/**
* \brief  recibe el id de un empleado y pide una actualizacion del
* 		  salario para reemplazar el cargado previamente
*
* \param  list*
* \param  lengthEmp
* \param  list*
* \param  lengthSec
* \param  idEmpleado
* \param  auxSalary
* \param  confirm
*
* \return retorna 0 si esta bien sino retorna -1*/
int ModifySalaryEmployee(Employee* employees, int lenEmp, Sectors* sectors, int lenSec, int index);


/**
* \brief  recibe el id de un empleado y pide una actualizacion del sector para reemplazar el cargado previamente
*
* \param  list*
* \param  lengthEmp
* \param  list*
* \param  lengthSec
* \param  idEmpleado
* \param  auxLastName
* \param  confirm
*
* \return retorna 0 si esta bien sino retorna */
int ModifySectorEmployee(Employee* employees, int lenEmp, Sectors* sectors, int lenSec, int index);


/**
* \brief  Informa la lista de empleados ordeanados por apellido o por salario
*
* \param  list*
* \param  lengthEmp
* \param  list*
* \param  lengthSec
*
* \return retorna 0 si esta bien sino retorna*/
int Informar(Employee* employees, int lenEmp, Sectors* sectors, int lenSec);


/**
* \brief  informa la suma de los salarios ingresados, el promedio y los emleados que superen el promedio
* \param  list*
* \param  lengthEmp
*/
void InformarSalarios(Employee* employees, int lengthEmp);

/**
* \brief  - Muestra menu de sectores, pide que se seleccione uno
*
* \param  list*
* \param  lengthEmp
* \param  list*
* \param  lengthSec
* \param  idEmpleado
* \param  auxLastName
* \param  confirm
*
* \return retorna 0 si esta bien sino retorna*/
int ChooseSector(int* input,char mensaje[],char mensajeError[], int valorMin, int extensionMax, Sectors* sectors, int lenSec);


/**
* \brief  ordena dos listas
*
* \param  list*
* \param  lengthEmp
* \param  list*
* \param  lengthSec
*/
void Burbujeo(Employee* employees, int lenEmp, int i, int j);
