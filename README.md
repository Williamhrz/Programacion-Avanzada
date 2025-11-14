# Estructura del Repositorio

El repositorio está organizado en dos carpetas principales, cada una correspondiente a un proyecto independiente desarrollado en C++ para la asignatura de Programación Avanzada. Ambos proyectos están estructurados de manera modular para mantener un código limpio, ordenado y fácil de mantener. Cada proyecto incluye un archivo **README.md** con instrucciones de compilación y ejecución.

---

## 🔹 Proyecto_Num_1

Esta carpeta contiene el desarrollo completo del primer proyecto. Su estructura interna está organizada modularmente para separar el código principal de las implementaciones y definiciones auxiliares.

### Estructura interna

- **proyecto.cpp**  
  Archivo principal que contiene la función `main()` y la lógica de ejecución del programa.

- **Archivos_cpp/**  
  Carpeta con las implementaciones (`.cpp`) de las clases, funciones o módulos utilizados en el proyecto.  
  Ejemplo:
  - `archivo1.cpp`
  - `archivo2.cpp`

- **Archivos_hpp/**  
  Carpeta que contiene los archivos de cabecera (`.hpp`) donde se declaran clases, funciones, estructuras y prototipos.

- **output/**  
  Carpeta donde se genera el archivo ejecutable después de compilar el proyecto.

- **runproyect**  
  Script ejecutable que automatiza la compilación y ejecución del programa.  
  Permite ejecutarlo con:  
  ```bash
  ./runproyect
