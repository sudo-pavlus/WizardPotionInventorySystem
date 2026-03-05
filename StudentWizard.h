#ifndef STUDENT_WIZARD_H
#define STUDENT_WIZARD_H

#include <string>
#include "Potion.h"

class StudentWizard
{
public:
	//Constructor and Destructor

	StudentWizard();
	StudentWizard(const std::string& name, const std::string& house);

	StudentWizard(const StudentWizard& other);
	StudentWizard& operator=(const StudentWizard& other);

	~StudentWizard();

	//Getters
	std::string getStudentName() const { return studentName; }
	std::string getHouse() const{ return house; }
	int getNumPotions() const { return numPotions; }

	//Functions
	void addPotion(const std::string& potionName, int strength);
	void removePotion(const std::string& potionName);
	int findPotionIndex(const std::string& potionName) const;
	const Potion& getPotion(int index) const;
	int getTotalStrength() const;



private:
	std::string studentName;
	std::string house;
	Potion* potions;
	int numPotions;
	
};


#endif


