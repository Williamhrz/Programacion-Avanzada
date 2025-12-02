#include "../Archivos_hpp/ListadoEstudiantil.hpp"
#include <iostream>
#include <fstream>

// Constructor
ListadoEstudiantil::ListadoEstudiantil() {
    head = nullptr;
    size = 0;
}

// Destructor: liberar memoria
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

    // Si el primer nodo es el que se elimina
    if (head->data.id == id) {
        Nodo* temp = head;
        head = head->next;
        delete temp;
        size--;
        return true;
    }

    // Buscar nodo
    Nodo* aux = head;
    while (aux->next && aux->next->data.id != id)
        aux = aux->next;

    if (!aux->next) return false; // no encontrado

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
    return -1; // no encontrado
}

// Imprimir lista en archivo txt
void ListadoEstudiantil::imprimirEnArchivo(const string& archivo) {
    ofstream file(archivo);

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
