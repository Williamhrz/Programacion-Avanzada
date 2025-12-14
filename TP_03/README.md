
# Taller 3 — Programación Avanzada (C++)

Este proyecto implementa las **tres actividades del Taller 3** de la asignatura Programación Avanzada.  
El código está completamente modularizado en archivos `.hpp` y `.cpp`, empleando estructuras dinámicas, manejo de archivos, clases, programación orientada a objetos y simulación interactiva.

---

## Estructura del proyecto



Taller3_ProgramacionAvanzada/

Archivos_cpp/

ListadoEstudiantil.cpp

SenalECG.cpp

Domino.cpp

Archivos_hpp/

ListadoEstudiantil.hpp

SenalECG.hpp

Domino.hpp

proyecto.cpp # Menú principal

README.md

proyecto.exe # Ejecutable (después de compilar)


---

## 🛠 Requisitos

- Compilador **g++** (C++17 o superior)  
- Funciona en **Windows, Linux o macOS**  
- Editor recomendado: **Visual Studio Code**  

---

## ▶ Compilación del proyecto

Desde la carpeta principal, ejecutar:



g++ proyecto.cpp Archivos_cpp/*.cpp -IArchivos_hpp -o proyecto.exe


o en caso de que el comodín no funcione (especialmente en PowerShell):



g++ proyecto.cpp Archivos_cpp/ListadoEstudiantil.cpp Archivos_cpp/SenalECG.cpp Archivos_cpp/Domino.cpp -IArchivos_hpp -o proyecto.exe


---

## Ejecución



./proyecto.exe


Esto abrirá el menú general:



=========== MENÚ GENERAL ===========

Actividad 1: Listado Estudiantil

Actividad 2: Señal ECG

Actividad 3: Dominó

Salir


---

# Descripción de las actividades

---

## **1. Actividad 1 — Listado Estudiantil (Lista enlazada simple)**

Permite administrar un listado dinámico de estudiantes mediante una lista enlazada.

**Funciones disponibles:**

- Insertar estudiante al final  
- Eliminar por ID  
- Buscar por ID  
- Invertir la lista  
- Mostrar lista en pantalla  
- Guardar lista en archivo TXT  
- Acceso posicional mediante `operator[]`  

**Estructura de cada estudiante:**



nombre | añoNacimiento | id | promedio | email


---

## **2. Actividad 2 — Procesamiento de Señal ECG**

Permite cargar, filtrar y analizar una señal ECG almacenada en un archivo de texto.

El archivo debe tener el formato:



<amplitud> <tiempo>
<amplitud> <tiempo>
...


**Operaciones:**

- Cargar señal desde archivo  
- Filtro pasa-bajos (IIR)  
- Detección de picos por umbral  
- Guardado de señal filtrada  
- Cálculo de la frecuencia cardiaca (BPM)  

**Ejemplo de archivo válido:**



0.12 0.00
0.15 0.01
0.30 0.02
0.10 0.03
0.45 0.04
...


---

## **3. Actividad 3 — Juego de Dominó (Modo manual + historial)**

Simulación interactiva de un juego de dominó para dos jugadores.  
El usuario selecciona manualmente qué ficha desea jugar y en qué lado de la mesa.

**Características:**

- Juego completamente manual (el usuario decide cada jugada)  
- Detección de bloqueo del juego  
- Sistema de pasar turno  
- Validación de jugadas  
- Historial completo en archivo `historial_domino.txt`  
  (jugador, ficha usada, estado de la mesa)  
- Determinación automática del ganador  

---

# Ejemplo de historial de dominó



[ Turno 1 ]
Jugador: Maria
Ficha: [6|3]
Mesa: [6|3]

[ Turno 2 ]
Jugador: Juan
Ficha: [3|2]
Mesa: [6|3], [3|2]

[ Turno 3 ]
Jugador: Maria
Ficha: PASAR
Mesa: [6|3], [3|2]

...


---

# Autores

- **William A. Hernández A.**  
- **Jesús D. Angulo B.**

_Programa de Ingeniería Mecatrónica_  
_Universidad Nacional de Colombia — Sede De la Paz_