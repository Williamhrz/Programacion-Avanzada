#ifndef PUZZLE_HPP
#define PUZZLE_HPP

#include <vector>
#include <string>

namespace puzzle {
    // Matriz 3x3
    using Tablero = std::vector<std::vector<int>>;

    struct Estado {
        Tablero tablero;
        int x, y; // Posición del 0 (espacio vacío)
        std::string movimientos; // Historial de movimientos (U, D, L, R)
    };

    void ejecutarPuzzle();
}

#endif