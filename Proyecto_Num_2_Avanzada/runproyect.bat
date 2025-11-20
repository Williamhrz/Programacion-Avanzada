@echo off
echo Compilando...

g++ proyecto.cpp ^
Archivos_cpp/act1_vector3D.cpp ^
Archivos_cpp/act2_matriz.cpp ^
Archivos_cpp/act3_polinomio.cpp ^
Archivos_cpp/act4_complejos.cpp ^
Archivos_cpp/act5_ecuaciones.cpp ^
Archivos_cpp/act6_domino.cpp ^
-I Archivos_hpp -o output/proyecto.exe

if %errorlevel% neq 0 (
    echo.
    echo Error en la compilacion.
    pause
    exit /b
)

echo.
echo Ejecutando...
output\proyecto.exe

pause
