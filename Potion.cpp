#include "Potion.h"

int Potion::health_restore = 4;

Potion::Potion() : Coordinates(0,0), collected(false) {}

bool Potion::isCollected() const { return collected; }
void Potion::collect() { collected = true; };
int Potion::getX()  { return x; }
int Potion::getY()  { return y; }
int Potion::getHealthRestore() { return health_restore; }
void Potion::setHealthRestore(int value)
{
    health_restore = value;
}

void Potion::move(int dx, int dy) {
    x = dx;
    y = dy;
}
// Генерируем случайные координаты зелья
void Potion::move_random()
{
    int dx = std::rand() % 15 + 1;
    int dy = std::rand() % 15 + 1;
    move(dx, dy);
}

void Potion::changeX(int value)
{
    x = value;
}

void Potion::changeY(int value) { y = value; }


// Перегрузка оператора + для объединения двух зелий
const Potion operator+(const Potion& potion1, const Potion& potion2) {
    Potion newPotion;

    newPotion.health_restore = potion1.health_restore + potion2.health_restore;

    // Возвращаем новый объект Potion
    return newPotion;
}

ostream& operator<<(ostream& os, Potion& potion)
{
    os << "Potion Position: (" << potion.x << ", " << potion.y << ")\n";
    os << "Health Restore: " << potion.health_restore << "\n";
    os << "Collected: " << (potion.collected ? "Yes" : "No") << "\n";
    return os;
}

Potion& Potion::operator++() {
    ++x;
    ++y;
    return *this; 
}

Potion Potion::operator++(int) {
    Potion temp = *this;
    ++x;
    ++y;
    return temp;
}