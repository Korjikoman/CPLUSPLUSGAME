#pragma once
#include "Inventory.h"
#include "Potion.h"
#include "Exceptions.h"
#include "Object.h"


class Player: public Object // ����� ��� ������������� ������
{
    friend void damagePlayer(Player& player, int damage);
private:
    int speed;
    Inventory inventory;
    int potions_count;
    int coins;

public:
    // �������������
    Player();
    std::string getName();
    
    // ���������� ������
    Player& movePlayer(int dx, int dy);

    // ���������, ���� �� �����
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
