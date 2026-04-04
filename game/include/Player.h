#pragma once
#include <string>

class Player {
public:
    Player(std::string name, int health);

    void takeDamage(int dmg);
    void move(float dx, float dy);
    int newMaxHealth() const;
    bool isAlive() const;

    float getX() const;
    float getY() const;
    std::string getName() const;

private:
    std::string name_;
    int health_;
    int maxHealth_;
    int rounds_;
    float x_, y_;
};