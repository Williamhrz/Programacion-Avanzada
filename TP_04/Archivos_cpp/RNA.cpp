#include "../Archivos_hpp/RNA.hpp"
#include "../Archivos_hpp/auto_save.hpp"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

namespace rna {
    bool esPar(int n) { return n % 2 == 0; }
    bool esPrimo(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) if (n % i == 0) return false;
        return true;
    }

    void procesarRecursivo(ifstream &archivo) {
        int n;
        if (!(archivo >> n)) return;

        string res = "Num " + to_string(n) + ": ";
        if (esPar(n)) res += "[Clase 0: Par] ";
        else res += "[Clase 1: Impar] ";
        
        if (esPrimo(n)) res += "[Clase 2: Primo] ";
        else if (n > 1) res += "[Clase 3: Compuesto] ";

        cout << res << endl;
        auto_save::guardarLog("resultado_rna.txt", res);
        
        procesarRecursivo(archivo);
    }

    void ejecutarClasificacionRNA() {
        cout << "--- Actividad 3: RNA ---" << endl;
        ifstream archivo("digitos.txt");
        if (!archivo.is_open()) {
            cout << "Crea 'digitos.txt' en Output/ primero." << endl;
            return;
        }
        auto_save::guardarLog("resultado_rna.txt", "--- INICIO CLASIFICACION ---");
        procesarRecursivo(archivo);
        archivo.close();
    }
}