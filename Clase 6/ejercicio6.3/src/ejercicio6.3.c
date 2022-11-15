/*
 ============================================================================
Cubilla Damian
Ejercicio 6-3:
Pedirle al usuario su nombre y apellido (en variables separadas, una para el nombre y otra para el apellido).
Ninguna de las dos variables se puede modificar.
Debemos lograr guardar en una tercer variable el apellido y el nombre con el siguiente formato:
Por ejemplo:
Si el nombre es juan ignacio y el apellido es gOmEz, la salida debería ser:
Gomez, Juan Ignacio
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void ingresarCadena(char cadenaUno[], char cadenaDos[]);
void concatenandoTextos(char cadenaUno[], char cadenaDos[], char cadenaTres[]);
void indicarMayusculas(char cadeUno[], int tam);

int main(void) {
	setbuf(stdout, NULL);
	char nombre[20];
	char apellido[20];
	char nombreYApellido[41];
	int longitud;

	ingresarCadena(nombre, apellido);

	concatenandoTextos(nombre, apellido, nombreYApellido);

	longitud=strlen(nombreYApellido);

	indicarMayusculas(nombreYApellido, longitud);

	puts(nombreYApellido);
	return EXIT_SUCCESS;
}

void ingresarCadena(char cadenaUno[], char cadenaDos[])
{
	printf("Ingrese su nombre: ");
	gets(cadenaUno);
	printf("Ingrese su apellido: ");
	gets(cadenaDos);
}

void concatenandoTextos(char cadenaUno[], char cadenaDos[], char cadenaTres[])
{
	strcpy(cadenaTres, cadenaDos);
	strcat(cadenaTres, ", ");
	strcat(cadenaTres, cadenaUno);
	strlwr(cadenaTres);
	cadenaTres[0]=toupper(cadenaTres[0]);
}

void indicarMayusculas(char cadeUno[], int tam)
{
	for(int i=0;i<tam;i++)
	{
		if(isspace(cadeUno[i]))
		{
			cadeUno[i+1]=toupper(cadeUno[i+1]);
		}
	}
}

