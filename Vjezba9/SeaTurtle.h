#ifndef SEATURTLE_H
#define SEATURTLE_H


#include "Aquatic.h"


class SeaTurtle : public Aquatic {
public:
SeaTurtle(const std::string& name, int age, double weight);


std::string getSpecies() const override;
double getDailyFood() const override;
std::string getName() const override;
};


#endif
