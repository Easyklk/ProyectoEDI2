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
	this->lPacientes->moverPrimero();
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
	this->lPacientes->moverPrimero();
	if (!this->lPacientes->estaVacia()) {
		if (existe(DNI)) {
			p = lPacientes->consultar();
		}
	}
	return p;
}

Paciente* ListaPacientes::eliminarPrimerPaciente() {
	this->lPacientes->moverPrimero();
	Paciente *p = this->lPacientes->consultar();
	this->lPacientes->eliminar();
	return p;
}

bool ListaPacientes::isEmpty() {
	return this->lPacientes->estaVacia();
}

int ListaPacientes::NumPacientesR(ListaDPI<Paciente*> *l) {
	int totalMedicos = 0;
	if (!l->estaVacia()) {
		if (!l->alFinal()) {
			totalMedicos++;
			l->avanzar();
			totalMedicos += NumPacientesR(l);
		}
	}
	return totalMedicos;
}

int ListaPacientes::NumPacientesR() {
	int cuenta;
	this->lPacientes->moverPrimero();
	cuenta = NumPacientesR(this->lPacientes);
	return cuenta;
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

