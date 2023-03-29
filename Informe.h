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
	// PRE: ---
	// DES: Constructor por defecto
	// COM: O(1)
	Informe();

	// PRE: ---
	// DES: Constructor parametrizado
	// COM: O(1)
	Informe(string informe, const FechaYHora &fyh, Medico *m);

	// PRE: ---
	// DES: Devuelve el medico del informe
	// COM: O(1)
	Medico* obtenerMedicoInf();

	// PRE: ---
	// DES: muestra por consola todos los atributos del informe
	// COM: O(1)
	void mostrar();

	// PRE: ---
	// DES: Destructor
	// COM: O(1)
	~Informe();
};

#endif /* INFORME_H_ */
