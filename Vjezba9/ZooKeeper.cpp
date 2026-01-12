#include "ZooKeeper.h"


int ZooKeeper::totalAnimalsServed = 0;


void ZooKeeper::processAnimal(Animal* animal)
{
if (!animal) return;


std::cout << "Species: " << animal->getSpecies()
<< ", Name: " << animal->getName()
<< ", Food: " << animal->getDailyFood() << "kg\n";


++totalAnimalsServed;
}


int ZooKeeper::getTotalAnimalsServed()
{
return totalAnimalsServed;
}
