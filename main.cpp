//============================================================================
// Name        : S06.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "paciente.h"
#include "Servicio.h"
#include <fstream>
#include <ctime>

using namespace std;

// ESTE CARGAR FUERA DE LAS CLASES ES SOLO PARA PRUEBAS

string obtenerFechaHora() {
    time_t t = std::time(nullptr);
    tm* now = std::localtime(&t);

    char buffer[128];
    string data;
    strftime(buffer, sizeof(buffer), "%d/%m/%Y %X", now);
    return buffer;

}

//
//int main() {
//	string sfecha;
//	sfecha = obtenerFechaHora();
//	// creamos un objeto de la clase FechaYHora
//	FechaYHora f(sfecha);
//	f.mostrar();
//	return 0;
//}
