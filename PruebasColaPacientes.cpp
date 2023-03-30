/*
 * PruebasColaPacientes.cpp
 *
 *  Created on: 30 mar 2023
 *      Author: Isaac Romanillos
 */

#include "PruebasColaPacientes.h"
#include "ColaPacientes.h"

void probarConstructoresColaPacientes() {
	cout << "Inicio probarConstructoresColaPacientes" << endl;
	ColaPacientes c = ColaPacientes();
	if (c.cuantos() != 0)
		cerr << "Error en el constructor por defecto" << endl;
	cout << "Fin probarConstructoresColaPacientes" << endl;
}

void probarInsertarColaPacientes() {
	cout << "Inicio probarInsertarColaPacientes" << endl;
	ColaPacientes c = ColaPacientes();

	Paciente *p1 = new Paciente();
	Paciente *p2 = new Paciente();
	Paciente *p3 = new Paciente();

	c.insertar(p1);
	if (c.cuantos() != 1)
		cerr << "Error al insertar paciente nº1" << endl;

	c.insertar(p2);
	if (c.cuantos() != 2)
		cerr << "Error al insertar paciente nº2" << endl;

	c.insertar(p3);
	if (c.cuantos() != 3)
		cerr << "Error al insertar paciente nº3" << endl;

	cout << "Fin probarInsertarColaPacientes" << endl;
}

void probarObtenerColaPacientes() {
	cout << "Inicio probarObtenerColaPacientes" << endl;
	ColaPacientes c = ColaPacientes();

	Paciente *p1 = new Paciente();

	c.insertar(p1);

	if (c.obtener()->toString() != p1->toString())
		cerr << "Error al obtener el paciente" << endl;

	if (c.cuantos() != 0)
		cerr << "Error al eliminar el paciente" << endl;

	cout << "Fin probarObtenerColaPacientes" << endl;
}

void probarCuantosColaPacientes() {
	cout << "Inicio probarCuantosColaPacientes" << endl;
	ColaPacientes c = ColaPacientes();

	Paciente *p1 = new Paciente();
	Paciente *p2 = new Paciente();
	Paciente *p3 = new Paciente();

	c.insertar(p1);
	c.insertar(p2);
	c.insertar(p3);
	if (c.cuantos() != 3)
		cerr << "Error al contar los pacientes" << endl;

	cout << "Fin probarCuantosColaPacientes" << endl;
}

void pruebasColaPacientes() {
	cout << "------------------------------------------------------" << endl;
	cout << "Inicio de las pruebas de la clase ColaPacientes" << endl;
	cout << "------------------------------------------------------" << endl;
	probarConstructoresColaPacientes();
	probarInsertarColaPacientes();
	probarObtenerColaPacientes();
	probarCuantosColaPacientes();
	cout << "------------------------------------------------------" << endl;
	cout << "Fin de las pruebas de la clase ColaPacientes" << endl;
	cout << "------------------------------------------------------" << endl;
}
