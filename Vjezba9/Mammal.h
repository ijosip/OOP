#ifndef MAMMAL_H
#define MAMMAL_H


#include "Animal.h"
#include <iostream>


class Mammal : virtual public Animal {
protected:
bool hasFur;


Mammal(const std::string& name, int age, double weight, bool hasFur);
};


#endif
