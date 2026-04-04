#include "Player.h"
#include "world.h"

Player::Player(std::string name, int health)
    : name_(name), health_(health), maxHealth_(health), x_(300.f), y_(400.f) {}
void Player::takeDamage(int dmg) {
    health_ -= dmg;
    if (health_ < 0) health_ = 0;
};
void Player::move(float dx, float dy) {
    x_ += dx;
    y_ += dy;
};
void Player::newMaxHealth() const{
    return (maxHealth_ + (2 ** rounds_));
}
bool Player::isAlive() const{
    return health_ > 0;
}
float Player::getX() const { return x_; }
float Player::getY() const { return y_; }
std::string Player::getName() const { return name_; }