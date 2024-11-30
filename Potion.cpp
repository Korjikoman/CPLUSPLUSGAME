#include "Potion.h"



Potion::Potion() : x(0), y(0), health_restore(4), collected(false) {}
Potion::Potion(int px, int py, int restore)
{
    x = px;
    y = py;
    health_restore = restore;
    collected = false;
}

bool Potion::isCollected() const { return collected; }
void Potion::collect() { collected = true; };
int Potion::getX() const { return x; }
int Potion::getY() const { return y; }
int Potion::getHealthRestore() const { return health_restore; }
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
