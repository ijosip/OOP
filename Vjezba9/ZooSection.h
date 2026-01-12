#ifndef ZOOSECTION_H
#define ZOOSECTION_H


#include <vector>
#include <memory>
#include <stdexcept>


template<typename T>
class ZooSection {
private:
std::vector<std::unique_ptr<T>> animals;


public:
void addAnimal(std::unique_ptr<T> animal)
{
if (!animal)
throw std::runtime_error("Nullptr animal");
animals.push_back(std::move(animal));
}


double totalFood() const
{
double sum = 0;
for (const auto& a : animals)
sum += a->getDailyFood();
return sum;
}


size_t size() const { return animals.size(); }


T* getAnimal(size_t index) const
{
return animals.at(index).get();
}
};


#endif
