#pragma once
#include "Inventory.h"
#include "Health.h"
#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <cstdlib> // ��� std::rand � std::srand
#include <ctime> 
class Player // ����� ��� ������������� ������
{

private:
    int x, y;
    Health health;
    int speed;
    int damage;
    Inventory inventory;
    int potions_count;

    bool is_alive;
    int coins;

public:
    // �������������
    Player();

    // ���������� ������
    void movePlayer(int dx, int dy);

    // ���������, ���� �� �����
    bool isAlive();
    Inventory getInventory();

    void add_coins(int value);
    int get_coins();
    int getX();
    int getY();
    int getspeed();
    void printPlayer();
    int getDamage();

    int getCurrentHealth();

    int getMaxHealth();
    void changeHealthValue(int new_value);

    void heal(int value);

    void is_dead();

};
