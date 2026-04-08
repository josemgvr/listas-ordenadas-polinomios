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

#include "tElemento.h"
#include <stdio.h>

//Crear un elemento
void construirElemento(float coficiente, int termino, tElemento *e){
    e->exponente = termino;
    e->coeficiente = coficiente;
}

// Asigna el valor de un TElemento a otro TElemento
void asignarElemento(tElemento *e1, tElemento e2) {
    e1->coeficiente = e2.coeficiente;
    e1->exponente = e2.exponente;
}

// Lee por teclado un TElemento
void leerElemento(tElemento *e) {
    printf("Ingrese el coficiente del elemento \n");
    scanf("%f", &e->coeficiente);
    printf("Ingrese el termino del elemento \n");
    scanf("%d", &e->exponente);
}

// Comprueba si dos TElemento son iguales. Dos términos se consideran
// iguales si tienen el mismo exponente
int igualElemento(tElemento uno, tElemento dos) {
    return uno.exponente == dos.exponente;
}

// Comprueba si elem1 es mayor que elem2 (se considera que un termino
//es mayor que otro si el exponente del primero es mayor que el
//exponente del segundo
int mayor(tElemento uno, tElemento dos) {
    return uno.exponente > dos.exponente;
}

// Muestra por pantalla un TElemento
void mostrarElemento(tElemento t) {
    printf("Termino: %d \n", t.exponente);
    printf("Coficiente: %.2f\n", t.coeficiente);
}

// Devuelve el exponente de un termino
int getExponente(tElemento e) {
    return e.exponente;
}

// Devuelve el coeficiente de un termino
float getCoeficiente(tElemento e) {
    return e.coeficiente;
}

// Devuelve la derivada de un termino
void derivada_elemento(tElemento *ed, tElemento e){
    if (e.exponente > 0) {
        ed->exponente = e.exponente-1;
        ed->coeficiente = e.coeficiente*e.exponente;
    } else {
        ed->coeficiente = 0;
        ed->exponente = 0;
    }
}
