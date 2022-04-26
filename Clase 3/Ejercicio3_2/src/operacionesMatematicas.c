/*
 * operacionesMatematicas.c
 *
 *  Created on: 11 abr. 2022
 *      Author: damia
 */

#include <stdio.h>
#include <stdlib.h>

void SumarNumeros(int primerNumero, int segundoNumero, int* regreso)
{
	int suma;
	suma=primerNumero+segundoNumero;
	*regreso=suma;
}
void RestarNumeros(int primerNumero, int segundoNumero, int* regreso)
{
	int resta;
	resta=primerNumero-segundoNumero;
	*regreso=resta;
}
void MultiplicarNumeros(int primerNumero, int segundoNumero, int* regreso)
{
	int multi;
	multi=primerNumero*segundoNumero;
	*regreso=multi;
}
int DividirNumeros(int primerNumero, int segundoNumero, float* regreso)
{
	int ret;
	float dividir;
	if(segundoNumero!=0)
	{
		dividir=(float)primerNumero/segundoNumero;
		*regreso=dividir;
		ret=1;
	}
	else
	{
		ret=0;
	}
	return ret;
}
