#include "Animal.h"


Animal::Animal(const std::string& name, int age, double weight)
: name(name), age(age), weight(weight)
{
if (name.empty())
throw std::invalid_argument("Name cannot be empty");
if (age < 0)
throw std::invalid_argument("Age cannot be negative");
if (weight <= 0)
throw std::invalid_argument("Weight must be positive");
}
