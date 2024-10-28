#include <iostream>
#include <stdio.h>
#include <stdbool.h>

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
    int value;
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
    const char* monster_type;   // монстры подраздел€ютс€ по видам сложности 
    int m_damage = 2;  // урон наносимый монстром
    Health health;
    bool is_alive;
};

struct Player {
    int x, y;
    Health health;
    int speed;
    int damage; // урон наносимый монстрам 
    Inventory inventory;
    Potion* potions;
    bool is_alive;
};
