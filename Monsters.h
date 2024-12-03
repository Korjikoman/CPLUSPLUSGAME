#pragma once
#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <cstdlib> // Для std::rand и std::srand
#include <ctime> 
#include <vector>

class Monsters // класс для представления монстров
{
    friend void damageMonster(Monsters& monster, int damage);
private:
    int x, y;
    int damage;
    int health;
    bool is_alive;

    std::string name;


    static std::vector<std::string> names;

public:
    Monsters();
    int getX() const;
    int getY() const;
    int getDamage() const;
    int getHealth();

    void changeHealthValue(int value);
    bool isAlive() const;
    // вывод характеристик монстра
    void printMonster();
    void move(int dx, int dy);

    void changeX(int value);
    void changeY(int value);
    void is_dead();
};