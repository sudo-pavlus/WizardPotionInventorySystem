#ifndef POTION_H
#define POTION_H

#include <string>

class Potion
{
public:
	Potion();
	Potion(std::string name, int str);

	~Potion();

	// Getters
	const std::string& getPotionName() const { return potionName; }
	int getStrength() const { return strength; }

	// Setters
	void setPotionName(const std::string& name) { potionName = name; }
	void setStrength(int str) { strength = str; }

private:
	std::string potionName;
	int strength;

};

#endif