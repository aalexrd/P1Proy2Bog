#pragma once
#ifndef Diccionario_H
#define Diccionario_H
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
class Diccionario{
protected:
	ifstream dic;
public:
	Diccionario(){}
	bool consultar(string str){
		dic.open("output.txt");
		string line;
		string data=str;
		transform(data.begin(), data.end(), data.begin(), ::tolower); //transformar en minusculasrrrrr
		if(dic.is_open()){
			while(getline(dic, line)){
				if(line==data){
					dic.close();
					return true;
				}
			}
			dic.close();
			return false;
		}
		else
			cout<<"No se ha podido encontrar el diccionario\n";
	}
	~Diccionario(){}
};
#endif