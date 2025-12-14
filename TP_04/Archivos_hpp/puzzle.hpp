#ifndef PUZZLE_HPP
#define PUZZLE_HPP

#include <vector>
#include <string>

namespace puzzle {
    // Matriz 3x3
    using Tablero = std::vector<std::vector<int>>;

    struct Estado {
        Tablero tablero;
        int x, y; // Coordenadas del 0 (espacio vacío)
        std::string movimientos; // Historial (L, R, U, D)
    };

    // Función principal pública
    void ejecutarPuzzle();
}

#endif