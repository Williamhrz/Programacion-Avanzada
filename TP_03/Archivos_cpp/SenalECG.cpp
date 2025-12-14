#include "../Archivos_hpp/SenalECG.hpp"
#include <fstream>
#include <iostream>

using namespace std;

// Constructor
SenalECG::SenalECG() {}

// Cargar señal desde archivo
bool SenalECG::cargarDesdeArchivo(const string& ruta) {

    ifstream file(ruta);
    if (!file.is_open()) {
        cout << "Error: No se pudo abrir el archivo " << ruta << endl;
        return false;
    }

    tiempo.clear();
    amplitud.clear();

    float t, a;
    while (file >> t >> a) {
        tiempo.push_back(t);
        amplitud.push_back(a);
    }

    file.close();

    cout << "Muestras cargadas: " << tiempo.size() << endl;
    return true;
}

// Filtro pasa bajos simple
void SenalECG::filtrarSenal() {

    if (amplitud.empty()) return;

    filtrada.resize(amplitud.size());

    float alpha = 0.5f;
    filtrada[0] = amplitud[0];

    for (size_t i = 1; i < amplitud.size(); i++) {
        filtrada[i] = alpha * amplitud[i] +
                      (1 - alpha) * filtrada[i - 1];
    }
}

// Detección de picos
void SenalECG::detectarPicos(float umbral) {

    picos.clear();

    for (size_t i = 1; i < filtrada.size() - 1; i++) {
        if (filtrada[i] > filtrada[i - 1] &&
            filtrada[i] > filtrada[i + 1] &&
            filtrada[i] > umbral) {

            picos.push_back(tiempo[i]);
        }
    }
}

// Guardar señal original y filtrada
void SenalECG::guardarEnArchivo(const string& ruta) {

    ofstream out(ruta);

    for (size_t i = 0; i < tiempo.size(); i++) {
        out << tiempo[i] << " "
            << amplitud[i] << " "
            << filtrada[i] << endl;
    }

    out.close();
}

// Calcular frecuencia cardiaca
float SenalECG::calcularFrecuenciaCardiaca() const {

    if (picos.size() < 2) return 0;

    float suma = 0;
    for (size_t i = 1; i < picos.size(); i++) {
        suma += (picos[i] - picos[i - 1]);
    }

    float rr = suma / (picos.size() - 1);
    if (rr <= 0) return 0;

    return 60.0f / rr;
}

int SenalECG::cantidadMuestras() const {
    return tiempo.size();
}

// Destructor
SenalECG::~SenalECG() {}
