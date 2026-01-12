#ifndef LION_H
#define LION_H


#include "Mammal.h"


class Lion : public Mammal {
public:
Lion(const std::string& name, int age, double weight);


std::string getSpecies() const override;
double getDailyFood() const override;
std::string getName() const override;
};


#endif
