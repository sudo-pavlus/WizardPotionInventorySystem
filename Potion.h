#ifndef POTION_H
#define POTION_H

#include <string>

class Potion
{
public:
	Potion();
	Potion(std::string name, int str);

	~Potion();
private:
	std::string potionName;
	int strength;

};

#endif