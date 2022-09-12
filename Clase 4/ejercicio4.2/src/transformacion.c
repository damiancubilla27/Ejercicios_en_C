/*
 * transformacion.c
 *
 *  Created on: 8 sep. 2022
 *      Author: damia
 */
#include <stdio.h>
#include <stdlib.h>
#include "transformacion.h"

int celsiusAFahrenheit(int grado)
{
	int retorno;
	retorno= (grado*1.8)+32;
	return retorno;
}

int fahrenheitACelsius(int grado)
{
	int retorno;
	retorno= (grado-32)/1.8;
	return retorno;
}
