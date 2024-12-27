#pragma once
#include "Object.h"



class Monsters: public Object // ����� ��� ������������� ��������
{
    friend void damageMonster(Monsters& monster, int damage);
private:

    static std::vector<std::string> names;

public:
    Monsters();
    Monsters& operator=(Object& obj);
    // ����� ������������� �������
    void move(int dx, int dy);
    friend ostream& operator<<(ostream& os, Monsters& monster);
    void isDead();
};