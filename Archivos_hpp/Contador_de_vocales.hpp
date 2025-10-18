#ifndef CONTADOR_DE_VOCALES_HPP
#define CONTADOR_DE_VOCALES_HPP

#include <iostream>
#include <string>
#include <cctype>

class Contador_de_vocales {
private:
    std::string texto;

public:
    Contador_de_vocales();
    void ingresar_la_Cadena();
    void mostrarResultados() const;

private:
    int contarVocales() const;
    bool esVocal(char c) const;
};

#endif
