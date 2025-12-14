@echo off
echo Compilando Sinfonia de Codigo...
g++ -I ../Archivos_hpp ../Proyecto.cpp ../Archivos_cpp/*.cpp -o proyecto.exe
if %errorlevel% equ 0 (
    echo Ejecutando aplicacion...
    proyecto.exe
) else (
    echo Error de compilacion.
)
pause