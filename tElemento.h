/********************************************************************************
Módulo:
Fichero: ( ) Programa  ( ) Espec. TAD (x) Impl. TAD
Autor: Jose Miguel Villora
Fecha: 07/04/2026
Descripción:
Este fichero implementa el TAD tElemento, que representa un término
individual de un polinomio. Cada elemento está formado por un coeficiente
real y un exponente entero. En este módulo se definen las operaciones
básicas sobre los elementos, como la asignación, lectura, comparación,
obtención de atributos y el cálculo de la derivada de un término.
Estas operaciones permiten su uso dentro de una lista ordenada para la
gestión y manipulación de polinomios.
*********************************************************************************/

#ifndef EJ_TELEMENTO_H
#define EJ_TELEMENTO_H

typedef struct termino {
    float coficiente;
    int termino;
}tElemento;

void contruirElemento(float coficiente, int termino, tElemento *e);

// Asigna el valor de un TElemento a otro TElemento
void asignarElemento(tElemento *e1, tElemento e2);
// Lee por teclado un TElemento
void leerElemento(tElemento *e);
// Comprueba si dos TElemento son iguales. Dos términos se consideran
// iguales si tienen el mismo exponente
int igualElemento(tElemento uno, tElemento dos);
// Comprueba si elem1 es mayor que elem2 (se considera que un termino
//es mayor que otro si el exponente del primero es mayor que el
//exponente del segundo
int mayor(tElemento uno, tElemento dos);
// Muestra por pantalla un TElemento
void mostrarElemento(tElemento t);
// Devuelve el exponente de un termino
int getExponente(tElemento e);
// Devuelve el coeficiente de un termino
float getCoeficiente(tElemento e);
// Devuelve la derivada de un termino
void derivada_elemento(tElemento *ed, tElemento e);


#endif //EJ_TELEMENTO_H