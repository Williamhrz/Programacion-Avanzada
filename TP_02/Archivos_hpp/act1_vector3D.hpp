#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

#include <iostream>

class Vector3D {
private:
    float x, y, z;

public:
    // Constructor
    Vector3D(float x = 0, float y = 0, float z = 0);

    // Métodos
    float magnitud() const;
    Vector3D normalizar() const;
    void imprimir() const;

    // Sobrecarga de operadores
    Vector3D operator+(const Vector3D& v) const;
    Vector3D operator-(const Vector3D& v) const;
    float operator*(const Vector3D& v) const; // producto escalar
};

#endif