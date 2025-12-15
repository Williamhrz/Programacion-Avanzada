**Proyecto académico — Programación Avanzada (C++)**

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

### Requisitos Previos
1.  Tener instalado el compilador `g++`.
2.  Contar con un entorno de desarrollo .
3. Sistema operativo: **Linux, macOS o Windows (WSL / PowerShell)**
4.  Asegurarse de que el archivo `digitos.txt` exista dentro de la carpeta `output/data/` para la Actividad 3.
---

**Compilación del proyecto**

Ejecución del programa

1. Linux / macOS / WSL

cd output/ 

    ```cmd
    ./run.sh
    ```

2. Windows (PowerShell / CMD)

cd output/  

    ```cmd
    run.bat
    ```
Si se genera algun problema intentar con:

Dé permisos y ejecute:

```bash
chmod +x build.sh
./run.sh
```

3. Otra forma para Windows

cd output/executable/

```cmd
proyecto.exe
```

Desde la carpeta principal del proyecto, ejecutar:

```bash
    g++ proyecto.cpp Archivos_cpp/*.cpp -I Archivos_hpp -o output/executable/proyecto.exe
```
---

**Una vez ejecutado, el programa mostrara lo siguiente:**

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
