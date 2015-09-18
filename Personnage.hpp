#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP

class Personnage
{
public:
	Personnage(void);
	void set_name(string name) {_name = name;};
	string get_name(void) {return _name;}
private:
	string _name;
};

#endif