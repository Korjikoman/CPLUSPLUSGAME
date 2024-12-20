#pragma once
#include "Player.h"
#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <cstdlib> // ��� std::rand � std::srand
#include <ctime> 

class Coin // ��������� ��� ������������� �������
{
private:
    int x, y;
    int value;
    bool collected;
public:
    Coin();

    int getX() const;
    int getY() const;
    int getValue() const;
    bool is_collected();
    void collect_coin(Player& player, int value);

    void changeX(int value);
    void changeY(int value);
    friend ostream& operator<<(ostream& os, Coin& coin);

};