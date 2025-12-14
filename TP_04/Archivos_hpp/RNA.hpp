#ifndef RNA_HPP
#define RNA_HPP

#include <vector>

// Usamos el namespace rna para proteger nuestras variables del resto del proyecto
namespace rna {

    // Constantes
    const int N_ENTRADAS = 35; 
    const int N_OCULTAS = 15;
    const int N_SALIDAS = 4;

    struct Muestra {
        std::vector<double> datosEntrada;
        std::vector<double> datosObjetivo;
        int idDigito;
    };

    class RedNeuronal {
    private:
        std::vector<double> neuronasOcultas;
        std::vector<double> neuronasSalida;
        
        // Pesos (Weights)
        std::vector<std::vector<double>> matrizPesosEntrada;
        std::vector<std::vector<double>> matrizPesosSalida;
        
        // Sesgos (Biases) - "bias" a veces causa conflicto, usamos "sesgos"
        std::vector<double> sesgosOcultos;
        std::vector<double> sesgosSalida;

        double factorAprendizaje;

        double funcSigmoide(double x);
        double derivadaSig(double x);

    public:
        // Constructor
        RedNeuronal(double tasa = 0.1);
        
        // Métodos principales
        std::vector<double> calcularSalida(const std::vector<double>& input);
        void realizarEntrenamiento(const std::vector<double>& input, const std::vector<double>& target);
    };

    // Función principal para llamar desde el main
    void ejecutarClasificacionRNA();

}

#endif
