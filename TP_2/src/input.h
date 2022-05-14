#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <float.h>

#ifndef INPUT_H_
#define INPUT_H_
#define MAXCHAR 256
#define MAX_STRING_NUMBER 64

#define INT_MAX		2147483647
#define INT_MIN		(-INT_MAX-1)
#undef FLT_MAX
#undef DBL_MAX
#undef LDBL_MAX
#define FLT_MAX		__FLT_MAX__
#define DBL_MAX		__DBL_MAX__
#define LDBL_MAX	__LDBL_MAX__

int inputStringAndNumber(char* input, char message[], char eMessage[], int minLimit, int maxLimit);


/// @fn int inputString(char*, char[], char[], int, int)
/// @brief input de un caracter que ingresa el usuario
///
/// @param input se carga el caracter ingresado
/// @param message mensaje a mostrar
/// @param eMessage mostrar mensaje de error
/// @param minLimit limite minimo de caracter
/// @param maxLimit limite maximo de caracter
/// @return
int inputString(char* input, char message[], char eMessage[], int minLimit, int maxLimit, int numberDisabled);

/// @fn int inputNumberInt(int*, char[], char[], int, int)
/// @brief Solicita un numero al usuario y lo valida como int
///
/// @param input numero int ingresado
/// @param message mensaje a mostrar
/// @param eMessage mensaje de error
/// @param minLimit limite numero minimo a validar
/// @param maxLimit limite numero maximo a validar
/// @return retorna numero devuelve 0 si no 1.
int inputNumberInt(int* input, char message[], char eMessage[], int minLimit, int maxLimit);

/// @fn int inputNumberFloat(float*, char[], char[], float, float)
/// @brief Solicita un numero al usuario y lo valida como flotante
///
/// @param input numero int ingresado
/// @param message mensaje a mostrar
/// @param eMessage mensaje de error
/// @param minLimit limite numero minimo a validar
/// @param maxLimit limite numero maximo a validar
/// @return retorna numero devuelve 0 si no 1.
int inputNumberFloat(float* input, char message[], char eMessage[], float minLimit, float maxLimit);

/// @fn int onlyLetters(char[])
/// @brief valida que sean solo letras
///
/// @param str
/// @return retorna 0 si no 1
int onlyLetters(char str[]);


/// @fn int validarInt(char[])
/// @brief evalua si una cadena ingresada por teclado es un numero int.
///
/// @param char cadena a evaluar.
/// @return  Si es un numero flotante retorna [1] si no [0]
int validarInt(char[20]);

/// @fn int validarFloat(char[])
/// @brief
///
/// @param str
/// @return
int validarFloat(char str[]);

/// @fn char checkContinue()
/// @brief pregunta si se quiere continuar o no
///
/// @return retorna la cadena ingresada
char checkContinue();

#endif /* INPUT_H_ */
