#include "../Archivos_hpp/Domino.hpp"
#include <iostream>
#include <algorithm>
#include <random>
#include <fstream>

using namespace std;

// ===================== FICHA =====================

Ficha::Ficha(int a, int b) : a(a), b(b) {}

void Ficha::girar() {
    int t = a;
    a = b;
    b = t;
}

string Ficha::toString() const {
    return "[" + to_string(a) + "|" + to_string(b) + "]";
}

// ===================== JUGADOR =====================

Jugador::Jugador(const string& nombre) : nombre(nombre) {}

void Jugador::agregarFicha(const Ficha& f) {
    mano.push_back(f);
}

bool Jugador::puedeJugar(int izq, int der) const {
    for (const auto& f : mano)
        if (f.getA() == izq || f.getB() == izq ||
            f.getA() == der || f.getB() == der)
            return true;
    return false;
}

bool Jugador::jugarFicha(int, int, Ficha&, bool&) { return false; }

int Jugador::sumarPuntos() const {
    int suma = 0;
    for (const auto& f : mano)
        suma += f.getA() + f.getB();
    return suma;
}

int Jugador::cantidadFichas() const {
    return mano.size();
}

// ===================== LISTA HISTORIAL =====================

ListaHistorial::ListaHistorial() : head(nullptr) {}

void ListaHistorial::agregar(const string& jugador,
                             const string& ficha,
                             const string& tablero) {

    NodoHistorial* nuevo = new NodoHistorial(jugador, ficha, tablero);

    if (!head) head = nuevo;
    else {
        NodoHistorial* aux = head;
        while (aux->sig)
            aux = aux->sig;
        aux->sig = nuevo;
    }
}

void ListaHistorial::guardarArchivo(const string& nombre) {
    ofstream out(nombre);

    NodoHistorial* aux = head;
    while (aux) {
        out << "Jugador: " << aux->jugador << "\n";
        out << "Ficha: " << aux->ficha << "\n";
        out << "Mesa: " << aux->tablero << "\n";
        out << "-----------------------------------\n";
        aux = aux->sig;
    }
    out.close();
}

ListaHistorial::~ListaHistorial() {
    NodoHistorial* aux = head;
    while (aux) {
        NodoHistorial* temp = aux;
        aux = aux->sig;
        delete temp;
    }
}

// ===================== JUEGO DOMINO =====================

JuegoDomino::JuegoDomino() : turno(0) {}

void JuegoDomino::crearFichas() {
    fichas.clear();
    for (int i = 0; i <= 6; i++)
        for (int j = i; j <= 6; j++)
            fichas.emplace_back(i, j);
}

void JuegoDomino::barajar() {
    random_device rd;
    mt19937 g(rd());
    shuffle(fichas.begin(), fichas.end(), g);
}

void JuegoDomino::repartir() {
    int n = jugadores.size() == 2 ? 7 : 5;
    int idx = 0;
    for (int r = 0; r < n; r++)
        for (auto& J : jugadores)
            J.agregarFicha(fichas[idx++]);
}

string JuegoDomino::mesaComoTexto() const {
    string txt = "";
    for (int i = 0; i < mesa.size(); i++) {
        txt += mesa[i].toString();
        if (i < mesa.size() - 1) txt += ", ";
    }
    return txt;
}

void JuegoDomino::agregarJugador(const string& nombre) {
    jugadores.emplace_back(nombre);
}

void JuegoDomino::iniciar() {
    mesa.clear();
    turno = 0;

    crearFichas();
    barajar();
    repartir();

    mesa.push_back(fichas.back());
    fichas.pop_back();
}

void JuegoDomino::jugar() {

    ListaHistorial historial;

    cout << "\n=== MODO MANUAL DEL DOMINO ===\n";

    int bloqueos = 0;

    while (true) {

        Jugador& J = jugadores[turno];
        cout << "\nTurno de: " << J.getNombre() << "\n";

        // Mostrar mesa
        cout << "Mesa: " << mesaComoTexto() << "\n";

        // Extremos
        int izq = mesa.front().getA();
        int der = mesa.back().getB();

        // Mostrar mano
        cout << "Tu mano:\n";
        cout << "0: PASAR\n";
        for (int i = 0; i < J.cantidadFichas(); i++) {
            cout << (i + 1) << ": " << J.getMano()[i].toString() << "\n";
        }

        // Verificar si el jugador NO puede jugar
        bool puede = J.puedeJugar(izq, der);

        if (!puede) {
            cout << "\nNo tienes jugadas posibles. Se registra PASAR.\n";

            bloqueos++;

            if (bloqueos >= jugadores.size()) {
                cout << "\n=== JUEGO BLOQUEADO ===\n";
                break;
            }

            turno = (turno + 1) % jugadores.size();
            continue;
        }

        // Si sí puede jugar → reiniciar contador de bloqueos
        bloqueos = 0;

        int opcion;
        bool jugadaValida = false;
        Ficha seleccionada;
        bool porIzq = false;

        while (!jugadaValida) {
            cout << "\nElige una acción: ";
            cin >> opcion;

            if (opcion == 0) {
                cout << "Has elegido pasar.\n";

                historial.agregar(J.getNombre(),
                                  "PASAR",
                                  mesaComoTexto());

                bloqueos++;

                if (bloqueos >= jugadores.size()) {
                    cout << "\n=== JUEGO BLOQUEADO ===\n";
                    break;
                }

                turno = (turno + 1) % jugadores.size();
                goto continuar_ciclo;
            }

            opcion -= 1; // Convertir a índice real

            if (opcion < 0 || opcion >= J.cantidadFichas()) {
                cout << "Indice invalido.\n";
                continue;
            }

            seleccionada = J.getMano()[opcion];

            cout << "¿Jugar por izquierda (0) o derecha (1)? ";
            int lado; cin >> lado;
            porIzq = (lado == 0);

            // VALIDACIONES
            if (porIzq) {
                if (seleccionada.getB() == izq ||
                    seleccionada.getA() == izq) {

                    if (seleccionada.getA() == izq)
                        seleccionada.girar();

                    J.getMano().erase(J.getMano().begin() + opcion);
                    mesa.insert(mesa.begin(), seleccionada);

                    jugadaValida = true;
                }
            } else {
                if (seleccionada.getA() == der ||
                    seleccionada.getB() == der) {

                    if (seleccionada.getB() == der)
                        seleccionada.girar();

                    J.getMano().erase(J.getMano().begin() + opcion);
                    mesa.push_back(seleccionada);

                    jugadaValida = true;
                }
            }

            if (!jugadaValida)
                cout << "Esa ficha NO encaja en ese lado.\n";
        }

        // Guardar historial si jugó
        if (jugadaValida)
            historial.agregar(J.getNombre(),
                              seleccionada.toString(),
                              mesaComoTexto());

        // Fin si alguien gana
        if (J.sinFichas()) break;

        turno = (turno + 1) % jugadores.size();

        continuar_ciclo:;
    }

    historial.guardarArchivo("exit/historial_domino.txt");
    cout << "\nJuego finalizado.\n";
}
