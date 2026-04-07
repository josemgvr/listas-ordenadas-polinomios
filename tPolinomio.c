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



// Lee por teclado un polinomio
tPolinomio *leerPolinomio() {
  char seleccion;
  tPolinomio *p;
  tElemento e1;
  tElemento e2;
  tNodo* nuevo = (tNodo*) malloc(sizeof(tNodo));

  CrearVacia(p);

  printf("Ingrese el primer elemento \n: ");
  leerElemento(&e1);
  asignarElemento(&nuevo->info, e1);
  *p = nuevo;
  nuevo->sig = NULL;

  printf("Desea ingresar otro elemeneto \n: ");
  scanf("%c", &seleccion);

  while (seleccion == 'y' || seleccion == 'Y') {
    tNodo *nuevo2 = (tNodo*) malloc(sizeof(tNodo));
    tNodo* act = *p;
    tNodo* ant;
    int encontrado = 0;

    printf("Ingrese el siguiente elemento \n: ");
    leerElemento(&e2);
    asignarElemento(&nuevo2->info, e2);

    while ( encontrado == 0 && act != NULL) {

      if (getExponente(e1) > getExponente(act->info)) { //significaría que esta delante
        if (act = *p){//comprobamos que sea el primer elemento
          nuevo2->sig = act;
          *p = nuevo2;
        } else {
          nuevo2->sig = act;
          ant->sig = nuevo2;
        }
      } else {
        if (act->sig == NULL) {
          act->sig = nuevo2;
          nuevo2->sig = NULL;
      }
        if (getExponente(e1) == getExponente(e2)) {
          act->sig = nuevo2;
          nuevo2->sig = act->sig->sig;
        }
      }
      act = act->sig;
    }


  }

  return p;

};
// Muestra por pantalla un polinomio
void mostrar(tPolinomio p) {
  tNodo * act = p;
  int i;
  while (act != NULL) {
    printf("El %d elemento es: /n", i+1);
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