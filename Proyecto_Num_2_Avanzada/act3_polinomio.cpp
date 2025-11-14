#include "act3_polinomio.hpp"
#include <cmath>
using namespace std;

// ========= CONSTRUCTOR =========
Polinomio::Polinomio(int grado) : grado(grado) {
    coef = new double[grado + 1];

    cout << "Ingrese los coeficientes desde grado 0 hasta " << grado << ":\n";
    for (int i = 0; i <= grado; i++) {
        cout << "Coeficiente de x^" << i << ": ";
        cin >> coef[i];
    }
}

// ========= CONSTRUCTOR POR COPIA =========
Polinomio::Polinomio(const Polinomio& other) {
    grado = other.grado;
    coef = new double[grado + 1];

    for (int i = 0; i <= grado; i++)
        coef[i] = other.coef[i];
}

// ========= DESTRUCTOR =========
Polinomio::~Polinomio() {
    delete[] coef;
}

// ========= EVALUAR =========
double Polinomio::evaluar(double x) const {
    double resultado = 0;

    for (int i = 0; i <= grado; i++) {
        resultado += coef[i] * pow(x, i);
    }

    return resultado;
}

// ========= IMPRIMIR =========
void Polinomio::imprimir() const {
    for (int i = grado; i >= 0; i--) {
        if (coef[i] == 0) continue;

        if (i != grado && coef[i] >= 0)
            cout << " + ";
        else if (coef[i] < 0)
            cout << " - ";

        double c = fabs(coef[i]);

        if (i == 0)
            cout << c;
        else if (i == 1)
            cout << c << "x";
        else
            cout << c << "x^" << i;
    }
}

// ========= DERIVADA =========
Polinomio Polinomio::derivada() const {
    if (grado == 0)
        return Polinomio(0);

    Polinomio d(grado - 1);

    for (int i = 1; i <= grado; i++) {
        d.coef[i - 1] = coef[i] * i;
    }

    return d;
}

// ========= SUMA =========
Polinomio Polinomio::operator+(const Polinomio& p) const {
    int nuevo_grado = max(grado, p.grado);
    Polinomio resultado(nuevo_grado);

    for (int i = 0; i <= nuevo_grado; i++) {
        double a = (i <= grado ? coef[i] : 0);
        double b = (i <= p.grado ? p.coef[i] : 0);
        resultado.coef[i] = a + b;
    }

    return resultado;
}

// ========= MULTIPLICACIÓN =========
Polinomio Polinomio::operator*(const Polinomio& p) const {
    int nuevo_grado = grado + p.grado;
    Polinomio resultado(nuevo_grado);

    for (int i = 0; i <= nuevo_grado; i++)
        resultado.coef[i] = 0;

    for (int i = 0; i <= grado; i++) {
        for (int j = 0; j <= p.grado; j++) {
            resultado.coef[i + j] += coef[i] * p.coef[j];
        }
    }

    return resultado;
}