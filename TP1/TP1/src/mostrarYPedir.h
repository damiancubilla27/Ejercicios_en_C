/*
 * mostrarYPedir.h
 *
 *  Created on: 22 sep. 2022
 *      Author: damia
 */

#ifndef MOSTRARYPEDIR_H_
#define MOSTRARYPEDIR_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculosMatematicos.h"

/**
 * @fn void utn_getNumeroEntero(int*, char*, int, int, int, float, float, float, int, int, int, int)
 * @brief Permite mostrar el menu principal, marcar el limite de opciones en el menu (1-5) y en caso de error devuelve un mensaje.
 *
 * @param pNum Se guardara la opcion elegida.
 * @param mensajeError Mensaje en caso de error en el ingreso.
 * @param min Limite minimo para el ingreso.
 * @param max Limite maximo para el ingreso.
 * @param reintentos Cantidad de reintentos que usuario tendra.
 * @param hos Valor actual de la variable hospedaje.
 * @param com Valor actual de la variable comida.
 * @param trans Valor actual de la variable transporte.
 * @param arq Valor actual de la variable arquero.
 * @param def Valor actual de la variable defensor.
 * @param med Valor actual de la variable mediocampista.
 * @param del Valor actual de la variable delantero.
 */
void utn_getNumeroEntero(int* pNum, char* mensajeError, int min, int max, int reintentos, float hos, float com, float trans, int arq, int def, int med, int del);

/**
 * @fn void ingresoDeMantenimiento(float, float, float, float*, float*, float*)
 * @brief Funcion que muestra un submenu con carga aleatoria para que el usuario pueda elegir que dato de mantemiento carga y cual no.
 *
 * @param hos Valor actual de la variable hospedaje.
 * @param com Valor actual de la variable comida.
 * @param tran Valor actual de la variable transporte.
 * @param hospe Puntero a direccion de memoria para guardar el nuevo costo de hospedaje.
 * @param comi Puntero a direccion de memoria para guardar el nuevo costo de comida.
 * @param transp Puntero a direccion de memoria para guardar el nuevo costo de transporte.
 */
void ingresoDeMantenimiento(float hos, float com, float tran,float* hospe, float* comi, float* transp);

/**
 * @fn int validarNumeroPosicion(void)
 * @brief Funcion que nos permite mostrar un submenu y poner limites a la opcion elegida. En caso de error de debera volver a ingresar.
 *
 * @return Retorna la opcion elegida por el usuario.
 */
int validarNumeroPosicion(void);

/**
 * @fn int jugadorPorPosicion(int, int, int, int, int, int*, int*, int*, int*)
 * @brief Esta funcion permite guardar la posicion seleccionada anteriormente e ir incrementando el numero de convocatorias hasta llegar un tope por posicion en el campo. En caso de llegar a dicho tope, se informara de que esta posicion ya esta llena.
 *
 * @param posicion Opcion de posicion a cargar.
 * @param arq Valor actual de la variable arquero.
 * @param def Valor actual de la variable defensor.
 * @param med Valor actual de la variable mediocampista.
 * @param del Valor actual de la variable delantero.
 * @param arquero Puntero a direccion de memoria de la variable arquero, para actualizar la nueva convocatoria.
 * @param defensor Puntero a direccion de memoria de la variable defensor, para actualizar la nueva convocatoria.
 * @param medio Puntero a direccion de memoria de la variable mediocampista, para actualizar la nueva convocatoria.
 * @param delantero Puntero a direccion de memoria de la variable delantero, para actualizar la nueva convocatoria.
 * @return Retorna 1 en caso de que se pudo cargar al nuevo convocado y retorna 0 en caso de que no.
 */
int jugadorPorPosicion(int posicion, int arq, int def, int med, int del, int* arquero, int* defensor, int* medio, int* delantero);

/**
 * @fn int validarConfederacion(void)
 * @brief Funcion que nos permite mostrar un submenu y poner limites a la opcion elegida. En caso de error de debera volver a ingresar.
 *
 * @return Retorna la opcion elegida por el usuario.
 */
int validarConfederacion(void);

/**
 * @fn void jugadorPorConfederacion(int, int, int, int, int, int, int, int*, int*, int*, int*, int*, int*)
 * @brief Esta funcion sirve para incrementar el ingreso de jugadores por confederacion.
 *
 * @param numero Es el valor que usuario ingresa para saber la confederacion.
 * @param asia Valor actual de la variable afc.
 * @param africa  Valor actual de la variable caf.
 * @param zNorte Valor actual de la variable concacaf.
 * @param suda Valor actual de la variable conmebol.
 * @param euro Valor actual de la variable uefa.
 * @param ocea Valor actual de la variable ofc.
 * @param asi Permite guardar el nuevo valor de la variable afc.
 * @param afri Permite guardar el nuevo valor de la variable caf.
 * @param norte Permite guardar el nuevo valor de la variable concacaf.
 * @param sudame Permite guardar el nuevo valor de la variable conmebol.
 * @param europa Permite guardar el nuevo valor de la variable uefa.
 * @param oceania Permite guardar el nuevo valor de la variable ofc.
 */
void jugadorPorConfederacion(int numero, int asia, int africa, int zNorte, int suda, int euro, int ocea, int* asi, int* afri, int* norte, int* sudame, int* europa, int* oceania);

#endif /* MOSTRARYPEDIR_H_ */
