/*
 ============================================================================
Cubilla Damian
Ejercicio 8-1:
Crear la estructura Jugador (nombre, goles metidos, partidos jugados, promedio de goles).
Crear una función que permita cargar los datos de un jugador y otra que los muestre.
Una tercera función calculará el promedio de goles.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char nombre[21];
	int golesMetidos;
	int partidosJugados;
	float promedioGoles;
}eJugador;

eJugador ingresoJugador(void);
void mostrarJugador(eJugador datoJugador);
float sacarPromedio(eJugador datoJugador);

int main(void) {
	setbuf(stdout, NULL);
	eJugador unJugador;
	float promedio;

	unJugador=ingresoJugador();
	mostrarJugador(unJugador);
	promedio=sacarPromedio(unJugador);
	printf("4.El promedio de goles es %.2f", promedio);

	return EXIT_SUCCESS;
}

eJugador ingresoJugador(void)
{
	eJugador eRetorno;
	printf("Ingrese nombre: ");
	fflush(stdin);
	scanf("%[^\n]", eRetorno.nombre);
	printf("Ingrese goles metidos: ");
	scanf("%d", &eRetorno.golesMetidos);
	printf("Ingrese partidos jugados: ");
	scanf("%d", &eRetorno.partidosJugados);

	return eRetorno;
}

void mostrarJugador(eJugador datoJugador)
{
	printf("1.Nombre: %s\n2.Goles metidos: %d\n3.Partido Jugados: %d\n", datoJugador.nombre, datoJugador.golesMetidos, datoJugador.partidosJugados);
}

float sacarPromedio(eJugador datoJugador)
{
	float retorno;
	retorno=(float)datoJugador.golesMetidos/datoJugador.partidosJugados;
	return retorno;
}
