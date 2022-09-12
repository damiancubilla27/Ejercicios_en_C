/*
 * validacion.c
 *
 *  Created on: 8 sep. 2022
 *      Author: damia
 */
#include <stdio.h>
#include <stdlib.h>
#include "validacion.h"

int IngresarCelsius(void)
{
    int retorno;
    do{
        printf("Ingrese la temperatura en celsius: ");
        scanf("%d", &retorno);
    }while(retorno<0 || retorno>100);
    return retorno;
}

int IngresarFahrenheit(void)
{
    int retorno;
    do{
        printf("Ingrese la temperatura en fahrenheit: ");
        scanf("%d", &retorno);
    }while(retorno<32 || retorno>212);
    return retorno;
}
