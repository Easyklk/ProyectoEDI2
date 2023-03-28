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
}

Servicio::Servicio(string especialidad) {
	for (int i = 0; i < MAX_PRIORIDAD; ++i) {
		this->colaPP[i] = new ColaPacientes();
	}
	this->especialidad = especialidad;
}

string Servicio::getEspecialidad() {
	return this->especialidad;
}

void Servicio::insertar(int prioridad, Paciente *p) {
	this->colaPP[prioridad - 1]->insertar(p);
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

