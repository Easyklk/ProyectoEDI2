/*
 * PruebasInformePacientes.cpp
 *
 *  Created on: 3 abr 2023
 *      Author: Isaac Romanillos
 */

#include "PruebasInformePacientes.h"
#include "InformePacientes.h"
#include "Paciente.h"

void probarConstructoresInformePacientes() {
	cout << "Inicio probarConstructoresInformePacientes" << endl;
	InformePacientes *iP = new InformePacientes();

	if (iP->contarInf() != 0)
		cerr << "Error en el constructor por defecto" << endl;
	delete iP;
	cout << "Fin probarConstructoresInformePacientes" << endl;
}

void probarAnadirInformePacientes() {
	cout << "Inicio probarAnadirInformePacientes" << endl;
	InformePacientes *iP = new InformePacientes();

	Informe *inf1 = new Informe();
	Informe *inf2 = new Informe();
	Informe *inf3 = new Informe();

	iP->anadir(inf1);
	if (iP->contarInf() != 1)
		cerr << "Error al insertar el informe nº1" << endl;

	iP->anadir(inf2);
	if (iP->contarInf() != 2)
		cerr << "Error al insertar el informe nº2" << endl;

	iP->anadir(inf3);
	if (iP->contarInf() != 3)
		cerr << "Error al insertar el informe nº3" << endl;

	delete iP;
	delete inf1;
	delete inf2;
	delete inf3;
	cout << "Fin probarAnadirInformePacientes" << endl;
}

void pruebasInformePacientes() {
	cout << "------------------------------------------------------" << endl;
	cout << "Inicio de las pruebas de la clase InformePacientes" << endl;
	cout << "------------------------------------------------------" << endl;
	probarConstructoresInformePacientes();
	probarAnadirInformePacientes();
	cout << "------------------------------------------------------" << endl;
	cout << "Fin de las pruebas de la clase InformePacientes" << endl;
	cout << "------------------------------------------------------" << endl;
}
