#pragma once
#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <cstdlib> // ��� std::rand � std::srand
#include <ctime> 
#include <string>
#include "Coordinates.h"
using namespace std;

class Item: public Coordinates // ����� ��� ������������� ������
{

private:
    std::string item_name;
    bool collected;
    int damage;

public:
    // �������������
    Item();

    int getX();
    int getY();

    std::string getName() const;
    int getDamage();
    bool isCollected();
    void Collected();


    friend ostream& operator<<(ostream& os, Item& item);

    void changeX(int value);
    void changeY(int value);
};