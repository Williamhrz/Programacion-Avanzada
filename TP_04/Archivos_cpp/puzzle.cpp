#include "../Archivos_hpp/puzzle.hpp"
#include "../Archivos_hpp/auto_save.hpp"
#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;

namespace puzzle {

    // META SEGÚN FIGURA 2 (Espiral):
    const Tablero META = {
        {1, 2, 3},
        {8, 0, 4},
        {7, 6, 5}
    };

    const string RUTA_SALIDA = "exit/resultado_puzzle.txt";

    // Genera el dibujo del tablero
    string formatearTableroConMovimiento(const Tablero& t, const string& infoMovimiento) {
        stringstream ss;
        ss << "-------------" << endl;
        for (int i = 0; i < 3; i++) {
            ss << "| ";
            for (int val : t[i]) {
                if(val == 0) ss << "  | "; 
                else ss << val << " | ";
            }
            if (i == 1 && !infoMovimiento.empty()) {
                ss << "   <--- " << infoMovimiento;
            }
            ss << endl << "-------------" << endl;
        }
        return ss.str();
    }

    // Función recursiva corregida (Invierte la perspectiva Cero vs Pieza)
    void imprimirRecursivo(const string& pasos, int index, Estado actual) {
        if (index > pasos.length()) return;

        string textoMovimiento = "";
        if (index == 0) {
            textoMovimiento = "Estado Inicial";
        } else {
            char m = pasos[index-1]; 
            // CORRECCIÓN AQUÍ: Invertimos los textos para reflejar el movimiento de la PIEZA
            // Si el 0 (vacio) sube 'U', la pieza baja.
            if (m == 'U') textoMovimiento = "Mover Pieza Abajo (Down)";   // Antes era Arriba
            else if (m == 'D') textoMovimiento = "Mover Pieza Arriba (Up)"; // Antes era Abajo
            else if (m == 'L') textoMovimiento = "Mover Pieza Derecha (Right)"; // Antes era Izq
            else if (m == 'R') textoMovimiento = "Mover Pieza Izquierda (Left)"; // Antes era Der
        }

        // Mostrar y Guardar
        string dibujo = formatearTableroConMovimiento(actual.tablero, textoMovimiento);
        cout << "\n--- Paso " << index << " ---" << endl;
        cout << dibujo;
        auto_save::guardarLog(RUTA_SALIDA, "Paso " + to_string(index));
        auto_save::guardarLog(RUTA_SALIDA, dibujo);

        if (index == pasos.length()) return;

        // Física del movimiento (Esta NO cambia, solo cambió el texto)
        char mov = pasos[index];
        int dx = 0, dy = 0;
        if (mov == 'U') dx = -1;      // 0 sube
        else if (mov == 'D') dx = 1;  // 0 baja
        else if (mov == 'L') dy = -1; // 0 izquierda
        else if (mov == 'R') dy = 1;  // 0 derecha

        Estado siguiente = actual;
        swap(siguiente.tablero[actual.x][actual.y], siguiente.tablero[actual.x + dx][actual.y + dy]);
        siguiente.x = actual.x + dx;
        siguiente.y = actual.y + dy;

        imprimirRecursivo(pasos, index + 1, siguiente);
    }

    bool esMeta(const Tablero& t) { return t == META; }

    Estado pedirConfiguracionInicial() {
        Estado e;
        e.tablero.resize(3, vector<int>(3));
        vector<bool> usados(9, false);
        
        cout << "\n=== CONFIGURACION 8-PUZZLE ===" << endl;
        cout << "Ingrese los numeros fila por fila (0 es el vacio)." << endl;
        cout << "Meta Espiral: \n1 2 3\n8 0 4\n7 6 5" << endl;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int val;
                while (true) {
                    cout << "Posicion [" << i << "][" << j << "]: ";
                    cin >> val;
                    if (val >= 0 && val <= 8 && !usados[val]) {
                        usados[val] = true;
                        e.tablero[i][j] = val;
                        if (val == 0) {
                            e.x = i;
                            e.y = j;
                        }
                        break;
                    } else {
                        cout << "Numero repetido o invalido." << endl;
                    }
                }
            }
        }
        e.movimientos = "";
        return e;
    }

    void resolverBFS(Estado inicial) {
        queue<Estado> cola;
        cola.push(inicial);
        set<Tablero> visitados;
        visitados.insert(inicial.tablero);

        // Movimientos internos del 0: U, D, L, R
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        char movs[] = {'U', 'D', 'L', 'R'};

        cout << "Buscando solucion optima..." << endl;

        while (!cola.empty()) {
            Estado actual = cola.front();
            cola.pop();

            if (esMeta(actual.tablero)) {
                cout << "\n!!! SOLUCION ENCONTRADA !!!" << endl;
                cout << "Pasos: " << actual.movimientos.length() << endl;
                auto_save::guardarLog(RUTA_SALIDA, "\n=== NUEVA SOLUCION ===");
                imprimirRecursivo(actual.movimientos, 0, inicial);
                return;
            }

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
        cout << "Sin solucion." << endl;
    }

    void ejecutarPuzzle() {
        Estado inicio = pedirConfiguracionInicial();
        resolverBFS(inicio);
    }
}