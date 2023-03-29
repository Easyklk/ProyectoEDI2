/*
 * InformePacientes.h
 *
 *  Created on: 6 mar 2023
 *      Author: Isaac Romanillos
 */

#ifndef INFORMEPACIENTES_H_
#define INFORMEPACIENTES_H_

#include "Pila.h"
#include "Informe.h"
#include "Medico.h"
#include <fstream>

class InformePacientes {
private:
	Pila<Informe*> *ptrInf;
	void mostrarR(Pila<Informe*> *ptrInf);
public:
	InformePacientes();
	void anadir(Informe *inf);
	void mostrar();
	void mostrarR();
	~InformePacientes();
};

#endif /* INFORMEPACIENTES_H_ */
