#pragma once
#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <cstdlib> // Для std::rand и std::srand
#include <ctime> 
#include <string>


class Item // класс для представления оружия
{

private:
    std::string item_name;
    int x, y;
    bool collected;
    int damage;

public:
    // инициализация
    Item();

    int getX();
    int getY();

    std::string getName() const;
    int getDamage();
    bool isCollected();
    void Collected();

    // вывод характеристик оружия
    void print_item();

    void changeX(int value);
    void changeY(int value);
};