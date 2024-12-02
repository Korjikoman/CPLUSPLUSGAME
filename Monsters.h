#pragma once
#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <cstdlib> // ��� std::rand � std::srand
#include <ctime> 

class Monsters // ����� ��� ������������� ��������
{
private:
    int x, y;
    int damage;
    int health;
    bool is_alive;

public:
    Monsters();
    // �������������
    Monsters(int m_x, int m_y, int m_damage, int m_health);
    int getX() const;
    int getY() const;
    int getDamage() const;
    int getHealth();

    void changeHealthValue(int value);
    bool isAlive() const;
    // ����� ������������� �������
    void printMonster();
    void move(int dx, int dy);

    void changeX(int value);
    void changeY(int value);
    void is_dead();
};