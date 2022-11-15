/*
 ============================================================================
Cubilla Damian
Escribir y leer un archivo binario con 5 alumnos
(utilizar la estructura del ejercicio 18-2).
Mostrar los datos luego de la lectura del archivo.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int legajo;
	char nombre[21];
	int nota;
}eAlumno;

int main(void) {
	setbuf(stdout, NULL);
	FILE* pArchivo;
	eAlumno miAlumno[5] = {{1, "walter", 4},{2, "carmen", 6},{3, "damian", 7},{4, "camila", 5},{5, "aldana", 8}};

	//Escritura
	pArchivo = fopen("alumnos.dat", "wb");
	fwrite(miAlumno,sizeof(eAlumno), 5, pArchivo);
	fclose(pArchivo);

	//Lectura
	pArchivo=fopen("alumnos.dat", "rb");
	fread(miAlumno,sizeof(eAlumno), 5, pArchivo);
	fclose(pArchivo);

	for(int i=0;i<5;i++)
	{
		printf("legajo: %d - nombre: %s - nota: %d\n", miAlumno[i].legajo, miAlumno[i].nombre, miAlumno[i].nota);
	}
	return EXIT_SUCCESS;
}
