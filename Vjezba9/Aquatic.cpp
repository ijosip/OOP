#include "Aquatic.h"


Aquatic::Aquatic(const std::string& name, int age, double weight, double maxDiveDepth)
: Animal(name, age, weight), maxDiveDepth(maxDiveDepth)
{
std::cout << "Stvorena vodena zivotinja koja roni do " << maxDiveDepth << "m\n";
}
