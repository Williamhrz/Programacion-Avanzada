#include "../Archivos_hpp/listadoEstudiantil.hpp"
#include <iostream>
#include <fstream>

// Constructor
ListadoEstudiantil::ListadoEstudiantil() {
    head = nullptr;
    size = 0;
}

// Destructor
ListadoEstudiantil::~ListadoEstudiantil() {
    Nodo* actual = head;
    while (actual) {
        Nodo* temp = actual;
        actual = actual->next;
        delete temp;
    }
}

// Insertar al final
void ListadoEstudiantil::insertarFinal(const Estudiante& e) {
    Nodo* nuevo = new Nodo{e, nullptr};

    if (!head) {
        head = nuevo;
    } else {
        Nodo* aux = head;
        while (aux->next)
            aux = aux->next;
        aux->next = nuevo;
    }

    size++;
}

// Eliminar por ID
bool ListadoEstudiantil::eliminarPorID(long id) {
    if (!head) return false;

    if (head->data.id == id) {
        Nodo* temp = head;
        head = head->next;
        delete temp;
        size--;
        return true;
    }

    Nodo* aux = head;
    while (aux->next && aux->next->data.id != id)
        aux = aux->next;

    if (!aux->next) return false;

    Nodo* temp = aux->next;
    aux->next = aux->next->next;
    delete temp;
    size--;
    return true;
}

// Buscar por ID
int ListadoEstudiantil::buscar(long id) {
    Nodo* aux = head;
    int pos = 0;

    while (aux) {
        if (aux->data.id == id) return pos;
        aux = aux->next;
        pos++;
    }
    return -1;
}

// Imprimir lista en archivo
void ListadoEstudiantil::imprimirEnArchivo(const string& ruta) {
    ofstream file(ruta);

    if (!file.is_open()) {
        cout << "Error: no se pudo crear el archivo " << ruta << endl;
        return;
    }

    Nodo* aux = head;
    while (aux) {
        file << aux->data.nombre << " | "
             << aux->data.anioNacimiento << " | "
             << aux->data.id << " | "
             << aux->data.promedio << " | "
             << aux->data.email << "\n";
        aux = aux->next;
    }

    file.close();
}

// Invertir la lista
void ListadoEstudiantil::invertirLista() {
    Nodo* prev = nullptr;
    Nodo* actual = head;
    Nodo* next = nullptr;

    while (actual) {
        next = actual->next;
        actual->next = prev;
        prev = actual;
        actual = next;
    }

    head = prev;
}

// Imprimir lista
void ListadoEstudiantil::imprimirLista() {
    Nodo* aux = head;

    if (!aux) {
        cout << "Lista vacia.\n";
        return;
    }

    cout << "\n=== LISTA DE ESTUDIANTES ===\n";

    while (aux) {
        cout << aux->data.nombre << " | "
             << aux->data.anioNacimiento << " | "
             << aux->data.id << " | "
             << aux->data.promedio << " | "
             << aux->data.email << "\n";
        aux = aux->next;
    }
}

// Operador []
Estudiante& ListadoEstudiantil::operator[](int index) {
    Nodo* aux = head;
    int i = 0;

    while (aux && i < index) {
        aux = aux->next;
        i++;
    }

    return aux->data;
}