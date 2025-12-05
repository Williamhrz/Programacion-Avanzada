@echo off
echo Compilando proyecto...

REM Compilar cada archivo fuente dentro de Archivos_cpp
g++ proyecto.cpp ^
   Archivos_cpp\Contador_de_vocales.cpp ^
   Archivos_cpp\Matriz_pseudo.cpp ^
   Archivos_cpp\Norma_vector_Eu.cpp ^
   Archivos_cpp\Operaciones_basicas.cpp ^
   Archivos_cpp\Vector.cpp ^
   -I Archivos_hpp -o proyecto.exe

if %errorlevel% neq 0 (
    echo Error en la compilacion.
    pause
    exit /b
)

echo Ejecucion del proyecto...
proyecto.exe
pause
