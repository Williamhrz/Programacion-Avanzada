#include "../Archivos_hpp/Operaciones_basicas.hpp"
#include <iomanip> // Para std::setprecision

Operacionesbasicas::Operacionesbasicas() : a(0.0), b(0.0) {}

void Operacionesbasicas::ingresa_los_Numeros() {
    std::cout << "Ingrese el primer número: ";
    std::cin >> a;
    std::cout << "Ingrese el segundo número: ";
    std::cin >> b;
}

double Operacionesbasicas::suma() const {
    return a + b;
}

double Operacionesbasicas::resta() const {
    return a - b;
}

double Operacionesbasicas::multiplicacion() const {
    return a * b;
}

double Operacionesbasicas::division() const {
    if (b == 0.0) {
        throw std::runtime_error("Error: no se puede dividir entre cero.");
    }
    return a / b;
}

void Operacionesbasicas::mostrarResultados() const {
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "\nResultados de las operaciones básicas:\n";
    std::cout << "Suma: " << suma() << "\n";
    std::cout << "Resta: " << resta() << "\n";
    std::cout << "Multiplicación: " << multiplicacion() << "\n";
    try {
        std::cout << "División: " << division() << "\n";
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }
}

// Función global que ejecuta todo el ejercicio
void ejecutarEjercicio1() {
    Operacionesbasicas op;
    op.ingresa_los_Numeros();
    op.mostrarResultados();
}
