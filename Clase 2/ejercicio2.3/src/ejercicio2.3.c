/*
 ============================================================================
Cubilla Damian
Ejercicio 2-3:
Debemos alquilar el servicio de transporte para llegar a Mar del Plata con un grupo de personas,
de cada persona debemos obtener los siguientes datos:
número de cliente,
estado civil ('s' para soltero", 'c' para casado o 'v' viudo),
edad( solo mayores de edad, más de 17),
temperatura corporal (validar por favor)
y genero('f' para femenino, 'm' para masculino, 'x' para no binario).
NOTA: El precio por pasajero es de $600.
Se debe informar (solo si corresponde):
a) La cantidad de personas con estado "viudo" de más de 60 años.
b) el número de cliente y edad de la mujer soltera más joven.
c) cuánto sale el viaje total sin descuento.
d) si hay más del 50% de los pasajeros que tiene más de 60 años ,
el precio final tiene un descuento del 25%, que solo mostramos si corresponde.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	char respuesta;
	int numeroCliente=0;
	char estadoCivil;
	int edad;
	int temperaturaCorpo;
	char genero;
	int acumuViudo=0;
	int flagFem=1;
	int clienteMujer=0;
	int edadMujer=0;
	int contadorClientes=0;
	int cuenta=0;
	do
	{
		printf("Ingrese numero de cliente: ");
		scanf("%d", &numeroCliente);
		printf("Ingrese estado civil (s para soltero, c para casado o v viudo): ");
		fflush(stdin);
		scanf("%c", &estadoCivil);
		printf("Ingresar edad: ");
		scanf("%d", &edad);
		while(edad<17)
		{
			printf("Reingresar edad: ");
			scanf("%d", &edad);
		}
		printf("Ingrese temperatura corporal: ");
		scanf("%d", &temperaturaCorpo);
		while(temperaturaCorpo<20 || temperaturaCorpo>45)
		{
			printf("Reingrese temperatura corporal: ");
			scanf("%d", &temperaturaCorpo);
		}
		printf("Ingrese genero(f para femenino, m para masculino, x para no binario): ");
		fflush(stdin);
		scanf("%c", &genero);

		if(estadoCivil=='v')
		{
			if(edad>60)
			{
				acumuViudo++;
			}
		}
		if(genero=='f' && estadoCivil=='s')
		{
			if(flagFem==1)
			{
				clienteMujer=numeroCliente;
				edadMujer=edad;
				flagFem=0;
			}
			else
			{
				if(edad<edadMujer)
				{
					clienteMujer=numeroCliente;
					edadMujer=edad;
				}
			}
		}
		contadorClientes++;

		//ACA ME QUEDE ME FALTA PUNTO D

		printf("Desea continuar? s/n: ");
		fflush(stdin);
		scanf("%c", &respuesta);
	}while(respuesta!='n');
	cuenta=contadorClientes*600;

	if(numeroCliente!=0)
	{
		printf("a) La cantidad de personas con estado viudo de más de 60 años: %d\n", acumuViudo);
		printf("b) el número de cliente y edad de la mujer soltera más joven: num: %d - edad: %d\n", clienteMujer, edadMujer);
		printf("c) cuanto sale el viaje total sin descuento: %d\n", cuenta);
	}

	return EXIT_SUCCESS;
}
