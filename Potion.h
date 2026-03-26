//Name: Ibrahim Karakus
//Section: 1
//Student ID: 22403627
#ifndef POTION_H
#define POTION_H

#include <string>

class Potion
{
public:
	Potion();
	Potion(const std::string& name, int str); 
	~Potion();

	// Getters
	const std::string& getPotionName() const { return potionName; }
	int getStrength() const { return strength; }

private:
	std::string potionName;
	int strength;

};

#endif