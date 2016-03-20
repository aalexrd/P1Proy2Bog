#pragma once
#ifndef Jugador_H
#define Jugador_H
#include <iostream>
#include <string>
using namespace std;
class Jugador{
protected:
	string nombre;
	int aciertos;
public:
	Jugador(){}
	Jugador(string nom){
		nombre=nom;
		aciertos=0;
	}
	void setAciertos(int aci){
		aciertos=aci;}
	void setNombre(string nom){
		nombre=nom; }
	string getNombre(){
		return nombre;}
	int getAciertos(){
		return aciertos;}
	~Jugador(){}
};
#endif