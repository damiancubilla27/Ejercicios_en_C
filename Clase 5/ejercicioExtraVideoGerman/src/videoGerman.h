/*
 * videoGerman.h
 *
 *  Created on: 16 sep. 2022
 *      Author: damia
 */

#ifndef VIDEOGERMAN_H_
#define VIDEOGERMAN_H_

void ingresarNumeros(int num[], int tam);
void validarNumeros(int num[], int tam);
int buscarNumeroMaximo(int num[], int tam);
int coincidirNumero(int num[], int tam, int numeroValor);
int buscarNumeroMinimo(int num[], int tam);
void imprimirIndices(int num[], int tam, int numeroValor);
void esMayorADiez(int num[], int tam);
void mostrarArray(int num[], int tam);
void mostrarMenorMayorQue(int num[], int tam);
float promedioNumeros(int num[], int tam);

#endif /* VIDEOGERMAN_H_ */
