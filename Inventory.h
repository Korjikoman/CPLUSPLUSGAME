#pragma once
#include "Item.h"
#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <cstdlib> // ��� std::rand � std::srand
#include <ctime> 
class Inventory // ����� ��� ������������� ��������� ������
{
private:
    int space;
    int items_count;
    int current_element;
    Item** inventory_items;

public:
    Inventory();

    int getSpace();
    void changeSpace(int new_space);
    int getCurrentElement();
    int getItemsCount();

    void print_inventory();
    int inventoryAddItem(Item* item);


    int getItem(int idx);

};
