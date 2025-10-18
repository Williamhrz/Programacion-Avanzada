#ifndef N_VECTOR_HPP
#define N_VECTOR_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class N_Vector {
private:
    std::vector<double> datos;

public:
    N_Vector();
    void ingresa_los_Datos();
    void mostrarResultados() const;

private:
    double normaL2() const;
    double normaLinf() const;
};

#endif
