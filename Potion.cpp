//Name: Ibrahim Karakus
//Section: 1
//Student ID: 22403627
#include "Potion.h"
#include <iostream>

Potion::Potion() : potionName(""), strength(0)
{}

Potion::Potion(const std::string& name, int str)
    : potionName(name), strength(str) {}

Potion::~Potion()
{}


