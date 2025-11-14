Estructura del Repositorio

El repositorio está organizado en dos carpetas principales, cada una correspondiente a un proyecto independiente desarrollado en C++ para la asignatura de **Programación Avanzada**.  
Ambos proyectos están estructurados de manera modular para mantener un código limpio, ordenado y fácil de mantener.  
Cada proyecto incluye un archivo **README.md** con instrucciones de compilación y ejecución.

Proyecto_Num_1 — TP01 Programación Avanzada

Esta carpeta contiene el desarrollo completo del **Trabajo Práctico 01**.  
Su estructura interna está organizada modularmente para separar el código principal de las implementaciones y definiciones auxiliares.

Estructura interna

- **proyecto.cpp**  
  Archivo principal que contiene la función `main()` y la lógica de ejecución del programa.

- **Archivos_cpp/**  
  Carpeta con las implementaciones (`.cpp`) de las clases, funciones o módulos utilizados en el proyecto.  
  Incluye:  
    - `Operaciones_basicas.cpp`  
    - `Vector.cpp`  
    - `Contador_de_vocales.cpp`  
    - `Norma_vector_Eu.cpp`  
    - `Matriz_pseudo.cpp`

- **Archivos_hpp/**  
  Carpeta que contiene los archivos de cabecera (`.hpp`) donde se declaran clases, funciones, estructuras y prototipos.  
  Incluye:  
    - `Operaciones_basicas.hpp`  
    - `Vector.hpp`  
    - `Contador_de_vocales.hpp`  
    - `Norma_vector_Eu.hpp`  
    - `Matriz_pseudo.hpp`

- **README.md**  
  Documentación completa del proyecto, incluyendo requisitos, instrucciones de compilación, menú principal y descripción de cada ejercicio.

- **runproyect**  
  Ejecutable generado tras compilar el proyecto.  
  Se ejecuta con:  
  ```bash
  ./runproyect

Proyecto_Num_2 — TP02 Programación Avanzada

Esta carpeta contiene el desarrollo completo del **Trabajo Práctico 02**.  
Al igual que en el proyecto anterior, el código está organizado de forma modular, separando las implementaciones (`.cpp`) de sus respectivas definiciones (`.hpp`).  
El proyecto incluye también un archivo principal que gestiona la ejecución general del programa.

---

Estructura interna

- **proyecto2.cpp**  
  Archivo principal que contiene la función `main()` del TP02.  
  Desde aquí se controlan las opciones del programa y se enlazan los distintos módulos.

- **Archivos_cpp/**

  Carpeta que contiene las implementaciones (`.cpp`) utilizadas específicamente en este proyecto.  
  Incluye:

    - `act1_vector3D.cpp` 
    - `act2_matriz.cpp` 
    - `act3_polinomio.cpp` 
    - `act4_complejos.cpp` 
    - `act5_ecuaciones.cpp` 
    - `act6_domino.cpp` 

- **Archivos_hpp/**

  Carpeta que agrupa los archivos de cabecera (`.hpp`) correspondientes a las clases, funciones y prototipos utilizados en el TP02.  
  Incluye:

    - `act1_vector3D.hpp`
    - `act2_matriz.hpp`
    - `act3_polinomio.hpp`
    - `act4_complejos.hpp`
    - `act5_ecuaciones.hpp`
    - `act6_domino.hpp`

- **README.md**

  Documento que explica el propósito del proyecto, su funcionamiento, la descripción de cada módulo y las instrucciones para compilar y ejecutar el programa.

- **Ejecutable — runproyect02**

  Ejecutable generado después de la compilación del TP02.  
  Para ejecutar:

```bash
./runproyect02
