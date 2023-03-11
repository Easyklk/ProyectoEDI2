/*
 * InformePacientes.cpp
 *
 *  Created on: 6 mar 2023
 *      Author: Isaac Romanillos
 */

#include "InformePacientes.h"

InformePacientes::InformePacientes() {
	// TODO Auto-generated constructor stub
	this->ptrInf = new Pila<Informe*>;

}

void InformePacientes::anadir(Informe *inf) {
}

void InformePacientes::mostrarR(Pila<Informe*> *ptrInf) {
	Informe *inf = nullptr;
	if (ptrInf->estaVacia()) {
		inf = ptrInf->getCima();
		cout << inf << " ";
		ptrInf->desapilar();
		mostrarR(ptrInf);
		ptrInf->apilar(inf);
	}
}

void InformePacientes::mostrarR() {
	this->mostrarR(this->ptrInf);
}

void InformePacientes::mostrar() {
	Pila<Informe*> *aux = new Pila<Informe*>();
	Informe *inf = nullptr;
	while (!this->ptrInf->estaVacia()) {
		inf = this->ptrInf->getCima();
		aux->apilar(inf);
		this->ptrInf->desapilar();
		cout << inf << " ";
	}
	cout << endl;
	while (!aux->estaVacia()) {
		inf = aux->getCima();
		this->ptrInf->apilar(inf);
		aux->desapilar();
	}
	delete aux;
}

void InformePacientes::mostrarInfMedico(string apellidos) {
//	Pila<Informe*> *aux = new Pila<Informe*>();
//	Informe *inf = nullptr;
//	Medico *m = nullptr;
//	while (!this->ptrInf->estaVacia()) {
//		inf = this->ptrInf->getCima();
//		aux->apilar(inf);
//		this->ptrInf->desapilar();
//		cout << inf << " ";
//	}
//	cout << endl;
//	while (!aux->estaVacia()) {
//		inf = aux->getCima();
//		this->ptrInf->apilar(inf);
//		aux->desapilar();
//	}
//	delete aux;
}

InformePacientes::~InformePacientes() {
// TODO Auto-generated destructor stub
	delete this->ptrInf;
}

