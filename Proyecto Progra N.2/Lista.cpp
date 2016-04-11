#include "Lista.h"

Nodo* Lista::obtNuevoNodo(const string& valor)
{
	return new Nodo(valor);
}

Lista::Lista(): ultimoPtr(nullptr), primerPtr(nullptr)
{
}

Lista::~Lista()
{ // Metodo de eliminar nodos
	if (!Vacio())
	{
		Nodo* actualPtr = primerPtr;
		Nodo* tempPtr;
		while (actualPtr != nullptr)
		{
			tempPtr = actualPtr;
			actualPtr = actualPtr->getSigPtr();
			delete tempPtr;
		}
	}
}

bool Lista::Vacio() const
{
	return primerPtr == nullptr;
}

void Lista::Insertar(const string& valor)
{ // Insertando nodos
	Nodo* newPtr = obtNuevoNodo(valor);
	if (Vacio())
		primerPtr = ultimoPtr = newPtr;
	else
	{
		newPtr->setSigPtr(primerPtr);
		primerPtr = newPtr;
	}
}

void Lista::imprimir() const
{ //Metodo de Imprimir 
	if (Vacio())
	{
		cout << "La lista esta vacia\n\n";
		return;
	}
	Nodo* actualPtr = primerPtr;
	cout << "La lista es: ";
	while (actualPtr != nullptr)
	{
		cout << actualPtr->getData() << endl;
		actualPtr = actualPtr->getSigPtr();
	}
	cout << "\n\n";
}

bool Lista::buscar(string opc) const
{ //Buscando 
	if (Vacio())
	{
		return 0;
	}
	Nodo* actualPtr = primerPtr;
	while (actualPtr != nullptr)
	{
		if (actualPtr->getData() == opc)
			return true;
		else
			actualPtr = actualPtr->getSigPtr();
	}
	return false;
}

Nodo* Lista::getPrimerPtr() const
{
	return primerPtr;
}

void Lista::setPrimerPtr(Nodo* primer_ptr)
{
	primerPtr = primer_ptr;
}

Nodo* Lista::getUltimoPtr() const
{
	return ultimoPtr;
}

void Lista::setUltimoPtr(Nodo* ultimo_ptr)
{
	ultimoPtr = ultimo_ptr;
}
