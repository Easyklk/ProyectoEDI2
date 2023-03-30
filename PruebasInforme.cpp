/*
 * PruebasInforme.cpp
 *
 *  Created on: 30 mar 2023
 *      Author: Isaac Romanillos
 */

#include "PruebasInforme.h"
#include "Informe.h"
#include "FechaYHora.h"

void probarConstructorInforme() {
	cout << "Inicio probarConstructoresGenericVov" << endl;
	Informe c;
	if (c.toString()
			!= "Informe{ Texto: , Fecha y hora: 0/0/0 0:0 Medico{ Nombre: , Apellidos: , Especialidad:  }}")
		cerr << "Error en el constructor por defecto" << endl;

	Medico *m = new Medico();
	Informe c1("Texto", FechaYHora(), m);
	if (c1.toString()
			!= "Informe{ Texto: Texto, Fecha y hora: 0/0/0 0:0 Medico{ Nombre: , Apellidos: , Especialidad:  }}")
		cerr << "Error en el constructor parametrizado" << endl;

	cout << "Fin probarConstructoresGenericVov" << endl;
}

void probarObtenerMedicoInf() {
	cout << "Inicio probarObtenerMedicoInf" << endl;

	Medico *m = new Medico();
	Informe c1("Texto", FechaYHora(), m);
	if (c1.obtenerMedicoInf()->toString() != m->toString())
		cerr << "Error en al obtener el medico del informe" << endl;

	cout << "Fin probarObtenerMedicoInf" << endl;
}

void pruebasInforme() {
	cout << "------------------------------------------------------" << endl;
	cout << "Inicio de las pruebas de la clase Informe" << endl;
	cout << "------------------------------------------------------" << endl;
	probarConstructorInforme();
	probarObtenerMedicoInf();
	cout << "------------------------------------------------------" << endl;
	cout << "Fin de las pruebas de la clase Informe" << endl;
	cout << "------------------------------------------------------" << endl;
}
