#include "Coin.h"




Coin::Coin() : Coordinates(0,0), value(5), collected(false) {}

int Coin::getX()  { return x; }
int Coin::getY()  { return y; }
int Coin::getValue() const { return value; }

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

ostream& operator<<(ostream& os, Coin& coin)
{
    os << "Coin Position: (" << coin.x << ", " << coin.y << ")\n";
    os << "Collected: " << (coin.is_collected() ? "Yes" : "No") << "\n";
    return os;
}
