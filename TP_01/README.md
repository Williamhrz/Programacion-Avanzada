**Proyecto académico — Programación Avanzada (C++)**

Este proyecto corresponde al desarrollo del **Trabajo Práctico 01 (TP01)** de la asignatura Programación Avanzada.  
Se implementan diferentes ejercicios introductorios en C++ enfocados en operaciones matemáticas, manejo de vectores, matrices y procesamiento básico de datos.

El proyecto está desarrollado de forma modular utilizando archivos `.hpp` y `.cpp`.

---

**Estructura del proyecto**

TP01_ProgramacionAvanzada/

- Archivos_cpp/
    - Operaciones_basicas.cpp
    - Vector.cpp
    - Contador_de_vocales.cpp
    - Norma_vector_Eu.cpp
    - Matriz_pseudo.cpp

- Archivos_hpp/
    - Operaciones_basicas.hpp
    - Vector.hpp
    - Contador_de_vocales.hpp
    - Norma_vector_Eu.hpp
    - Matriz_pseudo.hpp

- proyecto.cpp               # Archivo principal (menú general)
- README.md
- runproyect                 # Ejecutable

---

**Requisitos**

- Compilador: **g++ (C++17 o superior)**
- Sistema operativo: **Linux, macOS o Windows (WSL / PowerShell)**
- Editor recomendado: **Visual Studio Code**

---

**Compilación del proyecto**

Desde la carpeta principal del proyecto, ejecutar:

g++ proyecto.cpp Archivos_cpp/*.cpp -I Archivos_hpp -o runproyect

---

**Ejecución del programa**

**Linux / macOS / WSL**

./runproyect

**Windows (PowerShell / CMD)**

runproyect.exe

---

**Menú principal**

===========  MENÚ TP01  ===========
1. Operaciones básicas
2. Operaciones con vectores
3. Contador de vocales
4. Norma de vector (Euclidiana)
5. Matriz pseudoaleatoria
0. Salir

---

**Descripción de los ejercicios**

| Ejercicio | Descripción |
|----------|-------------|
| **1. Operaciones básicas** | Suma, resta, multiplicación y división entre dos números. |
| **2. Vectores** | Operaciones entre vectores como suma y resta. |
| **3. Contador de vocales** | Cuenta las vocales presentes en una cadena de texto. |
| **4. Norma vectorial** | Calcula la norma euclidiana de un vector. |
| **5. Matriz pseudoaleatoria** | Genera y muestra una matriz con valores pseudoaleatorios. |

---


**Autores**

- _**William A. Hernández A.**_
- _**Jesus D. Angulo B.**_
- _**Ivan M. Vasquez A.**_

**Estudiantes de Ingeniería Mecatrónica**
**Universidad Nacional de Colombia - Sede De la Paz**