#pragma once
#ifndef Lista_H
#define Lista_H
#include <iostream>
#include "Nodo.h"
using namespace std;
#pragma once
class Lista{
	friend class Juego;
public:
   Lista() : primerPtr( 0 ), ultimoPtr( 0 ) {}
    ~Lista(){                                              // Metodo de eliminar nodos
		if ( !Vacio() ){    
			Nodo *actualPtr = primerPtr;
			Nodo *tempPtr;
			while ( actualPtr != 0 ){  
				tempPtr = actualPtr;
				actualPtr = actualPtr->sigPtr;
				delete tempPtr;
			}
		}
   }
	bool Vacio() const{
	   return primerPtr == 0; }


	 void Insertar( const string &valor ){                    // Insertando nodos
		Nodo *newPtr = obtNuevoNodo( valor );
		if ( Vacio() )
			primerPtr = ultimoPtr = newPtr;
		else{
			newPtr->sigPtr = primerPtr; 
			primerPtr = newPtr; }
	}

	  void imprimir() const{                         //Metodo de Imprimir 
	   if ( Vacio() ){
		   cout << "La lista esta vacia\n\n";
		   return; }
	   Nodo *actualPtr = primerPtr;
	   cout << "La lista es: ";
	   while ( actualPtr != 0 ){
		   cout<<actualPtr->getData()<<endl;
		   actualPtr = actualPtr->sigPtr; }
	   cout << "\n\n";
   }

	  bool buscar(string opc){                            //Buscando 
	   if ( Vacio() ){
		   return 0; }
	   Nodo *actualPtr = primerPtr;
	   while(actualPtr!=0){
		   if(actualPtr->getData()==opc)
			   return true;
		   else
			   actualPtr=actualPtr->sigPtr;
	   }
	   return false;
   }

private:
	Nodo *primerPtr;
	Nodo *ultimoPtr;
	Nodo *obtNuevoNodo( const string &valor ){
	   return new Nodo ( valor ); }
};
#endif