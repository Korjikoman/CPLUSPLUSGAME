#pragma once
#include "Inventory.h"
#include "Potion.h"
#include "Exceptions.h"
#include "Object.h"


class Player: public Object // класс для представления игрока
{
    friend void damagePlayer(Player& player, int damage);
private:
    int speed;
    Inventory inventory;
    int potions_count;
    int coins;

public:
    // инициализация
    Player();
    std::string getName();
    
    // перемещаем игрока
    Player& movePlayer(int dx, int dy);

    // проверяем, умер ли игрок
    Inventory getInventory();

    void add_coins(int value);
    int get_coins();
    int getspeed();
    void printPlayer();
    void printCoordinates();

    void addItems(Item* item);
    int getItemsCount();
    Item* getItem(const std::string& itemName);
   
};
