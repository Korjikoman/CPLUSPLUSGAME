#pragma once
#include "Item.h"
#include "Potion.h"
#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <cstdlib> // Для std::rand и std::srand
#include <ctime> 
class Inventory // класс для представления инвентаря игрока
{
private:
    static int space;
    int items_count;
    int potions_count;
    int current_element;
    Item*** inventory_items;
    Potion** inventory_potions;
    int cols;
    int rows;

public:
    Inventory();
    static int getSpace();
    static void changeSpace(int new_space);
    int getCurrentElement();
    int getItemsCount();

    void print_inventory();
    void inventoryAddItem(Item* item);
    void inventoryAddPotion(Potion* potion);

    void usePotion();
    int getPotionsCount();

    Item*** getInventoryItems();
    int getRow(); 
    int getCol(); 
};