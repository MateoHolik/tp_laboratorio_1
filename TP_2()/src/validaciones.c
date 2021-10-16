/*
 * validaciones.c
 *
 *  Created on: 11 oct. 2021
 *  Author: Mateo Holik
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "validaciones.h"

int PedirInt(int* entrada,char mensaje[],char mensajeError[], int valorMin, int valorMax)
{
    int retorno;
    int esInt;
    int numeroValidado;
    char auxNum[10];

    retorno = 1;
    esInt = 0;
    numeroValidado = 0;

    printf("%s : ", mensaje);
    scanf("%s", auxNum);
    esInt = ValidarInt(auxNum);

    if(esInt)
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
        }
    }
    else
    {
        printf("ERROR ingrese unicamete numeros \n");
        retorno = -1;
    }
    return retorno;
}

int ValidarInt(char numeroAuxiliar[])
{
   int i;
   int retorno;

   i = 0;
   retorno = 1;

   while(numeroAuxiliar[i] != '\0')
   {
       if((atoi(numeroAuxiliar)) == 0)
       {
    	   retorno = 0;
       }

       i++;
   }
   return retorno;
}

int PedirFloat(float* entrada,char mensaje[],char mensajeError[], float valorMin, float valorMax)
{
    int retorno;
    int esFLoat;
    int numeroValidado;
    char numeroAuxiliar[10];

    numeroValidado = 0;
    esFLoat = 0;
    retorno = 1;

    printf("%s : ", mensaje);
    scanf("%s", numeroAuxiliar);
    esFLoat = ValidarFloat(numeroAuxiliar);

    if(esFLoat)
    {
        numeroValidado=atof(numeroAuxiliar);
        if(numeroValidado < valorMin || numeroValidado > valorMax)
        {
            printf("%s : ", mensajeError);
            scanf("%s", numeroAuxiliar);
            retorno = -1;
        }
        else
        {
            *entrada=numeroValidado;
        }
    }
    else
    {
        printf("Error ingrese unicamente numeros\n");
        retorno = -1;
    }
    return retorno;
}

int ValidarFloat(char numeroAuxiliar[])
{
   int i;
   int retorno;
   int contadorComas;

   i = 0;
   retorno = 1;
   contadorComas = 0;

   while(numeroAuxiliar[i] != '\0')
   {
       if(numeroAuxiliar[i] < '0' || numeroAuxiliar[i] > '9')
       {
           if(numeroAuxiliar[i] == '.')
           {
               contadorComas = contadorComas + 1;
           }
       }
       if((atof(numeroAuxiliar)) == 0 || contadorComas>1)
       {
    	   retorno = 0;
       }
       i++;
   }
   return retorno;
}

int PedirChar(char* entrada,char mensaje[],char mensajeError[], char valorMin, char valorMax)
{
    printf("%s: ", mensaje);
    fflush(stdin);
    scanf("%c", entrada);

    *entrada = toupper(*entrada);

    while (*entrada > valorMax || *entrada < valorMin)
    {
        printf("Reingrese %s: ", mensajeError);
        fflush(stdin);
        scanf("%c", entrada);
        *entrada = toupper(*entrada);
    }

    return 1;
}

int ValidarChar(char stringAuxiliar[])
{
   int i;
   int retorno;

   i = 0;
   retorno = 1;

   while(stringAuxiliar[i] != '\0')
   {
       if((stringAuxiliar[i] < 'a' || stringAuxiliar[i] > 'z') && (stringAuxiliar[i] < 'A' || stringAuxiliar[i] > 'Z'))
       {
    	   retorno = 0;
       }
       i = i + 1;
   }
   return retorno;
}


int PedirString(char* entrada,char mensaje[],char mensajeError[], int valorMin, int valorMax)
{
    char auxString[25];
    int sizeOfString;
    int retorno;
    int isCharacter;

    sizeOfString = 0;
    retorno = 0;
    isCharacter = 0;

    printf("%s: ", mensaje);
    fflush(stdin);
    scanf("%s", auxString);

    isCharacter = ValidarChar(auxString);

        if(isCharacter)
        {
          sizeOfString = strlen(auxString);
            if(sizeOfString > valorMax || sizeOfString < valorMin)
            {
                system("cls");
                printf("%s ", mensajeError);
                retorno = -1;
            }
            else
            {
                auxString[0] = toupper(auxString[0]);
                strcpy(entrada,auxString);
                retorno = 1;
            }
        }
        else
        {
            printf("ERROR: ingrese unicamente letras\n");
            retorno = -1;
        }

    return retorno;
}



