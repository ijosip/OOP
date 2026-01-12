#ifndef GNOME_H
#define GNOME_H


#include "Enemy.h"


class Gnome : public Enemy {
public:
Gnome(const std::string& name);
void attackPlayer(Player* target) override;
void specialAbility() override;
void displayStatus() const override;
};


#endif
