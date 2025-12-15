#ifndef HIL_HPP
#define HIL_HPP

namespace hil {

    // --- ESTRUCTURAS DE DATOS (Los "Planos") ---
    
    // 1. Estado del Derivador HOSM
    // Almacena la estimación de la señal y sus derivadas
    struct EstadoHOSM {
        double z0; // Señal estimada
        double z1; // 1ra derivada (Velocidad)
        double z2; // 2da derivada (Aceleración)
        double z3; // 3ra derivada (Jerk)
    };

    // 2. Estado de la Planta
    // Almacena las variables internas de la ecuación diferencial
    struct EstadoPlanta {
        double x1;
        double x2;
        double x3;
    };

    // --- FUNCIÓN PRINCIPAL ---
    // Esta es la única puerta de entrada que necesita el main.cpp
    void ejecutarSimulacion();

}

#endif // ACTIVIDAD2_HPP