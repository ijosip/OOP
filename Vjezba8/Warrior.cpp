#include "Warrior.h"
#include "Enemy.h"


Warrior::Warrior(const std::string& name)
: Player(name, 120), shield_active(false) {}


void Warrior::attackEnemy(Enemy* target)
{
if (!target || !target->isAlive()) return;


target->takeDamage(20);
if (!target->isAlive())
addScore(10);
}


void Warrior::specialAbility()
{
shield_active = true;
std::cout << name << " activates shield!" << std::endl;
}


void Warrior::takeDamage(int amount)
{
if (shield_active) {
amount /= 2;
shield_active = false;
}
GameCharacter::takeDamage(amount);
}


void Warrior::displayStatus() const
{
std::cout << "Warrior " << name << " | HP: " << health << " | Score: " << score << std::endl;
}
