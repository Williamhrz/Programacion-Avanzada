#include "../Archivos_hpp/SenalECG.hpp"
#include <iostream>
#include <fstream>

using namespace std;

// Constructor
SenalECG::SenalECG() {
    tiempo = {};
    amplitud = {};
    filtrada = {};
    picos = {};
}

// Cargar archivo
bool SenalECG::cargarDesdeArchivo(const string& nombreArchivo) {

    ifstream file("output/" + nombreArchivo);
    if (!file.is_open()) {
        cout << "Error: No se pudo abrir " << nombreArchivo << endl;
        return false;
    }

    tiempo.clear();
    amplitud.clear();

    float amp, t;

    while (file >> amp >> t) {
        amplitud.push_back(amp);
        tiempo.push_back(t);
    }

    file.close();
    return true;
}

// FILTRO PASA BAJOS IIR (CORREGIDO)
void SenalECG::filtrarSenal() {

    if (amplitud.empty()) return;

    filtrada.clear();
    filtrada.resize(amplitud.size());

    float alpha = 0.5f;       // VALOR CORREGIDO (antes era 0.1)
    filtrada[0] = amplitud[0];

    for (int i = 1; i < amplitud.size(); i++) {
        filtrada[i] = alpha * amplitud[i] + (1 - alpha) * filtrada[i - 1];
    }
}

// DETECCIÓN DE PICOS (CORREGIDO)
void SenalECG::detectarPicos(float umbral) {

    picos.clear();

    for (int i = 1; i < filtrada.size() - 1; i++) {

        float prev = filtrada[i - 1];
        float cur  = filtrada[i];
        float next = filtrada[i + 1];

        // pico si es máximo local y supera el umbral
        if (cur > prev && cur > next && cur > umbral) {
            picos.push_back(tiempo[i]);
        }
    }
}

// Guardar señal en archivo
void SenalECG::guardarEnArchivo(const string& nombre) {

    ofstream out(nombre);

    for (int i = 0; i < tiempo.size(); i++) {
        out << tiempo[i] << " "
            << amplitud[i] << " "
            << filtrada[i] << "\n";
    }

    out.close();
}

// Calcular frecuencia cardiaca
float SenalECG::calcularFrecuenciaCardiaca() {

    if (picos.size() < 2)
        return 0;

    float sumaRR = 0;
    int count = 0;

    for (int i = 0; i < picos.size() - 1; i++) {
        sumaRR += (picos[i + 1] - picos[i]);
        count++;
    }

    float RR = sumaRR / count;

    if (RR <= 0)
        return 0;

    return 60.0f / RR;
}

// Destructor
SenalECG::~SenalECG() {
    tiempo.clear();
    amplitud.clear();
    filtrada.clear();
    picos.clear();
}