#ifndef FIELD_HPP
#define FIELD_HPP

class Field
{
public:	
	Field(int w=1, int h=1);
	void printField(char ver_sep='|',char hor_sep='-');


private:
	int _w,_h;
	char _field[]; // taille encore inconnue

};

Field::Field(int w, int h) 
{
	// Trouver un moyen de créer _field alors qu'on recoit les variables 
	// de sa taille avec le constructeur :(
	_w = w, _h = h;
	char _field[w*h];
	for(int i=0;i<w*h;++i)
		_field[i]= {'A'};
}

void printXCharacters(char s, int x, bool endline=false)
{
	for(int i=0;i<x;++i)
		std::cout << s; 

	if(endline)
		std::cout << std::endl;
}

void Field::printField(char ver_sep,char hor_sep)
{
	for(int i=0;i<_w*_h;++i)
		std::cout << _field[i];
	std::cout << std::endl;

	printXCharacters(hor_sep, 2*_w+1, true);

	for(int i=0;i<_h;++i)
	{
		for(int j=0;j<_w;++j)
		{
			std::cout << _field[i+j*_w];
		}
		std::cout << std::endl;
		printXCharacters(hor_sep, 2*_w+1, true);
	}

}

#endif