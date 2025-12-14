#include "../Archivos_hpp/Matriz_pseudo.hpp"

Matriz_pseudo::Matriz_pseudo(int f, int c) : filas(f), columnas(c) {
    if (filas > 0 && columnas > 0)
        datos.resize(filas, std::vector<double>(columnas, 0.0));
}

void Matriz_pseudo::ingresarDatos() {
    std::cout << "Ingrese los elementos de la Matriz_pseudo (" << filas << "x" << columnas << "):\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            std::cin >> datos[i][j];
        }
    }
}

void Matriz_pseudo::mostrar() const {
    for (const auto& fila : datos) {
        for (double val : fila)
            std::cout << std::setw(10) << std::fixed << std::setprecision(4) << val << " ";
        std::cout << "\n";
    }
}

bool Matriz_pseudo::esCuadrada() const { return filas == columnas; }

double Matriz_pseudo::determinanteRecursivo(std::vector<std::vector<double>> mat) const {
    int n = mat.size();
    if (n == 1) return mat[0][0];
    if (n == 2) return mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];

    double det = 0.0;
    for (int p = 0; p < n; p++) {
        std::vector<std::vector<double>> submat(n - 1, std::vector<double>(n - 1));
        for (int i = 1; i < n; i++) {
            int col = 0;
            for (int j = 0; j < n; j++) {
                if (j == p) continue;
                submat[i - 1][col++] = mat[i][j];
            }
        }
        det += pow(-1, p) * mat[0][p] * determinanteRecursivo(submat);
    }
    return det;
}

double Matriz_pseudo::determinante() const {
    if (!esCuadrada())
        throw std::invalid_argument("No se puede calcular el determinante de una Matriz_pseudo no cuadrada.");
    return determinanteRecursivo(datos);
}

bool Matriz_pseudo::esSingular() const {
    if (!esCuadrada()) return false;
    return std::abs(determinante()) < 1e-9;
}

Matriz_pseudo Matriz_pseudo::traspuesta() const {
    Matriz_pseudo t(columnas, filas);
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            t.datos[j][i] = datos[i][j];
    return t;
}

Matriz_pseudo Matriz_pseudo::inversa() const {
    if (!esCuadrada())
        throw std::invalid_argument("La Matriz_pseudo no es cuadrada, no tiene inversa clásica.");

    int n = filas;
    Matriz_pseudo A = *this;
    Matriz_pseudo I(n, n);
    for (int i = 0; i < n; i++)
        I.datos[i][i] = 1.0;

    // Eliminación Gauss-Jordan
    for (int i = 0; i < n; i++) {
        double pivote = A.datos[i][i];
        if (std::abs(pivote) < 1e-9)
            throw std::runtime_error("La Matriz_pseudo es singular (determinante = 0).");

        for (int j = 0; j < n; j++) {
            A.datos[i][j] /= pivote;
            I.datos[i][j] /= pivote;
        }

        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = A.datos[k][i];
                for (int j = 0; j < n; j++) {
                    A.datos[k][j] -= factor * A.datos[i][j];
                    I.datos[k][j] -= factor * I.datos[i][j];
                }
            }
        }
    }
    return I;
}
Matriz_pseudo Matriz_pseudo::pseudoInversa() const {
    // A: m x n
    int m = filas;
    int n = columnas;

    // Transpuesta de A → n x m
    Matriz_pseudo At = traspuesta();

    // (A^T * A) → n x n
    Matriz_pseudo AtA(n, n);

    // Multiplicar A^T * A
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double suma = 0.0;
            for (int k = 0; k < m; k++) {
                suma += At.datos[i][k] * datos[k][j];
            }
            AtA.datos[i][j] = suma;
        }
    }

    try {
        // Inversa de (A^T * A)
        Matriz_pseudo invAtA = AtA.inversa();

        // Calcular pseudo-inversa: (A^T * A)^-1 * A^T
        Matriz_pseudo resultado(n, m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                double suma = 0.0;
                for (int k = 0; k < n; k++) {
                    suma += invAtA.datos[i][k] * At.datos[k][j];
                }
                resultado.datos[i][j] = suma;
            }
        }

        return resultado;
    } catch (...) {
        throw std::runtime_error("No es posible calcular la pseudo inversa (Matriz_pseudo singular).");
    }
}

// ============================================================
//  NUEVO MÉTODO QUE ENCAPSULA TODO EL EJERCICIO 5
// ============================================================
void Matriz_pseudo::ejecutarEjercicio() {
    std::cout << "Ingrese el número de filas: ";
    std::cin >> filas;
    std::cout << "Ingrese el número de columnas: ";
    std::cin >> columnas;

    datos.resize(filas, std::vector<double>(columnas, 0.0));
    ingresarDatos();

    std::cout << "\nMatriz_pseudo ingresada:\n";
    mostrar();

    try {
        if (esCuadrada()) {
            if (esSingular()) {
                std::cout << "\nLa Matriz_pseudo es cuadrada pero singular (determinante = 0), no tiene inversa.\n";
            } else {
                std::cout << "\nInversa de la Matriz_pseudo:\n";
                Matriz_pseudo inv = inversa();
                inv.mostrar();
            }
        } else {
            std::cout << "\nLa Matriz_pseudo no es cuadrada, se calculará la pseudo inversa:\n";
            Matriz_pseudo pinv = pseudoInversa();
            pinv.mostrar();
        }
    } catch (const std::exception& e) {
        std::cerr << "\nError: " << e.what() << "\n";
    }
}
