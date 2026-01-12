#include "SeaTurtle.h"
#include <stdexcept>


SeaTurtle::SeaTurtle(const std::string& name, int age, double weight)
: Animal(name, age, weight), Aquatic(name, age, weight, 200.0) {}


std::string SeaTurtle::getSpecies() const { return "SeaTurtle"; }


std::string SeaTurtle::getName() const { return name; }


double SeaTurtle::getDailyFood() const
{
double food = weight * 0.03;
if (food == 0)
throw std::logic_error("Daily food is zero");
return food;
}
