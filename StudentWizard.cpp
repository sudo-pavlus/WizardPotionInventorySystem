#include "StudentWizard.h"
#include <iostream>

int main() {


	return 0;
}

StudentWizard::StudentWizard()
{
}

StudentWizard::StudentWizard(std::string name, std::string house)
{
	studentName = name;
	this->house = house;
	potion = nullptr;
	numPotions = 0;
}


