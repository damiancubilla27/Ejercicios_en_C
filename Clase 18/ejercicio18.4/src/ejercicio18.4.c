/*
 ============================================================================
Cubilla Damian
Ejercicio 18-4:
Escribir y leer un archivo binario con 5 números enteros.
Mostrar los datos luego de la lectura del archivo

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	FILE* pArchivo;
	int arrayEnteros[5]={1,2,3,4,5};
	int numeros[5];
	//Escribo
	pArchivo=fopen("numeros.dat", "wb");
	fwrite(arrayEnteros, sizeof(int), 5, pArchivo);
	fclose(pArchivo);

	//Leer
	pArchivo=fopen("numeros.dat", "rb");
	fread(numeros, sizeof(int), 5, pArchivo);
	fclose(pArchivo);

	//Imprimo lo guardado
	for(int i=0;i<5;i++)
	{
		printf("%d\n", numeros[i]);
	}

	return EXIT_SUCCESS;
}
