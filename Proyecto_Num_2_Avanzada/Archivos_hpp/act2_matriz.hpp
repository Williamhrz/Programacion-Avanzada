#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>

class Matriz {
private:
    int n;
    int** datos;

public:
    // Constructor: inicializa matriz n×n con valores aleatorios
    Matriz(int n);

    // Constructor de copia
    Matriz(const Matriz& otra);

    // Destructor
    ~Matriz();

    // Operador para indexar matriz: m(i,j)
    int& operator()(int i, int j);

    // Imprimir matriz
    void imprimir() const;

    // Calcular transpuesta
    Matriz transpuesta() const;

    // Multiplicar por otra matriz n×n
    Matriz multiplicar(const Matriz& otra) const;
};

#endif
