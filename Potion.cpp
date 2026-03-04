#include "Potion.h"
#include <iostream>

Potion::Potion()
{
}

Potion::Potion(std::string name, int str)
{
	potionName = name;
	strength = str;
}

Potion::~Potion()
{
}
