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
#include <math.h>

//Crea un polinomio Vacio
void CrearVacia(tPolinomio *p) {
  *p = NULL;
}

//Comprueba que el polinomio esta vacia
int EsVacia(tPolinomio p) {
  return p == NULL;
}

//Crear o añade un elemento al polinomio
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

//Elimina un Nodo del tPolinomio
void EliminarElemento(tPolinomio *p, tElemento e) {
  tNodo * act = *p;
  tNodo * ant = NULL;
  int encontrado = 0;

  while (act != NULL && !encontrado) {
    if (igualElemento(act->info, e)) {
      encontrado = 1;
    } else {
      ant = act;
      act = act->sig;
    }

  }

  if (act != NULL) {
    if (ant != NULL) {
      ant->sig = act->sig;
    } else {
      *p = act->sig;
    }
    free(act);
  }
}

//Elimina enteramente el polinomio
void EliminarPolinomio(tPolinomio *p) {
  tNodo *act = *p;
  tNodo *aux;

  while (act != NULL) {
    aux = act;
    act = act->sig;
    free(aux);
  }
  *p = NULL;
}


// Lee por teclado un polinomio
tPolinomio *leerPolinomio() {
  char seleccion;
  tPolinomio *p = (tPolinomio*) malloc(sizeof(tPolinomio));
  tElemento e;
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
  int i = 0;
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
  tElemento e;
  while (act != NULL) {
    derivada_elemento(&e, act->info);
    construir(pd, e);
    act = act->sig;
  }

}

// Devuelve el valor de un polinomio aplicado a un valor x
float valor(tPolinomio p, float x) {
  tNodo * act = p;
  tElemento e;
  float resultado = 0;

  while (act != NULL) {
    resultado += getCoeficiente(act->info)*pow(x,getExponente(act->info));
    act = act->sig;
  }
  return resultado;
}
// Devuelve la suma de dos polinomios
void sumarPolinomios(tPolinomio *s, tPolinomio p1, tPolinomio p2) {
  tNodo * act1 = p1;
  tNodo * act2 = p2;
  tElemento e;
  int exponente;

  CrearVacia(s);

  while (act1 != NULL && act2 != NULL) {
    if (getExponente(act1->info) == getExponente(act2->info)) {
      exponente = getExponente(act1->info);
      float coeficiente = getCoeficiente(act1->info) + getCoeficiente(act2->info);
      if (coeficiente != 0) {
        construirElemento(coeficiente,exponente,&e);
        construir(s, e);
      }

      act1 = act1->sig;
      act2 = act2->sig;
    } else if (getExponente(act1->info) > getExponente(act2->info)) {
      construir(s, act1->info);
      act1 = act1->sig;
    } else {
      construir(s, act2->info);
      act2 = act2->sig;
    }

    while (act1 != NULL) {
      construir(s, act1->info);
      act1 = act1->sig;
    }

    while (act2 != NULL) {
      construir(s, act2->info);
      act2 = act2->sig;
    }

  }
}

