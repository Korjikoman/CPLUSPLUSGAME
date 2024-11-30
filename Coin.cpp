#include "Coin.h"




Coin::Coin() : x(0), y(0), value(5), collected(false) {}

int Coin::getX() const { return x; }
int Coin::getY() const { return y; }
int Coin::getValue() const { return value; }
void Coin::print_coin() {
    std::cout << "Coin Position: (" << x << ", " << y << ")\n";
    std::cout << "Collected: " << (is_collected() ? "Yes" : "No") << "\n";

}
bool Coin::is_collected() {
    if (collected == true) return true;
    return false;
}
// Собирем монетку
void Coin::collect_coin(Player& player, int value) {
    if (!collected)
    {
        collected = true;
        player.add_coins(value);
        printf("Coin collected! Total coins: %d\n", player.get_coins());
    }
}

void Coin::changeX(int value)
{
    x = value;
}

void Coin::changeY(int value)
{
    y = value;
}

