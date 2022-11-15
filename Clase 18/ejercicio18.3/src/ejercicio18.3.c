/*
 ============================================================================
Cubilla Damian
Crear la estructura alumno (legajo, nombre, nota), un array de este tipo y
hardcodearlo con 3 datos.
Escribir en un archivo de texto los datos del array, separando cada campo
con una coma y cada alumno con un salto de línea. Mostrar los datos luego
de haber leído los datos desde el archivo, en un array de cadenas.
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
	eAlumno misAlumnos[3]={{1, "walter", 4},{2, "carmen", 6},{3, "damian", 7}};
	eAlumno mustraAlum[3];

	pArchivo=fopen("alumnos.txt", "w");

	for(int i=0;i<3;i++)
	{
		fprintf(pArchivo, "%d, %s, %d\n", misAlumnos[i].legajo, misAlumnos[i].nombre, misAlumnos[i].nota);
	}
	fclose(pArchivo);

	pArchivo=fopen("alumnos.txt", "r");
	fread(mustraAlum,sizeof(eAlumno), 3, pArchivo);
	fclose(pArchivo);

	for(int j=0;j<3;j++)
	{
		printf("%d, %s, %d\n", mustraAlum[j].legajo, mustraAlum[j].nombre, mustraAlum[j].nota);
	}

	return EXIT_SUCCESS;
}
