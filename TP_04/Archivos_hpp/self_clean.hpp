#ifndef SELFCLEAN_HPP
#define SELFCLEAN_HPP

#include <string>
#include <fstream>

namespace self_clean { // Usamos un namespace descriptivo
    
    // Función única: Recibe un nombre y borra todo su contenido
    inline void reiniciarArchivo(const std::string& nombreArchivo) {
        std::ofstream archivo(nombreArchivo, std::ios::out); // 'out' sobreescribe desde cero
        if (archivo.is_open()) {
            archivo.close();
        }
    }
}

#endif // LIMPIADOR_HPP