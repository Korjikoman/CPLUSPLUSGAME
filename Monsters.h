#pragma once
#include "Object.h"



class Monsters: public Object // класс для представления монстров
{
    friend void damageMonster(Monsters& monster, int damage);
private:

    static std::vector<std::string> names;

public:
    Monsters();
    Monsters& operator=(Object& obj);
    // вывод характеристик монстра
    void move(int dx, int dy);
    friend ostream& operator<<(ostream& os, Monsters& monster);
    void isDead();
};