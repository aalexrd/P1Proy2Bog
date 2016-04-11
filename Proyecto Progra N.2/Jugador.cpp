#include "Jugador.h"

Jugador::Jugador()
{
}

Jugador::Jugador(string nom)
{
	nombre = nom;
	aciertos = 0;
}

void Jugador::setAciertos(int aci)
{
	aciertos = aci;
}

void Jugador::setNombre(string nom)
{
	nombre = nom;
}

string Jugador::getNombre() const
{
	return nombre;
}

int Jugador::getAciertos() const
{
	return aciertos;
}

Jugador::~Jugador()
{
}
