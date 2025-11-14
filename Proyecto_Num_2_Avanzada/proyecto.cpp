#include <iostream>
#include "Archivos_hpp/act2_matriz.hpp"

using namespace std;

int main() {
    int n;

    cout << "Ingrese el tamaño de la matriz (n x n): ";
    cin >> n;

    Matriz A(n);
    Matriz B(n);

    cout << "\nMatriz A:\n";
    A.imprimir();

    cout << "\nMatriz B:\n";
    B.imprimir();

    cout << "\nTranspuesta de A:\n";
    Matriz T = A.transpuesta();
    T.imprimir();

    cout << "\nA x B:\n";
    Matriz M = A.multiplicar(B);
    M.imprimir();

    return 0;
}
