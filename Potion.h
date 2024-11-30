#pragma once
#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <cstdlib> // ��� std::rand � std::srand
#include <ctime> 
class Potion // ����� ��� ������������� ����� ��������������
{
private:
    int x, y;
    static int health_restore;
    bool collected;
public:
    Potion();

    bool isCollected() const;
    void collect();
    int getX() const;
    int getY() const;
    static int getHealthRestore();
    static void setHealthRestore(int value);
    void print_potion();

    void move(int dx, int dy);
    void move_random();

    void changeX(int value);
    void changeY(int value);

};