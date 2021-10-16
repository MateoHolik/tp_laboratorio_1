/*
 * validaciones.h
 *
 *  Created on: 11 oct. 2021
 *  Author: Mateo Holik
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

/**
* \brief Solicita un número al usuario y lo valida
* \param entrada
* \param mensaje
* \param mensajeError
* \param valorMin
* \param valorMax
* \return si retorna 0 esta bien, si retorna -1 hubo un error
*/
int PedirInt(int* entrada,char mensaje[], char mensajeError[], int valorMin, int valorMax);


/**
* \brief la funcionr recibe un string y lo valida
* \param numeroAuxiliar
* \return si retorna 0 esta bien, si retorna -1 hubo un error
*
*/
int ValidarInt(char numeroAuxiliar[]);


/**
* \brief Solicita un número float al usuario y lo valida
* \param entrada
* \param mensaje
* \param mensajeError
* \param valorMin
* \param valorMax
* \return si retorna 0 esta bien, si retorna -1 hubo un error
*/
int PedirFloat(float* entrada,char mensaje[],char mensajeError[], float valorMin, float valorMax);


/**
* \brief recibe un string y valida si es float
* \param numeroAuxiliar
* \return si retorna 0 esta bien, si retorna -1 hubo un error
*
*/
int ValidarFloat(char numeroAuxiliar[]);


/**
* \brief Solicita un caracter al usuario y lo valida
* \param entrada
* \param mensaje
* \param mensajeError
* \param valorMin
* \param valorMax
 \return si retorna 0 esta bien, si retorna -1 hubo un error
*
*/
int PedirChar(char* entrada,char mensaje[],char mensajeError[], char valorMin, char valorMax);


/**
* \brief recibe un string y valida si tiene letras
* \param stringAuxiliar
* \return si retorna 0 esta bien, si retorna -1 hubo un error
*/
int ValidarChar(char stringAuxiliar[]);


/**
* \brief pide una cadena de caracteres al usuario y la valida
* \param entrada
* \param mensaje
* \param mensajeError
* \param valorMin
* \param valorMax
* \return si retorna 0 esta bien, si retorna -1 hubo un error
*/
int PedirString(char* entrada,char mensaje[],char mensajeError[], int valorMin, int valorMax);
#endif
