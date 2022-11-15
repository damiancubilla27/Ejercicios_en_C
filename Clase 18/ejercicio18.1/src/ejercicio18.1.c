/*
 ============================================================================
 Cubilla Damian
 Ejercicio 18-0:
Guardar en una variable nombre y apellido. Guardar el dato en un archivo de
texto, leerlo y luego mostrarlo.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int ingreseNombre(char* nombre);
int crearYGuardarArchivo(char* cadena, char* path);
int leerYMostrarArchivo(char* cadena, char* path);

int main(void) {
	setbuf(stdout, NULL);
	char nombreApellido[41];

	ingreseNombre(nombreApellido);
	//Crear un archivo y guardar texto
	crearYGuardarArchivo(nombreApellido, "nombre.txt");

	//Leer y mostrar el texto
	leerYMostrarArchivo(nombreApellido, "nombre.txt");

	return EXIT_SUCCESS;
}

int ingreseNombre(char* nombre)
{
	int retorno=-1;
	if(nombre!=NULL)
	{
		retorno=0;
		printf("Ingrese su nombre: ");
		scanf("%[^\n]", nombre);
	}
	return retorno;
}

int crearYGuardarArchivo(char* cadena, char* path)
{
	FILE* pArchivo;
	int exito=0;
	if(path!=NULL && cadena!=NULL)
	{
		exito=-1;
		pArchivo=fopen(path, "w");
		if(pArchivo!=NULL)
		{
			fprintf(pArchivo, "Su nombre es: %s",cadena);
			fclose(pArchivo);
		}
	}
	return exito;
}

int leerYMostrarArchivo(char* cadena, char* path)
{
	FILE* pArchivo;
	int exito=0;
	if(path!=NULL && cadena!=NULL)
	{
		exito=-1;
		pArchivo=fopen(path, "r");
		if(pArchivo!=NULL)
		{
			fgets(cadena, 51, pArchivo);
			fclose(pArchivo);
			puts(cadena);
		}
	}
	return exito;
}
