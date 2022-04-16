#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int onlyLetters(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

int inputString(char* input, char message[], char eMessage[], int minLimit, int maxLimit)
{
    int returnValue = -1;
    int counter = 0;
    int sizeScan = 0;
    char auxMessage[MAXCHAR];

    if(input != NULL && message != NULL && eMessage != NULL && maxLimit >= minLimit && maxLimit < MAXCHAR && minLimit > 0)
    {
        do
        {
            counter++;

            if(counter == 1)
            {
                printf("%s", message);
            }
            else
            {
                if(counter > 1)
                {
                    printf("%s", eMessage);
                }
            }

            fflush(stdin);
            if(scanf("%[^\n]s", auxMessage))
            {
                sizeScan = strlen(auxMessage);
            }
            else
            {
                continue;
            }
        } while(sizeScan < minLimit || sizeScan > maxLimit || onlyLetters(auxMessage)==0 );

        if(sizeScan >= minLimit && sizeScan <= maxLimit && sizeScan > 0 && maxLimit < MAXCHAR)
        {
            auxMessage[MAXCHAR-1] = '\0';

            strcpy(input, auxMessage);

            returnValue = 0;
        }
    }
    return returnValue;
}

int inputNumberInt(int* input, char message[], char eMessage[], int minLimit, int maxLimit)
{

	char inputNumero[MAX_STRING_NUMBER];
	int salida;
	int control;
	int convertedNumber;
	int counter = 0;
	salida = 1;

    if(maxLimit >= minLimit && minLimit >= INT_MIN
    	&& maxLimit <= INT_MAX && input != NULL
		&& message != NULL && eMessage != NULL)
    {
		do
		{
            counter++;

            if(counter == 1)
            {
                printf("%s", message);
            }
            else
            {
                if(counter > 1)
                {
                    printf("%s", eMessage);
                }
            }
			fflush(stdin);
			scanf("%[^\n]", inputNumero);
			control = validarInt(inputNumero);
			convertedNumber = atoi(inputNumero);
		}
		while(control == 1 || ((convertedNumber < minLimit || convertedNumber > maxLimit)));

		if(convertedNumber >= minLimit && convertedNumber <= maxLimit)
		{
			*input = convertedNumber;
			salida = 0;
		}
    }
	return salida;
}


int inputNumberFloat(float* input, char message[], char eMessage[], float minLimit, float maxLimit)
{

	char inputNumero[MAX_STRING_NUMBER];
	int control;
	int salida;
	salida = 0;
	int counter = 0;
	float convertedNumber;

    if(maxLimit >= minLimit && minLimit >= -FLT_MAX
    	&& maxLimit <= FLT_MAX && input != NULL
		&& message != NULL && eMessage != NULL)
    {
		do
		{
			counter++;

            if(counter == 1)
            {
                printf("%s", message);
            }
            else
            {
                if(counter > 1)
                {
                    printf("%s", eMessage);
                }
            }

			fflush(stdin);
			scanf("%[^\n]", inputNumero);

			control = validarFloat(inputNumero);
			convertedNumber = atof(inputNumero);

		}
		while(control == 1 || ((convertedNumber < minLimit || convertedNumber > maxLimit)));

		if(convertedNumber >= minLimit && convertedNumber <= maxLimit)
		{
			*input = convertedNumber;
			salida = 1;
		}
    }

	return salida;
}

int validarInt(char stringNumero[]){

	int returnValue = 0;
	int i = 0;
	char charAux;

	    do
	    {
	        charAux = stringNumero[i];
	        if(i == 0 && (charAux == '-' || charAux == '+'))
	        {
	            i = 1;
	        }

	        if((int)charAux >= (int)'0' && (int)charAux <= (int)'9')
	        {
	            returnValue = 0;
	        }
	        else
	        {
	            returnValue = 1;
	            break;
	        }
	        i++;
	    }while(stringNumero[i] != '\0');

	    return returnValue;
}

int validarFloat(char stringNumero[]){

	int returnValue = 0;
	int i = 0;
	int pointerCounter = 0;

	    do
	    {
	        if(i == 0 && ((int)stringNumero[0] == (int)'-'
	        || (int)stringNumero[0] == (int)'+'))
	        {
	            i = 1;
	        }

	        if(stringNumero[i] == '.')
	        {
	            pointerCounter++;
	        }
	        else
	        {
	            if((int)stringNumero[i] >= (int)'0'
	                && (int)stringNumero[i] <= (int)'9' && pointerCounter <= 1)
	            {
	                returnValue = 0;
	            }
	            else
	            {
	                returnValue = 1;
	                break;
	            }
	        }
	        i++;
	    }while(stringNumero[i] != '\0');

	return returnValue;

}

char checkContinue()
{
    char continuar='S';

    inputString(&continuar, "Confirme para continuar [S]i [N]o : ", "Confirme para continuar [S]i [N]o : ", 1, 1);
    continuar=toupper(continuar);

    return continuar;
}
