/*
 * PruebasListaMedicos.cpp
 *
 *  Created on: 2 abr 2023
 *      Author: Isaac Romanillos
 */

#include "PruebasListaMedicos.h"
#include "ListaMedicos.h"

void probarConstructorListaMedicos() {
	cout << "Inicio probarConstructorListaMedicos" << endl;
	ListaMedicos *lM = new ListaMedicos();
	if (!lM->isEmpty())
		cerr << "Error en el constructor por defecto" << endl;

	delete lM;
	cout << "Fin probarConstructorListaMedicos" << endl;
}

void probarInsertarListaMedicos() {
	cout << "Inicio probarInsertarListaMedicos" << endl;
	ListaMedicos *lM = new ListaMedicos();
	lM->insertar(new Medico());
	if (lM->isEmpty())
		cerr << "Error al insertar Medico" << endl;

	delete lM;
	cout << "Fin probarInsertarListaMedicos" << endl;
}

void probarBuscarMedico() {
	cout << "Inicio probarBuscarMedico" << endl;
	ListaMedicos *lM = new ListaMedicos();
	lM->insertar(new Medico("", "Fernandez", ""));
	if (lM->buscarMedico("Fernandez") == nullptr)
		cerr << "Error al buscar el Medico por apellido" << endl;

	delete lM;
	cout << "Fin probarBuscarMedico" << endl;
}

void probarBuscarMedicoEspecialidad() {
	cout << "Inicio probarBuscarMedicoEspecialidad" << endl;
	ListaMedicos *lM = new ListaMedicos();
	lM->insertar(new Medico("", "", "Neumología"));
	if (lM->buscarMedicoEspecialidad("Neumología") == nullptr)
		cerr << "Error al buscar el Medico por especialidad" << endl;

	delete lM;
	cout << "Fin probarBuscarMedicoEspecialidad" << endl;
}

void probarNumMedicosR() {
	cout << "Inicio probarNumMedicosR" << endl;
	ListaMedicos *lM = new ListaMedicos();
	lM->insertar(new Medico("", "", ""));
	lM->insertar(new Medico("", "", ""));
	lM->insertar(new Medico("", "", ""));

	if (lM->NumMedicosR() != 3)
		cerr << "Error al contar el numero de medicos de la lista" << endl;

	delete lM;
	cout << "Fin probarNumMedicosR" << endl;
}

void pruebasListaMedicos() {
	cout << "------------------------------------------------------" << endl;
	cout << "Inicio de las pruebas de la clase ListaMedicos" << endl;
	cout << "------------------------------------------------------" << endl;
	probarConstructorListaMedicos();
	probarInsertarListaMedicos();
	probarBuscarMedico();
	probarBuscarMedicoEspecialidad();
	probarNumMedicosR();
	cout << "------------------------------------------------------" << endl;
	cout << "Fin de las pruebas de la clase ListaMedicos" << endl;
	cout << "------------------------------------------------------" << endl;

}
