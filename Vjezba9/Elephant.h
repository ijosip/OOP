#ifndef ELEPHANT_H
#define ELEPHANT_H


#include "Mammal.h"


class Elephant : public Mammal {
public:
Elephant(const std::string& name, int age, double weight);


std::string getSpecies() const override;
double getDailyFood() const override;
std::string getName() const override;
};


#endif
