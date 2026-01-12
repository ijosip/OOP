#ifndef BOSS_H
#define BOSS_H


#include "Enemy.h"


class Boss : public Enemy {
public:
Boss(const std::string& name);
void attackPlayer(Player* target) override;
void specialAbility() override;
void displayStatus() const override;
};


#endif
