/*
 * ListaMedicos.cpp
 *
 *  Created on: 20 mar 2023
 *      Author: Isaac Romanillos
 */

#include "ListaMedicos.h"

ListaMedicos::ListaMedicos() {
	this->lMedicos = new ListaDPI<Medico*>();
}

void ListaMedicos::insertar(Medico *m) {
	bool enc = false;
	this->lMedicos->moverPrimero();
	while (!this->lMedicos->alFinal() && !enc) {
		if (this->lMedicos->consultar()->getApellidos() > m->getApellidos())
			enc = true;
		else
			this->lMedicos->avanzar();
	}
	this->lMedicos->insertar(m);
}

bool ListaMedicos::existe(string apellidos) {
	bool enc = false;
	this->lMedicos->moverPrimero();
	if (!this->lMedicos->estaVacia()) {
		while (!this->lMedicos->alFinal() && !enc) {
			if (this->lMedicos->consultar()->getApellidos() == apellidos)
				enc = true;
			else
				this->lMedicos->avanzar();
		}
	}
	return enc;
}

bool ListaMedicos::existeEspecialidad(string especialidad) {
	bool enc = false;
	this->lMedicos->moverPrimero();
	if (!this->lMedicos->estaVacia()) {
		while (!this->lMedicos->alFinal() && !enc) {
			if (this->lMedicos->consultar()->getApellidos() == especialidad)
				enc = true;
			else
				this->lMedicos->avanzar();
		}
	}
	return enc;
}

Medico* ListaMedicos::buscarMedico(string apellidos) {
	Medico *m = nullptr;
	this->lMedicos->moverPrimero();
	if (!this->lMedicos->estaVacia()) {
		if (existe(apellidos)) {
			m = lMedicos->consultar();
		}
	}
	return m;
}

Medico* ListaMedicos::buscarMedicoEspecialidad(string especialidad) {
	Medico *m = nullptr;
	this->lMedicos->moverPrimero();
	if (!this->lMedicos->estaVacia()) {
		if (existeEspecialidad(especialidad)) {
			m = lMedicos->consultar();
		}
	}
	return m;
}

Medico* ListaMedicos::obtenerPrimerMedico() {
	this->lMedicos->moverPrimero();
	Medico *m = this->lMedicos->consultar();
	this->lMedicos->eliminar();
	return m;
}

bool ListaMedicos::isEmpty() {
	return this->lMedicos->estaVacia();
}

int ListaMedicos::NumMedicosR(ListaDPI<Medico*> *l) {
	int totalMedicos = 0;
	if (!l->estaVacia()) {
		if (!l->alFinal()) {
			totalMedicos++;
			l->avanzar();
			totalMedicos += NumMedicosR(l);
		}
	}
	return totalMedicos;
}

int ListaMedicos::NumMedicosR() {
	int cuenta;
	this->lMedicos->moverPrimero();
	cuenta = NumMedicosR(this->lMedicos);
	return cuenta;
}

void ListaMedicos::mostrarR(ListaDPI<Medico*> *l) {
	if (!l->alFinal()) {
		l->consultar()->mostrar();
		cout << " ";
		l->avanzar();
		mostrarR(l);
	}
}

void ListaMedicos::mostrarR() {
	if (!this->lMedicos->estaVacia()) {
		this->lMedicos->moverPrimero();
		mostrarR(this->lMedicos);
	}
}

ListaMedicos::~ListaMedicos() {
	delete this->lMedicos;
}

