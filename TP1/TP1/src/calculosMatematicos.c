/*
 * calculosMatematicos.c
 *
 *  Created on: 22 sep. 2022
 *      Author: damia
 */


float costoTotal(float manteni, float aum)
{
	float retorno;
	retorno=manteni+aum;
	return retorno;
}

float calcularAumento(float manteni)
{
	float retorno;
	retorno=((float)35*manteni)/100;
	return retorno;
}

float calcularJugadoresEnEuropa(int juga)
{
	float retorno;
	retorno=((float)51*juga)/100;
	return retorno;
}

float calcularMantenimiento(float hospe, float com, float trans)
{
	float retorno;
	retorno=hospe+com+trans;
	return retorno;
}

float calcularPromedio(int confederacion, int numeroDeJugadores)
{
	float retorno;
	retorno=(float)confederacion/numeroDeJugadores;
	return retorno;
}
