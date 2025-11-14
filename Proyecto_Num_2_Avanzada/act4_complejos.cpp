#include "act4_complejos.hpp"

// ============================================================
//                       COMPLEX (binomial)
// ============================================================

complex::complex(double real, double imag) : a(real), b(imag) {}

// Conversión desde polar
complex::complex(const polar& p) {
    complex temp = p.toComplex();
    a = temp.real();
    b = temp.imag();
}

complex complex::operator+(const complex& c) const {
    return complex(a + c.a, b + c.b);
}

complex complex::operator-(const complex& c) const {
    return complex(a - c.a, b - c.b);
}

complex complex::operator*(const complex& c) const {
    return complex(a*c.a - b*c.b, a*c.b + b*c.a);
}

complex complex::operator/(const complex& c) const {
    double denom = c.a*c.a + c.b*c.b;
    return complex((a*c.a + b*c.b)/denom, (b*c.a - a*c.b)/denom);
}

complex complex::conj() const {
    return complex(a, -b);
}

polar complex::toPolar() const {
    double r = sqrt(a*a + b*b);
    double t = atan2(b, a);
    return polar(r, t);
}

void complex::imprimir() const {
    std::cout << a << " + " << b << "i";
}


// ============================================================
//                           POLAR
// ============================================================

polar::polar(double modulo, double argumento) : r(modulo), t(argumento) {}

// Conversión desde complex
polar::polar(const complex& c) {
    polar temp = c.toPolar();
    r = temp.modulo();
    t = temp.argumento();
}

polar polar::operator+(const polar& p) const {
    // Convertimos a binomial, sumamos, regresamos como polar
    complex c1 = this->toComplex();
    complex c2 = p.toComplex();
    return (c1 + c2).toPolar();
}

polar polar::operator-(const polar& p) const {
    complex c1 = this->toComplex();
    complex c2 = p.toComplex();
    return (c1 - c2).toPolar();
}

polar polar::operator*(const polar& p) const {
    return polar(r * p.r, t + p.t);
}

polar polar::operator/(const polar& p) const {
    return polar(r / p.r, t - p.t);
}

polar polar::conj() const {
    return polar(r, -t);
}

complex polar::toComplex() const {
    return complex(r * cos(t), r * sin(t));
}

void polar::imprimir() const {
    std::cout << r << " * e^(" << t << ")";
}


// ============================================================
//            Función acumula: suma complejos y polares
// ============================================================

complex acumula(const std::vector<complex>& listaC, const std::vector<polar>& listaP) {
    complex suma(0, 0);

    for (const auto& c : listaC)
        suma = suma + c;

    for (const auto& p : listaP)
        suma = suma + p.toComplex();

    return suma;
}