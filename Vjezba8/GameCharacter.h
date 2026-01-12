#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H


#include <string>
#include <iostream>


class GameCharacter {
protected:
int health;
int max_health;
std::string name;


public:
GameCharacter(const std::string& name, int health);
virtual ~GameCharacter();


virtual void displayStatus() const = 0;
virtual void specialAbility() = 0;


void takeDamage(int amount);
bool isAlive() const;


int getHealth() const;
const std::string& getName() const;
};


#endif
