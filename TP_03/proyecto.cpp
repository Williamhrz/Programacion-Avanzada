#include <iostream>
#include <string>

#include "Archivos_hpp/listadoEstudiantil.hpp"
#include "Archivos_hpp/SenalECG.hpp"
#include "Archivos_hpp/Domino.hpp"

using namespace std;

// ====================================================
//                MENÚ ACTIVIDAD 1
// ====================================================
void actividad1() {
    ListadoEstudiantil lista;
    int opcion;

    do {
        cout << "\n=== ACTIVIDAD 1: LISTADO ESTUDIANTIL ===\n";
        cout << "1. Insertar estudiante\n";
        cout << "2. Eliminar por ID\n";
        cout << "3. Buscar por ID\n";
        cout << "4. Imprimir en archivo\n";
        cout << "5. Invertir lista\n";
        cout << "6. Mostrar lista\n";
        cout << "0. Volver\n";
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            Estudiante e;
            cout << "Nombre: "; cin >> e.nombre;
            cout << "Año nacimiento: "; cin >> e.anioNacimiento;
            cout << "ID: "; cin >> e.id;
            cout << "Promedio: "; cin >> e.promedio;
            cout << "Email: "; cin >> e.email;

            lista.insertarFinal(e);
            cout << "Estudiante agregado.\n";
        }

        else if (opcion == 2) {
            long id;
            cout << "ID a eliminar: ";
            cin >> id;
            if (lista.eliminarPorID(id)) cout << "Eliminado.\n";
            else cout << "No encontrado.\n";
        }

        else if (opcion == 3) {
            long id;
            cout << "ID a buscar: ";
            cin >> id;
            int pos = lista.buscar(id);
            if (pos == -1) cout << "No encontrado.\n";
            else cout << "Encontrado en posicion " << pos << endl;
        }

        else if (opcion == 4) {
            string nombre;
            cout << "Nombre archivo salida: ";
            cin >> nombre;
            lista.imprimirEnArchivo("output/" + nombre);
            cout << "Archivo generado en output/.\n";
        }

        else if (opcion == 5) {
            lista.invertirLista();
            cout << "Lista invertida.\n";
        }

        else if (opcion == 6) {
            lista.imprimirLista();
        }

    } while (opcion != 0);
}

// ====================================================
//                MENÚ ACTIVIDAD 2
// ====================================================
void actividad2() {
    SenalECG ecg;
    string archivo;
    int opcion;

    do {
        cout << "\n=== ACTIVIDAD 2: SEÑAL ECG ===\n";
        cout << "1. Cargar señal desde archivo\n";
        cout << "2. Filtrar señal\n";
        cout << "3. Detectar picos\n";
        cout << "4. Guardar señal filtrada\n";
        cout << "5. Calcular frecuencia cardiaca\n";
        cout << "0. Volver\n";
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "Archivo (en output/): ";
            cin >> archivo;
            ecg.cargarDesdeArchivo("output/" + archivo);
        }

        else if (opcion == 2) {
            ecg.filtrarSenal();
            cout << "Señal filtrada.\n";
        }

        else if (opcion == 3) {
            float umbral;
            cout << "Umbral: ";
            cin >> umbral;
            ecg.detectarPicos(umbral);
            cout << "Picos detectados.\n";
        }

        else if (opcion == 4) {
            cout << "Archivo salida (en output/): ";
            cin >> archivo;
            ecg.guardarEnArchivo("output/" + archivo);
            cout << "Archivo guardado en output/.\n";
        }

        else if (opcion == 5) {
            float f = ecg.calcularFrecuenciaCardiaca();
            cout << "Frecuencia cardiaca estimada: "
                 << f << " BPM\n";
        }

    } while (opcion != 0);
}

// ====================================================
//                MENÚ ACTIVIDAD 3
// ====================================================
void actividad3() {
    JuegoDomino juego;

    cout << "\n=== ACTIVIDAD 3: DOMINO ===\n";

    string j1, j2;
    cout << "Jugador 1: "; cin >> j1;
    cout << "Jugador 2: "; cin >> j2;

    juego.agregarJugador(j1);
    juego.agregarJugador(j2);

    juego.iniciar();
    juego.jugar();
}

// ====================================================
//                       MAIN
// ====================================================
int main() {

    int opcion;

    do {
        cout << "\n=====================================\n";
        cout << "           PROYECTO TP_03\n";
        cout << "=====================================\n";
        cout << "1. Actividad 1: Listado estudiantil\n";
        cout << "2. Actividad 2: Señal ECG\n";
        cout << "3. Actividad 3: Domino\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) actividad1();
        else if (opcion == 2) actividad2();
        else if (opcion == 3) actividad3();

    } while (opcion != 0);

    return 0;
}
