#include <iostream>
#include <fstream>
#include <cstdlib> // Permet de vider le Terminal
#include <string> // Pour lecture de fichiers
#include "Personnage.hpp"
#include "Field.hpp"


using namespace std;

void clearTerminal(void);
bool isEmpty(ifstream &);
void initiateGame(void);
void startGame(void);


void clearTerminal(void)
{
	system("clear"); // if (system("CLS")) ???
}

bool isEmpty(ifstream& pFile)
{
    return pFile.peek() == ifstream::traits_type::eof();
}

void initiateGame(void)
{
	string name;
	cout << "Je ne crois pas qu'on se soit présenté... Qui es tu ? \nJe m'apelle : ";
	cin >> name;
	cout << "Bienvenue " << name ;
	ofstream info_file;
	
	Personnage heros = Personnage();
	heros.setName(name);
	clearTerminal();
	startGame();
}

/* Vérifie la présences des fichiers de sauvegardes */
void checkInfo(void)
{
	string line;
	ifstream file("info.txt");
	if (0)//(file.is_open())
	{
		cout << "pas vide";
		file.close();
	}
	else // Première partie ou fichier effacé
	{
		cout << "Fichier de sauvegarde introuvable :(\nDébut d'une nouvelle aventure !\n";
		ofstream info_file;
		info_file.open ("info.txt");
		info_file << "0";
  		info_file.close();
  		initiateGame();
	}
}

void startGame(void)
{
	cout << "- Zzzzzzz..." << endl << "Zzzzzzz..." << endl;
	cout << "- DEBOUT C'EST L'HEURE! J'ai besoin de toi en plus." << endl;
	cout << "- Quoi déjà? Bon okay" << endl;
	Field chambre = Field(6,4);
	chambre.printField();
}


int main(void)
{
	checkInfo();
	cout << endl; // au cas ou :)
	return 0;
}
