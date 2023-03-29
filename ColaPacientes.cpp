/*
 * ColaPacientes.cpp
 *
 *  Created on: 11 mar 2023
 *      Author: Isaac Romanillos
 */

#include "ColaPacientes.h"

ColaPacientes::ColaPacientes() {
	this->cp = new Cola<Paciente*>();
}

void ColaPacientes::insertar(Paciente *p) {
	this->cp->encolar(p);
}
void ColaPacientes::eliminar() {
	this->cp->desencolar();
}

Paciente* ColaPacientes::obtener() {
	//PDF Cito textualmente: 3. Obtener el primer paciente de la cola y eliminarlo.
	Paciente *p = this->cp->getPrimero();
	this->cp->desencolar();
	return p;
}

bool ColaPacientes::isEmpty() {
	return this->cp->estaVacia();
}

void ColaPacientes::mostrar() {
	Cola<Paciente*> *aux = new Cola<Paciente*>();
	Paciente *p = nullptr;
	while (!this->cp->estaVacia()) {
		p = this->cp->getPrimero();
		aux->encolar(p);
		this->cp->desencolar();
		p->mostrar();
		cout << endl;

	}
	while (!aux->estaVacia()) {
		p = aux->getPrimero();
		this->cp->encolar(p);
		aux->desencolar();
	}
	delete aux;
}

int ColaPacientes::cuantos() {
	int total = 0;
	Cola<Paciente*> *aux = new Cola<Paciente*>();
	Paciente *p = nullptr;
	while (!this->cp->estaVacia()) {
		p = this->cp->getPrimero();
		aux->encolar(p);
		this->cp->desencolar();
		total++;
	}

	while (!aux->estaVacia()) {
		p = aux->getPrimero();
		this->cp->encolar(p);
		aux->desencolar();
	}
	delete aux;
	return total;

}
ColaPacientes::~ColaPacientes() {
	// TODO Auto-generated destructor stub
	delete this->cp;
}

