#ifndef STUDENT_WIZARD_H
#define STUDENT_WIZARD_H

#include <string>
#include "Potion.h"

class StudentWizard
{
public:
	//Constructor and Destructor

	StudentWizard();
	StudentWizard(std::string name, std::string house);

	~StudentWizard();


private:
	std::string studentName;
	std::string house;
	Potion* potion;
	int numPotions;
	
};


#endif


