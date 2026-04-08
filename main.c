#include <stdio.h>
#include "tPolinomio.h"

int main() {
    tPolinomio *p1;
    tPolinomio *p2;
    tPolinomio suma;
    tPolinomio derivada;
    float x;

    printf("Introduce el primer polinomio:\n");
    p1 = leerPolinomio();

    printf("\nIntroduce el segundo polinomio:\n");
    p2 = leerPolinomio();

    printf("\nPolinomio 1:\n");
    mostrar(*p1);

    printf("\nPolinomio 2:\n");
    mostrar(*p2);

    printf("\nDerivada del primer polinomio:\n");
    derivada_polinomio(&derivada, *p1);
    mostrar(derivada);

    printf("\nIntroduce un valor para x: ");
    scanf("%f", &x);
    printf("Valor del polinomio 1 en x = %.2f: %.2f\n", x, valor(*p1, x));

    printf("\nSuma de los polinomios:\n");
    sumarPolinomios(&suma, *p1, *p2);
    mostrar(suma);

    // Liberar memoria
    EliminartPolinomio(p1);
    EliminartPolinomio(p2);
    EliminartPolinomio(&suma);
    EliminartPolinomio(&derivada);

    return 0;
}