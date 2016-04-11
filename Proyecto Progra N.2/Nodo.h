#ifndef Nodo_H
#define Nodo_H
#include <string>
using namespace std;

class Nodo
{
private:
	string data;
	Nodo* sigPtr;
public:
	Nodo(const string& info);
	string getData() const;
	void setData(const string& data);
	Nodo* getSigPtr() const;
	void setSigPtr(Nodo* sig_ptr);
};
#endif

