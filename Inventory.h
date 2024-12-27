#pragma once
#include "Item.h"
#include "Potion.h"
#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <cstdlib> // Для std::rand и std::srand
#include <ctime> 

#include <vector>
#include <string>

class Inventory {
private:
    static int space;
    int items_count;
    int potions_count;
    int current_element;

    std::vector<std::vector<Item*>> inventory_items;  // 2D контейнер для предметов
    std::vector<Potion*> inventory_potions;  // Вектор для зелий

public:

    

    Inventory();
    static int getSpace();
    static void changeSpace(int new_space);
    int getCurrentElement();
    int getItemsCount();
    int getRow();
    int getCol();

    std::vector<std::vector<Item*>>& getInventoryItems() {
        return inventory_items;
    }

    void clearInventory();
    void inventoryAddItem(Item* item);
    void inventoryAddPotion(Potion* potion);
    void usePotion();
    int getPotionsCount();

    friend std::ostream& operator<<(std::ostream& os, Inventory& inventory);
};