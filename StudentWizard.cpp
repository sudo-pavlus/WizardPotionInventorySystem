//Name: Ibrahim Karakus
//Section: 1
//Student ID: 22403627
#include "StudentWizard.h"
#include <iostream>


StudentWizard::StudentWizard() : studentName(""), house(""), potions(nullptr), numPotions(0) {
}


StudentWizard::StudentWizard(const std::string& name, const std::string& house)
	: studentName(name), house(house), potions(nullptr), numPotions(0) {
}

StudentWizard::StudentWizard(const StudentWizard& other)
{
	studentName = other.studentName;
	house = other.house;
	numPotions = other.numPotions;
	potions = new Potion[numPotions];
	for (int i = 0; i < numPotions; ++i) {
		potions[i] = other.potions[i];
	}
}

StudentWizard& StudentWizard::operator=(const StudentWizard& other)
{
	if (this != &other) {
		delete[] potions;
		studentName = other.studentName;
		house = other.house;
		numPotions = other.numPotions;
		potions = new Potion[numPotions];
		for (int i = 0; i < numPotions; ++i) {
			potions[i] = other.potions[i];
		}
	}
	return *this;
}

StudentWizard::~StudentWizard() {
	delete[] potions;
}

void StudentWizard::addPotion(const std::string& potionName, int strength) {
	Potion newPotion(potionName, strength);
	Potion* newPotions = new Potion[numPotions + 1];
	for (int i = 0; i < numPotions; ++i) {
		newPotions[i] = potions[i];
	}
	newPotions[numPotions] = newPotion;
	delete[] potions;
	potions = newPotions;
	++numPotions;
}

void StudentWizard::removePotion(const std::string& potionName) {
    int index = findPotionIndex(potionName);
    if (index != -1) {
        if (numPotions - 1 > 0) {
            Potion* newPotions = new Potion[numPotions - 1];
            for (int i = 0, j = 0; i < numPotions; ++i)
                if (i != index) newPotions[j++] = potions[i];
            delete[] potions;
            potions = newPotions;
        } else {
            delete[] potions;
            potions = nullptr;
        }
        --numPotions;
    }
}

int StudentWizard::findPotionIndex(const std::string& potionName) const {
	for (int i = 0; i < numPotions; ++i) {
		if (potions[i].getPotionName() == potionName) {
			return i;
		}
	}
	return -1;
}

const Potion& StudentWizard::getPotion(int index) const {
	if (index >= 0 && index < numPotions) {
		return potions[index];
	}
	throw std::out_of_range("Invalid potion index");
}

int StudentWizard::getTotalStrength() const
{
	int totalStr = 0;
	for (int i = 0; i < numPotions; i++) {
		totalStr += potions[i].getStrength();
	}
	return totalStr;
}





