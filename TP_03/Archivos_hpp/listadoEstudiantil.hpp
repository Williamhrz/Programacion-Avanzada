#ifndef LISTADO_ESTUDIANTIL_HPP
#define LISTADO_ESTUDIANTIL_HPP
#include <string>
using namespace std;

struct Estudiante{
    string nombre;
    int anioNacimiento;
    long  id;
    float promedio;
    string email;
};
struct Nodo{
    Estudiante data;
    Nodo* next;

};

class ListadoEstudiantil{
    private:
        Nodo* head;
        int size;
    public:
        ListadoEstudiantil();
        ~ListadoEstudiantil();
        void insertarFinal(const Estudiante& est);
        bool eliminarPorID(long id);
        int buscar (long id);
        void imprimirEnArchivo(const string& nombreArchivo);
        void invertirLista();
        void imprimirLista();
        Estudiante& operator[](int index);
};
#endif