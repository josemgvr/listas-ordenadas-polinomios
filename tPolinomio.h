/********************************************************************************
Módulo:
Fichero: ( ) Programa  ( ) Espec. TAD (x) Impl. TAD
Autor: Jose Miguel Villora
Fecha: 07/04/2026
Descripción:
Este fichero implementa el TAD tPolinomio, que define un polinomio como
una lista ordenada de términos (tElemento), organizada en orden
decreciente según el exponente. En este módulo se desarrollan las
operaciones necesarias para la gestión y manipulación de polinomios,
incluyendo la lectura, visualización, cálculo de la derivada, evaluación
del polinomio para un valor dado y la suma de dos polinomios. El uso de
una lista ordenada permite realizar estas operaciones de forma eficiente
y estructurada.
*********************************************************************************/

#ifndef EJ_TPOLINOMIO_H
#define EJ_TPOLINOMIO_H
#include "tElemento.h"

typedef struct Nodo {
    tElemento info;
    struct Nodo *sig;
}tNodo;

typedef tNodo* tPolinomio;

// Lee por teclado un polinomio
tPolinomio *leerPolinomio();
// Muestra por pantalla un polinomio
void mostrar(tPolinomio p);
// Devuelve la derivada de un polinomio
void derivada_polinomio(tPolinomio *pd, tPolinomio p);
// Devuelve el valor de un polinomio aplicado a un valor x
float valor(tPolinomio p, float x);
// Devuelve la suma de dos polinomios
void sumarPolinomios(tPolinomio *s, tPolinomio p1, tPolinomio p2);

#endif //EJ_TPOLINOMIO_H