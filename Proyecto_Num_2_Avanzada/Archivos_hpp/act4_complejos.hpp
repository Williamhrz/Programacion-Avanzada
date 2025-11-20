#ifndef ACT4_COMPLEJOS_HPP
#define ACT4_COMPLEJOS_HPP

#include <iostream>
#include <cmath>
#include <vector>

class polar; // declaración adelantada

// ===================== CLASE complexNum ===================== //
class complexNum {
private:
    double a;  // parte real
    double b;  // parte imaginaria

public:
    // Constructores
    complexNum(double real = 0, double imag = 0);
    complexNum(const polar& p);  // conversión de polar a binomial

    // Getters
    double real() const { return a; }
    double imag() const { return b; }

    // Operadores
    complexNum operator+(const complexNum& c) const;
    complexNum operator-(const complexNum& c) const;
    complexNum operator*(const complexNum& c) const;
    complexNum operator/(const complexNum& c) const;

    // Conjugado
    complexNum conj() const;

    // Conversión a polar
    polar toPolar() const;

    // Imprimir
    void imprimir() const;
};

// ===================== CLASE POLAR ===================== //
class polar {
private:
    double r;   // módulo
    double t;   // argumento

public:
    // Constructores
    polar(double modulo = 0, double argumento = 0);
    polar(const complexNum& c);  // conversión desde binomial

    // Getters
    double modulo() const { return r; }
    double argumento() const { return t; }

    // Operadores
    polar operator+(const polar& p) const;
    polar operator-(const polar& p) const;
    polar operator*(const polar& p) const;
    polar operator/(const polar& p) const;

    // Conjugado
    polar conj() const;

    // Conversión a complexNumNum
    complexNum toComplex() const;

    // Imprimir
    void imprimir() const;
};

// ========== Función acumula: suma múltiples complejos y polares ========== //
complexNum acumula(const std::vector<complexNum>& listaC, const std::vector<polar>& listaP);

#endif