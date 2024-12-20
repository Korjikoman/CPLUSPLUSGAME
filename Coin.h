#pragma once
#include "Player.h"
#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <cstdlib> // ��� std::rand � std::srand
#include <ctime> 
#include "Coordinates.h"

class Coin: public Coordinates // ��������� ��� ������������� �������
{
private:
    int value;
    bool collected;
public:
    Coin();

    int getX();
    int getY();
    int getValue() const;
    bool is_collected();
    void collect_coin(Player& player, int value);

    void changeX(int value);
    void changeY(int value);
    friend ostream& operator<<(ostream& os, Coin& coin);

};