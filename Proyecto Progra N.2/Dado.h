#pragma once
#ifndef Dado_H
#define Dado_H
#include <iostream>
using namespace std;

class Dado
{
private:
	char caras[6];
	char* alpha;
public:
	Dado();
	void refrescar();
	char getDado(int pos);
	~Dado();
};
#endif

