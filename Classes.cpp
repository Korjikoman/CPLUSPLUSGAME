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
    int space;  // 
    int items_count;  
    int current_element;
    int current_space;
    char** inventory_items;
};


struct Monsters {
    int x, y;
    bool is_alive;
    const char* type;   // монстры подразделяются по видам сложности 
    int damage;  // урон наносимый монстром
    Health health;
    bool is_alive;
};


struct Player {
    int x, y;
    Health health;
    int speed;
    int damage;
    Inventory inventory;
    Potion* potions;
    bool is_alive;
    int coins;
};

struct Menu {
    int selected_option;
    int highest_score;
};