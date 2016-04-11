#include "Juego.h"

Juego::Juego()
{
	srand(time(nullptr));
	limpiar();
}

void Juego::limpiar()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			Dado da;
			da.refrescar();
			tablero[i][j] = da;
		}
	}
}

bool Juego::verificarTablero(string str)
{
	if (strlen(str.c_str()) < 3)
	{
		cout << "Deben ser palabras de 3 o mas letras" << endl;
		system("pause");
		return false;
	}
	string temp = ""; //ir formando la palabra
	int k = 0;
	bool esta = false;
	while (k < strlen(str.c_str()))
	{ //ver si estan las letras en el tablero
		esta = false;
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				if (str[k] == tablero[i][j].getDado(partida))
				{
					esta = true;
					break;
				}
		k++;
		if (!esta)
			return false;
	}
	k = 0;
	char tableroCopia[5][5] = {{NULL}};
	for (int i = 0; i < 5; i++) //llenar tableroCopia con las caras de los dados
		for (int j = 0; j < 5; j++)
			tableroCopia[i][j] = tablero[i][j].getDado(partida);
	bool trayectoTablero[5][5] = {{false}};
	bool encontro = false, ret = false;
	int z = 0, w = 0, cw = 0, cz = 0; //cw y cz es donde guarda las coordenadas anteriores
retornar:
	for (int i = z; i < 5; i++)
	{
		for (int j = w; j < 5; j++)
		{
			if (tableroCopia[i][j] == str[k]) //si encuentra la letra
			{
				encontro = false;
				trayectoTablero[i][j] = true;
				if (ret == false)
					temp.push_back(tableroCopia[i][j]);
				if (temp == str)
					return true;
				if (j < 4 && tableroCopia[i][j + 1] == str[k + 1] && !trayectoTablero[i][j + 1])
				{ //horizontal ->
					encontro = true;
					k++;
					ret = false;
					z = i , w = j + 1 , cz = i , cw = j;
					goto retornar;
				}
				if (j > 0 && tableroCopia[i][j - 1] == str[k + 1] && !trayectoTablero[i][j - 1])
				{ //horizontal <-
					encontro = true;
					k++;
					ret = false;
					z = i , w = j - 1 , cz = i , cw = j;
					goto retornar;
				}
				if (i < 4 && tableroCopia[i + 1][j] == str[k + 1] && !trayectoTablero[i + 1][j])
				{ //vertical abajo
					encontro = true;
					k++;
					ret = false;
					z = i + 1 , w = j , cz = i , cw = j;
					goto retornar;
				}
				if (i > 0 && tableroCopia[i - 1][j] == str[k + 1] && !trayectoTablero[i - 1][j])
				{ //vertical arriba
					encontro = true;
					k++;
					ret = false;
					z = i - 1 , w = j , cz = i , cw = j;
					goto retornar;
				}
				if (i < 4 && j < 4 && tableroCopia[i + 1][j + 1] == str[k + 1] && !trayectoTablero[i + 1][j + 1])
				{ //diagonal "\"->
					encontro = true;
					ret = false;
					k++;
					z = i + 1 , w = j + 1 , cz = i , cw = j;
					goto retornar;
				}
				if (i > 0 && j > 0 && tableroCopia[i - 1][j - 1] == str[k + 1] && !trayectoTablero[i - 1][j - 1])
				{ //diagonal "\"<-
					encontro = true;
					k++;
					ret = false;
					z = i - 1 , w = j - 1 , cz = i , cw = j;
					goto retornar;
				}
				if (i > 0 && j < 4 && tableroCopia[i - 1][j + 1] == str[k + 1] && !trayectoTablero[i - 1][j + 1])
				{ //diagonal "/"->
					encontro = true;
					k++;
					ret = false;
					z = i - 1 , w = j + 1 , cz = i , cw = j;
					goto retornar;
				}
				if (i < 4 && j > 0 && tableroCopia[i + 1][j - 1] == str[k + 1] && !trayectoTablero[i + 1][j - 1])
				{ //diagonal "/"<-
					encontro = true;
					k++;
					ret = false;
					z = i + 1 , w = j - 1 , cz = i , cw = j;
					goto retornar;
				}
				if (!encontro)
				{
					if (temp != "")
						temp.pop_back();
					tableroCopia[i][j] = NULL;
					z = cz , w = cw;
					if (k == 0)
						ret = false;
					else
						ret = true;
					if (k > 0)
						k--;
					goto retornar;
				}
			}
		}
	}
	return false;
}

void Juego::verificar(string str, Lista& palabras)
{
	string temp = "";
	for (int i = 0; i < strlen(str.c_str()); i++)
		temp.push_back(tolower(str[i]));
	if (consultar(temp))
		if (palabras.buscar(temp))
		{
			cout << "La palabra ya se ingreso anteriormente.\n";
			system("pause");
		}
		else if (!verificarTablero(temp))
		{
			cout << "\nLa palabra no existe en el tablero\n";
			system("pause");
		}
		else
			palabras.Insertar(temp);
	else
	{
		cout << "\nLa palabra no existe en el diccionario\n";
		system("pause");
	}
}

void Juego::setw(char* i)
{
	int l = strlen(i);
	int pos = (int)((80 - l) / 2);
	for (int j = 0; j < pos; j++)
		cout << " ";
	cout << i;
}

void Juego::setw(string i)
{
	char* cstr = new char[strlen(i.c_str())];
	strcpy_s(cstr, strlen(i.c_str()) + 1, i.c_str());
	setw(cstr);
}

void Juego::imprimir()
{
	for (int i = 0; i < 5; i++)
	{
		if (i == 0)
				setw("\332\304\304\304\302\304\304\304\302\304\304\304\302\304\304\304\302\304\304\304\277\n");
		if (i != 0 && i != 5)
				setw("\303\304\304\304\305\304\304\304\305\304\304\304\305\304\304\304\305\304\304\304\264\n");
		stringstream line;
		for (int j = 0; j < 5; j++)
		{
			line << "\263 " << tablero[i][j].getDado(partida) << " ";
			if (j == 4)
				line << "\263\n";
		}
		setw(line.str());
		if (i == 4)
			setw("\300\304\304\304\301\304\304\304\301\304\304\304\301\304\304\304\301\304\304\304\331\n");
	}
}

void Juego::compararListas()
{
	setw("Vamos a ver cuales palabras se repitieron es sus listas:\n");
	for (Nodo* actualPtr = palabras1.getPrimerPtr(); actualPtr != nullptr; actualPtr = actualPtr->getSigPtr())
	{
		for (Nodo* actualPtr2 = palabras2.getPrimerPtr(); actualPtr2 != nullptr; actualPtr2 = actualPtr2->getSigPtr())
		{
			if (actualPtr->getData() == actualPtr2->getData())
			{
				setw(actualPtr->getData());
				cout << endl;
				actualPtr->getData() = "" , actualPtr2->getData() = "";
			}
		}
	}
	for (Nodo* actualPtr = palabras1.getPrimerPtr(); actualPtr != nullptr; actualPtr = actualPtr->getSigPtr())
	{
		int i = strlen(actualPtr->getData().c_str());
		int puntos = 0;
		if (i == 3 || i == 4)
			puntos = 1;
		if (i == 5)
			puntos = 2;
		if (i == 6)
			puntos = 3;
		if (i == 7)
			puntos = 4;
		if (i >= 8)
			puntos = 11;
		jugador1.setAciertos(jugador1.getAciertos() + puntos); //suma los puntos al jugador
	}
	for (Nodo* actualPtr = palabras2.getPrimerPtr(); actualPtr != nullptr; actualPtr = actualPtr->getSigPtr())
	{
		int i = strlen(actualPtr->getData().c_str());
		int puntos = 0;
		if (i == 3 || i == 4)
			puntos = 1;
		if (i == 5)
			puntos = 2;
		if (i == 6)
			puntos = 3;
		if (i == 7)
			puntos = 4;
		if (i >= 8)
			puntos = 11;
		jugador2.setAciertos(jugador2.getAciertos() + puntos); //suma los puntos al jugador
	}
}

void Juego::interfaz()
{
	system("Color F0");
	bool seguir = true;
	setw("Digite el nombre del jugador 1\n");
	jugador1.setNombre(readString());
	setw("Digite el nombre del jugador 2\n");
	jugador2.setNombre(readString());
	partida = 0; // cuando llega a la partida 6 se vuelven a reiniciar las letras del dado
	for (int i = 0; seguir; i++)
	{
		partida++;
		system("cls");
		system("Color F3");
		setw("Jugador: " + jugador1.getNombre());
		cout << endl;
		setw("Se recomienda que apunte en una hoja las palabras encontradas\n");
		imprimir(); //tablero para el primer jugador
		cout << endl;
		setw("Tiene 3 minutos para encontrar las palabras luego podra digitarlas\n");
		for (int k = 180; k > 0; k--)//suspender cualquier actividad durante 3 minutos
		{
			if (k <= 30) 
			{
				if (k == 30)
					setw("Te quedan 30 segundos\n");
				cout << k << " ";
			}
			this_thread::sleep_for(chrono::seconds(1));
		}
		system("cls");
		setw("\nIngrese las palabras que encontro " + jugador1.getNombre() + '\n');
		for (int k = 0; seguir; k++)
		{
			verificar(readString(), palabras1);
			system("cls");
			setw("Quiere ingresar otra palabra? Si o No? ");
			if (readString()[0] == 'N' || 'n')
				seguir = false;
		}
		seguir = true;
		system("cls");
		system("Color F6");
		setw("Jugador: " + jugador2.getNombre());
		setw("\nSe recomienda que apunte en una hoja las palabras encontradas\n");
		imprimir(); //tablero para el segundo jugador
		setw("\nTiene 3 minutos para encontrar las palabras luego podra digitarlas\n");
		for (int k = 180; k > 0; k--)//suspender cualquier actividad durante 3 minutos
		{
			if (k <= 30)
			{
				if (k == 30)
					setw("Te quedan 30 segundos\n");
				cout << k << " ";
			}
			this_thread::sleep_for(chrono::seconds(1));
		}
		system("cls");
		setw("\nIngrese las palabras que encontro " + jugador2.getNombre() + '\n');
		for (int k = 0; seguir; k++)
		{
			verificar(readString(), palabras2);
			system("cls");
			setw("Quiere ingresar otra palabra? Si o No? ");
			if (readString()[0] == 'N' || 'n')
				seguir = false;
		}
		seguir = true;
		system("cls");
		compararListas(); //muestra y elimina iguales en listas y suma puntos a los jugadores
		system("pause");
		system("cls");
		setw("Desea jugar otra ronda? Si o No? ");
		if (readString()[0] == 'N' || 'n')
		{
			seguir = false;
		}
		if (partida == 5)
		{
			for (int k = 0; k < 5; k++)
				for (int t = 0; t < 5; t++)
					tablero[k][t].refrescar();
			partida = 0;
		}
	}
	if (jugador1.getAciertos() == jugador2.getAciertos())
		setw("Es un empate! \n");
	else
		if (jugador1.getAciertos() > jugador2.getAciertos())
			setw("Felicidades " + jugador1.getNombre() + " has ganado.\n");
		else
			setw("Felicidades " + jugador2.getNombre() + " has ganado.\n");
	system("cls");
	setw("Gracias por jugar.\n");
	system("pause");
}

int Juego::readInt()
{
	string i;
k:
	getline(cin, i);
	for (int k = 0; k < strlen(i.c_str()); k++)
	{
		if (isdigit(i[k]) == false)
		{
			cout << "Digite lo que se le solicit\242, intente de nuevo\n";
			goto k;
		}
	}
	return atoi(i.c_str());
}

string Juego::readString()
{
	string i;
	getline(cin, i);
	return i;
}

