#ifndef AUTOSAVE_HPP
#define AUTOSAVE_HPP

#include <string>
#include <fstream>
#include <iostream>

namespace auto_save {
    // Guarda texto en un archivo en modo 'append' (sin borrar lo anterior)
    inline void guardarLog(const std::string& nombreArchivo, const std::string& texto) {
        // Se asume ejecución desde carpeta output/
        std::ofstream archivo(nombreArchivo, std::ios::app);
        if (archivo.is_open()) {
            archivo << texto << std::endl;
        }
    }
}

#endif