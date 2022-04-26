/*
 * operaciones.c
 *
 *  Created on: 11 abr. 2022
 *      Author: damia
 */

#include <stdio.h>
#include <stdlib.h>

void SumarEnteros(int numeroUno, int numeroDos, int* resultado)
{
	int cuenta;
	cuenta=numeroUno+numeroDos;
	* resultado=cuenta;
}

void RestarEnteros(int numeroUno, int numeroDos, int* resultado)
{
	int cuenta;
	cuenta=numeroUno-numeroDos;
	* resultado=cuenta;
}

void MultiplicarEnteros(int numeroUno, int numeroDos, int* resultado)
{
	int cuenta;
	cuenta=numeroUno*numeroDos;
	*resultado=cuenta;
}

int DividirEnteros(int numeroUno, int numeroDos, float* resultado)
{
	float cuenta;
	int error;

	if(numeroDos!=0)
	{
		cuenta=(float)numeroUno/numeroDos;
		*resultado=cuenta;
		error=1;
	}
	else
	{
		error=0;
	}
	return error;
}

