/*
 ============================================================================
Cubilla Damian
Ejercicio 3-6 (CADENAS):
Crear una función que reciba como parámetro una cadena de caracteres. Dicha función
permitirá reemplazar las vocales de la cadena por asteriscos. Retornara la cantidad de
reemplazos que se produjeron.
CADENAS -> C*D*N*S
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 31

int reemplazaVocales(char arrayCad[], int tam);

int main(void) {
	setbuf(stdout, NULL);
	char cadena[TAM];
	int vocales;
	puts("Ingrese un cadena: ");
	gets(cadena);

	vocales=reemplazaVocales(cadena, TAM);
	printf("%s  - Vocales en la palabra: %d", cadena, vocales);
	return EXIT_SUCCESS;
}

int reemplazaVocales(char arrayCad[], int tam)
{
	int retorno;
	retorno=-1;
	for(int i=0;i<tam;i++)
	{
		if(arrayCad[i]=='a' || arrayCad[i]=='e' || arrayCad[i]=='i' || arrayCad[i]=='o' || arrayCad[i]=='u')
		{
			arrayCad[i] = '*';
			retorno++;
		}
	}
	return retorno;
}
