/*
 ============================================================================
Cubilla Damian
- Definir un array de 10 alumnos.
- Definir un array de 3 divisiones.
- Relacionar los 10 alumnos con las 3 divisiones.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int idDivision;//PK
	char nombreDivision[5];
	int cuatrimestre;
}eDivision;

typedef struct
{
	int idAlumno;//PK
	char nombre[21];
	char apellido[21];
	int edad;
	int idDivision;//FK
}eAlumno;

void listarDivision(eDivision divisiones[], int tam);
void listarAlumnos(eAlumno alumnos[], int tam);
void listarAlumnosPorDivision(eAlumno alumnos[], int tam, eDivision divisiones[], int tamano);
void listarDivisionesPorAlumnos(eAlumno alumnos[], int tam, eDivision divisiones[], int tamano);

int main(void) {
	setbuf(stdout, NULL);
	eDivision listaDivisiones[3]={{1, "1C", 1},{2, "3A", 2}, {3, "2B", 2}};
	eAlumno listaAlumnos[10]={{100, "Juan", "Gomez", 20, 1},
								{101, "Maria", "Ruiz", 18, 3},
								{102, "Damian", "Cubilla", 26, 2},
								{103, "Jose", "Azzaro", 32, 1},
								{104, "Viviana", "Canosa", 22, 2},
								{105, "Mirtha", "Legrand", 66, 3},
								{106, "Antonio", "Rios", 50, 1},
								{107, "Luis", "Miguel", 45, 2},
								{108, "Marcelo", "Gallardo", 19, 2},
								{109, "Ignacio", "Fernandez", 30, 1}};

	listarDivision(listaDivisiones, 3);
	printf("-------------------------------------------------------\n");
	listarAlumnos(listaAlumnos, 10);
	printf("-------------------------------------------------------\n");
	listarAlumnosPorDivision(listaAlumnos, 10, listaDivisiones, 3);
	printf("-------------------------------------------------------\n");
	listarDivisionesPorAlumnos(listaAlumnos, 10, listaDivisiones, 3);
	return EXIT_SUCCESS;
}

void listarDivision(eDivision divisiones[], int tam)
{
	for(int i=0;i<tam;i++)
	{
		printf("idDivision: %d - nombre de la Division: %s  - cuatrimestre: %d\n", divisiones[i].idDivision, divisiones[i].nombreDivision, divisiones[i].cuatrimestre);
	}
}
void listarAlumnos(eAlumno alumnos[], int tam)
{
	for(int i=0;i<tam;i++)
	{
		printf("idAlumno: %d - nombre: %s - apellido: %s - edad: %d - idDivision: %d\n", alumnos[i].idAlumno, alumnos[i].nombre, alumnos[i].apellido, alumnos[i].edad, alumnos[i].idDivision);
	}
}

void listarAlumnosPorDivision(eAlumno alumnos[], int tam, eDivision divisiones[], int tamano)
{
	for(int i=0;i<tam;i++)
	{
		for(int j=0;j<tamano;j++)
		{
			if(alumnos[i].idDivision == divisiones[j].idDivision)
			{
				printf("id Alumno: %d - nombre: %s - apellido: %s - edad: %d - nombre de la division: %s\n", alumnos[i].idAlumno, alumnos[i].nombre, alumnos[i].apellido, alumnos[i].edad, divisiones[j].nombreDivision);
				break;
			}
		}
	}
}

void listarDivisionesPorAlumnos(eAlumno alumnos[], int tam, eDivision divisiones[], int tamano)
{
	for(int i=0;i<tamano;i++)
	{
		for(int j=0;j<tam;j++)
		{
			if(divisiones[i].idDivision==alumnos[j].idDivision)
			{
				printf("id Divison: %d - nombre: %s - apellido: %s - edad: %d - nombre de la division: %s\n", divisiones[i].idDivision, alumnos[j].nombre, alumnos[j].apellido, alumnos[j].edad, divisiones[i].nombreDivision);

			}
		}
	}
}
