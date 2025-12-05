#ifndef DOMINO_HPP
#define DOMINO_HPP

#include <string>
#include <vector>

// ===================== CLASE FICHA =====================
class Ficha {
private:
    int a, b;

public:
    Ficha(int a = 0, int b = 0);

    int getA() const { return a; }
    int getB() const { return b; }

    void girar();
    std::string toString() const;
};

// ===================== CLASE JUGADOR =====================
class Jugador {
private:
    std::string nombre;
    std::vector<Ficha> mano;

public:
    Jugador(const std::string& nombre);

    void agregarFicha(const Ficha& f);
    bool puedeJugar(int izq, int der) const;

    // Jugada automática que ya no usamos en modo manual
    bool jugarFicha(int izq, int der, Ficha& salida, bool& porIzq);

    bool sinFichas() const { return mano.empty(); }
    int sumarPuntos() const;
    int cantidadFichas() const;

    std::string getNombre() const { return nombre; }
    std::vector<Ficha>& getMano() { return mano; }    // ← necesario para modo manual
};

// ===================== LISTA ENLAZADA HISTORIAL =====================
struct NodoHistorial {
    std::string jugador;
    std::string ficha;
    std::string tablero;
    NodoHistorial* sig;

    NodoHistorial(const std::string& j,
                  const std::string& f,
                  const std::string& t)
        : jugador(j), ficha(f), tablero(t), sig(nullptr) {}
};

class ListaHistorial {
private:
    NodoHistorial* head;

public:
    ListaHistorial();
    void agregar(const std::string& jugador,
                 const std::string& ficha,
                 const std::string& tablero);
    void guardarArchivo(const std::string& nombre);
    ~ListaHistorial();
};

// ===================== CLASE JUEGO DOMINO =====================
class JuegoDomino {
private:
    std::vector<Ficha> fichas;
    std::vector<Ficha> mesa;
    std::vector<Jugador> jugadores;
    int turno;

public:
    JuegoDomino();

    void agregarJugador(const std::string& nombre);
    void iniciar();
    void jugar();

private:
    void crearFichas();
    void barajar();
    void repartir();
    std::string mesaComoTexto() const; // para historial
};

#endif
