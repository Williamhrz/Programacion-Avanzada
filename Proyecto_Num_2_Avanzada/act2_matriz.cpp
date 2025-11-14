#include "act2_matriz.hpp"
#include <cstdlib>
#include <ctime>

using namespace std;

// Constructor: inicializa matriz aleatoria
Matriz::Matriz(int n) : n(n) {
    datos = new int*[n];
    for (int i = 0; i < n; i++) {
        datos[i] = new int[n];
    }

    srand(time(NULL));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            datos[i][j] = rand() % 10;
}

// Constructor de copia
Matriz::Matriz(const Matriz& otra) : n(otra.n) {
    datos = new int*[n];
    for (int i = 0; i < n; i++) {
        datos[i] = new int[n];
        for (int j = 0; j < n; j++) {
            datos[i][j] = otra.datos[i][j];
        }
    }
}

// Destructor
Matriz::~Matriz() {
    for (int i = 0; i < n; i++)
        delete[] datos[i];
    delete[] datos;
}

// Operador () para acceso
int& Matriz::operator()(int i, int j) {
    return datos[i][j];
}

// Imprimir
void Matriz::imprimir() const {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << datos[i][j] << " ";
        cout << endl;
    }
}

// Transpuesta
Matriz Matriz::transpuesta() const {
    Matriz t(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            t.datos[j][i] = datos[i][j];

    return t;
}

// Multiplicación
Matriz Matriz::multiplicar(const Matriz& otra) const {
    Matriz r(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            r.datos[i][j] = 0;

            for (int k = 0; k < n; k++)
                r.datos[i][j] += datos[i][k] * otra.datos[k][j];
        }

    return r;
}