/*
 * ListaMedicos.h
 *
 *  Created on: 20 mar 2023
 *      Author: Isaac Romanillos
 */

#ifndef LISTAMEDICOS_H_
#define LISTAMEDICOS_H_
#include "ListaDPI.h"
#include "Medico.h"

class ListaMedicos {
private:
	ListaDPI<Medico*> *lMedicos;
	void mostrarR(ListaDPI<Medico*> *l);

public:
	ListaMedicos();
	void insertar(Medico *m);
	bool existe(string apellidos);
	Medico* buscarMedico(string apellidos);
	Medico* obtenerPrimerMedico();
	bool isEmpty();
	int NumMedico();
	void mostrarR();
	~ListaMedicos();
};

#endif /* LISTAMEDICOS_H_ */
