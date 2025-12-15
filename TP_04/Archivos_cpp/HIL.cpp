#include "../Archivos_hpp/HIL.hpp"
#include "../Archivos_hpp/auto_save.hpp"
#include "../Archivos_hpp/self_clean.hpp"

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <thread> 
#include <chrono> 

using namespace std;

namespace hil {

    // --- CONFIGURACIÓN MATEMÁTICA ---
    const double TAU = 0.004; // 4 ms (250 Hz)
    
    // Variable Global para L (Inicia en 1.8 por defecto)
    double L = 1.8;     
    
    // Lambdas fijos según el PDF
    const double LAMBDA[] = {1.3, 1.85, 2.79, 6.48}; 

    // --- FUNCIONES AUXILIARES ---
    double sign(double x) {
        if (x > 0) return 1.0;
        if (x < 0) return -1.0;
        return 0.0;
    }

    double phi_function(int i, double error) {
        int n = 3; 
        double pot_L = (double)(i + 1) / (n + 1);
        double pot_err = (double)(n - i) / (n + 1);
        // Usa la variable global L que se puede modificar en el menú
        return -LAMBDA[i] * pow(L, pot_L) * pow(fabs(error), pot_err) * sign(error);
    }

    // --- MODELO DE LA PLANTA ---
    double simularPlanta(double u, EstadoPlanta &p) {
        double x1_dot = p.x2;
        double x2_dot = p.x3;
        double x3_dot = -30.1 * p.x1 - 30.65 * p.x2 - 9.8 * p.x3 + u;

        p.x1 += x1_dot * TAU;
        p.x2 += x2_dot * TAU;
        p.x3 += x3_dot * TAU;

        return 21.0 * p.x1 - 28.0 * p.x2 + 7.0 * p.x3;
    }

    // --- GENERADOR DE REFERENCIA ---
    double generarReferencia(int tipo, double t) {
        switch(tipo) {
            case 1: return sin(t); 
            case 2: return (t >= 1.0) ? 1.0 : 0.0; 
            case 3: return (t >= 1.0) ? (0.5 * (t - 1.0)) : 0.0; 
            default: return 0.0;
        }
    }

    // --- BUCLE DE SIMULACIÓN (CON TIEMPO REAL) ---
    void bucleSimulacion(int k, int k_max, int tipoSenal, EstadoHOSM z, EstadoPlanta p, const string& nombreArchivo) {
        if (k >= k_max) return;

        auto inicio = std::chrono::high_resolution_clock::now();

        double t = k * TAU;
        
        // 1. Matemáticas
        double ref_input = generarReferencia(tipoSenal, t);
        double y_planta = simularPlanta(ref_input, p); 
        
        double error = z.z0 - y_planta; 
        double phi0 = phi_function(0, error);
        double phi1 = phi_function(1, error);
        double phi2 = phi_function(2, error);
        double phi3 = phi_function(3, error);

        EstadoHOSM z_next; 
        z_next.z0 = z.z0 + TAU*phi0 + TAU*z.z1 + (pow(TAU,2)/2.0)*z.z2 + (pow(TAU,3)/6.0)*z.z3;
        z_next.z1 = z.z1 + TAU*phi1 + TAU*z.z2 + (pow(TAU,2)/2.0)*z.z3;
        z_next.z2 = z.z2 + TAU*phi2 + TAU*z.z3;
        z_next.z3 = z.z3 + TAU*phi3;

        // 2. Guardar
        stringstream ss;
        ss << fixed << setprecision(5) 
           << t << "\t" << ref_input << "\t" << y_planta << "\t" 
           << z.z0 << "\t" << z.z1 << "\t" << z.z2 << "\t" << z.z3;
           
        auto_save::guardarLog(nombreArchivo, ss.str());

        // Visualización simple
        if (k % 50 == 0) { 
            std::cout << "t=" << t << " | Ref=" << ref_input << " | L=" << L << "\r" << std::flush;
        }

        // 3. Control de Tiempo Real
        auto fin = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duracion = fin - inicio;
        double espera = (TAU * 1000.0) - duracion.count();

        if (espera > 0) {
            std::this_thread::sleep_for(std::chrono::milliseconds((int)espera));
        }

        bucleSimulacion(k + 1, k_max, tipoSenal, z_next, p, nombreArchivo);
    }

    // --- FUNCIÓN PRINCIPAL CON MENÚ MEJORADO ---
    void ejecutarSimulacion() {
        int opcion = 0;
        bool ejecutando = true;

        while(ejecutando) {
            // Limpiamos pantalla un poco (opcional)
            cout << "\n========================================" << endl;
            cout << "   ACTIVIDAD 2: HIL (Planta + HOSM)    " << endl;
            cout << "========================================" << endl;
            cout << "Configuracion Actual: L = " << L << endl; // Muestra el valor actual
            cout << "----------------------------------------" << endl;
            cout << "1. Simular Senal Senoidal" << endl;
            cout << "2. Simular Senal Escalon" << endl;
            cout << "3. Simular Senal Rampa" << endl;
            cout << "4. Modificar Parametro L (Derivador)" << endl; // OPCIÓN PEDIDA
            cout << "5. Volver al Menu Principal" << endl;
            cout << "----------------------------------------" << endl;
            cout << "Seleccione una opcion: ";
            cin >> opcion;

            if (opcion == 4) {
                // Lógica para modificar L sin salir
                cout << "\n>> Ingrese nuevo valor para L: ";
                cin >> L;
                cout << ">> Valor actualizado correctamente a L = " << L << endl;
                // El bucle 'while' repite el menú inmediatamente con el nuevo valor
            } 
            else if (opcion >= 1 && opcion <= 3) {
                // Lógica de simulación
                string nombreArchivo;
                switch(opcion) {
                    case 1: nombreArchivo = "exit/datos_senoidal.txt"; break;
                    case 2: nombreArchivo = "exit/datos_escalon.txt"; break;
                    case 3: nombreArchivo = "exit/datos_rampa.txt"; break;
                }

                self_clean::reiniciarArchivo(nombreArchivo);
                auto_save::guardarLog(nombreArchivo, "Time\tRef_Input\tSalida_Planta\tHOSM_z0\tHOSM_z1\tHOSM_z2\tHOSM_z3");
                
                EstadoHOSM z_init = {0.0, 0.0, 0.0, 0.0};
                EstadoPlanta p_init = {0.0, 0.0, 0.0};

                cout << "\nIniciando Simulacion en Tiempo Real (10s)..." << endl;
                bucleSimulacion(0, 2500, opcion, z_init, p_init, nombreArchivo);
                
                cout << "\n\nSimulacion Finalizada." << endl;
                cout << "Datos guardados en '" << nombreArchivo << "'" << endl;
                
                // Opción: ¿Salir después de simular o volver al menú?
                // Usualmente es mejor volver al menú por si quiere probar otra señal.
                cout << "Presione Enter para continuar...";
                cin.ignore(); cin.get(); // Pausa simple
            } 
            else if (opcion == 5) {
                ejecutando = false; // Sale del while y termina la función
            } 
            else {
                cout << "Opcion invalida." << endl;
            }
        }
    }
}