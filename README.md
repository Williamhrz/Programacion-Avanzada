# Colección de Proyectos de Programación Avanzada en C++
**Ingeniería Mecatrónica - Universidad Nacional de Colombia**

## Descripción General
Este repositorio alberga una colección integral de **4 Trabajos Prácticos (TPs)** desarrollados en lenguaje C++. La suite de aplicaciones demuestra una curva de aprendizaje progresiva, abarcando desde los fundamentos del álgebra lineal y manejo de memoria, hasta la implementación de estructuras de datos dinámicas, procesamiento de señales digitales (DSP) e Inteligencia Artificial.

El desarrollo de todo el repositorio se rige bajo una filosofía de **Programación Modular, Recursiva y Orientada a Objetos**, separando estrictamente las interfaces, la implementación lógica y la gestión de recursos para garantizar un código limpio, escalable y mantenible.

### Características Principales del Repositorio
* **Multiplataforma:** Todo el código ha sido diseñado, compilado y probado para funcionar nativamente tanto en **Linux** (Ubuntu/Debian) como en **Windows**.
* **Arquitectura Modular:** Separación estricta de archivos:
    * `.hpp`: Definiciones y contratos (Headers).
    * `.cpp`: Implementación de la lógica (Source).
* **Gestión de Archivos:** Sistema estandarizado de lectura de datos (`/data`) y generación de reportes (`/exit`).
* **Automatización:** Scripts de construcción y ejecución incluidos (`run.sh` y `run.bat`) para facilitar el despliegue.

---

## Estructura del Proyecto

El repositorio se divide en cuatro módulos principales, cada uno correspondiente a una etapa de complejidad incremental:

```text
Proyecto_C++
 ┣  TP_01  (Fundamentos y Álgebra Lineal)
 ┣  TP_02  (POO y Modelado Matemático)
 ┣  TP_03  (Estructuras de Datos y Procesamiento de Señales)
 ┗  TP_04  (IA, HIL y Recursividad Avanzada)
```

Cada módulo (TP) mantiene una estructura interna estandarizada para facilitar la navegación y el mantenimiento:

* **`Archivos_hpp/`**: Cabeceras con las declaraciones de clases y funciones.
* **`Archivos_cpp/`**: Código fuente con la lógica de negocio.
* **`output/`**: Espacio de trabajo limpio.
    * `executable/`: Contiene los binarios compilados (`.exe` o binarios Linux).
    * `data/`: Archivos de entrada requeridos (ej. señales ECG, patrones numéricos).
    * `exit/`: Logs, reportes y resultados generados por el software.
* **`proyecto.cpp`**: Punto de entrada principal (Main) que orquesta los menús.

## Detalle de los Módulos

### [TP_01] Fundamentos y Operaciones Vectoriales
Introducción a la manipulación de memoria y operaciones matemáticas básicas.
* **Contenido:** Contador de vocales, operaciones matriciales (cálculo de pseudo-inversa), norma Euclideana de vectores y sobrecarga de operadores básicos.

### [TP_02] Programación Orientada a Objetos (POO)
Implementación de clases robustas para modelado matemático y simulación.
* **Contenido:** Clase `Vector3D`, aritmética de Polinomios y Números Complejos, resolución de sistemas de ecuaciones y una primera implementación lógica del juego de Dominó.

### [TP_03] Estructuras de Datos y Procesamiento Digital
Uso de memoria dinámica avanzada y análisis de datos reales.
* **Señal ECG:** Clase `SenalECG` para filtrar señales cardiacas, detectar picos R y calcular frecuencia cardiaca leyendo archivos `.txt`.
* **Listas Enlazadas:** Gestión dinámica de un listado estudiantil (inserción, borrado, búsqueda).
* **Dominó (Historial):** Implementación de listas para guardar y exportar el historial de movimientos de la partida.

### [TP_04] Aplicaciones Avanzadas e Inteligencia Artificial
Integración de algoritmos de búsqueda, sistemas de control y redes neuronales.
* **8-Puzzle:** Solución óptima mediante algoritmo de búsqueda en anchura (**BFS**) y reconstrucción recursiva del camino.
* **Simulación HIL:** Simulación de tiempo real de una planta dinámica acoplada a un derivador robusto (**HOSM**).
* **Red Neuronal (RNA):** Clasificación de dígitos (patrones 7x5) mediante Perceptrón Multicapa y algoritmo de **Backpropagation**.

---

**Autores**

- _**William A. Hernández A.**_  
- _**Jesús D. Angulo B.**_

**Estudiantes de Ingeniería Mecatrónica**  
**Universidad Nacional de Colombia — Sede De la Paz**