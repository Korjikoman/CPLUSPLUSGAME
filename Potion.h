#pragma once
#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Coordinates.h"
using namespace std;

class Potion: public Coordinates // ����� ��� ������������� ����� ��������������
{

private:
    static int health_restore;
    bool collected;
public:
    Potion();

    bool isCollected() const;
    void collect();
    int getX() override;
    int getY() override;
    static int getHealthRestore();
    static void setHealthRestore(int value);


    void move(int dx, int dy);
    void move_random();

    void changeX(int value);
    void changeY(int value);

    // ���������� ��������� + ��� ����������� ���� �����
    friend const Potion operator+(const Potion& potion1, const Potion& potion2);

    Potion& operator++();

    // ���������� ������������ ��������� ++
    Potion operator++(int);

    friend ostream& operator<<(ostream& os, Potion& potion);

};