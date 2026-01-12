#include "Boss.h"
#include "Player.h"


Boss::Boss(const std::string& name)
: Enemy(name, 300, 8) { max_health = 300; }


void Boss::attackPlayer(Player* target)
{
if (!target || !target->isAlive()) return;
target->takeDamage(10 * difficulty);
}


void Boss::specialAbility()
{
health += 50;
if (health > max_health)
health = max_health;
std::cout << name << " regenerates!" << std::endl;
}


void Boss::displayStatus() const
{
std::cout << "Boss " << name << " | HP: " << health << " | Difficulty: " << difficulty << std::endl;
}
