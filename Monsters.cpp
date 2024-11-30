#include "Monsters.h"


Monsters::Monsters() : x(0), y(0), health(10), damage(2), is_alive(true) {}
// инициализация
Monsters::Monsters(int m_x, int m_y, int m_damage, int m_health) :
    x(m_x), y(m_y), health(m_health), damage(m_damage), is_alive(true)
{}
int Monsters::getX() const { return x; }
int Monsters::getY() const { return y; }
int Monsters::getDamage() const { return damage; }
int Monsters::getHealth() { return health.getCurrentHealth(); }

void Monsters::changeHealthValue(int value) {
    health.changeHealthValue(value);
}
bool Monsters::isAlive() const { return is_alive; }
// вывод характеристик монстра
void Monsters::printMonster() {
    printf("Monster Position: (%d, %d)\n", x, y);
    printf("Damage: %d\n", damage);
    printf("Health: %d\n", health.getCurrentHealth());
    printf("Is Alive: %s\n", is_alive ? "Yes" : "No");
}

void Monsters::move(int dx, int dy) {
    x = dx;
    y = dy;

}

void Monsters::changeX(int value)
{
    x = value;
}

void Monsters::changeY(int value)
{
    y = value;
}

void Monsters::is_dead() { is_alive = false; }

// Генерируем случайные координаты монстра
void Monsters::move_random() {
    int dx = std::rand() % 15 + 1;
    int dy = std::rand() % 15 + 1;
    move(dx, dy);
}
