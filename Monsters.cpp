#include "Monsters.h"

std::vector<std::string> Monsters::names = { "Bob", "Dill", "Frank", "Sugarboy" };

Monsters::Monsters() {
   
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел
    name = names[rand() % names.size()];
    setHealth(10);
    setDamage(5);
}


// вывод характеристик монстра
void Monsters::printMonster() {
    std::cout << "Monster Name: " << name << std::endl;
    printf("Monster Position: (%d, %d)\n", getX(), getY());
    printf("Damage: %d\n", getDamage());
    printf("Health: %d\n", getCurrentHealth());
    printf("Is Alive: %s\n", isAlive() ? "Yes" : "No");
}

void Monsters::move(int dx, int dy) {
    setX(dx);
    setY(dy);

}


