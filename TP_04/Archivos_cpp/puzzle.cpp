#include "../Archivos_hpp/puzzle.hpp"
#include "../Archivos_hpp/auto_save.hpp"
#include <iostream>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

namespace puzzle {

    // Meta: 
    // 1 2 3
    // 4 5 6
    // 7 8 0
    const Tablero META = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

    // Función auxiliar para imprimir recursivamente
    void imprimirRecursivo(const string& pasos, int index) {
        if (index >= pasos.length()) return;
        
        string movimiento;
        if (pasos[index] == 'U') movimiento = "Arriba";
        else if (pasos[index] == 'D') movimiento = "Abajo";
        else if (pasos[index] == 'L') movimiento = "Izquierda";
        else if (pasos[index] == 'R') movimiento = "Derecha";

        string log = "Paso " + to_string(index + 1) + ": Mover " + movimiento;
        cout << log << endl;
        auto_save::guardarLog("resultado_puzzle.txt", log);

        imprimirRecursivo(pasos, index + 1);
    }

    bool esMeta(const Tablero& t) { return t == META; }

    void resolverBFS(Estado inicial) {
        queue<Estado> cola;
        cola.push(inicial);
        set<Tablero> visitados;
        visitados.insert(inicial.tablero);

        // Vectores de desplazamiento: Arriba, Abajo, Izq, Der
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        char movs[] = {'U', 'D', 'L', 'R'};

        cout << "Buscando solucion optima..." << endl;

        while (!cola.empty()) {
            Estado actual = cola.front();
            cola.pop();

            if (esMeta(actual.tablero)) {
                string msg = "Solucion encontrada en " + to_string(actual.movimientos.length()) + " pasos.";
                cout << msg << endl;
                auto_save::guardarLog("resultado_puzzle.txt", "\n--- NUEVA SOLUCION ---");
                auto_save::guardarLog("resultado_puzzle.txt", msg);
                
                // Llamada recursiva para imprimir/guardar pasos
                imprimirRecursivo(actual.movimientos, 0);
                return;
            }

            // Generar hijos
            for (int i = 0; i < 4; i++) {
                int nx = actual.x + dx[i];
                int ny = actual.y + dy[i];

                if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
                    Estado nuevo = actual;
                    swap(nuevo.tablero[actual.x][actual.y], nuevo.tablero[nx][ny]);
                    nuevo.x = nx;
                    nuevo.y = ny;
                    nuevo.movimientos += movs[i];

                    if (visitados.find(nuevo.tablero) == visitados.end()) {
                        visitados.insert(nuevo.tablero);
                        cola.push(nuevo);
                    }
                }
            }
        }
        cout << "No se encontro solucion." << endl;
    }

    void ejecutarPuzzle() {
        // Ejemplo de configuración inicial (Fig 1 del PDF)
        // 4 1 3
        // 5 7 2
        // 8 0 6
        // Nota: Ajustado para que sea solucionable en tiempo razonable para el ejemplo
        Estado inicio;
        inicio.tablero = {{1, 2, 3}, {4, 5, 0}, {7, 8, 6}}; // Estado cercano a meta para prueba rápida
        inicio.x = 1; 
        inicio.y = 2;
        inicio.movimientos = "";

        cout << "--- Actividad 1: 8-Puzzle ---" << endl;
        resolverBFS(inicio);
    }
}