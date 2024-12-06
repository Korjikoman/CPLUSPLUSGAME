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

    items_count = 0;
    current_element = 0;
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

// ������� ����������
void Inventory::print_inventory()
{
    std::cout << "Inventory (in matrix form):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (inventory_items[i][j] != nullptr) {
                std::cout << inventory_items[i][j]->getName();  // ������� ���������� � ��������
            }
            else {
                std::cout << "[Empty]";  // ��������, ���� ������ ������
            }

            // ��������� ������� �������� ��� ����������
            std::cout << "\t";
        }
        std::cout << std::endl;  // ������� �� ����� ������ ����� ������� ����
    }
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

Item*** Inventory::getInventoryItems()
{
    return inventory_items;
    
}

