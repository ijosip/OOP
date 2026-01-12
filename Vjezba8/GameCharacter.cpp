#include "GameCharacter.h"


GameCharacter::GameCharacter(const std::string& name, int health)
: health(health), max_health(health), name(name) {}


GameCharacter::~GameCharacter() {}


void GameCharacter::takeDamage(int amount)
{
if (!isAlive()) return;
health -= amount;
if (health < 0) health = 0;
}


bool GameCharacter::isAlive() const
{
return health > 0;
}


int GameCharacter::getHealth() const
{
return health;
}


const std::string& GameCharacter::getName() const
{
return name;
}
