#include <iostream>
#include <cstdlib>
#include "Archivos_hpp/Operaciones_basicas.hpp"
#include "Archivos_hpp/Vector.hpp"
#include "Archivos_hpp/Contador_de_vocales.hpp"
#include "Archivos_hpp/Norma_vector_Eu.hpp"
#include "Archivos_hpp/Matriz_pseudo.hpp"


void mostrarContexto(int opcion) {
    switch (opcion) {
        case 1:
            std::cout << "\n Ejercicio 1: Operaciones básicas con dos números enteros.\n";
            std::cout << "Este programa permite ingresar dos números y calcular su suma, resta, multiplicación y división.\n";
            break;
        case 2:
            std::cout << "\n Ejercicio 2: Vector de números decimales.\n";
            std::cout << "El programa encuentra el valor máximo y mínimo, junto con sus posiciones.\n";
            break;
        case 3:
            std::cout << "\n Ejercicio 3: Contador de vocales en una cadena.\n";
            std::cout << "El programa cuenta el número de vocales presentes en una palabra o frase.\n";
            break;
        case 4:
            std::cout << "\n Ejercicio 4: Cálculo de normas L2 y L∞.\n";
            std::cout << "El programa calcula las normas euclidiana y del infinito de un vector.\n";
            break;
        case 5:
            std::cout << "\n Ejercicio 5: Inversa y pseudo-inversa de una matriz.\n";
            std::cout << "El programa detecta si la matriz es cuadrada, calcula su inversa o pseudo-inversa según corresponda.\n";
            break;
        default:
            std::cout << "\n Opción no válida.\n";
    }
}

int main() {
    int opcion;

    do {
        std::cout << "\n     MENÚ DE EJECUCIÓN     \n";
        std::cout << "1. Operaciones básicas con dos números\n";
        std::cout << "2. Vector: máximo, mínimo y posiciones\n";
        std::cout << "3. Contar vocales en una cadena\n";
        std::cout << "4. Calcular normas L2 y L∞ de un vector\n";
        std::cout << "5. Inversa y pseudo-inversa de una matriz\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        if (opcion == 0) {
            std::cout << "\nSaliendo del programa...\n";
            break;
        }

        mostrarContexto(opcion);

        switch (opcion) {
            case 1: {
                ejecutarEjercicio1();
                break;
            }
            case 2: {
                Vector_Mm vec;
                vec.ingresa_los_Datos();
                vec.mostrarResultados();
                break;
            }
            case 3: {
                Contador_de_vocales cv;
                cv.ingresar_la_Cadena();
                cv.mostrarResultados();
            break;
            }
            case 4: {
                N_Vector nv;
                nv.ingresa_los_Datos();
                nv.mostrarResultados();
                break;
            }
            case 5: {
                Matriz_pseudo m;
                m.ejecutarEjercicio();
                break;
            }
            default:
                std::cout << "\n Por favor ingrese una opción válida.\n";
        }

        std::cout << "\n Presione ENTER para continuar...";
        std::cin.ignore();
        std::cin.get();
        system("clear || cls"); // limpia la pantalla (Linux/Windows)
    } while (true);

    return 0;
}
