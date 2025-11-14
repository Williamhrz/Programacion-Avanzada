#include "../Archivos_hpp/Contador_de_vocales.hpp"

Contador_de_vocales::Contador_de_vocales() : texto("") {}

void Contador_de_vocales::ingresar_la_Cadena() {
    std::cout << "Ingrese una cadena de texto: ";
    std::cin.ignore();  // limpia el buffer antes de getline
    std::getline(std::cin, texto);
}

bool Contador_de_vocales::esVocal(char c) const {
    c = std::tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int Contador_de_vocales::contarVocales() const {
    int contador = 0;
    for (char c : texto) {
        if (esVocal(c)) contador++;
    }
    return contador;
}

void Contador_de_vocales::mostrarResultados() const {
    int cantidad = contarVocales();
    std::cout << "\nResultados:\n";
    std::cout << "Cadena ingresada: \"" << texto << "\"\n";
    std::cout << "Número de vocales: " << cantidad << "\n";
}
