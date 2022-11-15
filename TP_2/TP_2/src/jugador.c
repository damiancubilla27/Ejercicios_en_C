#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "jugador.h"

//---------------------------------------------- PUNTO 1
void jugador_inicializarJugadores(eJugador listaJugadores[], int tam)
{
	for(int i=0;i<tam;i++)
	{
		listaJugadores[i].isEmpty = LIBRE;
	}
}

int jugador_buscarEspacioLibre(eJugador listaJugadores[], int tam)
{
	int retorno=-1;
	for(int i=0;i<tam;i++)
	{
		if(listaJugadores[i].isEmpty==LIBRE)
		{
			retorno=i;
			break;
		}
	}
	return retorno;
}

eJugador jugador_cargarUnJugador(void)
{
	eJugador auxJugador;
	int posicion;
	utn_getArrayCadena(auxJugador.nombre, "Ingrese nombre del jugador: ", "Error, reingrese nombre del jugador: ", 50);
	utn_getNumeroEntero(&posicion, "1. Arquero\n2. Defensor\n3. Mediocampista\n4. Delantero\nIngrese numero de posicion: ", "Error, reingrese numero de posicion: ", 1, 4);
	switch(posicion)
	{
	case 1:
		strcpy(auxJugador.posicion, "Arquero");
		break;
	case 2:
		strcpy(auxJugador.posicion, "Defensor");
		break;
	case 3:
		strcpy(auxJugador.posicion, "Mediocampista");
		break;
	case 4:
		strcpy(auxJugador.posicion, "Delantero");
		break;
	}
	utn_getEnteroCorto(&auxJugador.numeroCamiseta, "Ingrese numero de camiseta: ", "Error, reingrese numero de camiseta: ", 1, 100);
	utn_getNumeroEntero(&auxJugador.idConfederacion, "1. CONMEBOL\n2. UEFA\n3. AFC\n4. CAF\n5. CONCACAF\n6. OFC\nIngrese numero de confederacion: ", "Error, reingrese numero de confederacion: ", 1, 6);
	utn_getNumeroFlotante(&auxJugador.salario, "Ingrese salario: ", "Error, reingrese salario: ", 1, 200000);
	utn_getEnteroCorto(&auxJugador.aniosContrato, "Ingrese anios de contrato: ", "Error, reingrese anios de contrato: ", 1, 20);
	return auxJugador;
}

void jugador_agregarJugador(eJugador listajugadores[], int tam)
{
	int index;
	index=jugador_buscarEspacioLibre(listajugadores, tam);

	if(index!=-1)
	{
		listajugadores[index]=jugador_cargarUnJugador();
		if(jugador_verificarConfirmacion("Ingrese S para cargar el jugador: ")==0)
		{
			listajugadores[index].isEmpty=OCUPADO;
			listajugadores[index].id=index+1;
			printf("El jugador se agrego correctamente!\n");
		}
		else
		{
			printf("Se cancelo el dar de alta un jugador!\n");
		}
	}
	else
	{
		printf("No queda mas espacio para agregar jugador.\n");
	}

}

//---------------------------------------------- PUNTO 2
void jugador_mostrarTodosLosJugadores(eJugador listajugadores[], int tam, eConfederacion listaConfe[], int tamano)
{
	printf("                                          *** LISTA DE JUGADORES ***\n");
	printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("| ID |                     NOMBRE                         |       POSICION       |  N DE CAMISETA  |     SUELDO      |     CONFEDERACION    | ANIOS CONTRATO |\n");
	printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

	for(int i=0;i<tam;i++)
	{
		if(listajugadores[i].isEmpty==OCUPADO)
		{
			printf("| %d  | %-50s | %-20s | %-15d | %-15.2f | ", listajugadores[i].id, listajugadores[i].nombre, listajugadores[i].posicion, listajugadores[i].numeroCamiseta, listajugadores[i].salario);
			jugador_listarConfederacion(listajugadores, i, listaConfe, tamano);
			printf(" %-15d|\n", listajugadores[i].aniosContrato);
		}
	}
	printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void jugador_listarConfederacion(eJugador listajugadores[], int index, eConfederacion listaConfe[],int tamano)
{
	for(int j=0;j<tamano;j++)
	{
		if(listajugadores[index].idConfederacion==listaConfe[j].id)
		{
			printf("%-20s |", listaConfe[j].nombre);
		}
	}
}

int jugador_bajaDeJugador(eJugador listajugadores[], int tam, eConfederacion listaConfe[],int tamano)
{
	int retorno=-1;
	int numero;
	int indice;
	jugador_mostrarTodosLosJugadores(listajugadores, tam, listaConfe, tamano);
	utn_getNumeroEntero(&numero, "Ingrese el numero ID del jugador a dar de baja: ", "Error, reingrese el numero ID del jugador a dar de baja: ", 1, 3000);
	indice=jugador_buscarPorId(listajugadores, tam, numero);
	if(indice!=-1)
	{
		if(jugador_verificarConfirmacion("Ingrese S para dar la baja: ")==0)
		{
			printf("El jugador '%s' se dio de baja correctamente\n", listajugadores[indice].nombre);
			listajugadores[indice].isEmpty=LIBRE;
			retorno=0;
		}
		else
		{
			printf("Se cancelo la baja del jugador!\n");
		}
	}
	else
	{
		printf("Jugador no encontrado!\n");
	}
	return retorno;
}

int jugador_buscarPorId(eJugador listajugadores[], int tam, int id)
{
	int retorno=-1;
	for(int i=0;i<tam;i++)
	{
		if(listajugadores[i].isEmpty==OCUPADO && listajugadores[i].id==id)
		{
			retorno=i;
			break;
		}
	}
	return retorno;
}

//---------------------------------------------- PUNTO 3
int jugador_modificarJugador(eJugador listajugadores[], int tam, eConfederacion listaConfe[],int tamano)
{
	int retorno = -1;
	int id;
	int indice;
	int opcion;
	int posicion;
	jugador_mostrarTodosLosJugadores(listajugadores, tam, listaConfe, tamano);
	utn_getNumeroEntero(&id, "Ingrese el id del jugador a modificar: ", "Error, reingrese el id del jugador a modificar: ", 1, 3000);
	indice=jugador_buscarPorId(listajugadores, tam, id);
	if(indice!=-1)
	{
		do
		{
			utn_getNumeroEntero(&opcion, "1. Nombre\n2. Posicion\n3. Numero de Camiseta\n4. Confederación\n5. Salario\n6. Anios de Contrato\n7. Volver al Menu Principal\nIngrese opcion: ", "1. Nombre\n2. Posicion\n3. Numero de Camiseta\n4. Confederación\n5. Salario\n6. Anios de Contrato\n7. Volver al Menu Principal\nError, reingrese opcion: ", 1, 7);
			switch(opcion)
			{
			case 1:
				utn_getArrayCadena(listajugadores[indice].nombre, "Ingrese nuevo nombre: ", "Error, reingrese nuevo nombre: ", 50);
				system("pause");
				break;
			case 2:
				utn_getNumeroEntero(&posicion, "1. Arquero\n2. Defensor\n3. Mediocampista\n4. Delantero\nIngrese numero de la nueva posicion: ", "1. Arquero\n2. Defensor\n3. Mediocampista\n4. Delantero\nError, reingrese numero de posicion: ", 1, 4);
				switch(posicion)
				{
				case 1:
					strcpy(listajugadores[indice].posicion, "Arquero");
					break;
				case 2:
					strcpy(listajugadores[indice].posicion, "Defensor");
					break;
				case 3:
					strcpy(listajugadores[indice].posicion, "Mediocampista");
					break;
				case 4:
					strcpy(listajugadores[indice].posicion, "Delantero");
					break;
				}
				system("pause");
				break;
			case 3:
				utn_getEnteroCorto(&listajugadores[indice].numeroCamiseta, "Ingrese el nuevo numero de camiseta: ", "Error, reingrese nuevo numero de camiseta: ", 1, 100);
				system("pause");
				break;
			case 4:
				utn_getNumeroEntero(&listajugadores[indice].idConfederacion, "1. CONMEBOL\n2. UEFA\n3. AFC\n4. CAF\n5. CONCACAF\n6. OFC\nIngrese el nuevo numero de confederacion: ", "1. CONMEBOL\n2. UEFA\n3. AFC\n4. CAF\n5. CONCACAF\n6. OFC\nError, reingrese nuevo numero de confederacion: ", 1, 6);
				system("pause");
				break;
			case 5:
				utn_getNumeroFlotante(&listajugadores[indice].salario, "Ingrese nuevo salario: ", "Error, reingrese nuevo salario: ", 1, 200000);
				system("pause");
				break;
			case 6:
				utn_getEnteroCorto(&listajugadores[indice].aniosContrato, "Ingrese nuevo anios de contrato: ", "Error, reingrese nuevo anios de contrato: ", 1, 20);
				system("pause");
				break;
			}

		}while(opcion!=7);
		retorno=0;
	}
	else
	{
		printf("El id de jugador no encontrado!\n");
	}
	return retorno;
}

//---------------------------------------------- PUNTO 4
int jugador_listarImformes(eJugador listajugadores[], int tam, eConfederacion listaConfe[], int tamano)
{
	int retorno=-1;
	int opcion;
	do
	{
		utn_getNumeroEntero(&opcion, "1. Listado de los jugadores ordenados alfabéticamente por nombre de confederación y nombre de jugador"
				"						\n2. Listado de confederaciones con sus jugadores"
				"						\n3. Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio"
				"						\n4. Informar la confederación con mayor cantidad de años de contratos total"
				"						\n5. Informar porcentaje de jugadores por cada confederación"
				"						\n6. Informar cual es la región con más jugadores y el listado de los mismos"
				"						\n7. Salir\nIngrese opcion: ", "1. Listado de los jugadores ordenados alfabéticamente por nombre de confederación y nombre de jugador"
				"						\n2. Listado de confederaciones con sus jugadores"
				"						\n3. Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio"
				"						\n4. Informar la confederación con mayor cantidad de años de contratos total"
				"						\n5. Informar porcentaje de jugadores por cada confederación"
				"						\n6. Informar cual es la región con más jugadores y el listado de los mismos"
				"						\n7. Salir\nError, reingrese opcion: ", 1, 7);
		switch(opcion)
		{
		case 1:
			jugador_ordenarAlfabeticamente(listajugadores, tam, listaConfe, tamano);
			retorno=0;
			break;
		case 2:
			jugador_imprimirJugadorConfederacion(listajugadores, tam, listaConfe, tamano);
			retorno=0;
			break;
		case 3:
			jugador_listarTotalYPromedio(listajugadores, tam);
			retorno=0;
			break;
		case 4:
			jugador_imformarConfeMayorEnContratos(listajugadores, tam);
			retorno=0;
			break;
		case 5:
			jugador_imformarPorcentajeConfe(listajugadores, tam);
			retorno=0;
			break;
		case 6:
			jugador_informarRegionMasJugadores(listajugadores, tam, listaConfe, tamano);
			retorno=0;
			break;
		}

	}while(opcion!=7);
	return retorno;
}
// ------------------ Punto 4.1
int jugador_ordenarAlfabeticamente(eJugador listajugadores[], int tam, eConfederacion listaConfe[], int tamano)
{
	int retorno=-1;
	char nombreEnI[20];
	char nombreEnJ[20];
	eJugador auxJuga;

	for(int i=0;i<tam-1;i++)
	{
		for(int j=i+1;j<tam;j++)
		{
			if(listajugadores[i].isEmpty==OCUPADO && listajugadores[j].isEmpty==OCUPADO)
			{
				jugador_nombreConfederacion(listaConfe, tamano, listajugadores[i].idConfederacion, nombreEnI);
				jugador_nombreConfederacion(listaConfe, tamano, listajugadores[j].idConfederacion, nombreEnJ);
				if(strcmp(nombreEnI, nombreEnJ)>0 || (strcmp(nombreEnI, nombreEnJ)==0 && strcmp(listajugadores[i].nombre, listajugadores[j].nombre)>0))
				{
					auxJuga=listajugadores[i];
					listajugadores[i]=listajugadores[j];
					listajugadores[j]=auxJuga;
					retorno=0;
				}
			}
		}
	}
	jugador_mostrarTodosLosJugadores(listajugadores, tam, listaConfe, tamano);
	return retorno;
}

void jugador_nombreConfederacion(eConfederacion listaConfe[], int tamConfe, int indice, char* nombre)
{
	for(int i=0;i<tamConfe;i++)
	{
		if(listaConfe[i].id==indice)
		{
			strcpy(nombre, listaConfe[i].nombre);
		}
	}
}

// ------------------ Punto 4.2
int jugador_confirmarJugadorPorConfederacion(eJugador listajugadores[], int tam, int index)
{
	int retorno=-1;
	for(int i=0;i<tam;i++)
	{
		if(listajugadores[i].isEmpty==OCUPADO && listajugadores[i].idConfederacion==index)
		{
			retorno=0;
			break;
		}
	}
	return retorno;
}

void jugador_listarJugadorPorConfederacion(eJugador listajugadores[], int tam, int index, eConfederacion listaConfe[], int tamano)
{
	for(int i=0;i<tam;i++)
	{
		if(listajugadores[i].isEmpty==OCUPADO && listajugadores[i].idConfederacion==index)
		{
			printf("| %d  | %-50s | %-20s | %-15d | %-15.2f | ", listajugadores[i].id, listajugadores[i].nombre, listajugadores[i].posicion, listajugadores[i].numeroCamiseta, listajugadores[i].salario);
			jugador_listarConfederacion(listajugadores, i, listaConfe, tamano);
			printf(" %-15d|\n", listajugadores[i].aniosContrato);
		}
	}
}

void jugador_imprimirJugadorConfederacion(eJugador listajugadores[], int tam, eConfederacion listaConfe[], int tamano)
{
	if(jugador_confirmarJugadorPorConfederacion(listajugadores, tam,1)==0)
	{
		jugador_imprimirCarteleraConfe("CONFEDERACION CONMEBOL");
		jugador_listarJugadorPorConfederacion(listajugadores, tam, 1, listaConfe, tamano);
		jugador_imprimirSeparadorConfe();
	}
	else
	{
		jugador_imprimirCarteleraConfe("CONFEDERACION CONMEBOL");
		printf("NO SE INGRESARON JUGADORES DE LA CONFEDERACION CONMEBOL!\n");
		jugador_imprimirSeparadorConfe();
	}

	if(jugador_confirmarJugadorPorConfederacion(listajugadores, tam,2)==0)
	{
		jugador_imprimirCarteleraConfe("CONFEDERACION UEFA");
		jugador_listarJugadorPorConfederacion(listajugadores, tam, 2, listaConfe, tamano);
		jugador_imprimirSeparadorConfe();
	}
	else
	{
		jugador_imprimirCarteleraConfe("CONFEDERACION UEFA");
		printf("NO SE INGRESARON JUGADORES DE LA CONFEDERACION UEFA!\n");
		jugador_imprimirSeparadorConfe();
	}

	if(jugador_confirmarJugadorPorConfederacion(listajugadores, tam,3)==0)
	{
		jugador_imprimirCarteleraConfe("CONFEDERACION AFC");
		jugador_listarJugadorPorConfederacion(listajugadores, tam, 3, listaConfe, tamano);
		jugador_imprimirSeparadorConfe();
	}
	else
	{
		jugador_imprimirCarteleraConfe("CONFEDERACION AFC");
		printf("NO SE INGRESARON JUGADORES DE LA CONFEDERACION AFC!\n");
		jugador_imprimirSeparadorConfe();
	}

	if(jugador_confirmarJugadorPorConfederacion(listajugadores, tam,4)==0)
	{
		jugador_imprimirCarteleraConfe("CONFEDERACION CAF");
		jugador_listarJugadorPorConfederacion(listajugadores, tam, 4, listaConfe, tamano);
		jugador_imprimirSeparadorConfe();
	}
	else
	{
		jugador_imprimirCarteleraConfe("CONFEDERACION CAF");
		printf("NO SE INGRESARON JUGADORES DE LA CONFEDERACION CAF!\n");
		jugador_imprimirSeparadorConfe();
	}

	if(jugador_confirmarJugadorPorConfederacion(listajugadores, tam,5)==0)
	{
		jugador_imprimirCarteleraConfe("CONFEDERACION CONCACAF");
		jugador_listarJugadorPorConfederacion(listajugadores, tam, 5, listaConfe, tamano);
		jugador_imprimirSeparadorConfe();
	}
	else
	{
		jugador_imprimirCarteleraConfe("CONFEDERACION CONCACAF");
		printf("NO SE INGRESARON JUGADORES DE LA CONFEDERACION CONCACAF!\n");
		jugador_imprimirSeparadorConfe();
	}

	if(jugador_confirmarJugadorPorConfederacion(listajugadores, tam,6)==0)
	{
		jugador_imprimirCarteleraConfe("CONFEDERACION OFC");
		jugador_listarJugadorPorConfederacion(listajugadores, tam, 6, listaConfe, tamano);
		jugador_imprimirSeparadorConfe();
	}
	else
	{
		jugador_imprimirCarteleraConfe("CONFEDERACION OFC");
		printf("NO SE INGRESARON JUGADORES DE LA CONFEDERACION OFC!\n");
		jugador_imprimirSeparadorConfe();
	}
}

void jugador_imprimirCarteleraConfe(char* confederacion)
{
	printf("--------------------------------------------------------------------- %s ---------------------------------------------------------------------\n", confederacion);
	printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("| ID |                     NOMBRE                         |       POSICION       |  N DE CAMISETA  |     SUELDO      |     CONFEDERACION    | ANIOS CONTRATO |\n");
	printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void jugador_imprimirSeparadorConfe(void)
{
	printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
}

// ------------------------------- punto 4.3
void jugador_listarTotalYPromedio(eJugador listajugadores[], int tam)
{
	float totalSalario;
	int cantidadJugadores;
	float promedioTotal;
	int superanPromedio;

	juagador_TotalJugador(listajugadores, tam, &totalSalario, &cantidadJugadores);
	promedioTotal=jugador_contarTotalSalario(totalSalario, cantidadJugadores);
	superanPromedio=jugador_superanPromedio(listajugadores, tam, promedioTotal);
	printf("\n------------------------- TOTAL Y PROMEDIO SALARIAL -------------------------\n");
	printf("-----------------------------------------------------------------------------------------------------\n");
	printf("El total de salario es: %.2f - Su promedio es: %.2f - Los libros que superan el promedio son: %d\n", totalSalario, promedioTotal, superanPromedio);
	printf("-----------------------------------------------------------------------------------------------------\n\n");

}

void juagador_TotalJugador(eJugador listajugadores[], int tam, float* total, int* cantidad)
{
	float acumulador;
	int contador;
	acumulador=0;
	contador=0;
	for(int i=0;i<tam;i++)
	{
		if(listajugadores[i].isEmpty==OCUPADO)
		{
			acumulador+=listajugadores[i].salario;
			contador++;
		}
	}

	*total=acumulador;
	*cantidad=contador;
}

float jugador_contarTotalSalario(float total, int cantidad)
{
	float retorno;
	retorno=total/cantidad;
	return retorno;
}

int jugador_superanPromedio(eJugador listajugadores[], int tam, float prom)
{
	int retorno;
	retorno=0;
	for(int i=0;i<tam;i++)
	{
		if(listajugadores[i].isEmpty==OCUPADO && listajugadores[i].salario>prom)
		{
			retorno++;
		}
	}
	return retorno;
}

//--------------------------- punto 4.4
void jugador_imformarConfeMayorEnContratos(eJugador listajugadores[], int tam)
{
	int conmebol;
	int uefa;
	int afc;
	int caf;
	int concacaf;
	int ofc;

	conmebol=jugador_ConfePorAnios(listajugadores, tam, 1);
	uefa=jugador_ConfePorAnios(listajugadores, tam, 2);
	afc=jugador_ConfePorAnios(listajugadores, tam, 3);
	caf=jugador_ConfePorAnios(listajugadores, tam, 4);
	concacaf=jugador_ConfePorAnios(listajugadores, tam, 5);
	ofc=jugador_ConfePorAnios(listajugadores, tam, 6);

	printf("\n------------------------- CONFEDERACION CON MAYOR CANTIDAD DE ANIOS DE CONTRATO -------------------------\n");

	if(conmebol>uefa && conmebol>afc && conmebol>caf && conmebol>concacaf && conmebol>ofc)
	{
		jugador_imprimirConfeMayor("CONMEBOL", conmebol);
	}
	else if(uefa>conmebol && uefa>afc && uefa>caf && uefa>concacaf && uefa>ofc)
	{
		jugador_imprimirConfeMayor("UEFA", uefa);
	}
	else if(afc>conmebol && afc>uefa && afc>caf && afc>concacaf && afc>ofc)
	{
		jugador_imprimirConfeMayor("AFC", afc);
	}
	else if(caf>conmebol && caf>uefa && caf>afc && caf>concacaf && caf>ofc)
	{
		jugador_imprimirConfeMayor("CAF", caf);
	}
	else if(concacaf>conmebol && concacaf>uefa && concacaf>afc && concacaf>caf && concacaf>ofc)
	{
		jugador_imprimirConfeMayor("CONCACAF", concacaf);
	}
	else
	{
		jugador_imprimirConfeMayor("OFC", ofc);
	}
}

int jugador_ConfePorAnios(eJugador listajugadores[], int tam, int index)
{
	int retorno;
	retorno=0;
	for(int i=0;i<tam;i++)
	{
		if(listajugadores[i].isEmpty==OCUPADO && listajugadores[i].idConfederacion==index)
		{
			retorno=retorno+listajugadores[i].aniosContrato;
		}
	}
	return retorno;
}

void jugador_imprimirConfeMayor(char* confederacion, int anios)
{
	printf("-------------------------------------------------------------------------------------------------------\n");
	printf("La confederacion %s es la que mayor, tiene %d de anios de contrato\n", confederacion, anios);
	printf("-------------------------------------------------------------------------------------------------------\n\n");
}
//--------------------- punto 4.5
void jugador_imformarPorcentajeConfe(eJugador listajugadores[], int tam)
{
	int totalJugadores;
	int conmebol;
	int uefa;
	int afc;
	int caf;
	int concacaf;
	int ofc;
	float porcenConme;
	float porcenUefa;
	float porcenAfc;
	float porcenCaf;
	float porcenConca;
	float porcenOfc;

	totalJugadores=jugador_totalJugadores(listajugadores, tam);
	conmebol=jugador_acumuladorPorConfe(listajugadores, tam, 1);
	uefa=jugador_acumuladorPorConfe(listajugadores, tam, 2);
	afc=jugador_acumuladorPorConfe(listajugadores, tam, 3);
	caf=jugador_acumuladorPorConfe(listajugadores, tam, 4);
	concacaf=jugador_acumuladorPorConfe(listajugadores, tam, 5);
	ofc=jugador_acumuladorPorConfe(listajugadores, tam, 6);
	porcenConme=jugador_calcularPorcentaje(conmebol, totalJugadores);
	porcenUefa=jugador_calcularPorcentaje(uefa, totalJugadores);
	porcenAfc=jugador_calcularPorcentaje(afc, totalJugadores);
	porcenCaf=jugador_calcularPorcentaje(caf, totalJugadores);
	porcenConca=jugador_calcularPorcentaje(concacaf, totalJugadores);
	porcenOfc=jugador_calcularPorcentaje(ofc, totalJugadores);

	printf("\n------------------------- PORCENTAJE DE JUGADORES INGRESADOS POR CONFEDERACIONES -------------------------\n");
	printf("1. Porcentaje de jugadores de CONMEBOL: %.2f\n", porcenConme);
	printf("2. Porcentaje de jugadores de UEFA: %.2f\n",porcenUefa);
	printf("3. Porcentaje de jugadores de AFC: %.2f\n",porcenAfc);
	printf("4. Porcentaje de jugadores de CAF: %.2f\n",porcenCaf);
	printf("5. Porcentaje de jugadores de CONCACAF: %.2f\n",porcenConca);
	printf("6. Porcentaje de jugadores de OFC: %.2f\n",porcenOfc);
	printf("------------------------------------------------------------------------------------------------------------\n\n");
}

int jugador_totalJugadores(eJugador listajugadores[], int tam)
{
	int retorno;
	retorno=0;
	for(int i=0;i<tam;i++)
	{
		if(listajugadores[i].isEmpty==OCUPADO)
		{
			retorno++;
		}
	}
	return retorno;
}

int jugador_acumuladorPorConfe(eJugador listajugadores[], int tam, int index)
{
	int retorno;
	retorno=0;
	for(int i=0;i<tam;i++)
	{
		if(listajugadores[i].isEmpty==OCUPADO && listajugadores[i].idConfederacion==index)
		{
			retorno++;
		}
	}
	return retorno;
}

float jugador_calcularPorcentaje(int numeConfe, int totalJuga)
{
	float retorno;
	retorno=(float)(numeConfe*100)/totalJuga;
	return retorno;
}

//------------------------------ punto 4.6
void jugador_informarRegionMasJugadores(eJugador listajugadores[], int tam, eConfederacion listaConfe[], int tamano)
{
	int conmebol;
	int uefa;
	int afc;
	int caf;
	int concacaf;
	int ofc;

	jugador_calcularRegion(listajugadores, tam, 1, &conmebol);
	jugador_calcularRegion(listajugadores, tam, 2, &uefa);
	jugador_calcularRegion(listajugadores, tam, 3, &afc);
	jugador_calcularRegion(listajugadores, tam, 4, &caf);
	jugador_calcularRegion(listajugadores, tam, 5, &concacaf);
	jugador_calcularRegion(listajugadores, tam, 6, &ofc);

	printf("\n------------------------- LA REGION CON MAS JUGADORES -------------------------\n");
	if(conmebol>uefa && conmebol>afc && conmebol>caf && conmebol>concacaf && conmebol>ofc)
	{
		printf("Sudamerica es la region con mas jugadores: %d\n", conmebol);
		jugador_mostrarRegionConMasJuga(listajugadores, tam, listaConfe, tamano, 1);
	}
	else if(uefa>conmebol && uefa>afc && uefa>caf && uefa>concacaf && uefa>ofc)
	{
		printf("Europa es la region con mas jugadores: %d\n", uefa);
		jugador_mostrarRegionConMasJuga(listajugadores, tam, listaConfe, tamano, 2);
	}
	else if(afc>conmebol && afc>uefa && afc>caf && afc>concacaf && afc>ofc)
	{
		printf("Asia es la region con mas jugadores: %d\n", afc);
		jugador_mostrarRegionConMasJuga(listajugadores, tam, listaConfe, tamano, 3);
	}
	else if(caf>conmebol && caf>uefa && caf>afc && caf>concacaf && caf>ofc)
	{
		printf("Africa es la region con mas jugadores: %d\n", caf);
		jugador_mostrarRegionConMasJuga(listajugadores, tam, listaConfe, tamano, 4);
	}
	else if(concacaf>conmebol && concacaf>uefa && concacaf>afc && concacaf>caf && concacaf>ofc)
	{
		printf("Norte y Centro America es la region con mas jugadores: %d\n", concacaf);
		jugador_mostrarRegionConMasJuga(listajugadores, tam, listaConfe, tamano, 5);
	}
	else
	{
		printf("Oceania es la region con mas jugadores: %d\n", ofc);
		jugador_mostrarRegionConMasJuga(listajugadores, tam, listaConfe, tamano, 6);
	}

}


void jugador_calcularRegion(eJugador listajugadores[], int tam, int index, int* numeroJugares)
{
	int acumulador;
	acumulador=0;
	for(int i=0;i<tam;i++)
	{
		if(listajugadores[i].isEmpty==OCUPADO && listajugadores[i].idConfederacion==index)
		{
			acumulador++;
		}
	}
	*numeroJugares=acumulador;
}

void jugador_mostrarRegionConMasJuga(eJugador listajugadores[], int tam, eConfederacion listaConfe[], int tamano, int index)
{
	printf("----------------------------------------------------------------------------------------------------\n");
	printf("| ID |                     NOMBRE                         |        REGION        |  ANIO CREACION  |\n");
	printf("----------------------------------------------------------------------------------------------------\n");

	for(int i=0;i<tam;i++)
	{
		if(listajugadores[i].isEmpty==OCUPADO)
		{
			for(int j=0;j<tamano;j++)
			{
				if(listajugadores[i].idConfederacion==listaConfe[j].id && listaConfe[j].id==index)
				{
					printf("| %d  | %-50s | %-20s | %-15d |\n", listajugadores[i].id, listajugadores[i].nombre, listaConfe[j].region, listaConfe[j].anioCreacion);
				}
			}
		}
	}
	printf("----------------------------------------------------------------------------------------------------\n\n");
}

//---------------------------------------------- PUNTO 5
int jugador_verificarConfirmacion(char* mensaje)
{
	int retorno=-1;
	char respuesta;
	utn_getCaracter(&respuesta, mensaje, 'a','z', 'A','Z');
	if(respuesta=='s' || respuesta=='S')
	{
		retorno=0;
	}
	return retorno;
}

void jugador_verificarSalida(int* numero)
{
	if(jugador_verificarConfirmacion("Ingrese S para salir del programa: ")==0)
	{
		printf("Hasta luego!");
	}
	else
	{
		printf("Se cancelo el salir del programa!\n\n");
		*numero=1;
	}
}

//----------------------- Confederacion
//ALTA
void confederacion_inicializarConfederaciones(eConfederacion listaConfe[], int tamano)
{
	for(int i=0;i<tamano;i++)
	{
		listaConfe[i].isEmpty = LIBRE;
	}
}

int confederacion_buscarLibreConfederacion(eConfederacion listaConfe[], int tamano)
{
	int retorno=-1;
	for(int i=0;i<tamano;i++)
	{
		if(listaConfe[i].isEmpty==LIBRE)
		{
			retorno=i;
			break;
		}
	}
	return retorno;
}


eConfederacion confederacion_crearUnaNuevaConfe(void)
{
	eConfederacion auxConfe;
	utn_getArrayCadena(auxConfe.nombre, "Ingrese el nombre de la confederacion: ", "Error, reingrese el nombre de la confederacion: ", 50);
	utn_getArrayCadena(auxConfe.region, "Ingrese el nombre de la region: ", "Error, reingrese el nombre de la region: ", 50);
	utn_getNumeroEntero(&auxConfe.anioCreacion, "Ingrese el año de creacion: ", "Error, reingrese el año de creacion: ", 1900, 2022);
	return auxConfe;
}

void confederacion_agregarConfe(eConfederacion listaConfe[], int tamano)
{
	int index;
	index=confederacion_buscarLibreConfederacion(listaConfe, tamano);

	if(index!=-1)
	{
		listaConfe[index]=confederacion_crearUnaNuevaConfe();
		if(confederacion_confirmacionDeConfe("Ingrese S para cargar la confederacion: ")==0)
		{
			listaConfe[index].isEmpty=OCUPADO;
			listaConfe[index].id=index+1;
			printf("La confederacion se agrego correctamente!\n");
		}
		else
		{
			printf("Se cancelo el dar de alta una confederacion!\n");
		}
	}
	else
	{
		printf("No queda mas espacio para agregar confederacion.\n");
	}

}

int confederacion_confirmacionDeConfe(char* mensaje)
{
	int retorno=-1;
	char respuesta;
	utn_getCaracter(&respuesta, mensaje, 'a','z', 'A','Z');
	if(respuesta=='s' || respuesta=='S')
	{
		retorno=0;
	}
	return retorno;
}
//BAJA
void confederacion_mostrarTodosLasConfe(eConfederacion listaConfe[], int tamano)
{
	printf("----------------------------------------------------------------------------------------------------\n");
	printf("| ID |                     NOMBRE                         |        REGION        |  ANIO CREACION  |\n");
	printf("----------------------------------------------------------------------------------------------------\n");

	for(int i=0;i<tamano;i++)
	{
		if(listaConfe[i].isEmpty==OCUPADO)
		{
				printf("| %d  | %-50s | %-20s | %-15d |\n", listaConfe[i].id, listaConfe[i].nombre, listaConfe[i].region, listaConfe[i].anioCreacion);

		}
	}
}

int confederacion_bajaDeConfe(eConfederacion listaConfe[],int tamano)
{
	int retorno=-1;
	int numero;
	int indice;
	confederacion_mostrarTodosLasConfe(listaConfe, tamano);
	utn_getNumeroEntero(&numero, "Ingrese el numero ID del jugador a dar de baja: ", "Error, reingrese el numero ID del jugador a dar de baja: ", 1, 3000);
	indice=confederacion_buscarPorId(listaConfe, tamano, numero);
	if(indice!=-1)
	{
		if(confederacion_confirmacionDeConfe("Ingrese S para dar la baja: ")==0)
		{
			printf("El jugador '%s' se dio de baja correctamente\n", listaConfe[indice].nombre);
			listaConfe[indice].isEmpty=LIBRE;
			retorno=0;
		}
		else
		{
			printf("Se cancelo la baja del jugador!\n");
		}
	}
	else
	{
		printf("Jugador no encontrado!\n");
	}
	return retorno;
}

int confederacion_buscarPorId(eConfederacion listaConfe[],int tamano, int id)
{
	int retorno=-1;
	for(int i=0;i<tamano;i++)
	{
		if(listaConfe[i].isEmpty==OCUPADO && listaConfe[i].id==id)
		{
			retorno=i;
			break;
		}
	}
	return retorno;
}

//Modificacion
int confederacion_modificarConfe(eConfederacion listaConfe[],int tamano)
{
	int retorno = -1;
	int id;
	int indice;
	int opcion;
	confederacion_mostrarTodosLasConfe(listaConfe, tamano);
	utn_getNumeroEntero(&id, "Ingrese el id la confederacion a modificar: ", "Error, reingrese el id de la confederacion a modificar: ", 1, 3000);
	indice=confederacion_buscarPorId(listaConfe, tamano, id);
	if(indice!=-1)
	{
		do
		{
			utn_getNumeroEntero(&opcion, "1. Nombre\n2. Region\n3. anio de creacion\n4. Volver al Menu Principal\nIngrese opcion: ", "1. Nombre\n2. Region\n3. anio de creacion\n4. Volver al Menu Principal\nError, reingrese opcion: ", 1, 7);
			switch(opcion)
			{
			case 1:
				utn_getArrayCadena(listaConfe[indice].nombre, "Ingrese nuevo nombre: ", "Error, reingrese nuevo nombre: ", 50);
				retorno=0;
				break;
			case 2:
				utn_getArrayCadena(listaConfe[indice].region, "Ingrese nueva region: ", "Error, reingrese nueva region: ", 50);
				retorno=0;
				break;
			case 3:
				utn_getNumeroEntero(&listaConfe[indice].anioCreacion, "Ingrese el nuevo anio de creacion: ", "Error, reingrese nuevo anio de creacion: ", 1900, 2022);
				retorno=0;
				break;
			}

		}while(opcion!=4);
	}
	else
	{
		printf("El id de la confederacion no encontrado!\n");
	}
	return retorno;
}
