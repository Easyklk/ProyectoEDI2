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

	// PRE: ---
	// DES: muestra por consola todos los informes de la pila
	// COM: O(1)
	void mostrarR(Pila<Informe*> *ptrInf);
public:

	// PRE: ---
	// DES: Constructor por defecto
	// COM: O(1)
	InformePacientes();

	// PRE: inf correctamente inicializado
	// DES: inserta un informe en la pila
	// COM: O(1)
	void anadir(Informe *inf);

	// PRE: ---
	// DES: muestra por consola todos los pacientes de la pila
	// COM: O(n)
	void mostrar();

	// PRE: ---
	// DES: devuelve el numero de informes
	// COM: O(n)
	int contarInf();

	// PRE: ---
	// DES: Hace una llamada al metodo privado "mostrarR(Pila<Informe*> *ptrInf *ptrInf)"
	// COM: O(1)
	void mostrarR();

	// PRE: ---
	// DES: Destructor
	// COM: O(1)
	~InformePacientes();
};

#endif /* INFORMEPACIENTES_H_ */
