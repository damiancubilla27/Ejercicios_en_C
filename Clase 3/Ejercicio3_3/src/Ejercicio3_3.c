/*
 ============================================================================
 Name        : Ejercicio3_3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utnGet.h"

int main(void) {
	setbuf(stdout, NULL);
	//enteros
	int edad;
	int vueltaEntera;
	//floatantes
	float decimal;
	int vueltaFlotante;
	//caracter
	char letra;
	int vueltaCaracter;

	vueltaEntera=UtnGetNumeroEntero(&edad, "Ingrese edad: ", "Error en el ingreso de datos!\n", 0, 100, 3);
	if(vueltaEntera==0)
	{
		printf("La edad es: %d\n", edad);
	}
	else
	{
		printf("Se le acabaron los reintentos!");
	}

	vueltaFlotante=UtnGetNumeroFlotante(&decimal, "Ingrese un numero decimal: ", "Error en el ingreso de datos!\n", 0, 100, 2);
	if(vueltaFlotante==0)
	{
		printf("El decimal es: %.2f\n", decimal);
	}
	else
	{
		printf("Se le acabaron los reintentos!");
	}

	vueltaCaracter=UtnGetCaracter(&letra, "Ingrese una letra: ", "Error en el ingreso de datos!\n", 'A', 'Z', 2, 'a', 'z');
	if(vueltaCaracter==0)
	{
		printf("La letra es: %c\n", letra);
	}
	else
	{
		printf("Se le acabaron los reintentos!");
	}
	return EXIT_SUCCESS;
}


