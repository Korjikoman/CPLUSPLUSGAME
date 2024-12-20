#pragma once
#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <cstdlib> // ��� std::rand � std::srand
#include <ctime> 
#include <string>


class Item // ����� ��� ������������� ������
{

private:
    std::string item_name;
    int x, y;
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

    // ����� ������������� ������
    void print_item();

    void changeX(int value);
    void changeY(int value);
};