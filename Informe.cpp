/*
 * Informe.cpp
 *
 *  Created on: 6 mar 2023
 *      Author: Isaac Romanillos
 */

#include "Informe.h"
#include "FechaYHora.h"
#include "Medico.h"

Informe::Informe() {
	this->informe = "";
	this->hora = FechaYHora();
	this->m = new Medico();
}

Informe::Informe(string informe, const FechaYHora &fyh, Medico *m) {
	this->informe = informe;
	this->hora = fyh;
	this->m = m;
}

Medico* Informe::obtenerMedicoInf() {
	return this->m;
}

void Informe::mostrar() {
//	cout
//			<< "Informe { Informe: " + this->informe + ", Fecha y hora: "
//					+ this->hora + ", Medico: " + this->m + "}" << endl;
}

Informe::~Informe() {
	// TODO Auto-generated destructor stub
}

