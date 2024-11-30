#include "Coin.h"




Coin::Coin(int px, int py, int val)
    : x(px), y(py), value(val), collected(false) {}

int Coin::getX() const { return x; }
int Coin::getY() const { return y; }
int Coin::getValue() const { return value; }
void Coin::print_coin() {
    std::cout << "Coin Position: (" << getX() << ", " << getY() << ")\n";
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

