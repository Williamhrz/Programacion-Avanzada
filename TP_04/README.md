# Trabajo Práctico No. 4: Aplicaciones Avanzadas en C++
**Ingeniería Mecatrónica - Universidad Nacional de Colombia**

## Descripción General
Este proyecto implementa tres aplicaciones modulares en C++ utilizando un enfoque de **programación modular y recursiva**. El sistema integra algoritmos de búsqueda, simulación de sistemas dinámicos (HIL) y clasificación de datos, gestionados por una arquitectura centralizada.

## Estructura del Proyecto
El código se organiza para separar la definición (interfaces) de la implementación:
* **Archivos_hpp/**: Contiene las definiciones y contratos de cada módulo.
* **Archivos_cpp/**: Contiene la lógica matemática y recursiva.
* **Output/**: Directorio designado para la compilación, archivos de entrada y logs de resultados.

---

## Instrucciones de Compilación y Ejecución

### Requisitos Previos
1.  Tener instalado el compilador `g++`.
2.  Asegurarse de que el archivo `digitos.txt` exista dentro de la carpeta `Output/` para la Actividad 3.

### Para Windows
1.  Abra una terminal y navegue a la carpeta `Output`.
2.  Ejecute el script de construcción:
    ```cmd
    build.bat
    ```
3.  Si prefiere compilar manualmente:
    ```cmd
    g++ -I ../Archivos_hpp ../Proyecto.cpp ../Archivos_cpp/*.cpp -o TallerApp.exe
    TallerApp.exe
    ```

### Para Linux / MacOS
1.  Abra una terminal en la carpeta `Output`.
2.  Dé permisos y ejecute:
    ```bash
    chmod +x build.sh
    ./build.sh
    ```

---

## Metodología de Resolución

A continuación se detalla la lógica utilizada para resolver cada punto del taller:

### 1. 8-Puzzle (Rompecabezas de 8 piezas)
* **Problema:** Encontrar la secuencia óptima para ordenar un tablero $3\times3$.
* **Algoritmo:** Se implementó una búsqueda en anchura (**BFS**) para garantizar la solución más corta (óptima).
* **Recursividad:** Se utiliza una función recursiva para reconstruir e imprimir ("backtracking") el historial de movimientos desde el estado meta hasta el inicio una vez encontrada la solución.
* **Salida:** Los movimientos se muestran en consola y se guardan en `resultado_puzzle.txt`.

### 2. Simulación Hardware in the Loop (HIL)
* **Problema:** Simular una planta SISO y un derivador de orden superior.
* **Modelo:**
    * **Planta:** Se discretizó la ecuación de transferencia $G(s)$ simulando una respuesta inercial ante entradas escalón/senoidal.
    * **Derivador:** Se implementaron las ecuaciones de diferenciación robusta (Super-Twisting/HOSM) descritas en la guía (Ec. 2), utilizando la función $\varphi$ no lineal.
* **Recursividad:** La simulación temporal $t_k$ se maneja a través de una función recursiva que calcula el estado $k+1$ basado en $k$, sustituyendo los bucles `for` tradicionales para mantener el paradigma del proyecto.
* **Salida:** Genera `datos_planta.txt` con columnas tabuladas para análisis gráfico externo (Excel/Matlab).

### 3. Clasificación RNA (Red Neuronal Artificial)
* **Problema:** Clasificar números naturales leídos de un archivo.
* **Lógica de Clasificación:**
    * Clase 0 (Pares): $n \% 2 == 0$.
    * Clase 1 (Impares): $n \% 2 \neq 0$.
    * Clase 2 (Primos): Algoritmo de primalidad clásico.
    * Clase 3 (Compuestos): $n > 1$ y no primo.
* **Recursividad:** El procesamiento del archivo `digitos.txt` se realiza mediante una función recursiva que lee línea por línea hasta encontrar el `EOF` (End Of File), procesando y logueando cada número individualmente.

---
**Autor:** [Tu Nombre]
**Fecha:** Diciembre 2025