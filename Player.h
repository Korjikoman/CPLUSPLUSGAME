#pragma once
#include "Inventory.h"
#include "Potion.h"
#include "Exceptions.h"
#include "Object.h"
#include <iostream>
#include <format>



class Player: public Object // класс для представления игрока
{
    friend void damagePlayer(Player& player, int damage);
private:
    int speed;
    Inventory inventory;
    int coins;

public:
    // инициализация
    Player();
    Player(std::string name, int x, int y, int health, int speedd, int damage);
    std::string getName();
    void heal();
    // перемещаем игрока
    Player& movePlayer(int dx, int dy);

    // проверяем, умер ли игрок
    Inventory getInventory();

    void add_coins(int value);
    int get_coins();
    int getspeed();
    void printPlayer();
    void printCoordinates();
    
    void isDead() override;


    void addPotion(Potion& potion);

    void addItems(Item* item);
    int getItemsCount();
    Item* getItem(const std::string& itemName);
        
    // перегрузка оператора присваивания
    Player& operator=(Object& obj);
    friend ostream& operator<<(ostream& os, Player& player);
    


};
