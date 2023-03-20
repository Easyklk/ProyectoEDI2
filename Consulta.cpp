/*
 * Consulta.cpp
 *
 *  Created on: 13 feb 2023
 *      Author: Isaac Romanillos
 */

#include "Consulta.h"
#include "Medico.h"
#include "Paciente.h"
#include "fechayhora.h"

Consulta::Consulta() {
	// TODO Auto-generated constructor stub
	p = nullptr;
	m = nullptr;
	tipo = Pendiente;
}

Consulta::Consulta(Paciente *p) {
	this->p = p;
	m = nullptr;
	tipo = Pendiente;
}

Consulta::Consulta(Paciente *p, Medico *m) {
	this->p = p;
	this->m = m;
	tipo = Pendiente;
}

Consulta::Consulta(Paciente *p, Medico *m, const TipoConsulta &tc,
		const FechaYHora &f) {
	this->p = p;
	this->m = m;
	tipo = tc;
	hora = f;
}

Paciente* Consulta::getPaciente() {
	return this->p;
}

Medico* Consulta::getMedico() {
	return this->m;
}

FechaYHora Consulta::getHora() {
	return this->hora;
}

TipoConsulta Consulta::getTipo() {
	return this->tipo;
}

void Consulta::asignarMedico(Medico *m) {
	this->m = m;
}

void Consulta::agendarFecha(FechaYHora f) {
}

void Consulta::mostrar() {
	string tipo;
	if (this->tipo == Pendiente) {
		tipo = "Pendiente";
	} else if (this->tipo == Urgente) {
		tipo = "Urgente";
	} else {
		tipo = "Externa";
	}

	cout << "Consulta{ ";
	p->mostrar();
	m->mostrar();
	cout << "Tipo: " << tipo << ", ";
	hora.mostrar();
	cout << " }" << endl << endl;

}

bool Consulta::operator <(const Consulta &consulta) {
	return (this->hora < consulta.hora);
}

bool Consulta::operator ==(const Consulta &consulta) {
	return (this->hora == consulta.hora);

}

bool Consulta::operator >(const Consulta &consulta) {
	return (this->hora > consulta.hora);
}

string Consulta::toString() {
//	string a = p->toString();
//	return ("Consulta{ " + this->m->toString() + " Fecha y hora: "
//			+ this->hora.toString() + " } \n");
}

Consulta::~Consulta() {
	// TODO Auto-generated destructor stub
}

