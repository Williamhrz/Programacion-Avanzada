#ifndef SENAL_ECG_HPP
#define SENAL_ECG_HPP

#include <vector>
#include <string>

class SenalECG {
private:
    std::vector<float> tiempo;
    std::vector<float> amplitud;
    std::vector<float> filtrada;
    std::vector<float> picos;

public:
    // Constructor
    SenalECG();

    // Métodos pedidos por el taller
    bool cargarDesdeArchivo(const std::string& ruta);
    void filtrarSenal();
    void detectarPicos(float umbral);
    void guardarEnArchivo(const std::string& ruta);
    float calcularFrecuenciaCardiaca() const;

    int cantidadMuestras() const;

    // Destructor
    ~SenalECG();
};

#endif
