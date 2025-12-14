#include "../Archivos_hpp/act5_ecuaciones.hpp"
#include <sstream>
using namespace std;

// ========================== CTermino ==========================

CTermino::CTermino(double coef, int exp) : coef(coef), exp(exp) {}

string CTermino::toString() const {
    if (coef == 0) return "";

    stringstream ss;
    if (coef > 0) ss << "+";
    else ss << "-";

    double c = abs(coef);

    if (exp == 0)
        ss << c;
    else if (exp == 1)
        ss << c << "x";
    else
        ss << c << "x^" << exp;

    return ss.str();
}

// ========================== CPolinomio ==========================

CPolinomio::CPolinomio() : pol(nullptr), n(0) {}

CPolinomio::CPolinomio(const CPolinomio& otro) {
    n = otro.n;
    pol = new CTermino[n];
    for (int i = 0; i < n; i++)
        pol[i] = otro.pol[i];
}

CPolinomio::~CPolinomio() {
    delete[] pol;
}

void CPolinomio::redimensionar(int nuevoTam) {
    CTermino* nuevo = new CTermino[nuevoTam];

    for (int i = 0; i < n; i++)
        nuevo[i] = pol[i];

    delete[] pol;
    pol = nuevo;
    n = nuevoTam;
}

void CPolinomio::ordenar() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (pol[j].getExp() > pol[j + 1].getExp()) {
                CTermino temp = pol[j];
                pol[j] = pol[j + 1];
                pol[j + 1] = temp;
            }
        }
    }
}

void CPolinomio::insertar(const CTermino& t) {
    if (t.getCoef() == 0) return;

    // Buscar si ya existe ese exponente
    for (int i = 0; i < n; i++) {
        if (pol[i].getExp() == t.getExp()) {
            double nuevoCoef = pol[i].getCoef() + t.getCoef();
            pol[i].setCoef(nuevoCoef);
            return;
        }
    }

    // Si no existe → agregar nuevo término
    redimensionar(n + 1);
    pol[n - 1] = t;
    ordenar();
}

CPolinomio CPolinomio::sumar(const CPolinomio& p) const {
    CPolinomio r;

    for (int i = 0; i < n; i++)
        r.insertar(pol[i]);

    for (int j = 0; j < p.n; j++)
        r.insertar(p.pol[j]);

    return r;
}

CPolinomio CPolinomio::multiplicar(const CPolinomio& p) const {
    CPolinomio r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p.n; j++) {
            double coef = pol[i].getCoef() * p.pol[j].getCoef();
            int exp = pol[i].getExp() + p.pol[j].getExp();
            r.insertar(CTermino(coef, exp));
        }
    }

    return r;
}

string CPolinomio::toString() const {
    if (n == 0) return "0";

    string s;

    for (int i = 0; i < n; i++)
        s += pol[i].toString();

    // remover el '+' inicial si existe
    if (!s.empty() && s[0] == '+')
        s = s.substr(1);

    return s;
}