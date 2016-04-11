#pragma once
#ifndef Lista_H
#define Lista_H
#include <iostream>
#include "Nodo.h"
using namespace std;

class Lista
{
private:
	Nodo* ultimoPtr;
	Nodo* primerPtr;
	Nodo* obtNuevoNodo(const string& valor);
public:
	Lista();
	~Lista();
	bool Vacio() const;
	void Insertar(const string& valor);
	void imprimir() const;
	bool buscar(string opc) const;
	Nodo* getPrimerPtr() const;
	void setPrimerPtr(Nodo* primer_ptr);
	Nodo* getUltimoPtr() const;
	void setUltimoPtr(Nodo* ultimo_ptr);
	
};
#endif

