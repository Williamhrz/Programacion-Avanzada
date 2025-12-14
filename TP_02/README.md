Proyecto académico — Programación Avanzada (C++)

Este proyecto implementa los seis ejercicios del **Trabajo Práctico 02** de la asignatura Programación Avanzada, desarrollados en C++ con un enfoque modular, orientado a objetos y organizado en múltiples librerías (.hpp y .cpp).  
Incluye manejo de clases, sobrecarga de operadores, memoria dinámica, polinomios, números complejos, estructuras algebraicas y un juego completo de dominó.

---

Estructura del proyecto

TP02_ProgramacionAvanzada/

- Archivos_cpp/              
    - act1_vector3D.cpp
    - act2_matriz.cpp
    - act3_polinomio.cpp
    - act4_complejos.cpp
    - act5_ecuaciones.cpp
    - act6_domino.cpp

- Archivos_hpp/              
    - act1_vector3D.hpp
    - act2_matriz.hpp
    - act3_polinomio.hpp
    - act4_complejos.hpp
    - act5_ecuaciones.hpp
    - act6_domino.hpp

- proyecto.cpp               # Archivo principal (menú general)
- README.md                  
- runproyect                 # Ejecutable


---

**Requisitos**

- Compilador: **g++ (C++17 o superior)**
- Sistema operativo: **Linux, macOS o WSL en Windows**
- Editor recomendado: **Visual Studio Code o cualquier IDE compatible con C++**

---

**Compilación y ejecución**

Desde la carpeta principal del proyecto, abre una terminal y ejecuta:

g++ proyecto.cpp Archivos_cpp/*.cpp -I Archivos_hpp -o runproyect


---

Explicación de la línea de compilación

| Parte                | Descripción                                 |
| -------------------- | ------------------------------------------- |
| `g++`                | Compilador de C++                           |
| `proyecto.cpp`       | Archivo principal con el menú general       |
| `Archivos_cpp/*.cpp` | Compila todos los módulos del proyecto      |
| `-I Archivos_hpp`    | Indica dónde están los archivos `.hpp`      |
| `-o runproyect`      | Crea el ejecutable con ese nombre           |

---

**Ejecutar el programa**

Una vez compilado, corre el programa con:

./output/runproyect


Esto abrirá el menú interactivo:

==========  MENÚ DE EJECUCIÓN  ==========
1. Vector3D
2. Matriz NxN
3. Polinomio
4. Complejos / Polares
5. Ecuaciones algebraicas
6. Juego de Dominó
0. Salir


El usuario debe escribir el número del ejercicio que desea ejecutar.

El programa mostrará instrucciones y pedirá los datos necesarios.

---

**Descripción de los ejercicios**

| Ejercicio | Descripción |
|----------|-------------|
| **1. Vector3D** | Permite ingresar dos vectores A y B y obtener: suma, resta, producto punto, magnitud y normalización. |
| **2. Matriz NxN** | Genera una matriz aleatoria NxN, muestra su transpuesta y realiza la multiplicación M × M. |
| **3. Polinomio** | Permite ingresar el grado y un valor x para evaluar P(x) y obtener su derivada. |
| **4. Complejos y polares** | Se ingresa un complejo A y un polar B; permite sumar, multiplicar y obtener el conjugado. |
| **5. Ecuaciones algebraicas** | Permite ingresar polinomios por términos, evaluarlos, sumarlos y multiplicarlos. |
| **6. Juego de dominó** | Simula automáticamente una partida de dominó para 2 a 4 jugadores. |

---

**Detalle del ingreso de datos por ejercicio**

---

**1. Vector3D**

**Ingreso:**

Ingrese vector A (x y z): ax ay az
Ingrese vector B (x y z): bx by bz

**Ejemplo:**

1 2 3
4 5 6

**Operaciones:**
- Suma  
- Resta  
- Producto punto  
- Magnitud  
- Normalización  

---

**2. Matriz NxN**

**Ingreso:**

Tamaño de la matriz NxN: n


**Operaciones:**
- Matriz generada aleatoriamente  
- Transpuesta  
- Multiplicación M × M  

---

**3. Polinomio**

**Ingreso:**

Ingrese grado del polinomio P: g
Ingrese valor de x: x


**Operaciones:**
- Evaluación P(x)  
- Derivación  

---

**4. Complejos y Polares**

**Ingreso del complejo A:**

Ingrese parte real: a
Ingrese parte imaginaria: b


**Ingreso del polar B:**

Ingrese módulo: r
Ingrese ángulo: t


**Operaciones:**
- A + B  
- A × B  
- Conjugado de A  

---

**5. Ecuaciones algebraicas**

**Ingreso:**

Cantidad de términos de P: n1
Coeficiente y exponente: c e

Cantidad de términos de Q: n2
Coeficiente y exponente: c e

**Operaciones:**
- P(x)  
- Q(x)  
- P + Q  
- P × Q  

---

**6. Juego de Dominó**

**Ingreso:**

Número de jugadores (2-4): n
Nombre del jugador 1: x
Nombre del jugador 2: y
...


El sistema realiza automáticamente la simulación.

---

**Autores**

- _**William A. Hernández A.**_  
- _**Jesús D. Angulo B.**_  
- _**Iván M. Vásquez A.**_

**Estudiantes de Ingeniería Mecatrónica**  
**Universidad Nacional de Colombia — Sede De la Paz**




