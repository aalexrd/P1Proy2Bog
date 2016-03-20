#include <string>
#ifndef Nodo_H
#define Nodo_H
using namespace std;
class Nodo{
   friend class Lista;
   friend class Juego;
public:
   Nodo( const string &info ) : data( info ), sigPtr( NULL ) { }
   string getData() const { 
   return data; }
private:
   string data;
   Nodo *sigPtr;
}; 
#endif