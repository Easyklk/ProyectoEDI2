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

	// PRE: ---
	// DES: muestra por consola todos los medicos de la lista
	// COM: O(1)
	void mostrarR(ListaDPI<Medico*> *l);

	// PRE: ---
	// DES: Devuelve el numero de medicos de la lista
	// COM: O(1)
	int NumMedicosR(ListaDPI<Medico*> *l);

public:

	// PRE: ---
	// DES: Constructor por defecto
	// COM: O(1)
	ListaMedicos();

	// PRE: p correctamente inicializado
	// DES: inserta un medico en la lista
	// COM: O(n)
	void insertar(Medico *m);

	// PRE: ---
	// DES: devuelve true/false si existe o no un medico con ese apellido
	// COM: O(n)
	bool existe(string apellidos);

	// PRE: ---
	// DES: devuelve true/false si existe o no un medico con esa especialidad
	// COM: O(n)
	bool existeEspecialidad(string especialidad);

	// PRE: ---
	// DES: devuelve el medico con ese apellidos
	// COM: O(1)
	Medico* buscarMedico(string apellidos);

	// PRE: ---
	// DES: devuelve el medico con esa especialidad
	// COM: O(1)
	Medico* buscarMedicoEspecialidad(string especialidad);

	// PRE: ---
	// DES: devuelve y elimina el primer medico de la lista
	// COM: O(1)
	Medico* obtenerPrimerMedico();

	// PRE: ---
	// DES: Devuelve true/false si la lista esta o no vacia
	// COM: O(1)
	bool isEmpty();

	// PRE: ---
	// DES: Hace una llamada al metodo privado "NumMedicosR(ListaDPI<Medico*> *l)"
	// COM: O(1)
	int NumMedicosR();

	// PRE: ---
	// DES: Hace una llamada al metodo privado "mostrarR(ListaDPI<Medico*> *l)"
	// COM: O(1)
	void mostrarR();

	// PRE: ---
	// DES: Destructor
	// COM: O(1)
	~ListaMedicos();
};

#endif /* LISTAMEDICOS_H_ */
