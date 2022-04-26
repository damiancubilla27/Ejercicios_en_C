/*
 * utnGet.h
 *
 *  Created on: 13 abr. 2022
 *      Author: damia
 */

#ifndef UTNGET_H_
#define UTNGET_H_

int UtnGetNumeroEntero(int *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);
int UtnGetNumeroFlotante(float *resultado, char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos);
int UtnGetCaracter(char *resultado, char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos, char minimoMinuscula, char maximoMinuscula);

#endif /* UTNGET_H_ */
