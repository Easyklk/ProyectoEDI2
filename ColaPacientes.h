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
	// PRE: ---
	// DES: Constructor por defecto
	// COM: O(1)
	ColaPacientes();

	// PRE: p correctamente inicializado
	// DES: inserta un paciente en la cola
	// COM: O(1)
	void insertar(Paciente *p);

	// PRE: ---
	// DES: devuelve y elimina el primer paciente de la cola
	// COM: O(1)
	Paciente* obtener();

	// PRE: ---
	// DES: elimina el primer paciente de la cola
	// COM: O(1)
	void eliminar();

	// PRE: ---
	// DES: Devuelve true/false si la cola esta o no vacia
	// COM: O(1)
	bool isEmpty();

	// PRE: ---
	// DES: muestra por consola todos los pacientes de la cola
	// COM: O(n)
	void mostrar();

	// PRE: ---
	// DES: Devuelve el numero de pacientes de la cola
	// COM: O(n)
	int cuantos();

	// PRE: ---
	// DES: Destructor
	// COM: O(1)
	~ColaPacientes();
};

#endif /* COLAPACIENTES_H_ */
