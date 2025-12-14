#include "../Archivos_hpp/HIL.hpp"
#include "../Archivos_hpp/auto_save.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

namespace hil {

    // Constantes del PDF [cite: 12]
    const double TAU = 0.004;
    const double L = 1.8;
    const double LAMBDA[] = {1.3, 1.85, 2.79, 6.48}; // L0..L3 invertido según n-i

    double sign(double x) {
        if (x > 0) return 1.0;
        if (x < 0) return -1.0;
        return 0.0;
    }

    // Función phi descrita en Ec (2)
    double phi(int i, double diff) {
        // n=3. Exponentes: (n-i)/(n+1) -> (3-i)/4
        double pot1 = (double)(i + 1) / 4.0;
        double pot2 = (double)(3 - i) / 4.0;
        
        // lambda_n-i es confuso en texto, usaremos orden estándar para diferenciadores HOSM
        // Usualmente: lambda0 * L^(1/4)... pero seguiremos los valores dados directos
        double lambda_val = LAMBDA[i]; 
        
        return -lambda_val * pow(L, pot1) * pow(abs(diff), pot2) * sign(diff);
    }

    // Simulación Recursiva en el tiempo
    void simularPaso(int k, int k_max, EstadoDerivador z, double y_planta_ant, double u_ant) {
        if (k >= k_max) return;

        double t = k * TAU;
        
        // 1. Generar Referencia (Input) - Ejemplo Senoidal
        double f_tk = sin(t); 

        // 2. Simular Planta (Aproximación simple discretizada de Ec 1)
        // G(s) es compleja, aquí simulamos una respuesta inercial simple para demostración HIL
        // y[k] = 0.98*y[k-1] + 0.02*u[k-1] (Simulación dummy estable)
        double y_planta = 0.95 * y_planta_ant + 0.05 * f_tk;

        // 3. Calcular Derivador (Ec 2) [cite: 12]
        double diff = z.z0 - f_tk; // Error
        
        EstadoDerivador z_next;
        z_next.z0 = z.z0 + TAU * z.z1 + TAU * phi(0, diff); // Simplificado término superior despreciable
        z_next.z1 = z.z1 + TAU * z.z2 + TAU * phi(1, diff);
        z_next.z2 = z.z2 + TAU * z.z3 + TAU * phi(2, diff);
        z_next.z3 = z.z3 + TAU * phi(3, diff);

        // 4. Guardar datos
        string linea = to_string(t) + "\t" + to_string(f_tk) + "\t" + to_string(y_planta) + "\t" + to_string(z.z1);
        auto_save::guardarLog("datos_planta.txt", linea);

        // Paso recursivo
        simularPaso(k + 1, k_max, z_next, y_planta, f_tk);
    }

    void ejecutarSimulacion() {
        cout << "--- Actividad 2: Simulacion HIL ---" << endl;
        auto_save::guardarLog("datos_planta.txt", "Time\tRef\tPlanta\tDerivada1");
        
        EstadoDerivador z_init = {0, 0, 0, 0};
        // Simular 1000 pasos (4 segundos aprox)
        simularPaso(0, 1000, z_init, 0.0, 0.0);
        
        cout << "Simulacion terminada. Datos en 'datos_planta.txt'" << endl;
    }
}