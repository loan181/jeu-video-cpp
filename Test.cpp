#include <iostream>
#include <fstream>
#include <cstdlib> // Permet de vider le Terminal
#include <string> // Pour lecture de fichiers


using namespace std;

void clearTerminal(void)
{
	system("clear"); // if (system("CLS")) ???
}

bool isEmpty(ifstream& pFile)
{
    return pFile.peek() == ifstream::traits_type::eof();
}

void checkInfo(void)
{
	string line;
	ifstream file ("info.txt");
	if (file.is_open())
	{
		cout << "pas vide";
	file.close();
	}
	else // Première partie où fichier effacé
	{
		cout << "Fichier de sauvegarde introuvable :(\nDébut d'une nouvelle aventure !";
		ofstream info_file;
		info_file.open ("info.txt");
		info_file << "0";
  		info_file.close();
	}


}

int checkInfo(void)
{
	start();
	cout << endl; // au cas ou :)
	return 0;
}
