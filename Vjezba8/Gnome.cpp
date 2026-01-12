#include "Gnome.h"
#include "Player.h"


Gnome::Gnome(const std::string& name)
: Enemy(name, 90, 3) {}


void Gnome::attackPlayer(Player* target)
{
if (!target || !target->isAlive()) return;
target->takeDamage(5 * difficulty);
}


void Gnome::specialAbility()
{
if (health > 20)
std::cout << name << " blows the trumpet for help!" << std::endl;
}


void Gnome::displayStatus() const
{
std::cout << "Gnome " << name << " | HP: " << health << " | Difficulty: " << difficulty << std::endl;
}
