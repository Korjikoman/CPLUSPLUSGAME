#include "Monsters.h"

std::vector<std::string> Monsters::names = { "Bob", "Dill", "Frank", "Sugarboy" };

Monsters::Monsters() {
   
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел
    name = names[rand() % names.size()];
    setHealth(10);
    setDamage(5);
}



void Monsters::move(int dx, int dy) {
    setX(dx);
    setY(dy);

}


Monsters& Monsters::operator=(Object& obj) {
    if (this != &obj) {
        // Копируем общие поля базового класса
        setX(obj.getX());
        setY(obj.getY());
        setHealth(obj.getCurrentHealth());
        setDamage(obj.getDamage());
        this->name = obj.getName();
    }
    return *this;
}

// вывод характеристик монстра
std::ostream& operator<<(std::ostream& os, Monsters& monster) {
    os << static_cast<Object&>(monster);

    printf("Health: %d\n", monster.getCurrentHealth());
    printf("Is Alive: %s\n", monster.isAlive() ? "Yes" : "No");
    return os;
}