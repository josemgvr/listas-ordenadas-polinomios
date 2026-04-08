# 📐 Listas Ordenadas y Polinomios en C

Implementación en **C** del TAD Lista Ordenada aplicado a la representación y manipulación algebraica de **polinomios**. Cada polinomio se modela como una lista enlazada ordenada de términos (coeficiente + exponente), mantenida siempre en **orden decreciente de exponente** y sin exponentes repetidos.

> Proyecto académico para la práctica de estructuras de datos dinámicas y Tipos Abstractos de Datos (TAD).

---

## 📋 Tabla de contenidos

- [Descripción](#-descripción)
- [Estructura del proyecto](#-estructura-del-proyecto)
- [Funcionalidades](#-funcionalidades)
- [Ejemplo de uso](#-ejemplo-de-uso)
- [Compilación y ejecución](#️-compilación-y-ejecución)
- [Requisitos](#-requisitos)

---

## 📖 Descripción

Un **polinomio** se representa internamente como una lista enlazada ordenada de términos, donde cada nodo almacena un par `(coeficiente, exponente)`. La lista se mantiene ordenada de mayor a menor exponente, y no se permiten exponentes duplicados.

Este diseño permite implementar operaciones algebraicas (suma, derivada, evaluación) de forma eficiente y estructurada, aplicando los principios de abstracción propios del paradigma TAD.

---

## 🗂 Estructura del proyecto

```
listas-ordenadas-polinomios/
├── main.c           # Programa principal de prueba
├── tElemento.h      # Interfaz del TAD tElemento (término del polinomio)
├── tElemento.c      # Implementación del TAD tElemento
├── tPolinomio.h     # Interfaz del TAD tPolinomio
├── tPolinomio.c     # Implementación del TAD tPolinomio (lista ordenada)
├── CMakeLists.txt   # Configuración de compilación con CMake
└── .gitignore
```

| Módulo | Responsabilidad |
|---|---|
| `tElemento` | Representa un término: coeficiente (`float`) y exponente (`int`) |
| `tPolinomio` | Gestiona la lista ordenada de términos y sus operaciones |
| `main.c` | Programa de prueba interactivo |

---

## ✅ Funcionalidades

- **Lectura interactiva** de un polinomio desde teclado, término a término
- **Representación** del polinomio como lista enlazada ordenada por exponente
- **Suma** de dos polinomios, agrupando términos con igual exponente
- **Derivada** de un polinomio aplicando la regla de la potencia
- **Evaluación** de un polinomio `p(x)` para un valor real `x` dado
- **Liberación de memoria** al finalizar (sin fugas de memoria)

---

## 💻 Ejemplo de uso

```
Introduce el primer polinomio:
> 3x^4 - 2x^2 + x - 5

Introduce el segundo polinomio:
> x^3 + 4x - 1

Polinomio 1:   3.00x^4 - 2.00x^2 + 1.00x - 5.00
Polinomio 2:   1.00x^3 + 4.00x - 1.00

Derivada del primer polinomio:
  12.00x^3 - 4.00x + 1.00

Introduce un valor para x: 2
Valor del polinomio 1 en x = 2.00: 37.00

Suma de los polinomios:
  3.00x^4 + 1.00x^3 - 2.00x^2 + 5.00x - 6.00
```

---

## ⚙️ Compilación y ejecución

### Con GCC (línea de comandos)

```bash
gcc *.c -o polinomios
./polinomios
```

### Con CMake

```bash
mkdir build && cd build
cmake ..
make
./polinomios
```

---

## 📦 Requisitos

- Compilador C (GCC, Clang o compatible con C99)
- CMake 3.x *(opcional, solo si se usa el método CMake)*
- Sistema operativo: Linux, macOS o Windows (con MinGW/WSL)

---

## 📚 Conceptos aplicados

- Tipos Abstractos de Datos (TAD)
- Listas enlazadas dinámicas
- Gestión manual de memoria (`malloc` / `free`)
- Modularidad y separación de interfaz e implementación (`.h` / `.c`)
- Operaciones algebraicas sobre polinomios
