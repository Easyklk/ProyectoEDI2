/*
 * Paciente.h
 *
 *  Created on: 6 feb 2023
 *      Author: Isaac Romanillos
 */

#ifndef PACIENTE_H_
#define PACIENTE_H_

#include"InformePacientes.h"
#include <string>
using namespace std;
enum Genero {
	Masculino, Femenino, Indefinido
};

class Paciente {
private:
	string nombre;
	string apellidos;
	string DNI;
	Genero genero;
	int edad;
	InformePacientes *pInformes;
public:
	// PRE: ---
	// DES: Constructor por defecto
	// COM: O(1)
	Paciente();

	Paciente(string nombre, string apellidos, string DNI, Genero genero,
			int edad);

	Paciente(const Paciente &orig);

	~Paciente();

	void setNombre(string nombre);
	void setApellidos(string apellidos);
	void setDNI(string dni);
	void setGenero(Genero genero);
	void setEdad(int edad);

	string getNombre();
	string getApellidos();
	string getDNI();
	int getGenero();
	int getEdad();

	void mostrarInfPac(string apellidosMedico);
	void mostrarInfPac();
	void aniadirInfor(Informe *inf);

	bool operator <(const Paciente &paciente);
	bool operator ==(const Paciente &paciente);
	bool operator >(const Paciente &paciente);

	void mostrar();
};

#endif /* PACIENTE_H_ */
