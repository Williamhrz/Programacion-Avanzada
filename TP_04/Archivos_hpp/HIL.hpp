#ifndef HIL_HPP
#define HIL_HPP

namespace hil {
    struct EstadoDerivador {
        double z0, z1, z2, z3;
    };

    void ejecutarSimulacion();
}

#endif