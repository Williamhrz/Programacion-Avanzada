Proyecto académico — Programación Avanzada (C++)

Este proyecto implementa los cinco ejercicios del Trabajo Práctico 01 de la asignatura Programación Avanzada, desarrollados en C++ con un enfoque modular, orientado a objetos y organizado en múltiples librerías (.hpp y .cpp).

TP01_ProgramacionAvanzada/

    - Archivos_cpp/              # Implementaciones (.cpp)
        - Operaciones_basicas.cpp
        - Vector.cpp
        - Contador_de_vocales.cpp
        - Norma_vector_Eu.cpp
        - Matriz_pseudo.cpp

    - Archivos_hpp/              # Cabeceras (.hpp)
        - Operaciones_basicas.hpp
        - Vector.hpp
        - Contador_de_vocales.hpp
        - Norma_vector_Eu.hpp
        - Matriz_pseudo.hpp
    - proyecto.cpp               # Archivo principal (menú general)
    - README.md                  # Documentación del proyecto

**Requisitos:**

- Compilador: g++ (C++17 o superior)

- Sistema operativo: Linux, macOS o WSL en Windows

- Editor recomendado: Visual Studio Code o cualquier IDE compatible con C++

**Compilación y ejecución:**

Desde la carpeta principal del proyecto, abre una terminal y ejecuta:

    g++ proyecto.cpp Archivos_cpp/*.cpp -I Archivos_hpp -o runproyect
_________________________________________________________________________________________________

    | Parte                | Descripción                            |
    | -------------------- | -------------------------------------- |
    | `g++`                | Compilador de C++                      |
    | `proyecto.cpp`       | Archivo principal que contiene el menú |
    | `Archivos_cpp/*.cpp` | Compila todos los módulos del proyecto |
    | `-I Archivos_hpp`    | Indica dónde están los archivos `.hpp` |
    | `-o runproyect`      | Crea el ejecutable con ese nombre      |


**Ejecutar el programa**

Una vez compilado, corre el programa con:

    ./runproyect

Esto abrirá el menú interactivo del trabajo práctico:

    ===== MENÚ DE EJECUCIÓN TP01 =====
    1. Operaciones básicas con dos números
    2. Vector de números decimales
    3. Contador de vocales
    4. Cálculo de normas L2 y L∞
    5. Inversa y pseudo-inversa de una matriz
    Seleccione una opción:

El usuario debe escribir el número del ejercicio que desea ejecutar.
El programa mostrará una breve descripción y luego pedirá los datos necesarios.

    | Ejercicio                                     | Descripción                                                                                                                     |
    | --------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------- |
    | **1. Operaciones básicas**                    | Permite ingresar dos números (enteros o decimales) y muestra su suma, resta, multiplicación y división.                         |
    | **2. Vector de números decimales**            | Calcula el valor máximo, mínimo y sus posiciones dentro del vector ingresado.                                                   |
    | **3. Contador de vocales**                    | Cuenta cuántas vocales contiene una palabra o frase ingresada.                                                                  |
    | **4. Cálculo de normas**                      | Calcula las normas **L2 (Euclidiana)** y **L∞ (del infinito)** de un vector.                                                    |
    | **5. Inversa y pseudo-inversa de una matriz** | Calcula la inversa si la matriz es cuadrada, o la pseudo-inversa si no lo es. Detecta automáticamente si la matriz es singular. |


**Autores**

- _**William A. Hernández A.**_
- _**Jesus D. Angulo B.**_
- _**Ivan M. Vasquez A.**_
**Estudiantes de Ingeniería Mecatrónica**
**Universidad Nacional de Colombia - Sede De la Paz**