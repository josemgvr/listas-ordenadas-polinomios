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

void asignarElemento(tElemento *e1, tElemento e2) {
    e1->coficiente = e2.coficiente;
    e1->termino = e2.termino;
}

void leerElemento(tElemento *e) {
    printf("Ingrese el coficiente del elemento \n");
    scanf("%f", &e->coficiente);
    printf("Ingrese el termino del elemento \n");
    scanf("%d", &e->termino);
}

int igualElemento(tElemento uno, tElemento dos) {
    return uno.coficiente == dos.coficiente && uno.termino == dos.termino;
}

int mayor(tElemento uno, tElemento dos) {
    return uno.coficiente > dos.coficiente;
}

void mostrarElemento(tElemento t) {
    printf("Termino: %d \n", t.termino);
    printf("Coficiente: %.2f\n", t.coficiente);
}

int getExponente(tElemento e) {
    return e.termino;
}

float getCoeficiente(tElemento e) {
    return e.coficiente;
}

void derivada_elemento(tElemento *ed, tElemento e){
    if (e.termino > 0) {
        ed->termino = e.termino-1;
        ed->coficiente = e.coficiente*e.termino;
    } else {
        ed->coficiente = 0;
        ed->termino = 1;
    }
}
