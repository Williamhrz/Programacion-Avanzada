**Proyecto académico — Programación Avanzada (C++)**

Este proyecto corresponde al desarrollo completo del **Taller 3 (TP03)** de la asignatura Programación Avanzada.  
Se implementan tres actividades principales empleando programación orientada a objetos, estructuras dinámicas, manejo de archivos, procesamiento de señales y simulación de juegos.

El proyecto está desarrollado en C++ y organizado de forma modular mediante archivos `.hpp` y `.cpp`.

---

**Estructura del proyecto**

TP03_ProgramacionAvanzada/

- Archivos_cpp/
    - listadoEstudiantil.cpp
    - SenalECG.cpp
    - Domino.cpp

- Archivos_hpp/
    - listadoEstudiantil.hpp
    - SenalECG.hpp
    - Domino.hpp

- proyecto.cpp               # Archivo principal (menú general)
- README.md
- output/                    # Carpeta de generados
    - data/                  # Carpeta de datos
    - executable/            # Carpeta de ejecutables
        - proyecto_run.exe
        - proyecto
    - exit/                  # Carpeta de archivos de salida

---

**Requisitos**

- Compilador: **g++ (C++17 o superior)**
- Sistema operativo: **Linux, macOS o Windows (PowerShell / CMD)**
- Editor recomendado: **Visual Studio Code o cualquier IDE compatible con C++**

---

**Compilación del proyecto**

Desde la carpeta principal del proyecto (TP03), ejecutar:

**Explicación de la línea de compilación**

| Parte                    | Descripción                                            |
|-------------------------|--------------------------------------------------       |
| `g++`                   | Compilador de C++                                       |
| `proyecto.cpp`          | Archivo principal con el menú general                   |
| `Archivos_cpp/*.cpp`    | Compila todos los módulos del proyecto                  |
| `-I Archivos_hpp`       | Indica la ruta de los archivos de cabecera              |
| `-o output/executable/` | Genera el ejecutable dentro de la carpeta                |

---

**Ejecución del programa**

---

**Linux / macOS / WSL**

1. Ubicarse en la carpeta del proyecto
2. Entrar a la carpeta output:

cd output

3. Ejecutar el programa:

    ```bash
        ./run.sh
    ```

Si se genera algun problema de permisos y ejecute:

    ```bash
    chmod +x build.sh
    ./run.sh
    ```

---

**Windows**

1. Ubicarse en la carpeta del proyecto
2. Entrar a la carpeta output:

cd output

3. Ejecutar el programa:

    ```bash
        run.bat
    ```

Otra forma para poder ejecutarlo seria esta:

    ```bash
        g++ proyecto.cpp Archivos_cpp/*.cpp -I Archivos_hpp -o output/executable/proyecto_run.exe

    ```
---

Al ejecutarse, se mostrará el menú general:

===========  MENÚ GENERAL  ===========
1. Listado Estudiantil
2. Señal ECG
3. Dominó
0. Salir

El usuario debe ingresar el número de la actividad que desea ejecutar.

---

**Descripción de las actividades**

| Actividad | Descripción |
|----------|-------------|
| **1. Listado Estudiantil** | Gestión de estudiantes mediante una lista enlazada simple. |
| **2. Señal ECG** | Procesamiento de señales biomédicas con filtrado y detección de picos. |
| **3. Dominó** | Simulación manual de un juego de dominó con historial de jugadas. |

---

**Detalle de cada actividad**

---

**1. Listado Estudiantil (Lista Enlazada Simple)**

**Funcionalidades:**
- Insertar estudiante
- Eliminar por ID
- Buscar estudiante por ID
- Invertir la lista
- Imprimir lista en pantalla
- Guardar listado en archivo `.txt`
- Acceso por índice mediante sobrecarga del operador `[]`

**Salida a archivo:**
- El archivo se guarda dentro de la carpeta `output`

---

**2. Señal ECG (Procesamiento de señal)**

**Funcionalidades:**
- Cargar señal ECG desde archivo `.txt`
- Filtrar la señal con un filtro pasa-bajos IIR
- Detección de picos a partir de un umbral
- Cálculo de frecuencia cardiaca (BPM)
- Guardar señal filtrada en archivo

**Formato del archivo de entrada:**
- Dos columnas: amplitud y tiempo

---

**3. Dominó (Modo manual con historial)**

**Funcionalidades:**
- Registro de jugadores
- Reparto de fichas
- Validación de jugadas
- Opción de pasar turno
- Detección de bloqueo
- Registro completo de jugadas en archivo

**Archivo generado:**
- `historial_domino.txt` dentro de la carpeta `output`

---

**Autores**

- _**William A. Hernández A.**_  
- _**Jesús D. Angulo B.**_

**Estudiantes de Ingeniería Mecatrónica**  
**Universidad Nacional de Colombia — Sede De la Paz**
