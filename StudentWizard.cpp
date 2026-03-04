#include "StudentWizard.h"
#include <iostream>


StudentWizard::StudentWizard() : studentName(""), house(""), potions(nullptr), numPotions(0) {
}


StudentWizard::StudentWizard(const std::string& name, const std::string& house)
	: studentName(name), house(house), potions(nullptr), numPotions(0) {
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
	int index = findPotionIdex(potionName);
	if (index != -1) {
		Potion* newPotions = new Potion[numPotions - 1];
		for (int i = 0, j = 0; i < numPotions; ++i) {
			if (i != index) {
				newPotions[j++] = potions[i];
			}
		}
		delete[] potions;
		potions = newPotions;
		--numPotions;
	}
}

int StudentWizard::findPotionIdex(const std::string& potionName) const {
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





