#ifndef ACT6_DOMINO_HPP
#define ACT6_DOMINO_HPP

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ======================== FICHA =========================
class Ficha {
private:
    int a, b;

public:
    Ficha(int a = 0, int b = 0);

    int getA() const { return a; }
    int getB() const { return b; }

    void girar();
    void imprimir() const;
};

// ======================== JUGADOR =========================
class Jugador {
private:
    string nombre;
    vector<Ficha> mano;

public:
    Jugador(const string& nombre);

    void agregarFicha(const Ficha& f);
    void mostrarMano() const;

    bool puedeJugar(int izq, int der) const;
    bool jugarFicha(int izq, int der, Ficha& fichaSalida, bool& porIzquierda);

    bool sinFichas() const { return mano.empty(); }
    string getNombre() const { return nombre; }

    // Necesarios para determinar ganador
    int sumarPuntos() const;
    int cantidadFichas() const;
};

// ======================== JUEGO DOMINO =========================
class JuegoDomino {
private:
    vector<Ficha> fichas;      
    vector<Ficha> mesa;        
    vector<Jugador> jugadores; 
    int turnoActual;

public:
    JuegoDomino();

    void agregarJugador(const string& nombre);

    void barajar();
    void repartir();
    void iniciar();
    void reiniciar();

    void mostrarMesa() const;
    bool juegoTerminado() const;

    void jugar();
};

#endif
