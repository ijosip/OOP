#include "Mage.h"
#include "Enemy.h"


Mage::Mage(const std::string& name)
: Player(name, 80), mana(100) {}


void Mage::attackEnemy(Enemy* target)
{
if (!target || !target->isAlive()) return;


if (mana >= 20) {
target->takeDamage(40);
mana -= 20;
} else {
target->takeDamage(20);
}


if (!target->isAlive())
addScore(10);
}


void Mage::specialAbility()
{
if (health > 50)
std::cout << name << " teleports away!" << std::endl;
}


void Mage::displayStatus() const
{
std::cout << "Mage " << name << " | HP: " << health << " | Mana: " << mana << " | Score: " << score << std::endl;
}
