/*
 * Hospital.h
 *
 *  Created on: 27 feb 2023
 *      Author: Isaac Romanillos
 */

#ifndef HOSPITAL_H_
#define HOSPITAL_H_

#include "Paciente.h"
#include "Medico.h"
#include "Informe.h"
#include "ListaPacientes.h"
#include "ListaMedicos.h"
#include "Servicio.h"

class Hospital {
private:
	string nombre;
	ListaPacientes *lP;
	ListaMedicos *lM;
	Servicio *sv;

	// PRE: ---
	// DES: carga desde un fichero todos los pacientes en la lista de pacientes
	// COM: O(n)
	void cargarPaciente();

	// PRE: ---
	// DES: carga desde un fichero todos los medicos en la lista de medicos
	// COM: O(n)
	void cargarMedicos();

	// PRE: ---
	// DES: carga desde un fichero todos los informes en la lista de informes
	// COM: O(n)
	void cargarInformes();

public:

	// PRE: ---
	// DES: Constructor por defecto
	// COM: O(1)
	Hospital();

	// PRE: ---
	// DES: Constructor por defecto
	// COM: O(1)
	Hospital(string nombre, string nomServicio);

	// PRE: ---
	// DES: devuelve this->nombre
	// COM: O(1)
	string getNombre();

	// PRE: ---
	// DES: devuelve this->sv
	// COM: O(1)
	Servicio* getServicio();

	string obtenerFechaHora();

	// PRE: ---
	// DES: muestra por consola todos los pacientes
	// COM: O(n)
	void mostrarPacientes();

	// PRE: ---
	// DES: muestra por consola todos los medicos
	// COM: O(n)
	void mostrarMedicos();

	// PRE: ---
	// DES: muestra por consola todas las consultas
	// COM: O(n)
	void mostrarPacientesEspera();

	// PRE: ---
	// DES: muestra por consola el nº total de pacientes, medicos y consultas
	// COM: O(n)
	void mostrarEstadisticas();

	// PRE: que exista un paciente con ese DNI
	// DES: devuelve el paciente con el DNI facilitado
	// COM: O(n)
	Paciente* buscarPaciente(string DNI);

	// PRE: que exista un medico con ese apellido
	// DES: devuelve el Medico con el apellido facilitado
	// COM: O(n)
	Medico* buscarMedico(string apellidos);

	Medico* buscarMedicoEspecialidad(string especialidad);

	// PRE: que exista alguna consulta con ese DNI de paciente
	// DES: devuelve la consulta con el DNI de paciente facilitado
	// COM: O(n)
//	Informe* buscarInforme(string DNI);

	// PRE: ---
	// DES: crea un informe para un paciente
	// COM: O(n)
	void generarInforme();

	// PRE: ---
	// DES: Destructor
	// COM: O(1)
	~Hospital();

};

#endif /* HOSPITAL_H_ */
