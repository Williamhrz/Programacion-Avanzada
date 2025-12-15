@echo off
echo Compilando Sinfonia de Codigo...
g++ -I ../Archivos_hpp ../Proyecto.cpp ../Archivos_cpp/*.cpp -o ./executable/proyecto_run.exe
if %errorlevel% equ 0 (
    echo Ejecutando aplicacion...
    ./executable/proyecto_run.exe
) else (
    echo Error de compilacion.
)
pause