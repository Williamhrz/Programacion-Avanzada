#include <iostream>
#include <cstdlib>

// Archivos .hpp del proyecto
#include "Archivos_hpp/act1_vector3D.hpp"
#include "Archivos_hpp/act2_matriz.hpp"
#include "Archivos_hpp/act3_polinomio.hpp"
#include "Archivos_hpp/act4_complejos.hpp"
#include "Archivos_hpp/act5_ecuaciones.hpp"
#include "Archivos_hpp/act6_domino.hpp"

using namespace std;

// =============================================================
//                 DESCRIPCIÓN DE CADA EJERCICIO
// =============================================================
void mostrarContexto(int opcion) {
    switch (opcion) {

        case 1:
            cout << "\n Ejercicio 1: Clase Vector3D.\n";
            cout << "Operaciones entre dos vectores: suma, resta,\n";
            cout << "producto escalar, magnitud y normalización.\n";
            break;

        case 2:
            cout << "\n Ejercicio 2: Matriz NxN con memoria dinámica.\n";
            cout << "Genera matrices aleatorias, calcula transpuesta\n";
            cout << "y multiplicación entre matrices cuadradas.\n";
            break;

        case 3:
            cout << "\n Ejercicio 3: Clase Polinomio.\n";
            cout << "Permite evaluar, derivar, sumar y multiplicar polinomios.\n";
            break;

        case 4:
            cout << "\n Ejercicio 4: Números complejos y polares.\n";
            cout << "Operaciones básicas, conjugados y conversión binomial/polar.\n";
            break;

        case 5:
            cout << "\n Ejercicio 5: Ecuaciones algebraicas tipo polinomio.\n";
            cout << "Inserción de términos, suma y multiplicación de polinomios.\n";
            break;

        case 6:
            cout << "\n Ejercicio 6: Juego de Dominó.\n";
            cout << "Simulación completa del juego usando POO.\n";
            break;

        default:
            cout << "\n Opción no válida.\n";
    }
}

// =============================================================
//                      MENÚ PRINCIPAL
// =============================================================
int main() {
    int opcion;

    do {
        cout << "\n==========  MENÚ DE EJECUCIÓN  ==========\n";
        cout << "1. Punto 1 - Vector3D\n";
        cout << "2. Punto 2 - Matriz NxN\n";
        cout << "3. Punto 3 - Polinomio\n";
        cout << "4. Punto 4 - Complejos / Polares\n";
        cout << "5. Punto 5 - Ecuaciones algebraicas\n";
        cout << "6. Punto 6 - Juego de Dominó\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (opcion == 0) {
            cout << "\nSaliendo del programa...\n";
            break;
        }

        mostrarContexto(opcion);

        // =============================================================
        //                   LLAMADO A CADA EJERCICIO
        // =============================================================
        switch (opcion) {

            // ====================== PUNTO 1 ============================
            case 1: {
                float ax, ay, az, bx, by, bz;

                cout << "\nIngrese vector A (x y z): ";
                cin >> ax >> ay >> az;
                cout << "Ingrese vector B (x y z): ";
                cin >> bx >> by >> bz;

                Vector3D A(ax, ay, az);
                Vector3D B(bx, by, bz);

                cout << "\nA = "; A.imprimir();
                cout << "\nB = "; B.imprimir();

                cout << "\n\nA + B = "; (A + B).imprimir();
                cout << "\nA - B = "; (A - B).imprimir();
                cout << "\nA · B = " << (A * B);
                cout << "\n|A| = " << A.magnitud();
                cout << "\nA normalizado = "; A.normalizar().imprimir();
                cout << "\n";
                break;
            }

            // ====================== PUNTO 2 ============================
            case 2: {
                int n;
                cout << "\nTamaño de la matriz NxN: ";
                cin >> n;

                Matriz M(n);

                cout << "\nMatriz generada:\n";
                M.imprimir();

                cout << "\nTranspuesta:\n";
                M.transpuesta().imprimir();

                cout << "\nM * M:\n";
                (M * M).imprimir();
                break;
            }

            // ====================== PUNTO 3 ============================
            case 3: {
                int g;
                cout << "\nIngrese grado del polinomio P: ";
                cin >> g;

                Polinomio P(g);

                double x;
                cout << "\nIngrese valor de x: ";
                cin >> x;

                cout << "\nP(x) = " << P.evaluar(x);

                cout << "\nDerivada: ";
                P.derivada().imprimir();
                cout << "\n";
                break;
            }

            // ====================== PUNTO 4 ============================
            case 4: {
                double a, b;
                cout << "\nNúmero complejo A (a + bi)\n";
                cout << "Ingrese parte real: ";
                cin >> a;
                cout << "Ingrese parte imaginaria: ";
                cin >> b;
                complexNum A(a, b);

                double r, t;
                cout << "\nNúmero polar B (r, θ)\n";
                cout << "Ingrese módulo: ";
                cin >> r;
                cout << "Ingrese ángulo: ";
                cin >> t;
                polar B(r, t);

                cout << "\nA = "; A.imprimir();
                cout << "\nB = "; B.imprimir();

                cout << "\n\nA + B = "; (A + B.toComplex()).imprimir();
                cout << "\nA * B = "; (A * B.toComplex()).imprimir();
                cout << "\nConjugado de A = "; A.conj().imprimir();
                cout << "\n";
                break;
            }

            // ====================== PUNTO 5 ============================
            case 5: {
                CPolinomio P, Q;

                int n1;
                cout << "\nCantidad de términos de P: ";
                cin >> n1;

                for (int i = 0; i < n1; i++) {
                    double c; int e;
                    cout << "Coeficiente y exponente: ";
                    cin >> c >> e;
                    P.insertar(CTermino(c, e));
                }

                int n2;
                cout << "\nCantidad de términos de Q: ";
                cin >> n2;

                for (int i = 0; i < n2; i++) {
                    double c; int e;
                    cout << "Coeficiente y exponente: ";
                    cin >> c >> e;
                    Q.insertar(CTermino(c, e));
                }

                cout << "\nP(x) = " << P.toString();
                cout << "\nQ(x) = " << Q.toString();

                cout << "\n\nP + Q = " << P.sumar(Q).toString();
                cout << "\nP * Q = " << P.multiplicar(Q).toString();
                cout << "\n";
                break;
            }

            // ====================== PUNTO 6 ============================
            case 6: {
                JuegoDomino game;

                int jugadores;
                cout << "\nNúmero de jugadores (2-4): ";
                cin >> jugadores;

                while (jugadores < 2 || jugadores > 4) {
                    cout << "Cantidad inválida. Ingrese un número entre 2 y 4: ";
                    cin >> jugadores;
                }

                for (int i = 1; i <= jugadores; i++) {
                    string nombre;
                    cout << "Nombre del jugador " << i << ": ";
                    cin >> nombre;
                    game.agregarJugador(nombre);
                }

                game.iniciar();
                game.jugar();
                break;
            }
        }
            cout << "\n Presione ENTER para continuar...";
            cin.ignore();
            cin.get();
            system("clear || cls");

        } while (true);

    return 0;
}