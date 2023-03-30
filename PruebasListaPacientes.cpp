/*
 * PruebasListaPacientes.cpp
 *
 *  Created on: 30 mar 2023
 *      Author: Isaac Romanillos
 */

#include "PruebasListaPacientes.h"
#include "ListaPacientes.h"

void probarConstructorListaPacientes() {
	cout << "Inicio probarConstructorListaPacientes" << endl;
	ListaPacientes *lP = new ListaPacientes();
	if (!lP->isEmpty())
		cerr << "Error en el constructor por defecto" << endl;

	delete lP;
	cout << "Fin probarConstructorListaPacientes" << endl;
}

void probarInsertarListaPacintes() {
	cout << "Inicio probarInsertarListaPacintes" << endl;
	ListaPacientes *lP = new ListaPacientes();
	lP->insertar(new Paciente());
	if (lP->isEmpty())
		cerr << "Error al insertar paciente" << endl;

	delete lP;
	cout << "Fin probarInsertarListaPacintes" << endl;
}

void probarBuscarPaciente() {
	cout << "Inicio probarBuscarPaciente" << endl;
	ListaPacientes *lP = new ListaPacientes();
	lP->insertar(new Paciente("", "", "01010101A", Genero(0), 0));
	if (lP->buscarPaciente("01010101A") == nullptr)
		cerr << "Error al buscar paciente por DNI" << endl;

	delete lP;
	cout << "Fin probarBuscarPaciente" << endl;
}

void probarEliminarPrimerPaciente() {
	cout << "Inicio probarEliminarPrimerPaciente" << endl;
	ListaPacientes *lP = new ListaPacientes();
	lP->insertar(new Paciente("", "", "01010101A", Genero(0), 0));
	lP->eliminarPrimerPaciente();
	if (!lP->isEmpty())
		cerr << "Error al eliminar el primer paciente" << endl;

	delete lP;
	cout << "Fin probarEliminarPrimerPaciente" << endl;
}

void probarNumPacientesR() {
	cout << "Inicio probarNumPacientesR" << endl;
	ListaPacientes *lP = new ListaPacientes();
	lP->insertar(new Paciente("", "", "01010101A", Genero(0), 0));
	lP->insertar(new Paciente("", "", "01010101B", Genero(1), 0));
	lP->insertar(new Paciente("", "", "01010101C", Genero(2), 0));

	if (lP->NumPacientesR() != 3)
		cerr << "Error al contar el numero de pacientes de la lista" << endl;

	delete lP;
	cout << "Fin probarNumPacientesR" << endl;
}

void pruebasListaPacientes() {
	cout << "------------------------------------------------------" << endl;
	cout << "Inicio de las pruebas de la clase ListaPacientes" << endl;
	cout << "------------------------------------------------------" << endl;
	probarConstructorListaPacientes();
	probarInsertarListaPacintes();
	probarBuscarPaciente();
	probarEliminarPrimerPaciente();
	probarNumPacientesR();
	cout << "------------------------------------------------------" << endl;
	cout << "Fin de las pruebas de la clase ListaPacientes" << endl;
	cout << "------------------------------------------------------" << endl;
}
