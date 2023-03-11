/*
 * Informe.h
 *
 *  Created on: 6 mar 2023
 *      Author: Isaac Romanillos
 */

#ifndef INFORME_H_
#define INFORME_H_

#include "FechaYHora.h"
#include "Medico.h"
#include <iostream>
#include <string>

using namespace std;

class Informe {
private:
	string informe;
	FechaYHora hora;
	Medico *m;
public:
	Informe();
	Informe(string informe, const FechaYHora &fyh, Medico *m);
	Medico* obtenerMedicoInf();
	void mostrar();
	~Informe();
};

#endif /* INFORME_H_ */
