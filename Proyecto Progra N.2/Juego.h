#pragma once
#ifndef Juego_H
#define Juego_H
#include <iostream>
#include <sstream>
#include "Jugador.h"
#include "Dado.h"
#include "Diccionario.h"
#include "Lista.h"
#include <time.h> //random number
#include <thread>
#include <chrono>
using namespace std;

class Juego : public Diccionario
{
	Dado tablero[5][5];
	Jugador jugador1;
	Jugador jugador2;
	Lista palabras1;
	Lista palabras2;
	int partida;
public:
	Juego();
	void limpiar();
	bool verificarTablero(string str);
	void verificar(string str, Lista& palabras);
	void setw(char* i);
	void setw(string i);
	void imprimir();
	void compararListas();
	void interfaz();
	int readInt();
	string readString();
};
#endif

