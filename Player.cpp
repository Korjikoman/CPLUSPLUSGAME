#include "Player.h"


Player::Player()
{
    std::cout << "Initializing player...\n";
    std::cout << "Player's name (<= 100 characters): \n";
    name = safeString(100);

    std::cout << "Coordinates of a player: (0;0)\n";

    std::cout << "Enter the initial health of the player ";
    int init_health = safeInt(1,10);
    changeHealthValue(init_health);

    std::cout << "Enter the speed of the player ";
    speed = safeInt(1, 10);

    std::cout << "Enter the damage of the player ";
    int init_damage = safeInt(1, 2);
    setDamage(init_damage);

    // Инициализация родительского класса Object

    potions_count = 0; // Инициализация по умолчанию
    coins = 0;         // Начальное количество монет

    std::cout << "Player " << name << " initialized successfully!\n";
}

// перемещаем игрока
Player& Player::movePlayer(int x, int y) {
    setX(getX() + x);
    setY(getY() + y);
    printf("Player moved to (%d, %d)\n", getX(), getY());
    return *this;
}

void Player::printCoordinates() {
    std::cout << "Player is at (" << getX() << ", " << getY() << ")\n";
}

// проверяем, умер ли игрок

Inventory Player::getInventory() {
    return inventory;
}


void Player::add_coins(int value) { coins += value; }
int Player::get_coins() { return coins; }

int Player::getspeed() { return speed; }

// выводим основные характеристики игрока
void Player::printPlayer()
{
    printf("Player Position: (%d, %d)\n", getX(), getY());
    printf("Health: %d/%d\n", getCurrentHealth(), getMaxHealth());
    printf("Speed: %d\n", speed);
    printf("Player inventory space: %d, items count: %d\n", inventory.getSpace(), inventory.getItemsCount());
    printf("Player coins: %d\n", coins);
} // вывод игрока


void Player::addItems(Item* item)
{
    inventory.inventoryAddItem(item);
}

int Player::getItemsCount() {
   return  inventory.getItemsCount();
}

Item* Player::getItem(const std::string& itemName) {
    Item*** items = inventory.getInventoryItems();
    for (int i = 0; i < Inventory::getSpace(); i++) {
        for (int j = 0; j < Inventory::getSpace(); j++) {
            std::cout << "Item [" << i + 1 << ";" << j+1 << "]" << items[i][j]->getName() << ", Damage: " << items[i][j]->getDamage() << std::endl;
            if (items[i][j]->getName().find(itemName) != std::string::npos) return items[i][j];
        }

    }
 
    return nullptr;
}

std::string Player::getName() {
    return name;
}