/*
 * Servicio.h
 *
 *  Created on: 11 mar 2023
 *      Author: Isaac Romanillos
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_

#include "ColaPacientes.h"
#include <string>

using namespace std;

const int MAX_PRIORIDAD = 5; 		//1..5
class Servicio {
private:
	string especialidad;
	ColaPacientes *colaPP[MAX_PRIORIDAD];
	Medico *m;
public:

	// PRE: ---
	// DES: Constructor por defecto
	// COM: O(n)
	Servicio();

	// PRE: ---
	// DES: Constructor parametrizado
	// COM: O(n)
	Servicio(string especialidad);

	// PRE: ---
	// DES: devuelve this->especialidad
	// COM: O(1)
	string getEspecialidad();

	// PRE: ---
	// DES: devuelve this->m
	// COM: O(1)
	Medico* getMedico();

	// PRE: ---
	// DES: modifica this->m = m
	// COM: O(1)
	void setMedico(Medico *m);

	// PRE: p correctamente inicializado
	// DES: inserta un paciente en la lista
	// COM: O(n)
	void insertar(int prioridad, Paciente *p);

	// PRE: ---
	// DES: Devuelve el primer paciente de una cola especifica
	// COM: O(1)
	Paciente* obtenerPrimerPaciente(int prioridad);

	// PRE: ---
	// DES: Devuelve true/false si la cola especifica esta o no vacia
	// COM: O(1)
	bool estaVaciaPrioridad(int prioridad);

	// PRE: ---
	// DES: Devuelve true/false si todas las colas estan o no vacia
	// COM: O(1)
	bool estaVacia();

	// PRE: ---
	// DES: muestra por consola todos los pacientes de una cola especifica
	// COM: O(1)
	void mostrarPrioridad(int prioridad);

	// PRE: ---
	// DES: muestra por consola todos los pacientes de la cola
	// COM: O(n)
	void mostrar();

	// PRE: ---
	// DES: Devuelve el numero de pacientes de la cola especifica
	// COM: O(1)
	int numPacientes(int prioridad);

	// PRE: ---
	// DES: Destructor
	// COM: O(n)
	~Servicio();
};

#endif /* SERVICIO_H_ */
