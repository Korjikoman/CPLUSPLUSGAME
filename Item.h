#pragma once
#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <cstdlib> // ƒл€ std::rand и std::srand
#include <ctime> 
#include <string>
using namespace std;

class Item // класс дл€ представлени€ оружи€
{

private:
    std::string item_name;
    int x, y;
    bool collected;
    int damage;

public:
    // инициализаци€
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