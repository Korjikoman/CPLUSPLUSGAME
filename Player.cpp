#include "Player.h"

Player::Player()
{
    int p_health;
    std::cout << "Initializing player...\n";

    std::cout << "Coordinates of a player: (" << x << "; " << "y)\n";


    std::cout << "Enter the initial health of the player: ";
    std::cin >> p_health;
    health.changeHealthValue(p_health);


    std::cout << "Enter the speed of the player: ";
    std::cin >> speed;

    std::cout << "Enter the damage of the player: ";
    std::cin >> damage;



    potions_count = 0; // ������������� �� ���������
    is_alive = true;   // ����� ��� ��� ��������
    coins = 0;         // ��������� ���������� �����

    std::cout << "Player initialized successfully!\n";
}

// ���������� ������
void Player::movePlayer(int dx, int dy) {
    x = dx * speed;
    y = dy * speed;
    printf("Player moved to (%d, %d)\n", x, y);
}

// ���������, ���� �� �����
bool Player::isAlive() {
    return is_alive;

}
Inventory Player::getInventory() {
    return inventory;
}


void Player::add_coins(int value) { coins += value; }
int Player::get_coins() { return coins; }
int Player::getX() { return x; }
int Player::getY() { return y; }
int Player::getspeed() { return speed; }
// ������� �������� �������������� ������
void Player::printPlayer()
{
    printf("Player Position: (%d, %d)\n", x, y);
    printf("Health: %d/%d\n", health.getCurrentHealth(), health.getMaxHealth());
    printf("Speed: %d\n", speed);
    printf("Player inventory space: %d, items count: %d\n", inventory.getSpace(), inventory.getItemsCount());
    printf("Player coins: %d\n", coins);
} // ����� ������

int Player::getCurrentHealth() {
    return health.getCurrentHealth();
}

int Player::getMaxHealth() {
    return health.getMaxHealth();
}
// ������ �������� �������� �������� ������ (��������, ��� ����� � �������� �� ������ ��������)
void Player::changeHealthValue(int new_value) {
    health.changeHealthValue(new_value);
}

void Player::heal(int value) {
    health.heal(value);
}
int Player::getDamage() { return damage; }

void Player::is_dead() { is_alive = false; }
