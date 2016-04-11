#include "Diccionario.h"

Diccionario::Diccionario()
{
}

bool Diccionario::consultar(string str)
{
	dic.open("output.txt");
	string line = "";
	for (int i = 0; i < strlen(str.c_str()); i++)//transformar en minusculas
		line += tolower(str[i]);
	str = line;
	line = "";
	if (dic.is_open())
	{
		while (getline(dic, line))
		{
			if (line == str)
			{
				dic.close();
				return true;
			}
		}
		dic.close();
		return false;
	}
	cout << "No se ha podido encontrar el diccionario\n";
	system("pause");
	return false;
}

Diccionario::~Diccionario()
{
}

