#include "Dado.h"

Dado::Dado()
{
	alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}

void Dado::refrescar()
{
	for (int i = 0; i < 6; i++)
	{
		int x = rand() % 26;
		if (0 <= x < 26)
		{
			caras[i] = alpha[x];
		}
		else
		{
			refrescar();
		}
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = i + 1; j < 6; j++)
		{
			if (caras[i] == caras[j])
			{
				refrescar();
			}
		}
	}
}

char Dado::getDado(int pos)
{
	return caras[pos];
}

Dado::~Dado()
{
}

