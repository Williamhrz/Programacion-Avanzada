#include "../Archivos_hpp/Vector.hpp"

Vector_Mm::Vector_Mm() {}

void Vector_Mm::ingresa_los_Datos() {
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

double Vector_Mm::valorMaximo(int& posicion) const {
    double max = std::numeric_limits<double>::lowest();
    posicion = -1;

    for (int i = 0; i < datos.size(); i++) {
        if (datos[i] > max) {
            max = datos[i];
            posicion = i;
        }
    }
    return max;
}

double Vector_Mm::valorMinimo(int& posicion) const {
    double min = std::numeric_limits<double>::max();
    posicion = -1;

    for (int i = 0; i < datos.size(); i++) {
        if (datos[i] < min) {
            min = datos[i];
            posicion = i;
        }
    }
    return min;
}

void Vector_Mm::mostrarResultados() const {
    if (datos.empty()) {
        std::cout << "El vector está vacío.\n";
        return;
    }

    int posMax, posMin;
    double max = valorMaximo(posMax);
    double min = valorMinimo(posMin);

    std::cout << "\nResultados del vector:\n";
    std::cout << "Valor máximo: " << max << " (posición " << posMax << ")\n";
    std::cout << "Valor mínimo: " << min << " (posición " << posMin << ")\n";
}
