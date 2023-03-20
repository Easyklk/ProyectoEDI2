/*
 * ListaPacientes.h
 *
 *  Created on: 20 mar 2023
 *      Author: Isaac Romanillos
 */

#ifndef LISTAPACIENTES_H_
#define LISTAPACIENTES_H_
#include "ListaDPI.h"
#include "Paciente.h"

class ListaPacientes {
private:
	ListaDPI<Paciente*> *lPacientes;
	void mostrarR(ListaDPI<Paciente*> *l);

public:
	ListaPacientes();
	void insertar(Paciente *p);
	bool existe(string DNI);
	Paciente* buscarPaciente(string DNI);
	Paciente* obtenerPrimerPaciente();
	bool isEmpty();
	int NumPacientes();
	void mostrarR();
	~ListaPacientes();
};

#endif /* LISTAPACIENTES_H_ */
