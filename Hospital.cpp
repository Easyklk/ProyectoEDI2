/*
 * Hospital.cpp
 *
 *  Created on: 27 feb 2023
 *      Author: Isaac Romanillos
 */

#include "Hospital.h"
#include "Paciente.h"
#include "Medico.h"
#include "FechaYHora.h"
#include "Servicio.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

Hospital::Hospital() {
	this->nombre = "";
	this->sv = new Servicio("");
	this->lP = new ListaPacientes();
	this->lM = new ListaMedicos();
	this->cargarPaciente();
	this->cargarMedicos();
	this->cargarInformes();
}

Hospital::Hospital(string nombre, string nomServicio) {
	this->nombre = nombre;
	this->sv = new Servicio(nomServicio);
	this->lP = new ListaPacientes();
	this->lM = new ListaMedicos();
	this->cargarPaciente();
	this->cargarMedicos();
	this->cargarInformes();
}

string Hospital::getNombre() {
	return this->nombre;
}

Servicio* Hospital::getServicio() {
	return this->sv;
}

string Hospital::obtenerFechaHora() {
	time_t t = std::time(nullptr);
	tm *now = std::localtime(&t);

	char buffer[128];
	string data;
	strftime(buffer, sizeof(buffer), "%d/%m/%Y %X", now);
	return buffer;

}

void Hospital::mostrarPacientes() {
	this->lP->mostrarR();
}

void Hospital::mostrarPacientesEspera() {
	for (int i = 1; i <= MAX_PRIORIDAD; ++i) {
		if (!this->sv->estaVaciaPrioridad(i)) {
			cout << "-------------------------------- Prioridad " << i
					<< " --------------------------------" << endl;
			this->sv->mostrarPrioridad(i);
			cout << endl;
		}
	}
}

void Hospital::mostrarMedicos() {
	this->lM->mostrarR();
}

void Hospital::mostrarEstadisticas() {
	cout << this->lP->NumPacientesR() << " Pacientes" << endl;
	cout << this->lM->NumMedicosR() << " Medicos" << endl;
	for (int i = 1; i <= MAX_PRIORIDAD; ++i) {
		cout << this->sv->numPacientes(i) << " pacientes con prioridad " << i
				<< endl;
	}
}

Paciente* Hospital::buscarPaciente(string DNI) {
	Paciente *p = this->lP->buscarPaciente(DNI);
	return p;
}

Medico* Hospital::buscarMedico(string apellidos) {
	Medico *m = this->lM->buscarMedico(apellidos);
	return m;
}

Medico* Hospital::buscarMedicoEspecialidad(string especialidad) {
	Medico *m = this->lM->buscarMedicoEspecialidad(especialidad);
	return m;
}

void Hospital::cargarPaciente() {
	ifstream ifs;
	Paciente *p = nullptr;
	ifs.open("pacientes.csv");
	if (ifs.fail()) {
		cerr << "ERROR: fichero no encontrado." << endl;
	} else {
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
				p = new Paciente(nombre, apellidos, DNI, Genero(stoi(genero)),
						stoi(edad));
				int prioridad = 1 + rand() % 5;
				sv->insertar(prioridad, p);

				this->lP->insertar(p);
			}
		}
		ifs.close();
	}
}

void Hospital::cargarMedicos() {
	ifstream ifs;
	string nombre, apellidos, especialidad;
	Medico *m = nullptr;
	ifs.open("medicos.csv");
	if (ifs.fail()) {
		cerr << "ERROR: fichero no encontrado." << endl;
	} else {
		while (!ifs.eof()) {
			getline(ifs, nombre, ';');
			if (!ifs.eof()) {
				getline(ifs, apellidos, ';');
				getline(ifs, especialidad, '\n');
				m = new Medico(nombre, apellidos, especialidad);
				this->lM->insertar(m);
			}
		}
		ifs.close();
	}
}

void Hospital::cargarInformes() {
	Informe *inf;
	Medico *m;
	Paciente *p;
	string DNI, texto, apellidos, fecha;
	ifstream ifs("informes.csv");
	if (ifs.fail()) {
		cerr << "ERROR: fichero no encontrado." << endl;
	} else {
		while (!ifs.eof()) {
			getline(ifs, DNI, ';');
			if (!ifs.eof()) {
				getline(ifs, texto, ';');
				getline(ifs, apellidos, ';');
				getline(ifs, fecha, '\n');
				if (this->lM->existe(apellidos)) {
					m = this->lM->buscarMedico(apellidos);
					if (this->lP->existe(DNI)) {
						p = this->lP->buscarPaciente(DNI);
						FechaYHora fyh(fecha);
						inf = new Informe(texto, fyh, m);
						p->aniadirInfor(inf);
					}
				}

			}
		}
	}
}

void Hospital::generarInforme() {
	ofstream ofs;
	Informe *inf;
	Paciente *p;
	Medico *m = this->sv->getMedico();
	for (int i = 1; i <= MAX_PRIORIDAD; ++i) {
		cout << "-------------------------------- Prioridad " << i
				<< " --------------------------------" << endl;
		while (!this->sv->estaVaciaPrioridad(i)) {
			p = this->sv->obtenerPrimerPaciente(i);
			inf = new Informe("Texto de Ejemplo",
					FechaYHora(this->obtenerFechaHora()), m);
			p->aniadirInfor(inf);
			p->mostrar();
			cout << endl;
			p->mostrarInfPac();
			cout << endl;
		}
	}
}

Hospital::~Hospital() {
	while (!this->lP->isEmpty()) {
		delete this->lP->eliminarPrimerPaciente();
	}
	delete this->lP;

	while (!this->lM->isEmpty()) {
		delete this->lM->obtenerPrimerMedico();
	}
	delete this->lM;

	delete this->sv;
}

