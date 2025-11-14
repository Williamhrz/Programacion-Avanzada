#ifndef ACT6_DOMINO_HPP
#define ACT6_DOMINO_HPP

#include <iostream>
#include <vector>
#include <string>

class Ficha {
private:
    int a, b;

public:
    Ficha(int a = 0, int b = 0);

    int getA() const { return a; }
    int getB() const { return b; }

    void girar(); // intercambia a <-> b
    void imprimir() const;
};

class Jugador {
private:
    std::string nombre;
    std::vector<Ficha> mano;

public:
    Jugador(const std::string& nombre = "");

    std::string getNombre() const { return nombre; }

    void agregarFicha(const Ficha& f);
    void mostrarMano() const;

    bool puedeJugar(int extremoIzq, int extremoDer) const;
    bool jugarFicha(int extremoIzq, int extremoDer, Ficha& fichaSalida, bool& porIzquierda);
    
    bool sinFichas() const { return mano.empty(); }
};

class JuegoDomino {
private:
    std::vector<Ficha> fichas;
    std::vector<Jugador> jugadores;
    std::vector<Ficha> mesa;

    int turnoActual;

public:
    JuegoDomino();

    void agregarJugador(const std::string& nombre);

    void iniciar();
    void repartir();
    void barajar();

    void mostrarMesa() const;
    bool jugadaValida(const Ficha& f, bool& porIzquierda) const;

    void jugar();
    bool juegoTerminado() const;
    void reiniciar();
};

#endif