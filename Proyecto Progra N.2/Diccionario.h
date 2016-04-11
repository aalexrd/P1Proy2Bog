#pragma once
#ifndef Diccionario_H
#define Diccionario_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Diccionario
{
protected:
	ifstream dic;
public:
	Diccionario();

	bool consultar(string str);

	~Diccionario();
};
#endif

