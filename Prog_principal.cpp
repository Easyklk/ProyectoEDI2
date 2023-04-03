//============================================================================
// Name        : Entrega 2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "PruebasColaPacientes.h"
#include "PruebasMedico.h"
#include "PruebasPaciente.h"
#include "PruebasInforme.h"
#include "PruebasListaPacientes.h"
#include "PruebasListaMedicos.h"
#include "PruebasServicio.h"
#include "PruebasInformePacientes.h"
#include "Hospital.h"
using namespace std;

// Muestra el menu por pantalla y devuelve una opcion elegida.
int menu(string nombre) {

	int opcion;

	do {
		cout << endl;
		cout << "--------  " << nombre << "  --------" << endl << endl;

		cout << "     1. Mostrar Estadísticas               " << endl;
		cout << "     2. Mostrar Pacientes                  " << endl;
		cout << "     3. Mostrar Médicos                    " << endl;
		cout << "     4. Mostrar Pacientes Espera			" << endl;
		cout << "     5. Buscar Paciente                    " << endl;
		cout << "     6. Buscar Medico                      " << endl;
		cout << "     7. Asignar Medico						" << endl;
		cout << "     8. Procesar las colas de espera		" << endl;

		cout << "     0. Finalizar.                         " << endl;
		cout << "                        Opción:  ";

		cin >> opcion;
		cin.ignore();

	} while ((opcion < 0) || (opcion > 8));

	return opcion;
}

// Programa principal:
int main() {
//	-------Pruebas-------
//	pruebasMedico();
//	pruebasPaciente();
//	pruebasColaPacientes();
//	pruebasInforme();
//	pruebasListaPacientes();
//	pruebasListaMedicos();
//	pruebasServicio();
//	pruebasInformePacientes();
	//	-------Pruebas-------

	Hospital *hospital = nullptr;
	Paciente *p = nullptr;
	Medico *m = nullptr;
	bool salir = false;
	int opcion;
	string DNI, apellido;

	hospital = new Hospital("Hospital Uex", "Traumatología");

	while (!salir) {
		opcion = menu(hospital->getNombre());

		switch (opcion) {
		case 1:
			hospital->mostrarEstadisticas();
			break;

		case 2:
			hospital->mostrarPacientes();
			break;

		case 3:
			hospital->mostrarMedicos();
			break;

		case 4:
			hospital->mostrarPacientesEspera();
			break;

		case 5:
			cout << "Introduzca el DNI a buscar: ";
			cin >> DNI;
			p = hospital->buscarPaciente(DNI);
			if (p != nullptr) {
				p->mostrar();
				cout << endl;
				p->mostrarInfPac();
			} else
				cerr << " No hay ningun paciente con a ese DNI" << endl;
			break;

		case 6:
			cout << "Introduzca el apellido a buscar: ";
			cin >> apellido;
			m = hospital->buscarMedico(apellido);
			if (m != nullptr)
				m->mostrar();
			else
				cerr << " No hay ningun medico con ese apellido" << endl;
			break;

		case 7:
			m = hospital->buscarMedicoEspecialidad(
					hospital->getServicio()->getEspecialidad());
			if (m != nullptr) {
				hospital->getServicio()->setMedico(m);
				cout << "Medico asignado: ";
				m->mostrar();
			} else
				cerr << "No hay ningun medico con esa especialidad" << endl;
			break;

		case 8:
			if (hospital->getServicio()->getMedico() != nullptr) {
				hospital->generarInforme();
			} else
				cerr << " No hay ningun medico asignado" << endl;

			break;

		case 0:
			salir = true;
			break;

		default:
			break;

		}

	}

	delete hospital;

	return 0;
}
