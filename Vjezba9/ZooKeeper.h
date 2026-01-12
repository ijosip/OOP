#ifndef ZOOKEEPER_H
#define ZOOKEEPER_H


#include "Animal.h"
#include <iostream>


class ZooKeeper {
private:
static int totalAnimalsServed;


public:
void processAnimal(Animal* animal);
static int getTotalAnimalsServed();
};


#endif
