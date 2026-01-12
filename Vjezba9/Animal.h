#ifndef ANIMAL_H
#define ANIMAL_H


#include <string>
#include <stdexcept>


class Animal {
protected:
std::string name;
int age;
double weight;


Animal(const std::string& name, int age, double weight);


public:
virtual ~Animal() = default;


virtual std::string getSpecies() const = 0;
virtual double getDailyFood() const = 0;
virtual std::string getName() const = 0;
};


#endif
