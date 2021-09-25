#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef BIBILIOTECA_H_
#define BIBILIOTECA_H_


/***
 * @fn float CargarNumeroFlotante(char[])
 * @brief Carga un numero flotante validado
 *
 * @param mensaje de carga
 * @return retorna el numero validado flotante
 */
float CargarNumeroFlotante(char mensaje[]);


/***
 * @fn void SumarNumeros(float, float, float*)
 * @brief suma dos numeros
 *
 * @param numeroIngresado1
 * @param numeroIngresado2
 * @param resultado de la suma de dos numeros
 */
void SumarNumeros (float numeroIngresado1, float numeroIngresado2, float* resultado);


/***
 * @fn void RestarNumeros(float, float, float*)
 * @brief resta dos numeros
 *
 * @param numeroIngresado1
 * @param numeroIngresado2
 * @param resultado de la resta de dos numeros
 */
void RestarNumeros(float numeroIngresado1, float numeroIngresado2, float* resultado);


/***
 * @fn void MultiplicarNumeros(float, float, float*)
 * @brief multiplica dos numeros
 *
 * @param numeroIngresado1
 * @param numeroIngresado2
 * @param resultado de la multiplicacion de dos numeros
 */
void MultiplicarNumeros(float numeroIngresado1, float numeroIngresado2, float* resultado);


/***
 * @fn int DividirNumeros(float, float, float*)
 * @brief divide dos numeros ingresados
 *
 * @param numeroIngresado1
 * @param numeroIngresado2
 * @param resultado de la division de dos numeros
 * @return el retorno es de  control si es 1 no se realizara la division y si retorna 0 realiza el calculo
 */
int DividirNumeros(float numeroIngresado1, float numeroIngresado2, float* resultado);


/***
 * @fn void CalcularFactorial(float, float*)
 * @brief calcula el factorial del numero ingresado
 *
 * @param numeroIngresado
 * @param resultado del factorial calculado
 */
void CalcularFactorial(float numeroIngresado, float* resultado);


/***
 * @fn int CargarNumeroInt(char[])
 * @brief valida y almacena el numero ingresado
 *
 * @param mensaje
 * @return retorna el numero entero validado
 */
int CargarNumeroInt(char mensaje[]);


/***
 * @fn int ValidarNumeroInt(char[])
 * @brief valida el numero entero
 *
 * @param numeroIngresado
 * @return reotrna un numero entero validado
 */
int ValidarNumeroInt(char numeroIngresado[]);


/***
 * @fn int ValidarNumeroFloat(char[])
 * @brief valida que el nuemero ingresado sea flotante
 *
 * @param numeroIngresado
 * @return retorna el numero float validado
 */
int ValidarNumeroFloat(char numeroIngresado[]);


/***
 * @fn int main(void)
 * @brief
 *
 * @return
 */


#endif /* BIBILIOTECA_H_ */
