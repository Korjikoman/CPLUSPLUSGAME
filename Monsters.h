#pragma once
#include "Object.h"

class Monsters: public Object // класс для представления монстров
{
    friend void damageMonster(Monsters& monster, int damage);
private:
    std::string name;
    static std::vector<std::string> names;

public:
    Monsters();

    // вывод характеристик монстра
    void printMonster();
    void move(int dx, int dy);
};