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

Medico* ListaMedicos::buscarMedico(string apellidos) {
	Medico *m = nullptr;
	if (!this->lMedicos->estaVacia()) {
		if (existe(apellidos)) {
			m = lMedicos->consultar();
		}
	}
	return m;
}

Medico* ListaMedicos::obtenerPrimerMedico() {
	Medico *m = nullptr;
	this->lMedicos->moverPrimero();
	m = this->lMedicos->consultar();
	this->lMedicos->eliminar();
	return m;
}

bool ListaMedicos::isEmpty() {
	return this->lMedicos->estaVacia();
}

int ListaMedicos::NumMedico() {
	int total = 0;
	if (!this->lMedicos->estaVacia()) {
		if (!this->lMedicos->alFinal()) {
			total++;
			this->lMedicos->avanzar();
			NumMedico();
		}
	}
	return total;
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

