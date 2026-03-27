#include "WizardPotionInventorySystem.h"
#include "StudentWizard.h"
#include <iostream>
using namespace std;


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
        //std::cout << "Cannot add student wizard. Student wizard " << name << " already exists." << std::endl;
        return;
    }

    StudentWizard newStudent(name, house);

	if (capacity == 0) {
        capacity = 1;
        students = new StudentWizard[capacity];
    }
    else if(numStudents == capacity){
        capacity *= 2;
        StudentWizard* temp = new StudentWizard[capacity];
        for(int i = 0; i < numStudents; i++){
            temp[i] = students[i];
        }
        delete[] students;
        students = temp;
        
    }
    int pos = numStudents;
    while (pos > 0 && students[pos - 1].getStudentName() > name) {
        students[pos] = students[pos - 1];
        pos--;
    }
    students[pos] = newStudent;
    numStudents++;

    //StudentWizard newStudent(name, house);
    //StudentWizard* temp = new StudentWizard[numStudents + 1];
    //for (int i = 0; i < numStudents; i++) {
    //    temp[i] = students[i];
    //}
    //temp[numStudents] = newStudent;
    //delete[] students;
    //students = temp;
    //numStudents++;
    //sortStudentsAlphabetically();

    //std::cout << "Added student wizard " << name << "." << std::endl;
}

void WizardPotionInventorySystem::removeStudentWizard(const std::string name)
{
    int index = findStudentIndex(name);
	if (index == -1) {
        //std::cout << "Cannot remove student wizard. Student wizard " << name << " does not exist." << std::endl;
        return;
    }
	students[index] = students[numStudents - 1];
    numStudents--;
 //   StudentWizard* temp = new StudentWizard[numStudents - 1];
 //   for (int i = 0, j = 0; i < numStudents; i++) {
 //       if (i != index) {
 //           temp[j++] = students[i];
 //       }
 //   }
 //   delete[] students;
 //   students = temp;
 //   numStudents--;
	////std::cout << "Removed student wizard " << name << "." << std::endl;

}

void WizardPotionInventorySystem::
brewPotion(const std::string studentName, 
const std::string potionName, const int strength)
{
	int index = findStudentIndex(studentName);
	if(index == -1){
        std::cout << "Cannot brew potion. Student wizard " << studentName << " does not exist." << std::endl;
        return;
    }
    if (students[index].findPotionIndex(potionName) != -1) {
        std::cout << "Cannot brew potion. Potion already exists in potion inventory of " << studentName << "." << std::endl;
        return;
    }
	students[index].addPotion(potionName, strength);
    std::cout << "Brewed potion " << potionName << " for student wizard " << studentName << "." << std::endl;
}

void WizardPotionInventorySystem::discardPotion(const std::string studentName, const std::string potionName)
{
    int index = findStudentIndex(studentName);
    if (index == -1) {
        std::cout << "Cannot discard potion. Student wizard " << studentName << " does not exist." << std::endl;
        return;
    }
    if (students[index].findPotionIndex(potionName) == -1) {
        std::cout << "Cannot discard potion. Potion does not exist in potion inventory of " << studentName << "." << std::endl;
        return;
    }
    students[index].removePotion(potionName);

    std::cout << "Discarded potion " << potionName << " from student wizard " << studentName << "." << std::endl;
}

void WizardPotionInventorySystem::transferPotion
(const std::string potionName, const std::string
    fromStudentName, const std::string toStudentName)
{
	int fromIndex = findStudentIndex(fromStudentName);
	int toIndex = findStudentIndex(toStudentName);

    if (fromIndex == -1 || toIndex == -1) {
        std::cout << "Cannot transfer potion. One or both student wizards do not exist." << std::endl;
        return;
    }
    if (students[fromIndex].findPotionIndex(potionName) == -1) {
        std::cout << "Cannot transfer potion. Potion does not exist in potion inventory of " << fromStudentName << "." << std::endl;
        return;
	}
	if (students[toIndex].findPotionIndex(potionName) != -1) {
        std::cout << "Cannot transfer potion. Potion already exists in potion inventory of " << toStudentName << "." << std::endl;
        return;
    }
	const Potion& potionToTransfer = students[fromIndex].getPotion(students[fromIndex].findPotionIndex(potionName));
	students[toIndex].addPotion(potionToTransfer.getPotionName(), potionToTransfer.getStrength());
    students[fromIndex].removePotion(potionName);
	std::cout << "Transferred potion " << potionName << " from " << fromStudentName << " to " << toStudentName << "." << std::endl;
}

void WizardPotionInventorySystem::showAllStudentWizards() const
{
    //std::cout << "Student wizards in the system:" << std::endl;
    if (numStudents == 0) {
        //std::cout << "None" << std::endl;
        return;
    }
    for (int i = 0; i < numStudents; ++i) {
        //std::cout << students[i].getStudentName()
        //          << ", House: " << students[i].getHouse() 
        //          <<", "<<students[i].getNumPotions() 
        //          <<" potion(s), "
        //          <<students[i].getTotalStrength()<<" total strength."
        //          << std::endl;
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
	int index = findStudentIndex(name);
    if (index == -1) {
        //std::cout << "Student wizard " << name << " does not exist." << std::endl;
        return;
    }
    const StudentWizard& student = students[index];
 //   std::cout << "Student wizard:"<< std::endl << student.getStudentName();
 //   std::cout << ", House: " << student.getHouse();
	//std::cout << ", " << student.getNumPotions() << " potion(s), " << student.getTotalStrength() << " total strength." << std::endl;
 //   std::cout << "Potions:" << std::endl;
    for (int i = 0; i < student.getNumPotions(); i++) {
        const Potion& potion = student.getPotion(i);
   //     std::cout << potion.getPotionName() 
			//<< ", strength " << potion.getStrength() << "."
   //               << std::endl;
	}
}

void WizardPotionInventorySystem::showPotion(const std::string potionName) const {
    int count = 0;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].findPotionIndex(potionName) != -1) {
            count++;
        }
    }
    if (count == 0) {
        std::cout << "Potion " << potionName << " does not exist." << std::endl;
        return;
    }
    std::cout << "Potion \"" << potionName << "\" found in " << count << " student wizard(s):" << std::endl;
    int num = 1;
    for (int i = 0; i < numStudents; i++) {
        int idx = students[i].findPotionIndex(potionName);
        if (idx != -1) {
            std::cout << num++ << ". " << students[i].getStudentName()
                << ", strength " << students[i].getPotion(idx).getStrength() << "." << std::endl;
        }
    }
}

int WizardPotionInventorySystem::findStudentIndex(const std::string& name) const {
    int left = 0, right = numStudents - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (students[mid].getStudentName() == name)
            return mid;
        else if (students[mid].getStudentName() < name)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}