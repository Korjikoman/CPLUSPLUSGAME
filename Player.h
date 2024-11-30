#pragma once
#include "Inventory.h"
#include "Health.h"
#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <cstdlib> // Для std::rand и std::srand
#include <ctime> 
class Player // класс для представления игрока
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
    // инициализация
    Player();

    // перемещаем игрока
    void movePlayer(int dx, int dy);

    // проверяем, умер ли игрок
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
