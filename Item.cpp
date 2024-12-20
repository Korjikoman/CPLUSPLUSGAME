#include "Item.h"



Item::Item() : Coordinates(0,0) {
    std::cout << "Initializing Item...\n";

    std::cout << "Enter the name of the item: ";
    std::cin.ignore(); // Очищаем буфер
    std::getline(std::cin, item_name);

    std::cout << "Enter the damage of the item: ";
    std::cin >> damage;

    collected = false; // По умолчанию предмет не собран
    std::cout << "Item initialized successfully!\n";
}

int Item::getX() { return x; };
int Item::getY() { return y; };
std::string Item::getName() const { return item_name; }
int Item::getDamage() { return damage; }
bool Item::isCollected() { return collected; }
void Item::Collected() { collected = true; }



void Item::changeX(int value)
{
    x = value;
}

void Item::changeY(int value)
{
    y = value;
}

ostream& operator<<(ostream& os, Item& item)
{
    os << "Item Position: (" << item.x << " ; " << item.y << ")\n";
    os << "Item damage: " << item.damage << "\n";
    os << "Collected: " << (item.collected ? "Yes" : "No") << "\n";

    return os;
}
