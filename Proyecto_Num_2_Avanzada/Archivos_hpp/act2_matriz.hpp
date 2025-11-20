#ifndef ACT2_MATRIZ_HPP
#define ACT2_MATRIZ_HPP

#include <iostream>

class Matriz {
private:
    int n;          // tamaño de la matriz (n x n)
    int** datos;    // puntero doble para matriz dinámica

public:
    // Constructor: crea la matriz y la llena con números aleatorios
    Matriz(int n);

    // Constructor de copia (profunda)
    Matriz(const Matriz& otra);

    // Destructor: libera memoria dinámica
    ~Matriz();

    // Operador para acceder a un elemento
    int& operator()(int i, int j);

    // Obtener el tamaño
    int getSize() const { return n; }

    // Imprimir matriz en consola
    void imprimir() const;

    // Retorna la matriz transpuesta
    Matriz transpuesta() const;

    // Multiplica 2 matrices n×n
    Matriz multiplicar(const Matriz& otra) const;

    // Sobrecarga del operador * como alias de multiplicar
    Matriz operator*(const Matriz& otra) const {
        return multiplicar(otra);
    }
};

#endif