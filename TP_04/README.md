**Proyecto académico — Programación Avanzada (C++)**

Este proyecto corresponde al desarrollo del **Trabajo Práctico 04 (TP04)** de la asignatura Programación Avanzada.  
El taller integra algoritmos de búsqueda, simulación de sistemas, hardware-in-the-loop (HIL) y clasificación mediante redes neuronales artificiales (RNA).

El proyecto está organizado de forma modular y controlado desde un menú principal.

---

**Estructura del proyecto**

TP04_ProgramacionAvanzada/

- Archivos_cpp/
    - puzzle.cpp
    - HIL.cpp
    - RNA.cpp

- Archivos_hpp/
    - puzzle.hpp
    - HIL.hpp
    - RNA.hpp

- proyecto.cpp               # Archivo principal (menú general)
- README.md
- output/
    - ejecutables y archivos generados

---

**Requisitos**

- Compilador: **g++ (C++17 o superior)**
- Sistema operativo: **Linux, macOS o Windows (WSL / PowerShell)**
- Editor recomendado: **Visual Studio Code**

---

**Compilación del proyecto**

Desde la carpeta principal del proyecto, ejecutar:

g++ proyecto.cpp Archivos_cpp/*.cpp -I Archivos_hpp -o output/proyecto.exe

---

**Ejecución del programa**

**Linux / macOS / WSL**

cd output  
./proyecto.exe

**Windows (PowerShell / CMD)**

cd output  
proyecto.exe

---

**Menú principal**

===========  MENÚ TP04  ===========
1. 8-Puzzle (BFS recursivo)
2. Simulación Planta / Derivador (HIL)
3. Clasificación RNA (Dígitos)
0. Salir

---

**Descripción de las actividades**

| Actividad | Descripción |
|----------|-------------|
| **1. 8-Puzzle** | Resolución del problema del 8-puzzle usando búsqueda BFS. |
| **2. Simulación HIL** | Simulación de una planta con derivador en lazo cerrado. |
| **3. RNA** | Clasificación de datos mediante una red neuronal artificial. |

---

**Detalle de las actividades**

---

**1. 8-Puzzle**

- Implementa el algoritmo BFS
- Muestra pasos de resolución
- Representación matricial del estado del tablero

---

**2. Simulación Planta / Derivador (HIL)**

- Simulación de sistema dinámico
- Evaluación del comportamiento de la señal
- Separación clara entre modelo y controlador

---

**3. Clasificación mediante RNA**

- Clasificación de patrones
- Uso de pesos y funciones de activación
- Evaluación del resultado de clasificación

---

**Autores**

- _**William A. Hernández A.**_  
- _**Jesús D. Angulo B.**_

**Estudiantes de Ingeniería Mecatrónica**  
**Universidad Nacional de Colombia — Sede De la Paz**
