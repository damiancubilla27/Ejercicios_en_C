/*
 ============================================================================
Cubilla Damian
Crear una función que reciba como parámetros un array con 5 nombres
(que estarán previamente hardcodearlos).
La función deberá guardar la lista de nombres en un archivo de texto.
int EscribirNombresTXT(char* nombres, char* path);
Otra función se encargará de la lectura de dicha lista.
int LeerNombresTXT(char* nombres, char* path);

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int EscribirNombresTXT(char nombres[][15], char* path);
int LeerNombresTXT(char nombres[][15], char* path);

int main(void) {
	setbuf(stdout, NULL);
	char arrayNombres[5][15]={"Carmen", "Damian", "Camila", "Axel", "Aldana"};

	EscribirNombresTXT(arrayNombres, "escribirNombres.txt");

	LeerNombresTXT(arrayNombres, "escribirNombres.txt");

	return EXIT_SUCCESS;
}

int EscribirNombresTXT(char nombres[][15], char* path)
{
	int retorno;
	FILE* pArchivo;
	if(nombres!=NULL && path!=NULL)
	{
		retorno=-1;
		pArchivo=fopen(path, "w");
		if(pArchivo!=NULL)
		{
			for(int i=0;i<5;i++)
			{
				fprintf(pArchivo, "%s\n", nombres[i]);
			}
			fclose(pArchivo);
			retorno=0;
		}
	}
	return retorno;
}

int LeerNombresTXT(char nombres[][15], char* path)
{
	FILE* pArchivo;
	int retorno;
	if(nombres!=NULL && path!=NULL)
	{
		retorno=-1;
		pArchivo=fopen(path, "r");
		if(pArchivo!=NULL)
		{
			for(int i=0;i<5;i++)
			{
				puts(nombres[i]);
			}
			fclose(pArchivo);
			retorno=0;
		}
	}
	return retorno;
}
