#include "Mammal.h"


Mammal::Mammal(const std::string& name, int age, double weight, bool hasFur)
: Animal(name, age, weight), hasFur(hasFur)
{
if (hasFur)
std::cout << "Stvoren sisavac s dlakom\n";
else
std::cout << "Stvoren sisavac s malo dlake\n";
}
