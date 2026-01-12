#ifndef DOLPHIN_H
#define DOLPHIN_H


#include "Mammal.h"
#include "Aquatic.h"


class Dolphin : public Mammal, public Aquatic {
public:
Dolphin(const std::string& name, int age, double weight);


std::string getSpecies() const override;
double getDailyFood() const override;
std::string getName() const override;
};


#endif
