#ifndef ACT5_ECUACIONES_HPP
#define ACT5_ECUACIONES_HPP

#include <iostream>
#include <string>

// ========================== CTermino ==========================
class CTermino {
private:
    double coef;
    int exp;

public:
    CTermino(double coef = 0, int exp = 0);

    double getCoef() const { return coef; }
    int getExp() const { return exp; }

    void setCoef(double c) { coef = c; }
    void setExp(int e) { exp = e; }

    std::string toString() const;
};

// ========================== CPolinomio ==========================
class CPolinomio {
private:
    CTermino* pol;  // arreglo dinámico
    int n;          // cantidad de términos

    void ordenar();                     // orden ascendente por exponente
    void redimensionar(int nuevoTam);   // ampliar memoria

public:
    CPolinomio();                       // polinomio vacío
    CPolinomio(const CPolinomio& otro); // constructor por copia
    ~CPolinomio();

    int getNumTerminos() const { return n; }

    void insertar(const CTermino& t);   // insertar término en orden

    CPolinomio sumar(const CPolinomio& p) const;
    CPolinomio multiplicar(const CPolinomio& p) const;

    std::string toString() const;
};

#endif