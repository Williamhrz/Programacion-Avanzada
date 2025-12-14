#include "../Archivos_hpp/RNA.hpp"
#include "../Archivos_hpp/auto_save.hpp"   // <--- Tu modulo de guardado
#include "../Archivos_hpp/self_clean.hpp"  // <--- Tu modulo de limpieza
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>
#include <sstream> 

namespace rna {
    
    // --- Implementación de la Clase RedNeuronal ---
    // (Esta parte matematica sigue igual, no cambia nada aqui)

    RedNeuronal::RedNeuronal(double tasa) : factorAprendizaje(tasa) {
        neuronasOcultas.resize(N_OCULTAS);
        neuronasSalida.resize(N_SALIDAS);
        
        matrizPesosEntrada.resize(N_ENTRADAS, std::vector<double>(N_OCULTAS));
        matrizPesosSalida.resize(N_OCULTAS, std::vector<double>(N_SALIDAS));
        
        sesgosOcultos.resize(N_OCULTAS);
        sesgosSalida.resize(N_SALIDAS);

        for (int i = 0; i < N_ENTRADAS; i++)
            for (int j = 0; j < N_OCULTAS; j++)
                matrizPesosEntrada[i][j] = ((double)std::rand() / RAND_MAX) * 2.0 - 1.0;

        for (int i = 0; i < N_OCULTAS; i++)
            for (int j = 0; j < N_SALIDAS; j++)
                matrizPesosSalida[i][j] = ((double)std::rand() / RAND_MAX) * 2.0 - 1.0;
        
        for (int i = 0; i < N_OCULTAS; i++) sesgosOcultos[i] = ((double)std::rand() / RAND_MAX) * 2.0 - 1.0;
        for (int i = 0; i < N_SALIDAS; i++) sesgosSalida[i] = ((double)std::rand() / RAND_MAX) * 2.0 - 1.0;
    }

    double RedNeuronal::funcSigmoide(double x) {
        return 1.0 / (1.0 + std::exp(-x));
    }

    double RedNeuronal::derivadaSig(double x) {
        return x * (1.0 - x); 
    }

    std::vector<double> RedNeuronal::calcularSalida(const std::vector<double>& input) {
        for (int j = 0; j < N_OCULTAS; j++) {
            double acumulado = sesgosOcultos[j];
            for (int i = 0; i < N_ENTRADAS; i++) {
                acumulado += input[i] * matrizPesosEntrada[i][j];
            }
            neuronasOcultas[j] = funcSigmoide(acumulado);
        }

        for (int k = 0; k < N_SALIDAS; k++) {
            double acumulado = sesgosSalida[k];
            for (int j = 0; j < N_OCULTAS; j++) {
                acumulado += neuronasOcultas[j] * matrizPesosSalida[j][k];
            }
            neuronasSalida[k] = funcSigmoide(acumulado);
        }
        return neuronasSalida;
    }

    void RedNeuronal::realizarEntrenamiento(const std::vector<double>& input, const std::vector<double>& target) {
        calcularSalida(input);

        std::vector<double> deltasSalida(N_SALIDAS);
        for (int k = 0; k < N_SALIDAS; k++) {
            double error = target[k] - neuronasSalida[k];
            deltasSalida[k] = error * derivadaSig(neuronasSalida[k]);
        }

        std::vector<double> deltasOculta(N_OCULTAS);
        for (int j = 0; j < N_OCULTAS; j++) {
            double error = 0.0;
            for (int k = 0; k < N_SALIDAS; k++) {
                error += deltasSalida[k] * matrizPesosSalida[j][k];
            }
            deltasOculta[j] = error * derivadaSig(neuronasOcultas[j]);
        }

        for (int j = 0; j < N_OCULTAS; j++) {
            for (int k = 0; k < N_SALIDAS; k++) {
                matrizPesosSalida[j][k] += factorAprendizaje * deltasSalida[k] * neuronasOcultas[j];
            }
        }
        for (int k = 0; k < N_SALIDAS; k++) sesgosSalida[k] += factorAprendizaje * deltasSalida[k];

        for (int i = 0; i < N_ENTRADAS; i++) {
            for (int j = 0; j < N_OCULTAS; j++) {
                matrizPesosEntrada[i][j] += factorAprendizaje * deltasOculta[j] * input[i];
            }
        }
        for (int j = 0; j < N_OCULTAS; j++) sesgosOcultos[j] += factorAprendizaje * deltasOculta[j];
    }

    // --- Funciones Auxiliares ---

    std::vector<double> generarVectorObjetivo(int num) {
        std::vector<double> t(4, 0.0);
        if (num % 2 == 0) t[0] = 1.0; 
        if (num % 2 != 0) t[1] = 1.0; 
        if (num == 2 || num == 3 || num == 5 || num == 7) t[2] = 1.0; 
        if (num == 4 || num == 6 || num == 8 || num == 9) t[3] = 1.0; 
        return t;
    }

    // --- AQUI ESTA EL CAMBIO IMPORTANTE ---
    void ejecutarClasificacionRNA() {
        std::srand(std::time(0));
        std::cout << "\n--- CLASIFICACION DE DIGITOS CON RNA (Modular) ---" << std::endl;

        std::string rutaLectura = "data/digitos.txt"; 
        std::string rutaEscritura = "exit/resultado_rna.txt";

        // Intentar abrir el archivo de lectura
        std::ifstream archivoLectura(rutaLectura);
        if (!archivoLectura.is_open()) {
            rutaLectura = "data/digitos.txt"; 
            archivoLectura.open(rutaLectura);
            rutaEscritura = "exit/resultado_rna.txt"; 
            if (!archivoLectura.is_open()) {
                std::cerr << "Error: No se encuentra digitos.txt" << std::endl;
                return;
            }
        }

        // Cargar datos
        std::vector<Muestra> conjuntoDatos;
        std::vector<double> bufferImagen;
        int valorLeido;
        int indiceDigito = 0;

        while (archivoLectura >> valorLeido && indiceDigito < 10) {
            bufferImagen.push_back((double)valorLeido);
            if (bufferImagen.size() == 35) {
                Muestra m;
                m.datosEntrada = bufferImagen;
                m.idDigito = indiceDigito;
                m.datosObjetivo = generarVectorObjetivo(indiceDigito);
                conjuntoDatos.push_back(m);
                bufferImagen.clear();
                indiceDigito++;
            }
        }
        archivoLectura.close();

        if (conjuntoDatos.empty()) return;

        // Entrenar
        RedNeuronal red(0.1); 
        std::cout << "Entrenando red..." << std::endl;
        for (int e = 0; e < 20000; e++) {
            for (const auto& muestra : conjuntoDatos) {
                red.realizarEntrenamiento(muestra.datosEntrada, muestra.datosObjetivo);
            }
        }
        std::cout << "Entrenamiento completado." << std::endl;


        // --- AQUI USAMOS TUS MODULOS DE GUARDADO ---

        // 1. Limpiamos el archivo primero (suponiendo que self_clean tiene una función limpiar)
        // Nota: Reemplaza "limpiarArchivo" con el nombre real de tu función en self_clean.hpp
        // si se llama diferente.
        self_clean::reiniciarArchivo(rutaEscritura); 

        std::cout << "\nResultados:" << std::endl;
        
        std::string cabecera = "Digito | Par      | Impar    | Primo    | Compuesto";
        std::string lineaSep = "---------------------------------------------------";
        
        // Imprimir en pantalla
        std::cout << cabecera << std::endl << lineaSep << std::endl;

        // Guardar cabecera usando tu modulo
        auto_save::guardarLog(rutaEscritura, cabecera);
        auto_save::guardarLog(rutaEscritura, lineaSep);

        for (const auto& muestra : conjuntoDatos) {
            std::vector<double> res = red.calcularSalida(muestra.datosEntrada);
            
            auto formatear = [](double v) { return (v > 0.8 ? "SI" : "."); };

            // Usamos stringstream para construir la linea con formato
            std::stringstream ss;
            ss << std::setw(6) << muestra.idDigito << " | "
               << std::setw(8) << formatear(res[0]) << " | "
               << std::setw(8) << formatear(res[1]) << " | "
               << std::setw(8) << formatear(res[2]) << " | "
               << std::setw(8) << formatear(res[3]);
            
            // Convertimos el stringstream a string
            std::string lineaFinal = ss.str();

            // Imprimimos en pantalla
            std::cout << lineaFinal << std::endl;

            // Guardamos en archivo usando tu modulo
            auto_save::guardarLog(rutaEscritura, lineaFinal);
        }
        
        std::cout << std::endl;
    }

} // fin namespace rna
