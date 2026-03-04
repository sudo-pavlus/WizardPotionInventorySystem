#include "WizardPotionInventorySystem.h"
#include "StudentWizard.h"
#include <iostream>
WizardPotionInventorySystem::WizardPotionInventorySystem()
{
}

WizardPotionInventorySystem::~WizardPotionInventorySystem()  
{
    delete[] students;
}

void WizardPotionInventorySystem::addStudentWizard(const std::string name, const std::string house)
{
    if (findStudentIndex(name) != -1) {
        std::cout << "Cannot add student wizard. Student wizard " << name << " already exists." << std::endl;
        return;
    }
    StudentWizard newStudent(name, house);
    StudentWizard* temp = new StudentWizard[numStudents + 1];
    for (int i = 0; i < numStudents; i++) {
        temp[i] = students[i];
    }
    temp[numStudents] = newStudent;
    delete[] students;
    students = temp;
    numStudents++;
    sortStudentsAlphabetically();

    std::cout << "Added student wizard " << name << "." << std::endl;
}

void WizardPotionInventorySystem::removeStudentWizard(const std::string name)
{
    int index = findStudentIndex(name);
	if (index == -1) {
        std::cout << "Cannot remove student wizard. Student wizard " << name << " does not exist." << std::endl;
        return;
    }
    StudentWizard* temp = new StudentWizard[numStudents - 1];
    for (int i = 0, j = 0; i < numStudents; i++) {
        if (i != index) {
            temp[j++] = students[i];
        }
    }
    delete[] students;
    students = temp;
    numStudents--;
	std::cout << "Removed student wizard " << name << "." << std::endl;

}

void WizardPotionInventorySystem::brewPotion(const std::string studentName, const std::string potionName, int strength)
{
    // TODO: implement
}

void WizardPotionInventorySystem::discardPotion(const std::string studentName, const std::string potionName)
{
    // TODO: implement
}

void WizardPotionInventorySystem::transferPotion(const std::string potionName, const std::string fromStudentName, const std::string toStudentName)
{
    // TODO: implement
}

void WizardPotionInventorySystem::showAllStudentWizards() const
{
    std::cout << "Student wizards in the system:" << std::endl;
    if (numStudents == 0) {
        std::cout << "None" << std::endl;
        return;
    }
    for (int i = 0; i < numStudents; ++i) {
        std::cout << students[i].getStudentName()
                  << ", House: " << students[i].getHouse() 
                  <<", "<<students[i].getNumPotions() 
                  <<" potion(s), "
                  <<students[i].getTotalStrength()<<" total strength."
                  << std::endl;
    }
}
void WizardPotionInventorySystem::sortStudentsAlphabetically() {
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - i - 1; j++) {
            if (students[j].getStudentName() > students[j + 1].getStudentName()) {
                StudentWizard temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void WizardPotionInventorySystem::showStudentWizard(const std::string name) const
{
    // TODO: implement
}

void WizardPotionInventorySystem::showPotion(const std::string potionName) const
{
    // TODO: implement
}

int WizardPotionInventorySystem::findStudentIndex(const std::string& name) const {
    for (int i = 0; i < numStudents; i++) {
        if (students[i].getStudentName() == name) {
            return i;
        }
    }
    return -1;
}
