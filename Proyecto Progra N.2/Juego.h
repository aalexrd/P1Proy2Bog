#pragma once
#ifndef Juego_H
#define Juego_H
#include <iostream>
#include <string>
#include "Jugador.h"
#include "Dado.h"
#include "Diccionario.h"
#include "Lista.h"
#include <Windows.h>
using namespace std;
class Juego{
private:
	Dado tablero[5][5];
	Jugador jugador1;
	Jugador jugador2;
	Diccionario dic;
	char *alpha;
	int partida;
public:
	Juego(){
		alpha="ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
		srand(time(NULL));
		std::cout<<"Cargando...";
		for(int i=0; i<5; i++){
			for(int j=0; j<5; j++){
				Dado da;
				Sleep(20);
				da.refrescar(alpha);
				tablero[i][j]=da;
			}
		}
		std::system("cls");
	}
	void limpiar(){
		Juego();
	}
	bool verificarTablero(string str){
		int i=0;
		int cont=0;
		while(str[i]!=NULL){	//cuantas letras tiene la palabra
			cont++;
			i++;
		}
		if(i<3){
			std::cout<<"Deben ser palabras de 3 o mas letras"<<endl;
			return false;
		}
		string palabra= str;		//separar letras de la palabra
		string temp="";		//ir formando la palabra
		int k=0;
		bool esta=false;
		while(k<cont){
			esta=false;
			for(int i=0; i<5; i++){
				for(int j=0; j<5; j++){
					if(palabra[k]==tablero[i][j].getDado(partida)){
						esta=true;
						break;}
				}
			}
			k++;
			if(esta==false){
				return false;
			}
		}
		k=0;
		char tableroCopia[5][5]={{NULL}};
		for(int i=0; i<5; i++){
			for(int j=0; j<5; j++){
				tableroCopia[i][j]=tablero[i][j].getDado(partida);
			}}
		bool trayectoTablero[5][5]={{false}};
		bool encontro=false, ret=false;
		int z=0, w=0, cw=0, cz=0;
		retornar:
		for(int i=z; i<5; i++){
			for(int j=w; j<5; j++){
				if(tableroCopia[i][j]==palabra[k]){
					encontro=false;
					trayectoTablero[i][j]=true;
					if(ret==false){
						temp.push_back(tableroCopia[i][j]); }
					if(temp==str){
						return true; }
					if((tableroCopia[i+1][j+1]==palabra[k+1])&&(trayectoTablero[i+1][j+1]!=true)&&(j<=3)&&(i<=3)){	//diagonal "\">
						encontro=true;
						ret=false;
						k++;
						z=i+1, w=j+1, cz=i, cw=j;
						goto retornar;
					}
					if((tableroCopia[i][j+1]==palabra[k+1])&&(trayectoTablero[i][j+1]!=true)&&(j<=3)){ //horizontal ->
						encontro=true;
						k++;
						ret=false;
						z=i, w=j+1, cz=i, cw=j;
						goto retornar;
					}
					if((tableroCopia[i][j-1]==palabra[k+1])&&(trayectoTablero[i][j-1]!=true)&&(j>=1)){ //horizontal <-
						encontro=true;
						k++;
						ret=false;
						z=i, w=j-1, cz=i, cw=j;
						goto retornar;
					}
					if((tableroCopia[i+1][j]==palabra[k+1])&&(trayectoTablero[i+1][j]!=true)&&(i<=3)){ //vertical abajo
						encontro=true;
						k++;
						ret=false;
						z=i+1, w=j, cz=i, cw=j;
						goto retornar;
					}
					if((tableroCopia[i-1][j]==palabra[k+1])&&(trayectoTablero[i-1][j]!=true)&&(i>=1)){ //vertical arriba
						encontro=true;
						k++;
						ret=false;
						z=i-1, w=j, cz=i, cw=j;
						goto retornar;
					}
					if((tableroCopia[i-1][j-1]==palabra[k+1])&&(trayectoTablero[i-1][j-1]!=true)&&(i>=1)&&(i>=1)){	//diagonal "\"<
						encontro=true;
						k++;
						ret=false;
						z=i-1, w=j-1, cz=i, cw=j;
						goto retornar;
					}
					if((tableroCopia[i-1][j+1]==palabra[k+1])&&(trayectoTablero[i-1][j+1]!=true)&&(i>=1)&&(j<=3)){	//diagonal "/">
						encontro=true;
						k++;
						ret=false;
						z=i-1, w=j+1, cz=i, cw=j;
						goto retornar;
					}
					if((tableroCopia[i+1][j-1]==palabra[k+1])&&(trayectoTablero[i+1][j-1]!=true)&&(i<=3)&&(j>=1)){	//diagonal "/"<
						encontro=true;
						k++;
						ret=false;
						z=i+1, w=j-1, cz=i, cw=j;
						goto retornar;
					}
					if(encontro==false){
						if(temp!=""){
							temp.erase(temp.length()-1); }
						tableroCopia[i][j]=NULL;
						z=cz, w=cw;
						if(k==0){
							ret=false; }
						else {
							ret=true; }
						if(k>0){
							k--; }
						goto retornar;
					}
				}
			}
		}
		return false;
		}
	void verificar(string str, Lista &palabras){
		if(dic.consultar(str)==true){
			if(palabras.buscar(str)==true){
				std::cout<<"La palabra ya se ingreso anteriormente.\n";
				return;
			}
			else{
				if(verificarTablero(str)==false){
					cout<<"\nLa palabra no existe en el tablero\n";
					return;
				}
				else{
					palabras.Insertar(str);
				}
			}
		}
		else
			cout<<"\nLa palabra no existe en el diccionario\n";
	}
	void imprimir(){
		for(int i=0; i<5; i++)
			for(int j=0; j<5; j++){
				std::cout<<tablero[i][j].getDado(partida)<<" ";
				if(j==4){
					std::cout<<endl; }
			}
	}
	void compararListas(Lista &palabras1, Lista &palabras2){
		std::cout<<"Vamos a ver cuales palabras se repitieron es sus listas: "<<endl;
		for(Nodo *actualPtr=palabras1.primerPtr; actualPtr!=NULL; actualPtr=actualPtr->sigPtr){
			for(Nodo *actualPtr2=palabras2.primerPtr; actualPtr2!=NULL; actualPtr2=actualPtr2->sigPtr){
				if(actualPtr->data==actualPtr2->data){
					std::cout<<actualPtr->data<<endl;
					actualPtr->data="", actualPtr2->data="";
				}
			}
		}
		for(Nodo *actualPtr=palabras1.primerPtr; actualPtr!=NULL; actualPtr=actualPtr->sigPtr){
			int i=0;
			while(actualPtr->data[i]!=NULL){	//cuantas letras tiene la palabra
			i++; }
			int puntos=0;
			if(i==3||i==4)
				puntos=1;
			if(i==5)
				puntos=2;
			if(i==6)
				puntos=3;
			if(i==7)
				puntos=4;
			if(i>=8)
				puntos=11;
			jugador1.setAciertos(jugador1.getAciertos()+puntos); //suma los puntos al jugador
		}
		for(Nodo *actualPtr=palabras2.primerPtr; actualPtr!=NULL; actualPtr=actualPtr->sigPtr){
			int i=0;
			while(actualPtr->data[i]!=NULL){	//cuantas letras tiene la palabra
			i++; }
			int puntos=0;
			if(i==3||i==4)
				puntos=1;
			if(i==5)
				puntos=2;
			if(i==6)
				puntos=3;
			if(i==7)
				puntos=4;
			if(i>=8)
				puntos=11;
			jugador2.setAciertos(jugador2.getAciertos()+puntos); //suma los puntos al jugador
		}
	}

	void interfaz(){
		HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof cfi;
		cfi.nFont = 0;
		cfi.dwFontSize.X = 0;
		cfi.dwFontSize.Y = 16;
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_NORMAL;
		wcscpy_s(cfi.FaceName, L"Consolas");
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
		std::cout<<"Cuantas partidas desea jugar?\n";                //el numero de partidas que los usuarios quieren jugar
		int partidas;
		while (!(std::cin >> partidas)) {
			std::cout << "No ingreso un numero, intente de nuevo\n";
			std::cin.clear();   
			std::cin.ignore();  
		}
		SetConsoleTextAttribute(outcon, FOREGROUND_GREEN);
		std::cout<<"Digite el nombre del jugador 1"<<endl;
		string nombre;
		std::cin>>nombre;
		jugador1.setNombre(nombre);
		SetConsoleTextAttribute(outcon, FOREGROUND_RED);
		std::cout<<"Digite el nombre del jugador 2"<<endl;
		std::cin>>nombre;
		jugador2.setNombre(nombre);
		partida=-1;                                            // cuando llega a la partida 6 se vuelven a reiniciar las letras del dado
		for(int i=0;i<partidas;i++){
			partida++;
			std::system("cls");
			SetConsoleTextAttribute(outcon, FOREGROUND_GREEN);
			std::cout<<"Jugador: "<<jugador1.getNombre();
			std::cout<<"\nSe recomienda que apunte en una hoja las palabras encontradas\n";
			imprimir();                                      //tablero para el primer jugador
			std::cout<<"\nTiene 3 minutos para encontrar las palabras luego podra digitarlas\n";
			for(int k=180; k>=0; k--){
				if(k<=10)
					std::cout<<k<<" ";
				Sleep(1000);
			}
			std::system("cls");
			std::cout<<"Ingrese cuantas palabras encontro "<<jugador1.getNombre()<<endl;
			int cant;
			while (!(std::cin >> cant)) {
				std::cout << "No ingreso un numero, intente de nuevo\n";
				std::cin.clear();   
				std::cin.ignore();  
			}
			Lista palabras1;
			std::cout<<"\nIngrese las palabras en mayuscula y con cuidado, si no estas no se encontraran\n";
			for(int k=0; k<cant; k++){
				string pal;
				std::cin>>pal;
				verificar(pal, palabras1);
			}
			std::system("cls");
			SetConsoleTextAttribute(outcon, FOREGROUND_RED);
			std::cout<<"Jugador: "<<jugador2.getNombre();
			std::cout<<"\nSe recomienda que apunte en una hoja las palabras encontradas\n";
			imprimir();                                      //tablero para el segundo jugador
			std::cout<<"\nTiene 3 minutos para encontrar las palabras luego podra digitarlas\n";
			for(int k=180; k>=0; k--){
				if(k<=10)
					std::cout<<k<<" ";
				Sleep(1000);
			}
			std::system("cls");
			std::cout<<"Ingrese cuantas palabras encontro "<<jugador2.getNombre()<<endl;
			while (!(std::cin >> cant)) {
				std::cout << "No ingreso un numero, intente de nuevo\n";
				std::cin.clear();   
				std::cin.ignore();  
			}
			Lista palabras2;
			std::cout<<"\nIngrese las palabras en mayuscula y con cuidado, si no estas no se encontraran\n";
			for(int k=0; k<cant; k++){
				string pal;
				std::cin>>pal;
				verificar(pal, palabras2);
			}
			std::system("cls");
			SetConsoleTextAttribute(outcon, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			compararListas(palabras1, palabras2); //elimina iguales en listas y suma puntos a los jugadores
			std::system("pause");
			std::system("cls");
			if(partida==5){
				for(int k=0;k<partidas;k++){
					for(int t=0;t<partidas;t++){
						tablero[k][t].refrescar(alpha);
					}
				}
				partida=-1;
			}
		}
		if(jugador1.getAciertos()==jugador2.getAciertos()){
			std::cout<<"Es un empate! \n"; }
		else{
		if(jugador1.getAciertos()>jugador2.getAciertos()){
			SetConsoleTextAttribute(outcon, FOREGROUND_GREEN);
			std::cout<<"Felicidades "<<jugador1.getNombre()<<" has ganado.\n"; }
		else {
			SetConsoleTextAttribute(outcon, FOREGROUND_RED);
			std::cout<<"Felicidades "<<jugador2.getNombre()<<" has ganado.\n"; }
		}
		std::cout<<"Desea jugar otra ronda?\n";
		bool si;
		std::cout<<"Digite el numero de su seleccion:\n1 = Si\n0 = No\n";
		std::cin>>si;
		if(si==true){
			interfaz(); }
		else
			std::cout<<"Gracias por jugar."<<endl;
	}
	};
#endif
