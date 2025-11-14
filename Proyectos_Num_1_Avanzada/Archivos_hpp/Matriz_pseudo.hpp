#ifndef MATRIZ_PSEUDO_HPP
#define MATRIZ_PSEUDO_HPP

#include <vector>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cmath>

class Matriz_pseudo {
private:
    std::vector<std::vector<double>> datos;
    int filas;
    int columnas;

public:
    // Constructores
    Matriz_pseudo(int filas = 0, int columnas = 0);

    // Métodos principales
    void ingresarDatos();
    void mostrar() const;
    bool esCuadrada() const;
    double determinante() const;
    Matriz_pseudo inversa() const;
    Matriz_pseudo traspuesta() const;
    Matriz_pseudo pseudoInversa() const;
    bool esSingular() const;

    // Método para encapsular todo el ejercicio 5
    void ejecutarEjercicio();

private:
    double determinanteRecursivo(std::vector<std::vector<double>> mat) const;
};

#endif
