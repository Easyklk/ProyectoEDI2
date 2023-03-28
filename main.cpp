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

using namespace std;

// ESTE CARGAR FUERA DE LAS CLASES ES SOLO PARA PRUEBAS
void cargarPacientes(Servicio *&ser) {
	ifstream ifs;

	ifs.open("pacientes.csv");
	if (ifs.fail()) {
		cerr << "ERROR: fichero no encontrado." << endl;
	} else {
		// Datos de pacientes
		while (!ifs.eof()) {
			string DNI;
			getline(ifs, DNI, ';');
			if (!ifs.eof()) {
				string nombre;
				getline(ifs, nombre, ';');
				string apellidos;
				getline(ifs, apellidos, ';');
				string genero;
				getline(ifs, genero, ';');
				string edad;
				getline(ifs, edad, '\n');

				Paciente *p = new Paciente(nombre, apellidos, DNI,
						Genero(stoi(genero)), stoi(edad));
				// calcular prioridad
				int prioridad = rand() % 5;
				ser->insertar(prioridad, p);
			}
		}

		ifs.close();

	}

}

//int main() {
//	srand(1992);
//	Servicio *ser = new Servicio("Traumatología");
//	cargarPacientes(ser); // SOLO PARA PROBAR CARGO DESDE AQUI
//	ser->mostrarPrioridad(1);
//	delete ser;
//	return 0;
//}
