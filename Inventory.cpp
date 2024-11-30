#include "Inventory.h"


Inventory::Inventory() {
    std::cout << "Initializing Inventory...\n";

    std::cout << "Enter the inventory space: ";
    std::cin >> space;

    if (space <= 0) {
        std::cerr << "Invalid inventory size! Setting space to 1.\n";
        space = 1;
    }
    inventory_items = new Item * [space];

    items_count = 0;
    current_element = 0;
}


int Inventory::getSpace() { return space; }
void Inventory::changeSpace(int new_space) {
    space = new_space;
}
int Inventory::getCurrentElement() { return current_element; }
int Inventory::getItemsCount() { return items_count; }

// Выводим интвентарь
void Inventory::print_inventory()
{
    printf("Inventory space: %d\n", space);
    printf("Your inventory:\n");
    if (items_count == 0) printf("There's nothing in it\n");
    for (int i = 0; i < items_count; i++)
    {
        std::cout << "  Item " << i + 1 << ": " << inventory_items[i]->getName() << std::endl;
    }
    std::cout << "Inventory current element: " << current_element << std::endl;
}

// Добавляем предмет в инвентарь
int Inventory::inventoryAddItem(Item* item)
{
    if (items_count >= space)
    {
        printf("Inventory is full! Cannot add item '%s'.\n", item->getName());
        return 0; // Не удалось добавить предмет
    }

    // Добавление предмета в массив строк
    inventory_items[items_count] = item;
    items_count++;

    item->Collected();   // Помечаем предмет как собранный
    std::cout << "Item " << item->getName() << " added to inventory.\n";
    return 0;
}

int Inventory::getItem(int idx) {
    return inventory_items[idx]->getDamage();
}
