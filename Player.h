#pragma once
#include "Inventory.h"
#include "Potion.h"
#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <cstdlib> // Для std::rand и std::srand
#include <ctime> 



class Player // класс для представления игрока
{
    friend void damagePlayer(Player& player, int damage);
private:

    int x, y;
    std::string name;
    int health;
    static int maxHealth;
    
    
    int speed;
    int damage;
    Inventory inventory;
    int potions_count;

    bool is_alive;
    int coins;

public:
    // инициализация
    Player();
    std::string getName();
    
    // перемещаем игрока
    Player& movePlayer(int dx, int dy);

    // проверяем, умер ли игрок
    bool isAlive();
    Inventory getInventory();

    void add_coins(int value);
    int get_coins();
    int& getX();
    int& getY();
    int getspeed();
    void printPlayer();
    int getDamage();
    void printCoordinates();
    int getCurrentHealth();

    void changeHealthValue(int new_value);

    void heal(int value);
    void is_dead();
    void addItems(Item* item);
    int getItemsCount();
    Item* getItem(const std::string& itemName);
    static void setMaxHealth(int value);
    static int getMaxHealth();
};
