/*
 ============================================================================
Cubilla Damian
Ejercicio 7:
Realizar el algoritmo que permita ingresar los datos de los alumnos de una división de la UTN FRA,
los datos solicitados son:
Legajo
Tipo cursada(L: "libre" - P: "presencial" – R: "remota")
Cantidad de materias( mas de cero y menos de 8)
Sexo (F: “femenino” – M: “masculino” , O: “no binario”)
Nota promedio (entre 0 y 10)
Edad (validar)
Se debe informar de existir, o informar que no existe , en el caso que corresponda.
a) El Legajo del mejor promedio femenino.
b) El legajo del más joven de los alumnos masculinos entre los que dan libre.
c) El promedio de nota por sexo.
d) La edad y legajo del que cursa más materias. (Sin importar su género)

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int legajo;
	char tipoCursada;
	int cantidadMaterias;
	char sexo;
	int promedio;
	int edad;
	int mejorPromF;
	int legajoFem;

	mejorPromF=0;
	legajoFem=0;

	for(int i=0;i<3;i++)
	{
		printf("Ingresar legajo: ");
		scanf("%d", &legajo);
		printf("Ingrese tipo de cursada - L:libre - P:presencial – R:remota.. ");
		fflush(stdin);
		scanf("%c", &tipoCursada);
		printf("Ingresar la cantidad de materias: ");
		scanf("%d", &cantidadMaterias);
		while(cantidadMaterias<0 || cantidadMaterias>8)
		{
			printf("Esa cantidad de materias no existen, ingrese nuevamente: ");
			scanf("%d", &cantidadMaterias);
		}
		printf("Ingresar sexo - F: “femenino” – M: “masculino” , O: “no binario” .. ");
		fflush(stdin);
		scanf("%c", &sexo);
		printf("Ingrese su promedio: ");
		scanf("%d", &promedio);
		while(promedio<0 || promedio>10)
		{
			printf("Ese promedio no existen, ingrese nuevamente: ");
			scanf("%d", &promedio);
		}
		printf("Ingrese su edad: ");
		scanf("%d", &edad);
		while(edad<0 || edad>80)
		{
			printf("Edad no valida, ingrese nuevamente: ");
			scanf("%d", &edad);
		}


		if(sexo=='f')
		{
			if(promedio>mejorPromF)
			{
				mejorPromF=promedio;
				legajoFem=legajo;
			}
		}

	}

	if(legajoFem==0)
	{
		printf("a.No existe el legajo del mejor promedio femenino!\n");
	}
	else
	{
		printf("a.El legajo del mejor promedio femenino es: %d\n", legajoFem);
	}


	/*
	printf("El legajo es: %d", legajo);
	printf("Cursada: %c", tipoCursada);
	printf("Cantidad materias: %d", cantidadMaterias);
	printf("sexo: %c", sexo);
	printf("Promedio: %d", promedio);
	printf("Edad: %d", edad);
*/
	return EXIT_SUCCESS;
}
