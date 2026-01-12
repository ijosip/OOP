#ifndef AQUATIC_H
#define AQUATIC_H


#include "Animal.h"
#include <iostream>


class Aquatic : virtual public Animal {
protected:
double maxDiveDepth;


Aquatic(const std::string& name, int age, double weight, double maxDiveDepth);
};


#endif
