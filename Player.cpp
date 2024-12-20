#include "Player.h"


Player::Player() : Object(0, 0, 0, 0)
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

   

    coins = 0;         // Начальное количество монет

    std::cout << "Player " << name << " initialized successfully!\n";
}

Player::Player(std::string name, int x, int y, int health, int speedd, int damage) : Object(x,y,health,damage)
{
    std::cout << "Initializing player...\n";
    speed = 1;
    coins = 0;
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

void Player::addPotion(Potion& potion)
{
    inventory.inventoryAddPotion(&potion);
}

// проверяем, умер ли игрок

Inventory Player::getInventory() {
    return inventory;
}


void Player::add_coins(int value) { coins += value; }
int Player::get_coins() { return coins; }

int Player::getspeed() { return speed; }

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

void Player::heal() {
    if (inventory.getPotionsCount() > 0) {
        changeHealthValue(4);
        inventory.usePotion();
        std::cout << "Player used a potion. Potions left: " << inventory.getPotionsCount() << "\n";
    }
    else {
        std::cout << "No potions left to heal!\n";
    }

    /*Object::heal(10);*/
}


Player& Player::operator=(Object& obj) {
    if (this != &obj) {
        // Копируем общие поля базового класса
        setX(obj.getX());
        setY(obj.getY());
        setHealth(obj.getCurrentHealth());
        setDamage(obj.getDamage());
        this->name = obj.getName(); 
    }
    return *this;
}

// выводим основные характеристики игрока
std::ostream& operator<<(std::ostream& os, Player& player) {
    
    os << static_cast<Object&>(player);
    os << "Speed: " << player.getspeed() << "\n";
    os << "Inventory Space: " << player.getInventory().getSpace()
        << ", Items Count: " << player.getInventory().getItemsCount() << "\n";
    os << "Potions: " << player.getInventory().getPotionsCount() << "\n";
    os << "Coins: " << player.get_coins() << "\n";
    return os;
    
}