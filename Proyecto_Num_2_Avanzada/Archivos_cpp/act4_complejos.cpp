#include "../Archivos_hpp/act4_complejos.hpp"

// ============================================================
//                       COMPLEX (binomial)
// ============================================================

complexNum::complexNum(double real, double imag) : a(real), b(imag) {}

// Conversión desde polar
complexNum::complexNum(const polar& p) {
    complexNum temp = p.toComplex();
    a = temp.real();
    b = temp.imag();
}

complexNum complexNum::operator+(const complexNum& c) const {
    return complexNum(a + c.a, b + c.b);
}

complexNum complexNum::operator-(const complexNum& c) const {
    return complexNum(a - c.a, b - c.b);
}

complexNum complexNum::operator*(const complexNum& c) const {
    return complexNum(a*c.a - b*c.b, a*c.b + b*c.a);
}

complexNum complexNum::operator/(const complexNum& c) const {
    double denom = c.a*c.a + c.b*c.b;
    return complexNum((a*c.a + b*c.b)/denom, (b*c.a - a*c.b)/denom);
}

complexNum complexNum::conj() const {
    return complexNum(a, -b);
}

polar complexNum::toPolar() const {
    double r = sqrt(a*a + b*b);
    double t = atan2(b, a);
    return polar(r, t);
}

void complexNum::imprimir() const {
    std::cout << a << " + " << b << "i";
}


// ============================================================
//                           POLAR
// ============================================================

polar::polar(double modulo, double argumento) : r(modulo), t(argumento) {}

// Conversión desde complex
polar::polar(const complexNum& c) {
    polar temp = c.toPolar();
    r = temp.modulo();
    t = temp.argumento();
}

polar polar::operator+(const polar& p) const {
    // Convertimos a binomial, sumamos, regresamos como polar
    complexNum c1 = this->toComplex();
    complexNum c2 = p.toComplex();
    return (c1 + c2).toPolar();
}

polar polar::operator-(const polar& p) const {
    complexNum  c1 = this->toComplex();
    complexNum  c2 = p.toComplex();
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

complexNum polar::toComplex() const {
    return complexNum(r * cos(t), r * sin(t));
}

void polar::imprimir() const {
    std::cout << r << " * e^(" << t << ")";
}


// ============================================================
//            Función acumula: suma complejos y polares
// ============================================================

complexNum acumula(const std::vector<complexNum>& listaC, const std::vector<polar>& listaP) {
    complexNum suma(0, 0);

    for (const auto& c : listaC)
        suma = suma + c;

    for (const auto& p : listaP)
        suma = suma + p.toComplex();

    return suma;
}