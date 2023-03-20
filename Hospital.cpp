/*
 * Hospital.cpp
 *
 *  Created on: 27 feb 2023
 *      Author: Isaac Romanillos
 */

#include "Hospital.h"
#include "Paciente.h"
#include "Consulta.h"
#include "Medico.h"
#include "FechaYHora.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Hospital::Hospital() {
	this->nombre = "";
	ListaPacientes *lP = new ListaPacientes();
	ListaMedicos *lM = new ListaMedicos();
	this->cargarPaciente();
	this->cargarMedicos();
	this->cargarConsulta();
}

Hospital::Hospital(string nombre) {
	this->nombre = nombre;
	ListaPacientes *lP = new ListaPacientes();
	ListaMedicos *lM = new ListaMedicos();
	this->cargarPaciente();
	this->cargarMedicos();
	this->cargarConsulta();
}

string Hospital::getNombre() {
	return this->nombre;
}

void Hospital::mostrarPacientes() {
	this->lP->mostrarR();
}

void Hospital::mostrarConsultas() {

}

void Hospital::mostrarMedicos() {

}

void Hospital::mostrarEstadisticas() {
}

Paciente* Hospital::buscarPaciente(string dni) {

}

Medico* Hospital::buscarMedico(string apellidos) {

}

Consulta* Hospital::buscarConsulta(string DNI) {

}

void Hospital::cargarPaciente() {
	ifstream ifs;
//	int genero, edad;
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

//				edad = stoi(edadString);
//				genero = stoi(generoString);
//				Genero generoGen = Genero(stoi(genero));

				p = new Paciente(nombre, apellidos, DNI, Genero(stoi(genero)),
						stoi(edad));
				this->lP->insertar(p);
			}
		}
		ifs.close();
	}
}

void Hospital::cargarConsulta() {
	ifstream ifs;
	Paciente *p = nullptr;
	Medico *m = nullptr;
	Consulta *c = nullptr;
	FechaYHora fyh;
	string DNI, apellidos, fecha, tipoConsultaString;
	int tipoInt;
	ifs.open("consultas.csv");
	if (ifs.fail()) {
		cerr << "ERROR: fichero no encontrado." << endl;
	} else {
		while (!ifs.eof()) {
			getline(ifs, DNI, ';');
			if (!ifs.eof()) {
				getline(ifs, apellidos, ';');
				getline(ifs, tipoConsultaString, ';');
				getline(ifs, fecha, '\n');
				tipoInt = stoi(tipoConsultaString);
				TipoConsulta tipoConsultaEnum = TipoConsulta(tipoInt);
				p = buscarPaciente(DNI);
				m = buscarMedico(apellidos);
				if (fecha == "-") {
					fyh = FechaYHora();
				} else {
					fyh = FechaYHora(fecha);
				}
				c = new Consulta(p, m, tipoConsultaEnum, fyh);
//				this->VOV_Consultas->insertarElemento(c);
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

void Hospital::almacenarPaciente(string DNI) {

}

Hospital::~Hospital() {
	while (!this->lP->isEmpty()) {
		delete this->lP->obtenerPrimerPaciente();
	}
	while (!this->lM->isEmpty()) {
		delete this->lM->obtenerPrimerMedico();
	}
}

