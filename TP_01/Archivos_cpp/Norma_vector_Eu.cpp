#include "../Archivos_hpp/Norma_vector_Eu.hpp"

N_Vector::N_Vector() {}

void N_Vector::ingresa_los_Datos() {
    int n;
    std::cout << "Ingrese el tamaño del vector: ";
    std::cin >> n;

    datos.resize(n);
    std::cout << "Ingrese " << n << " valores decimales:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "Elemento [" << i << "]: ";
        std::cin >> datos[i];
    }
}

double N_Vector::normaL2() const {
    double suma = 0.0;
    for (double x : datos)
        suma += x * x;
    return std::sqrt(suma);
}

double N_Vector::normaLinf() const {
    if (datos.empty()) return 0.0;
    double maxAbs = 0.0;
    for (double x : datos)
        maxAbs = std::max(maxAbs, std::abs(x));
    return maxAbs;
}

void N_Vector::mostrarResultados() const {
    if (datos.empty()) {
        std::cout << "El vector está vacío.\n";
        return;
    }

    std::cout << "\nResultados de las normas:\n";
    std::cout << "Norma L2 (euclidiana): " << normaL2() << "\n";
    std::cout << "Norma L∞ (infinito): " << normaLinf() << "\n";
}
