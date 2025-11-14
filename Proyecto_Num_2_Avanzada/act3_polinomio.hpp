#ifndef ACT3_POLINOMIO_HPP
#define ACT3_POLINOMIO_HPP

#include <iostream>

class Polinomio {
private:
    int grado;       
    double* coef;    

public:
    // Constructor: recibe el grado e inicializa coeficientes
    Polinomio(int grado);

    // Constructor por copia
    Polinomio(const Polinomio& other);

    // Destructor
    ~Polinomio();

    // Evaluar P(x)
    double evaluar(double x) const;

    // Imprimir formato estándar
    void imprimir() const;

    // Derivada → retorna nuevo Polinomio
    Polinomio derivada() const;

    // Sobrecarga suma
    Polinomio operator+(const Polinomio& p) const;

    // Sobrecarga multiplicación
    Polinomio operator*(const Polinomio& p) const;
};

#endif