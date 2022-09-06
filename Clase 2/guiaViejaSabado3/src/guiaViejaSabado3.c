/*
 ============================================================================
Ejercicio 1-3:
Realizar el algoritmo que permita ingresar los datos de los alumnos de una división de
la UTN FRA, los datos solicitados son:
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
	int cantMaterias;
	char sexo;
	int promedio;
	int edad;
	int banderaFem=1;
	int promFemenino;
	int legajoFemenino;
	int banderaMascu=1;
	int edadMascu;
	int legajoMasJoven;
	int acumuFem=0;
	int acumuMas=0;
	int contaFem=0;
	int contaMas=0;
	float promF;
	float promM;
	int bandeMasMate=1;
	int masMate;
	int edadMasMate;
	int legajoMasMate;
	char respuesta;

	do{
		printf("Ingrese numero de legajo: ");
		scanf("%d", &legajo);
		printf("Ingrese tipo de cursada (L: libre - P: presencial - R: remota): ");
		fflush(stdin);
		scanf("%c", &tipoCursada);
		printf("Ingrese cantidad de materias: ");
		scanf("%d", &cantMaterias);
		while(cantMaterias<1 || cantMaterias>8)
		{
			printf("Reingrese cantidad de materias: ");
			scanf("%d", &cantMaterias);
		}
		printf("Ingrese el sexo (F: femenino - M: masculino - X: no binario): ");
		fflush(stdin);
		scanf("%c", &sexo);
		printf("Ingrese nota promedio: ");
		scanf("%d", &promedio);
		while(promedio<0 || promedio>10)
		{
			printf("Reingrese nota promedio: ");
			scanf("%d", &promedio);
		}
		printf("Ingrese edad: ");
		scanf("%d", &edad);
		while(edad<17 || edad>90)
		{
			printf("Ingrese edad: ");
			scanf("%d", &edad);
		}

		if(sexo=='F')
		{
			acumuFem=acumuFem+promedio;
			contaFem++;
			if(banderaFem==1)
			{
				legajoFemenino=legajo;
				promFemenino=promedio;
				banderaFem=0;
			}
			else
			{
				if(promFemenino<promedio)
				{
					legajoFemenino=legajo;
					promFemenino=promedio;
				}
			}
		}

		if(sexo=='M')
		{
			acumuMas=acumuMas+promedio;
			contaMas++;
			if(tipoCursada=='L')
			{
				if(banderaMascu==1)
				{
					legajoMasJoven=legajo;
					edadMascu=edad;
					banderaMascu=0;
				}
				else
				{
					if(edad<edadMascu)
					{
						legajoMasJoven=legajo;
						edadMascu=edad;
					}
				}
			}
		}

		if(bandeMasMate==1)
		{
			masMate=cantMaterias;
			edadMasMate=edad;
			legajoMasMate=legajo;
			bandeMasMate=0;
		}
		else
		{
			if(masMate<cantMaterias)
			{
				masMate=cantMaterias;
				edadMasMate=edad;
				legajoMasMate=legajo;
			}
		}
		printf("Desea contunuar? (s/n): ");
		fflush(stdin);
		scanf("%c", &respuesta);
	}while(respuesta != 'n');

	promF=(float)acumuFem/contaFem;
	promM=(float)acumuMas/contaMas;

	printf("a) El Legajo del mejor promedio femenino es: %d\n", legajoFemenino);
	printf("b) El legajo del más joven de los alumnos masculinos entre los que dan libre es: %d\n", legajoMasJoven);
	printf("c) El promedio de nota por sexo es: Masculino: %.2f - Femenino: %.2f\n", promM, promF);
	printf("d) La edad y legajo del que cursa más materias es: edad: %d - legajo: %d\n", edadMasMate, legajoMasMate);
	return EXIT_SUCCESS;
}
