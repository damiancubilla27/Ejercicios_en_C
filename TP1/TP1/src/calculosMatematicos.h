/*
 * calculosMatematicos.h
 *
 *  Created on: 22 sep. 2022
 *      Author: damia
 */

#ifndef CALCULOSMATEMATICOS_H_
#define CALCULOSMATEMATICOS_H_

/**
 * @fn float calcularPromedio(int, int)
 * @brief Permite calcular el promedio de jugadores que juegan en cada confederacion del mundo.
 *
 * @param confederacion Indica la confederacion del jugador.
 * @param numeroDeJugadores Indica el numero de jugadores ingresados.
 * @return Retorna el numero promedio de jugadores.
 */
float calcularPromedio(int confederacion, int numeroDeJugadores);

/**
 * @fn float calcularMantenimiento(float, float, float)
 * @brief Funcion que permite sumar todos los mantenimientos ingresados.
 *
 * @param hospe Valor de hospedaje.
 * @param com Valor de comida.
 * @param trans Valor de transporte.
 * @return Devuelve las suma de todos los valores ingresados.
 */
float calcularMantenimiento(float hospe, float com, float trans);

/**
 * @fn float calcularJugadoresEnEuropa(int)
 * @brief Esta funcion permite saber si mas del 50% de los jugadores participan de las ligas europeas.
 *
 * @param jugador El numero de jugadores ingresados.
 * @return Retorna el 50% de los jugadores ingresados.
 */
float calcularJugadoresEnEuropa(int jugador);

/**
 * @fn float calcularAumento(float)
 * @brief Esta funcion permite hallar el 35% de aumento por jugadores en ligas europeos.
 *
 * @param manteni Valor de mantenimiento.
 * @return Devuelve el 35% de la variable mantenimiento.
 */
float calcularAumento(float manteni);

/**
 * @fn float costoTotal(float, float)
 * @brief Esta funcion se encarga de sumar el mantenimiento total mas el aumento por jugadores en ligas europeos.
 *
 * @param manteni En este parametro le pasamos en valor de mantenimiento total.
 * @param aum En este parametro le pasamos en valor de aumento.
 * @return retorna el costo total de la operacion.
 */
float costoTotal(float manteni, float aum);

#endif /* CALCULOSMATEMATICOS_H_ */
