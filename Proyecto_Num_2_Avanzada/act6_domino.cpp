#include "act6_domino.hpp"
#include <algorithm>
#include <random>
using namespace std;

// ======================== FICHA =========================

Ficha::Ficha(int a, int b) : a(a), b(b) {}

void Ficha::girar() {
    int temp = a;
    a = b;
    b = temp;
}

void Ficha::imprimir() const {
    cout << "[" << a << "|" << b << "]";
}

// ======================== JUGADOR =========================

Jugador::Jugador(const string& nombre) : nombre(nombre) {}

void Jugador::agregarFicha(const Ficha& f) {
    mano.push_back(f);
}

void Jugador::mostrarMano() const {
    cout << nombre << " -> ";
    for (const auto& f : mano) {
        f.imprimir();
        cout << " ";
    }
    cout << "\n";
}

bool Jugador::puedeJugar(int izq, int der) const {
    for (const auto& f : mano) {
        if (f.getA() == izq || f.getB() == izq ||
            f.getA() == der || f.getB() == der)
            return true;
    }
    return false;
}

bool Jugador::jugarFicha(int izq, int der, Ficha& fichaSalida, bool& porIzquierda) {
    for (int i = 0; i < mano.size(); i++) {
        Ficha f = mano[i];

        // Intentar por la izquierda
        if (f.getB() == izq) {
            fichaSalida = f;
            porIzquierda = true;
            mano.erase(mano.begin() + i);
            return true;
        }
        if (f.getA() == izq) {
            f.girar();
            fichaSalida = f;
            porIzquierda = true;
            mano.erase(mano.begin() + i);
            return true;
        }

        // Intentar por la derecha
        if (f.getA() == der) {
            fichaSalida = f;
            porIzquierda = false;
            mano.erase(mano.begin() + i);
            return true;
        }
        if (f.getB() == der) {
            f.girar();
            fichaSalida = f;
            porIzquierda = false;
            mano.erase(mano.begin() + i);
            return true;
        }
    }

    return false;
}

// ======================== JUEGO DOMINO =========================

JuegoDomino::JuegoDomino() : turnoActual(0) {}

void JuegoDomino::agregarJugador(const string& nombre) {
    jugadores.emplace_back(nombre);
}

void JuegoDomino::barajar() {
    random_device rd;
    mt19937 g(rd());
    shuffle(fichas.begin(), fichas.end(), g);
}

void JuegoDomino::repartir() {
    int porJugador = (jugadores.size() == 2 ? 7 : 5);

    int index = 0;
    for (int i = 0; i < porJugador; i++) {
        for (auto& j : jugadores) {
            j.agregarFicha(fichas[index++]);
        }
    }
}

void JuegoDomino::iniciar() {
    fichas.clear();
    mesa.clear();
    turnoActual = 0;

    // Crear fichas (28)
    for (int i = 0; i <= 6; i++) {
        for (int j = i; j <= 6; j++) {
            fichas.emplace_back(i, j);
        }
    }

    barajar();
    repartir();

    // Primera ficha a la mesa
    mesa.push_back(fichas.back());
    fichas.pop_back();
}

void JuegoDomino::mostrarMesa() const {
    cout << "Mesa: ";
    for (const auto& f : mesa) {
        f.imprimir();
        cout << " ";
    }
    cout << "\n";
}

bool JuegoDomino::juegoTerminado() const {
    for (const auto& j : jugadores) {
        if (j.sinFichas()) return true;
    }
    return false;
}

void JuegoDomino::jugar() {
    cout << "\n=== INICIA EL JUEGO DEL DOMINO ===\n";

    while (!juegoTerminado()) {
        Jugador& j = jugadores[turnoActual];

        cout << "\nTurno de " << j.getNombre() << "\n";
        j.mostrarMano();
        mostrarMesa();

        int izq = mesa.front().getA();
        int der = mesa.back().getB();

        if (!j.puedeJugar(izq, der)) {
            cout << j.getNombre() << " no puede jugar.\n";
            turnoActual = (turnoActual + 1) % jugadores.size();
            continue;
        }

        Ficha f;
        bool porIzq;

        if (j.jugarFicha(izq, der, f, porIzq)) {
            if (porIzq)
                mesa.insert(mesa.begin(), f);
            else
                mesa.push_back(f);

            cout << j.getNombre() << " jugó ";
            f.imprimir();
            cout << "\n";
        }

        turnoActual = (turnoActual + 1) % jugadores.size();
    }

    cout << "\n=== JUEGO TERMINADO ===\n";

    for (const auto& j : jugadores) {
        if (j.sinFichas()) {
            cout << "Ganador: " << j.getNombre() << " 🎉\n";
            return;
        }
    }
}

void JuegoDomino::reiniciar() {
    iniciar();
}