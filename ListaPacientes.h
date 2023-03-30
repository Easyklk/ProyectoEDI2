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

	// PRE: ---
	// DES: muestra por consola todos los pacientes de la lista
	// COM: O(1)
	void mostrarR(ListaDPI<Paciente*> *l);

	// PRE: ---
	// DES: Devuelve el numero de pacientes de la lista
	// COM: O(1)
	int NumPacientesR(ListaDPI<Paciente*> *l);

public:

	// PRE: ---
	// DES: Constructor por defecto
	// COM: O(1)
	ListaPacientes();

	// PRE: p correctamente inicializado
	// DES: inserta un paciente en la lista
	// COM: O(n)
	void insertar(Paciente *p);

	// PRE: ---
	// DES: devuelve true/false si existe o no un paciente con ese DNI
	// COM: O(n)
	bool existe(string DNI);

	// PRE: ---
	// DES: devuelve el paciente con ese DNI
	// COM: O(1)
	Paciente* buscarPaciente(string DNI);

	// PRE: ---
	// DES: devuelve y elimina el primer paciente de la lista
	// COM: O(1)
	Paciente* eliminarPrimerPaciente();

	// PRE: ---
	// DES: Devuelve true/false si la lista esta o no vacia
	// COM: O(1)
	bool isEmpty();

	// PRE: ---
	// DES: Hace una llamada al metodo privado "NumPacientesR(ListaDPI<Paciente*> *l)"
	// COM: O(1)
	int NumPacientesR();

	// PRE: ---
	// DES: Hace una llamada al metodo privado "mostrarR(ListaDPI<Paciente*> *l)"
	// COM: O(1)
	void mostrarR();

	// PRE: ---
	// DES: Destructor
	// COM: O(1)
	~ListaPacientes();
};

#endif /* LISTAPACIENTES_H_ */
