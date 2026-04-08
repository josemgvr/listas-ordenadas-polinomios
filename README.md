\# Listas ordenadas y polinomios



Implementación en C del \*\*TAD Lista Ordenada\*\* aplicado a la

representación y manipulación de \*\*polinomios\*\*.



Un polinomio se define como una lista ordenada de términos, organizada

en \*\*orden decreciente según el exponente\*\*, donde cada término está

formado por un coeficiente real y un exponente entero.  

El objetivo principal del proyecto es practicar el uso de \*\*estructuras

de datos dinámicas\*\* y \*\*Tipos Abstractos de Datos (TAD)\*\* para resolver

un problema concreto de forma estructurada y eficiente.



\---



\## Estructuras de datos utilizadas



\- Lista enlazada ordenada

\- Tipos de Datos Abstractos (TAD)

\- Estructuras dinámicas



La lista se mantiene siempre ordenada por exponente y no se permiten

exponentes repetidos, lo que facilita la implementación de las

operaciones sobre los polinomios.



\---



\## Funcionalidades implementadas



\- Lectura de un polinomio desde teclado

\- Representación de un polinomio mediante una lista ordenada

\- Cálculo de la derivada de un polinomio

\- Evaluación de un polinomio para un valor dado de `x`

\- Suma de dos polinomios



\---



\## Ejemplo de uso



El programa permite introducir un polinomio por teclado y mostrar por

pantalla su derivada, el valor del polinomio para un determinado valor

de `x` y la suma con un segundo polinomio introducido por el usuario.



\---



\## Estructura del proyecto



\- `listaOrdenada.h / .c`  

&#x20; Implementación del TAD \*\*Lista Ordenada\*\*



\- `tElemento.h / .c`  

&#x20; Implementación del TAD `tElemento`, que representa un término del

&#x20; polinomio (coeficiente y exponente)



\- `tPolinomio.h / .c`  

&#x20; Implementación del TAD `tPolinomio`, que gestiona las operaciones sobre

&#x20; polinomios utilizando una lista ordenada de términos



\- `main.c`  

&#x20; Programa principal de prueba del TAD `tPolinomio`



\- `CMakeLists.txt`  

&#x20; Archivo de configuración para la compilación del proyecto



\---



\## Compilación y ejecución



\### Compilación con gcc



```bash

gcc \*.c -o polinomios

