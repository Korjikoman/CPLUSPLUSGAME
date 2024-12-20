#include "Inventory.h"

// Inventory space is a static variable
int Inventory::space = 4;

Inventory::Inventory() {
    std::cout << "Initializing Inventory...\n";

    inventory_items = new Item * *[Inventory::space];
    cols = rows = Inventory::space / 2;
    for (int i = 0; i < Inventory::space; ++i) {
        inventory_items[i] = new Item * [Inventory::space];  // ��� ������ ������ �������� ������ ��� �������
        for (int j = 0; j < Inventory::space; ++j) {
            inventory_items[i][j] = nullptr;  // ���������� ��� ������ ������ (nullptr)
        }
    }

    inventory_potions = new Potion*[Inventory::space];
   
    for (int i = 0; i < Inventory::space; ++i) {
            inventory_potions[i] = nullptr;  // ���������� ��� ������ ������ (nullptr)
    }


    items_count = 0;
    current_element = 0;
    potions_count = 0;
}


int Inventory::getSpace() { return space; }

// Static method that chages inventory space
void Inventory::changeSpace(int new_space) {
    space = new_space;
}
int Inventory::getCurrentElement() { return current_element; }
int Inventory::getItemsCount() { return items_count; }

int Inventory::getRow() {
    return items_count / cols;
}
int Inventory::getCol() {
    
    return items_count % cols;

}

// ��������� ������� � ���������
void Inventory::inventoryAddItem(Item* item) {
    if (items_count >= rows * cols) {
        std::cout << "Inventory is full!" << std::endl;
        return;  // ������������� ����������
    }

    int row = getRow();
    int col = getCol();

    // ���������, ��� ������� ������������� ��������
    if (inventory_items[row][col] != nullptr) {
        std::cout << "Error: Slot (" << row << ", " << col << ") is already occupied.\n";
        return;
    }

    inventory_items[row][col] = item;  // �������� �������
    items_count++;
    std::cout << "Item added to slot (" << row << ", " << col << ")\n";
}

// ��������� ����� � ���������
void Inventory::inventoryAddPotion(Potion* potion) {
    if (potions_count >= Inventory::space) {
        std::cout << "Inventory is full!" << std::endl;
        return;  // ������������� ����������
    }

    // ���������, ��� ������� ������������� ��������
    if (inventory_potions[potions_count] != nullptr) {
        std::cout << "Error: Slot (" << potions_count << ") is already occupied.\n";
        return;
    }

    inventory_potions[potions_count] = potion;  // �������� �������
    potions_count++;
    std::cout << "Potion added to slot (" << potions_count << ")\n";
}

void Inventory::usePotion()
{
    if (potions_count <= 0) {
        std::cout << "No potions left!\n";
        return;
    }

    // ������� ��������� �����
    inventory_potions[potions_count - 1]->changeX(-1);
    inventory_potions[potions_count - 1]->changeY(-1);

    inventory_potions[potions_count - 1] = nullptr;

    // ��������� ���������� �����
    potions_count--;
    std::cout << "Potion used! Potions left: " << potions_count << "\n";
}

int Inventory::getPotionsCount()
{
    return potions_count;
}


Item*** Inventory::getInventoryItems()
{
    return inventory_items;
    
}

// ������� ���������
ostream& operator<<(ostream& os, Inventory& inventory)
{
    os << "Inventory (in matrix form):\n";
    // ����� ��������� � ���������
    for (int i = 0; i < inventory.rows; ++i) {
        for (int j = 0; j < inventory.cols; ++j) {
            if (inventory.inventory_items[i][j] != nullptr) {
                os << inventory.inventory_items[i][j]->getName(); 
            }
            else {
                os << "[Empty]"; 
            }
            os << "\t"; 
        }
        os << "\n"; 
    }

    // ����� �����
    os << "Potions:\n";
    for (int i = 0; i < inventory.potions_count; ++i) {
        if (inventory.inventory_potions[i] != nullptr) {
            os << "[Potion]";  
        }
        else {
            os << "[Empty]";  
        }
        os << "\t";  
    }
    os << "\n";
    return os;
}
