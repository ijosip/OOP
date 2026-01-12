#ifndef WARRIOR_H
#define WARRIOR_H


#include "Player.h"


class Warrior : public Player {
private:
bool shield_active;


public:
Warrior(const std::string& name);
void attackEnemy(Enemy* target) override;
void specialAbility() override;
void displayStatus() const override;
void takeDamage(int amount);
};


#endif
