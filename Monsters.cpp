#include "Monsters.h"



Monsters::Monsters() {
    x = 0;
    y = 0;
    damage = 2;
    is_alive = true;
    health = 10;
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел
    name = names[rand() % names.size()];
}

std::vector<std::string> Monsters::names = { "Bob", "Dill", "Frank", "Sugarboy" };


int Monsters::getX() const { return x; }
int Monsters::getY() const { return y; }
int Monsters::getDamage() const { return damage; }
int Monsters::getHealth() { return health; }

void Monsters::changeHealthValue(int value) {
    health = value;
}
bool Monsters::isAlive() const { return is_alive; }
// вывод характеристик монстра
void Monsters::printMonster() {
    std::cout << "Monster Name: " << name << std::endl;
    printf("Monster Position: (%d, %d)\n", x, y);
    printf("Damage: %d\n", damage);
    printf("Health: %d\n", health);
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

