/*
 * ColaPacientes.h
 *
 *  Created on: 11 mar 2023
 *      Author: Isaac Romanillos
 */

#ifndef COLAPACIENTES_H_
#define COLAPACIENTES_H_
#include "Cola.h"
#include "Paciente.h"

class ColaPacientes {
private:
	Cola<Paciente*> *cp;
public:
	ColaPacientes();
	void insertar(Paciente *p);
	Paciente* obtener();
	bool isEmpty();
	void mostrar();
	int cuantos();
	~ColaPacientes();
};

#endif /* COLAPACIENTES_H_ */
