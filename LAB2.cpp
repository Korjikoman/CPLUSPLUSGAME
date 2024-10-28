
#include <iostream>
#include <stdio.h>
#include <stdbool.h>

int main()
{
    std::cout << "Hello World!\n";
}


struct Health {
    int current_health;
    int max_health; 
};

struct Potion {
    int x, y;
    int health_restore;
    bool collected;
};

struct Coin {
    int x, y;
    bool collected; 
};

struct Inventory {
    int space;  // сколько влезет в рюкзак
    int items_count;  // сколько уже там вещей
    int current_element;
};

struct Monsters {
    int x, y;
    bool is_alive;
    const char* monster_type;   // монстры подразделяются по видам сложности 
    int m_damage = 2;  // урон наносимый монстром
    Health health;
    bool is_alive;
};

struct Player {
    int x, y; 
    const char* name = "Bob";
    Health health;
    int p_damage = 1; // урон наносимый монстрам 
    bool has_backpack = false; // есть ли у игрока рюкзак
    Inventory inventory;
    Potion* potions;
    bool is_alive;
};

