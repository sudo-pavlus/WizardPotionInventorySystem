#include <chrono>
#include <iostream>
#include "WizardPotionInventorySystem.h"

void testAddStudentWizard(int N) {
    WizardPotionInventorySystem system;

    auto start = std::chrono::high_resolution_clock::now();
    for (int j = 0; j < N; j++) {
        system.addStudentWizard("Student" + std::to_string(j), "Gryffindor");
    }
    auto end = std::chrono::high_resolution_clock::now();

    double ms = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(end - start).count();
    std::cout << "addStudentWizard tested with " << N << " student wizards. It took " << ms << " ms." << std::endl;
}

void testRemoveStudentWizard(int N) {
    WizardPotionInventorySystem system;
    for (int j = 0; j < N; j++) {
        system.addStudentWizard("Student_" + std::to_string(j), "Gryffindor");
    }
    std::string middleStudent = "Student_" + std::to_string(N / 2);

    auto start = std::chrono::high_resolution_clock::now();
    system.removeStudentWizard(middleStudent);
    auto end = std::chrono::high_resolution_clock::now();

    double ms = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(end - start).count();
    std::cout << "removeStudentWizard tested with " << N << " student wizards. It took " << ms << " ms." << std::endl;
}

void testShowAllStudentWizards(int N) {
    WizardPotionInventorySystem system;
    for (int j = 0; j < N; j++) {
        system.addStudentWizard("Student_" + std::to_string(j), "Gryffindor");
    }

    auto start = std::chrono::high_resolution_clock::now();
    system.showAllStudentWizards();
    auto end = std::chrono::high_resolution_clock::now();

    double ms = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(end - start).count();
    std::cout << "showAllStudentWizards tested with " << N << " student wizards. It took " << ms << " ms." << std::endl;
}

void testShowStudentWizard(int N) {
    WizardPotionInventorySystem system;
    for (int j = 0; j < N; j++) {
        system.addStudentWizard("Student_" + std::to_string(j), "Gryffindor");
    }
    std::string middleStudent = "Student_" + std::to_string(N / 2);

    auto start = std::chrono::high_resolution_clock::now();
    system.showStudentWizard(middleStudent);
    auto end = std::chrono::high_resolution_clock::now();

    double ms = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(end - start).count();
    std::cout << "showStudentWizard tested with " << N << " student wizards. It took " << ms << " ms." << std::endl;
}
int main() {
    int testNumbers[] = { 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000 };
    for (int N : testNumbers) {
        std::cout << "Running Tests for N = " << N << std::endl;

        testAddStudentWizard(N);
        testShowAllStudentWizards(N);
        testShowStudentWizard(N);
        testRemoveStudentWizard(N);
    }

    return 0;
}