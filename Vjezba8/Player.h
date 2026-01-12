#ifndef PLAYER_H
#define PLAYER_H


#include "GameCharacter.h"


class Enemy;


class Player : public GameCharacter {
protected:
int score;


public:
Player(const std::string& name, int health);
virtual ~Player();


virtual void attackEnemy(Enemy* target) = 0;
void addScore(int amount);
};


#endif
