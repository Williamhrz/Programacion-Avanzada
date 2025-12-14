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
    SenalECG();

    bool cargarDesdeArchivo(const std::string& nombreArchivo);

    void filtrarSenal();

    void detectarPicos(float umbral);

    void guardarEnArchivo(const std::string& nombre);

    float calcularFrecuenciaCardiaca();

    int cantidadMuestras() const { return tiempo.size(); }

    ~SenalECG();
};

#endif
