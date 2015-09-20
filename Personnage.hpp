#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP

class Personnage
{
public:
	Personnage(void) {};
	void setName(std::string str) {_name=str;}
private:
	std::string _name;
	int money=0;//,xp=0,max_hp=10,hp=max_hp,strength=1,attack=1,defense=1;
};

#endif