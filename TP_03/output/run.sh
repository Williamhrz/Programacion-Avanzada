#!/bin/bash

echo "Compilando el proyecto..."
g++ ../proyecto.cpp ../Archivos_cpp/*.cpp -I ../Archivos_hpp -o ./executable/proyecto

if [ $? -eq 0 ]; then
    echo "Compilación exitosa."
    echo "Ejecutando el programa..."
    ./executable/proyecto
else
    echo "Error en la compilación."
fi
