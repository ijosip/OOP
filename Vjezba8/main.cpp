#include <vector>
#include <algorithm>
#include "Warrior.h"
#include "Mage.h"
#include "Gnome.h"
#include "Boss.h"


int main()
{
Warrior* conan = new Warrior("Conan");
Mage* merlin = new Mage("Merlin");
Gnome* gnomeo = new Gnome("Gnomeo");
Gnome* sneaky = new Gnome("Sneaky");
Boss* dragon = new Boss("Dragon");


std::vector<GameCharacter*> characters = {
conan, merlin, gnomeo, sneaky, dragon
};


conan->attackEnemy(gnomeo);
conan->displayStatus(); gnomeo->displayStatus();


merlin->attackEnemy(sneaky);
merlin->displayStatus(); sneaky->displayStatus();


gnomeo->attackPlayer(conan);
conan->displayStatus(); gnomeo->displayStatus();


merlin->attackEnemy(gnomeo);
dragon->attackPlayer(merlin);
merlin->attackEnemy(gnomeo);


conan->attackEnemy(dragon);
merlin->attackEnemy(dragon);


for (auto c : characters)
c->specialAbility();


GameCharacter* healthiest = nullptr;
for (auto c : characters) {
if (c->isAlive()) {
c->displayStatus();
if (!healthiest || c->getHealth() > healthiest->getHealth())
healthiest = c;
}
}


if (healthiest)
std::cout << "Highest HP: " << healthiest->getName() << std::endl;


for (auto c : characters)
delete c;
}
