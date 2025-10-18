#ifndef VECTOR_Mm_HPP
#define VECTOR_Mm_HPP

#include <iostream>
#include <vector>
#include <limits>

class Vector_Mm {
private:
    std::vector<double> datos;

public:
    Vector_Mm();
    void ingresa_los_Datos();
    void mostrarResultados() const;

private:
    double valorMaximo(int& posicion) const;
    double valorMinimo(int& posicion) const;
};

#endif
