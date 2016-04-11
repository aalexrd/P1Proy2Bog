#include "Nodo.h"

Nodo::Nodo(const string& info): data(info), sigPtr(nullptr)
{
}

string Nodo::getData() const
{
	return data;
}

void Nodo::setData(const string& data)
{
	this->data = data;
}

Nodo* Nodo::getSigPtr() const
{
	return sigPtr;
}

void Nodo::setSigPtr(Nodo* sig_ptr)
{
	sigPtr = sig_ptr;
}
