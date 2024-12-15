#pragma once
#include "Object.h"

class Monsters: public Object // ����� ��� ������������� ��������
{
    friend void damageMonster(Monsters& monster, int damage);
private:

    static std::vector<std::string> names;

public:
    Monsters();

    // ����� ������������� �������
    void printMonster();
    void move(int dx, int dy);
};