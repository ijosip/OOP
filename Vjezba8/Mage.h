#ifndef MAGE_H
#define MAGE_H


#include "Player.h"


class Mage : public Player {
private:
int mana;


public:
Mage(const std::string& name);
void attackEnemy(Enemy* target) override;
void specialAbility() override;
void displayStatus() const override;
};


#endif
