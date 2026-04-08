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

#include "tPolinomio.h"

#include <stdio.h>
#include <stdlib.h>

void CrearVacia(tPolinomio *p) {
  *p = NULL;
}

int EsVacia(tPolinomio p) {
  return p == NULL;
}

void construir(tPolinomio* p, tElemento e1) {
  tNodo* act = *p;
  tNodo* ant = NULL;
  tNodo* nuevo = (tNodo*) malloc(sizeof(tNodo));
  asignarElemento(&nuevo->info, e1);

  while (act != NULL && mayor(act->info, e1)) {
    ant = act;
    act = act->sig;
  }

  if (ant == NULL) {
    *p = nuevo;
  } else {
    ant->sig = nuevo;
  }
  nuevo->sig = act;
}

// Lee por teclado un polinomio
tPolinomio *leerPolinomio() {
  char seleccion;
  tPolinomio *p;
  tElemento e;
  tNodo* nuevo = (tNodo*) malloc(sizeof(tNodo));
  CrearVacia(p);

  printf("Ingrese el PRIMER elemento: \n");
  leerElemento(&e);
  construir(p, e);

  printf("¿Desea ingresar otro término? : \n");
  scanf(" %c", &seleccion);

  while (seleccion == 'y' || seleccion == 'Y') {
    printf("Ingrese el SIGUIENTE elemento: \n");
    leerElemento(&e);
    construir(p, e);

    printf("¿Desea ingresar otro término? : \n");
    scanf(" %c", &seleccion);

  }

  return p;

};


// Muestra por pantalla un polinomio
void mostrar(tPolinomio p) {
  tNodo * act = p;
  int i;
  while (act != NULL) {
    printf("El %d elemento es: \n", i+1);
    mostrarElemento(act->info);
    act = act->sig;
    i++;
  }
}

// Devuelve la derivada de un polinomio
void derivada_polinomio(tPolinomio *pd, tPolinomio p) {
  tNodo * act = p;

  while (act != NULL) {
    act = act->sig;
  }

}

// Devuelve el valor de un polinomio aplicado a un valor x
float valor(tPolinomio p, float x);
// Devuelve la suma de dos polinomios
void sumarPolinomios(tPolinomio *s, tPolinomio p1, tPolinomio p2);