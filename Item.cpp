#include "Item.h"



Item::Item() {
    std::cout << "Initializing Item...\n";

    std::cout << "Enter the name of the item: ";
    std::cin.ignore(); // Очищаем буфер
    std::getline(std::cin, item_name);

    std::cout << "Enter the damage of the item: ";
    std::cin >> damage;

    collected = false; // По умолчанию предмет не собран
    x = 0;
    y = 0;
    std::cout << "Item initialized successfully!\n";
}

int Item::getX() { return x; };
int Item::getY() { return y; };
std::string Item::getName() const { return item_name; }
int Item::getDamage() { return damage; }
bool Item::isCollected() { return collected; }
void Item::Collected() { collected = true; }

// вывод характеристик оружия
void Item::print_item() {
    printf("Item Position: (%d, %d)\n", x, y);
    printf("Item damage: %d\n", damage);
    printf("Is item collected: %s\n", collected ? "Yes" : "No");
}

void Item::changeX(int value)
{
    x = value;
}

void Item::changeY(int value)
{
    y = value;
}
