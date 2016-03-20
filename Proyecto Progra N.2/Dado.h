#pragma once
#ifndef Dado_H
#define Dado_H
#include <iostream>
#include <string>
#include <time.h>
using namespace std;
class Dado{
private:
	char caras[6];
public:
	Dado(){};
	void refrescar(const char *alpha){
retornar:
		for(int i=0; i<6; i++){
			int x=rand()%26;
			if(0<=x<26){
				caras[i]=alpha[x]; }
			else{
				goto retornar; }
		}
		for(int i=0; i<6; i++){
			for(int j=i+1; j<6; j++){
				if(caras[i]==caras[j]){
					goto retornar; }
			}
		}
	}
	char getDado(int pos){
		return caras[pos];
	}
	~Dado(){}
};
#endif