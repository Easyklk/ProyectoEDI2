/*
 * ListaPacientes.cpp
 *
 *  Created on: 20 mar 2023
 *      Author: Isaac Romanillos
 */

#include "ListaPacientes.h"

ListaPacientes::ListaPacientes() {
	this->lPacientes = new ListaDPI<Paciente*>();
}

void ListaPacientes::insertar(Paciente *p) {
	bool enc = false;
	this->lPacientes->moverPrimero();
	while (!this->lPacientes->alFinal() && !enc) {
		if (this->lPacientes->consultar()->getDNI() > p->getDNI())
			enc = true;
		else
			this->lPacientes->avanzar();
	}
	this->lPacientes->insertar(p);
}

bool ListaPacientes::existe(string DNI) {
	bool enc = false;
	if (!this->lPacientes->estaVacia()) {
		while (!this->lPacientes->alFinal() && !enc) {
			if (this->lPacientes->consultar()->getDNI() == DNI) {
				enc = true;
			} else
				this->lPacientes->avanzar();
		}
	}
	return enc;
}

Paciente* ListaPacientes::buscarPaciente(string DNI) {
	Paciente *p = nullptr;
	if (!this->lPacientes->estaVacia()) {
		if (existe(DNI)) {
			p = lPacientes->consultar();
		}
	}
	return p;
}

Paciente* ListaPacientes::obtenerPrimerPaciente() {
	Paciente *p = nullptr;
	this->lPacientes->moverPrimero();
	p = this->lPacientes->consultar();
	this->lPacientes->eliminar();
	return p;
}

bool ListaPacientes::isEmpty() {
	return this->lPacientes->estaVacia();
}

int ListaPacientes::NumPacientes() {
	int total = 0;
	if (!this->lPacientes->estaVacia()) {
		if (!this->lPacientes->alFinal()) {
			total++;
			this->lPacientes->avanzar();
			NumPacientes();
		}
	}
	return total;
}

void ListaPacientes::mostrarR(ListaDPI<Paciente*> *l) {
	if (!l->alFinal()) {
		l->consultar()->mostrar();
		cout << " ";
		l->avanzar();
		mostrarR(l);
	}
}
void ListaPacientes::mostrarR() {
	if (!this->lPacientes->estaVacia()) {
		this->lPacientes->moverPrimero();
		mostrarR(this->lPacientes);
	}
}

ListaPacientes::~ListaPacientes() {
	delete this->lPacientes;
}

