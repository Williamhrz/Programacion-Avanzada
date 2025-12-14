#include "../Archivos_hpp/act1_vector3D.hpp"
#include <cmath>

// Constructor
Vector3D::Vector3D(float x, float y, float z) : x(x), y(y), z(z) {}

// Magnitud del vector
float Vector3D::magnitud() const {
    return std::sqrt(x*x + y*y + z*z);
}

// Normalización
Vector3D Vector3D::normalizar() const {
    float mag = magnitud();
    if (mag == 0) return Vector3D(0, 0, 0);
    return Vector3D(x / mag, y / mag, z / mag);
}

// Imprimir
void Vector3D::imprimir() const {
    std::cout << "(" << x << ", " << y << ", " << z << ")";
}

// Suma
Vector3D Vector3D::operator+(const Vector3D& v) const {
    return Vector3D(x + v.x, y + v.y, z + v.z);
}

// Resta
Vector3D Vector3D::operator-(const Vector3D& v) const {
    return Vector3D(x - v.x, y - v.y, z - v.z);
}

// Producto escalar
float Vector3D::operator*(const Vector3D& v) const {
    return x * v.x + y * v.y + z * v.z;
}