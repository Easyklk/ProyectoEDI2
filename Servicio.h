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
	Servicio();
	Servicio(string especialidad);

	string getEspecialidad();
	void setMedico(Medico *m);
	Medico* getMedico();

	void insertar(int prioridad, Paciente *p);
	Paciente* obtenerPrimerPaciente(int prioridad);

	bool estaVaciaPrioridad(int prioridad);
	bool estaVacia();
	void mostrarPrioridad(int prioridad);
	void mostrar();
	int numPacientes(int prioridad);
	~Servicio();
};

#endif /* SERVICIO_H_ */
