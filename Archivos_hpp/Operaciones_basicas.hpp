#ifndef OPERACIONESBASICAS_HPP
#define OPERACIONESBASICAS_HPP

#include <iostream>
#include <stdexcept>

class Operacionesbasicas {
private:
    double a, b; // Cambiado a double, pero mantiene el mismo nombre

public:
    Operacionesbasicas();
    void ingresa_los_Numeros();
    void mostrarResultados() const;

private:
    double suma() const;
    double resta() const;
    double multiplicacion() const;
    double division() const;
};

// Función que ejecuta todo el ejercicio 1
void ejecutarEjercicio1();

#endif
