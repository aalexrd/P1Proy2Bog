#pragma once
#ifndef Jugador_H
#define Jugador_H
#include <iostream>
using namespace std;

class Jugador
{
protected:
	string nombre;
	int aciertos;
public:
	Jugador();
	Jugador(string nom);
	void setAciertos(int aci);
	void setNombre(string nom);
	string getNombre() const;
	int getAciertos() const;
	~Jugador();
};
#endif

