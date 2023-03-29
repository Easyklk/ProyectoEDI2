/*
 * Servicio.cpp
 *
 *  Created on: 11 mar 2023
 *      Author: Isaac Romanillos
 */

#include "Servicio.h"

Servicio::Servicio() {
	for (int i = 0; i < MAX_PRIORIDAD; ++i) {
		this->colaPP[i] = new ColaPacientes();
	}
	this->especialidad = "";
	this->m = nullptr;
}

Servicio::Servicio(string especialidad) {
	for (int i = 0; i < MAX_PRIORIDAD; ++i) {
		this->colaPP[i] = new ColaPacientes();
	}
	this->especialidad = especialidad;
	this->m = nullptr;
}

string Servicio::getEspecialidad() {
	return this->especialidad;
}

void Servicio::setMedico(Medico *m) {
	this->m = m;
}

Medico* Servicio::getMedico() {
	return this->m;
}

void Servicio::insertar(int prioridad, Paciente *p) {
	this->colaPP[prioridad - 1]->insertar(p);
}

Paciente* Servicio::obtenerPrimerPaciente(int prioridad) {
	return this->colaPP[prioridad - 1]->obtener();

}

void Servicio::eliminarPrimerPaciente(int prioridad) {
	this->colaPP[prioridad - 1]->eliminar();
}

bool Servicio::estaVaciaPrioridad(int prioridad) {
	return this->colaPP[prioridad - 1]->isEmpty();
}

bool Servicio::estaVacia() {
	bool vacias = true;
	int i = 0;
	while (i < MAX_PRIORIDAD) {
		if (!this->colaPP[i]->isEmpty()) {
			vacias = false;
		}
		i++;
	}
	return vacias;
}

void Servicio::mostrarPrioridad(int prioridad) {
	this->colaPP[prioridad - 1]->mostrar();
}

void Servicio::mostrar() {
	for (int i = 0; i < MAX_PRIORIDAD; ++i) {
		this->colaPP[i]->mostrar();
	}
}

int Servicio::numPacientes(int prioridad) {
	return colaPP[prioridad - 1]->cuantos();
}

Servicio::~Servicio() {
// TODO Auto-generated destructor stub
	int i = 0;
	while (!this->colaPP[i]->isEmpty()) {
		delete this->colaPP[i];
	}
}

