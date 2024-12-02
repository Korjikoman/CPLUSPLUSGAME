#include "Player.h"

int Player::maxHealth = 10;

Player::Player()
{
    std::cout << "Initializing player...\n";

    std::cout << "Coordinates of a player: (" << x << "; " << y <<")\n";


    std::cout << "Enter the initial health of the player: ";
    std::cin >> health;


    std::cout << "Enter the speed of the player: ";
    std::cin >> speed;

    std::cout << "Enter the damage of the player: ";
    std::cin >> damage;



    potions_count = 0; // Инициализация по умолчанию
    is_alive = true;   // Игрок жив при создании
    coins = 0;         // Начальное количество монет

    std::cout << "Player initialized successfully!\n";
}

// перемещаем игрока
Player& Player::movePlayer(int x, int y) {
    this->x += x;
    this->y += y;
    printf("Player moved to (%d, %d)\n", this->x, this->y);
    return *this;
}

void Player::printCoordinates() {
    std::cout << "Player is at (" << x << ", " << y << ")\n";
}

// проверяем, умер ли игрок
bool Player::isAlive() {
    return is_alive;

}
Inventory Player::getInventory() {
    return inventory;
}


void Player::add_coins(int value) { coins += value; }
int Player::get_coins() { return coins; }
int& Player::getX() { return x; }
int& Player::getY() { return y; }
int Player::getspeed() { return speed; }
// выводим основные характеристики игрока
void Player::printPlayer()
{
    printf("Player Position: (%d, %d)\n", x, y);
    printf("Health: %d/%d\n", health, Player::maxHealth);
    printf("Speed: %d\n", speed);
    printf("Player inventory space: %d, items count: %d\n", inventory.getSpace(), inventory.getItemsCount());
    printf("Player coins: %d\n", coins);
} // вывод игрока

int Player::getCurrentHealth() {
    return health;
}

// Меняем значение текущего здоровья игрока (например, при битве с монстром он теряет здоровье)
void Player::changeHealthValue(int new_value) {
    health = new_value;
}

void Player::heal(int value) {
    health += value;
}
int Player::getDamage() { return damage; }

void Player::is_dead() { is_alive = false; }


void Player::addItems(Item* item)
{
    inventory.inventoryAddItem(item);
}

int Player::getItemsCount() {
   return  inventory.getItemsCount();
}

Item* Player::getItem(const std::string& itemName) {
    Item** items = inventory.getInventoryItems();
    for (int i = 0; i < inventory.getItemsCount(); ++i) {
        std::cout << "Item " << i + 1 << ": " << items[i]->getName() << ", Damage: " << items[i]->getDamage() << std::endl;
        if (items[i]->getName() == itemName) return items[i];
    }
 
    return nullptr;
}


void Player::setMaxHealth(int value) {
    Player::maxHealth = value;
}


int Player::getMaxHealth() {
    return maxHealth;
}