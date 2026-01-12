#include "Player.h"
#include "Enemy.h"


Player::Player(const std::string& name, int health)
: GameCharacter(name, health), score(0) {}


Player::~Player() {}


void Player::addScore(int amount)
{
score += amount;
}
