#include "Object.h"

int Object::maxHealth = 10;

Object::Object()
{
    this->x = 0;
    this->y = 0;
    this->health = 0;
    this->damage = 0;
    this->is_alive = true;
}

Object::Object(int x, int y, int health, int damage) {
    this->x = x;
    this->y = y;
    this->health = health;
    this->damage = damage;
    this->is_alive = true;
    std::cout << "Object initiallated successfully!\n";
}

bool Object::isAlive()
{
    return is_alive;
}

void Object::isDead()
{
    health = 0;
    is_alive = false;
}

int& Object::getX()
{
    return x;
}

int& Object::getY()
{
    return y;
}

void Object::setX(int value)
{
    x = value;
}

void Object::setY(int value)
{
    y = value;
}

int Object::getDamage()
{
    return damage;
}

void Object::setDamage(int value)
{
    damage = value;
}

std::string Object::getName()
{
    return name;
}


int Object::getCurrentHealth()
{
    return health;
}

void Object::changeHealthValue(int new_value)
{
    health = new_value;
}

int Object::getMaxHealth()
{
    return maxHealth;
}

void Object::heal(int value)
{
    health += value;
    std::cout << "Object's health restored\n";
}

void Object::setMaxHealth(int value)
{
    maxHealth = value;
}

void Object::setHealth(int value)
{
    health = value;
}
