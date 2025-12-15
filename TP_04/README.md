**Proyecto académico — Programación Avanzada (C++)**

<<<<<<< HEAD
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
## Descripción General
Este proyecto implementa tres aplicaciones de ingeniería avanzada desarrolladas en C++ bajo un enfoque de **programación modular y orientada a objetos**. El sistema integra algoritmos de búsqueda en espacios de estados, simulación de sistemas dinámicos en tiempo real (HIL) e Inteligencia Artificial (Redes Neuronales), gestionados mediante una arquitectura centralizada.

El código hace uso extensivo de recursividad para el control de flujos y herramientas personalizadas de gestión de archivos (`auto_save`, `self_clean`) para garantizar la persistencia y organización de los datos.

Estructura del Directorio
La organización de archivos del proyecto es la siguiente:

* **`Archivos_hpp/`**: Contiene las definiciones (.hpp) y módulos de utilidad.
* **`Archivos_cpp/`**: Contiene la implementación lógica (.cpp) de los algoritmos.
* **`output/data/`**: Contiene los archivos de entrada requeridos (ej. `digitos.txt`).
* **`output/executable/`**: Carpeta destino para el binario compilado.
* **`output/exit/`**: Carpeta donde se guardan los reportes y logs de resultados.
* **`proyecto.cpp`**: Archivo principal (Main).
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
## Instrucciones de Compilación y Ejecución

### Requisitos Previos
1.  Tener instalado el compilador `g++`.
2.  Contar con un entorno de desarrollo (IDE o terminal con herramientas de compilación).
3.  Asegurarse de que el archivo `digitos.txt` exista dentro de la carpeta `output/data/` para la Actividad 3.


### Para Windows
1.  Abra una terminal y navegue a la carpeta `output`.
2.  Ejecute el script de construcción:
    ```cmd
    run.bat
    ```
3.  Si prefiere compilar manualmente:
    ```cmd
    g++ -I ../Archivos_hpp ../Proyecto.cpp ../Archivos_cpp/*.cpp -o TallerApp.exe
    proyecto.exe
    ```

### Para Linux / MacOS
1.  Abra una terminal en la carpeta `output`.
2.  Dé permisos y ejecute:
    ```bash
    chmod +x build.sh
    ./run.sh
    ```
=======
## Descripción General
Este proyecto implementa tres aplicaciones de ingeniería avanzada desarrolladas en C++ bajo un enfoque de **programación modular y orientada a objetos**. El sistema integra algoritmos de búsqueda en espacios de estados, simulación de sistemas dinámicos en tiempo real (HIL) e Inteligencia Artificial (Redes Neuronales), gestionados mediante una arquitectura centralizada.

El código hace uso extensivo de recursividad para el control de flujos y herramientas personalizadas de gestión de archivos (`auto_save`, `self_clean`) para garantizar la persistencia y organización de los datos.

Estructura del Directorio
La organización de archivos del proyecto es la siguiente:
>>>>>>> e73d339 (Revert "Merge branch 'desarrollo-jesus' of https://github.com/Williamhrz/Programacion-Avanzada into desarrollo-william")

* **`Archivos_hpp/`**: Contiene las definiciones (.hpp) y módulos de utilidad.
* **`Archivos_cpp/`**: Contiene la implementación lógica (.cpp) de los algoritmos.
* **`output/data/`**: Contiene los archivos de entrada requeridos (ej. `digitos.txt`).
* **`output/executable/`**: Carpeta destino para el binario compilado.
* **`output/exit/`**: Carpeta donde se guardan los reportes y logs de resultados.
* **`proyecto.cpp`**: Archivo principal (Main).
---
**Autores**

- _**William A. Hernández A.**_
- _**Jesus D. Angulo B
