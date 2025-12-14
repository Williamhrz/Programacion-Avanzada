#include <iostream>
#include "Archivos_hpp/puzzle.hpp"
#include "Archivos_hpp/HIL.hpp"
#include "Archivos_hpp/RNA.hpp"

using namespace std;

int main() {
    int op;
    do {
        cout << "\n=== TALLER 4: INGENIERIA MECATRONICA ===" << endl;
        cout << "1. 8-Puzzle (BFS Recursivo)" << endl;
        cout << "2. Simulacion Planta/Derivador (HIL)" << endl;
        cout << "3. Clasificacion RNA (Digitos)" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione: ";
        cin >> op;

        switch(op) {
            case 1: puzzle::ejecutarPuzzle(); break;
            case 2: hil::ejecutarSimulacion(); break;
            case 3: rna::ejecutarClasificacionRNA(); break;
            case 0: cout << "Saliendo..." << endl; break;
            default: cout << "Opcion invalida." << endl;
        }
    } while(op != 0);
    return 0;
}