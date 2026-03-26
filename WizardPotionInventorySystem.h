//Name: Ibrahim Karakus
//Section: 1
//Student ID: 22403627
#ifndef WIZARD_POTION_INVENTORY_SYSTEM_H
#define WIZARD_POTION_INVENTORY_SYSTEM_H

#include <string>

//#include "SudentWizard.h"

#include "StudentWizard.h"
class WizardPotionInventorySystem
{
public:
	//Constructor and Destructor

	WizardPotionInventorySystem();
	~WizardPotionInventorySystem();

	//Functions

	void addStudentWizard(const std::string name, const std::string house);
	void removeStudentWizard(const std::string name);
	void brewPotion(const std::string studentName, const std::string potionName, const int strength);
	void discardPotion(const std::string studentName, const std::string potionName);
	void transferPotion(const std::string potionName, const std::string fromStudentName, const std::string toStudentName);
	void showAllStudentWizards() const;
	void showStudentWizard(const std::string name) const;
	void showPotion(const std::string potionName) const;

private:
	StudentWizard* students = nullptr;
	int numStudents = 0;
	int findStudentIndex(const std::string& name) const;
	void sortStudentsAlphabetically();
	int capacity = 0;
};

#endif
