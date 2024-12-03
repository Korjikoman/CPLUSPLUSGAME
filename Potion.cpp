#include "Potion.h"

int Potion::health_restore = 4;

Potion::Potion() : x(0), y(0), collected(false) {}

bool Potion::isCollected() const { return collected; }
void Potion::collect() { collected = true; };
int Potion::getX() const { return x; }
int Potion::getY() const { return y; }
int Potion::getHealthRestore() { return health_restore; }
void Potion::setHealthRestore(int value)
{
    health_restore = value;
}
void Potion::print_potion()
{
    printf("Potion Position: (%d, %d)\n", x, y);
    printf("Health Restore: %d\n", health_restore);
    printf("Collected: %s\n", collected ? "Yes" : "No");
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