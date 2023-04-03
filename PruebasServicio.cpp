/*
 * PruebasServicio.cpp
 *
 *  Created on: 2 abr 2023
 *      Author: Isaac Romanillos
 */

#include "PruebasServicio.h"
#include "Servicio.h"

void probarConstructorServicio() {
	cout << "Inicio probarConstructorServicio" << endl;
	Servicio *sv = new Servicio();
	if (sv->getMedico() != nullptr || sv->getEspecialidad() != ""
			|| !sv->estaVacia())
		cerr << "Error en el constructor por defecto" << endl;

	Servicio *sv1 = new Servicio("Neumología");
	if (sv1->getMedico() != nullptr || sv1->getEspecialidad() != "Neumología"
			|| !sv1->estaVacia())
		cerr << "Error en el constructor parametrizado" << endl;

	if (sv1->getMedico() != nullptr)
		cerr << "Error al obtener el medico" << endl;

	if (sv1->getEspecialidad() != "Neumología")
		cerr << "Error al obtener la especialidad" << endl;

	sv->setMedico(new Medico());
	if (sv->getMedico() == nullptr)
		cerr << "Error al modificar el medico del servicio" << endl;

	delete sv;
	delete sv1;
	cout << "Fin probarConstructorServicio" << endl;
}

void probarInsertarPacienteServicio() {
	cout << "Inicio probarInsertarPacienteServicio" << endl;
	Servicio *sv = new Servicio();
	sv->insertar(2, new Paciente("", "", "01010101B", Genero(0), 0));
	if (sv->estaVaciaPrioridad(2) || sv->estaVacia())
		cerr << "Error al insertar Paciente en Servicio" << endl;

	delete sv;
	cout << "Fin probarInsertarPacienteServicio" << endl;
}

void probarObtenerPrimerPaciente() {
	cout << "Inicio probarObtenerPrimerPaciente" << endl;
	Servicio *sv = new Servicio();
	sv->insertar(1, new Paciente("", "", "", Genero(0), 0));
	Paciente *p = sv->obtenerPrimerPaciente(1);
	if (p == nullptr)
		cerr << "Error al obtener primer paciente" << endl;

	delete sv;
	cout << "Fin probarObtenerPrimerPaciente" << endl;
}

void probarEstaVaciaPrioridad() {
	cout << "Inicio estaVaciaPrioridad" << endl;
	Servicio *sv = new Servicio();
	if (!sv->estaVaciaPrioridad(1))
		cerr << "Error la cola con prioridad 0 SI deberia estar vacia" << endl;

	sv->insertar(2, new Paciente("", "", "", Genero(0), 0));
	if (sv->estaVaciaPrioridad(2))
		cerr << "Error la cola con prioridad 0 NO deberia estar vacia" << endl;

	delete sv;
	cout << "Fin estaVaciaPrioridad" << endl;
}

void probarNumPacientesServicio() {
	cout << "Inicio numPacientesServicio" << endl;
	Servicio *sv = new Servicio();
	if (sv->numPacientes(2) != 0)
		cerr
				<< "Error el numero de pacientes de la cola con prioridad 1 deberia 0"
				<< endl;

	sv->insertar(3, new Paciente("", "", "", Genero(0), 0));
	sv->insertar(3, new Paciente("", "", "", Genero(0), 0));
	sv->insertar(3, new Paciente("", "", "", Genero(0), 0));
	if (sv->numPacientes(3) != 3)
		cerr
				<< "Error el numero de pacientes de la cola con prioridad 3 deberia 3"
				<< endl;
	delete sv;
	cout << "Fin numPacientesServicio" << endl;
}

void pruebasServicio() {
	cout << "------------------------------------------------------" << endl;
	cout << "Inicio de las pruebas de la clase Servicio" << endl;
	cout << "------------------------------------------------------" << endl;
	probarConstructorServicio();
	probarInsertarPacienteServicio();
	probarObtenerPrimerPaciente();
	probarEstaVaciaPrioridad();
	probarNumPacientesServicio();
	cout << "------------------------------------------------------" << endl;
	cout << "Fin de las pruebas de la clase Servicio" << endl;
	cout << "------------------------------------------------------" << endl;

}
