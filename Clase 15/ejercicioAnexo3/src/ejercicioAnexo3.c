/*
 ============================================================================
Cubilla Damian
3-Dada la siguiente estructura: int legajo; char nombre[20]; int edad;
Realizar una función que cargue un array de 3 estudiantes.
Retorna el estudiante dado de alta y por parámetro 0 si funcionó correctamente -1 mal.
Una vez devuelto el estudiante cargarlo en una posición del array.
Al final mostrar el array cargado
Utilizar aritmetica de punteros

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct
{
	int legajo;
	char nombre[20];
	int edad;
}eEstudiante;

eEstudiante cargarEstudiante();
int cargarEstudiantes(eEstudiante* pEstu, int tam);
void imprimirArray(eEstudiante* pEstu, int tam);

int main(void) {
	setbuf(stdout, NULL);
	eEstudiante arrayEstudiantes[3];
	eEstudiante* pEstudiante;
	pEstudiante=arrayEstudiantes;

	if(cargarEstudiantes(pEstudiante, 3)==0)
	{
		imprimirArray(pEstudiante, 3);
	}
	else
	{
		printf("Todo mal!!");
	}

	return EXIT_SUCCESS;
}

eEstudiante cargarEstudiante()
{
	eEstudiante auxEstu;
	printf("Ingrese legajo: ");
	scanf("%d", &auxEstu.legajo);
	printf("Ingrese nombre: ");
	fflush(stdin);
	scanf("%s", auxEstu.nombre);
	printf("Ingrese edad: ");
	scanf("%d", &auxEstu.edad);

	return auxEstu;
}

int cargarEstudiantes(eEstudiante* pEstu, int tam)
{
	int retorno=-1;
	if(pEstu != NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			*(pEstu+i)=cargarEstudiante();
		}
		retorno=0;
	}
	return retorno;
}

void imprimirArray(eEstudiante* pEstu, int tam)
{
	for(int i=0;i<tam;i++)
	{
		printf("Legajo %d - Nombre %s - Edad %d\n", (pEstu+i)->legajo, (pEstu+i)->nombre, (pEstu+i)->edad);
	}
}
