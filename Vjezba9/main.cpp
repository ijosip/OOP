#include <iostream>
#include "ZooSection.h"
#include "ZooKeeper.h"
#include "Lion.h"
#include "Elephant.h"
#include "Dolphin.h"
#include "SeaTurtle.h"


int main()
{
try {
ZooSection<Animal> zoo;
ZooKeeper keeper;


zoo.addAnimal(std::make_unique<Lion>("Simba", 5, 190));
zoo.addAnimal(std::make_unique<Elephant>("Dumbo", 10, 5000));
zoo.addAnimal(std::make_unique<Dolphin>("Flipper", 8, 150));
zoo.addAnimal(std::make_unique<SeaTurtle>("Leonardo", 50, 300));


for (size_t i = 0; i < zoo.size(); ++i)
keeper.processAnimal(zoo.getAnimal(i));


std::cout << "Total daily food: " << zoo.totalFood() << "kg\n";
std::cout << "Animals fed: " << ZooKeeper::getTotalAnimalsServed() << std::endl;
}
catch (const std::exception& e) {
std::cout << "Exception: " << e.what() << std::endl;
}
}
