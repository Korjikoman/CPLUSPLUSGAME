#include "Inventory.h"

// Inventory space is a static variable
int Inventory::space = 4;

Inventory::Inventory() {
    std::cout << "Initializing Inventory...\n";

    inventory_items = new Item * *[Inventory::space];
    for (int i = 0; i < Inventory::space; ++i) {
        inventory_items[i] = new Item * [Inventory::space];  // ��� ������ ������ �������� ������ ��� �������
        for (int j = 0; j < Inventory::space; ++j) {
            inventory_items[i][j] = nullptr;  // ���������� ��� ������ ������ (nullptr)
        }
    }

    items_count = 0;
    current_element = 0;
}
Inventory::~Inventory() {
    for (int i = 0; i < Inventory::space; ++i) {
        delete[] inventory_items[i];  // ������� ������ ��� ������ ������
    }
    delete[] inventory_items;  // ������� ������ ��� ������� �����
}

int Inventory::getSpace() { return space; }

// Static method that chages inventory space
void Inventory::changeSpace(int new_space) {
    space = new_space;
}
int Inventory::getCurrentElement() { return current_element; }
int Inventory::getItemsCount() { return items_count; }

// ������� ����������
void Inventory::print_inventory()
{
    std::cout << "Inventory:\n";
    for (int i = 0; i < Inventory::space; ++i) {
        std::cout << "Row " << i << ":\n";
        for (int j = 0; j < Inventory::space; ++j) {
            if (inventory_items[i][j] != nullptr) {
                inventory_items[i][j]->print_item();  // ������� ���������� � ��������
            }
            else {
                std::cout << "Empty slot\n";
            }
        }
    }
}

// ��������� ������� � ���������
void Inventory::inventoryAddItem(Item* item) {
    int row = 0;
    int col = 0;
    if (row >= Inventory::space || col >= Inventory::space || inventory_items[row][col] != nullptr) {
        std::cout << "Cannot add item here. Invalid position or slot is already occupied." << std::endl;
    }
    inventory_items[row][col] = item; 
    items_count++;
}

Item*** Inventory::getInventoryItems()
{
   
    return inventory_items;
    
}

