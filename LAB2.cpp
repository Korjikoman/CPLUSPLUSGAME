
#include <iostream>
#include <stdio.h>
#include <stdbool.h>

#include "Classes.cpp"

int main()
{
    std::cout << "Hello World!\n";
}



void init_player(Player* player, int x, int y, int health, int speed, int damage) {
    // координаты
    player->x = x;
    player->y = y;
    // здоровье
    player->health.max_health = health;
    //рюкзак
    player->inventory.space = 4;
    player->inventory.items_count = 0;
    player->inventory.current_element = 0;
    // скорость перевижения и урон врагам 
    player->speed = speed;
    player->damage = damage;
    // возрождение
    player->is_alive = true;
}

// перемещение игрока
void move_player(Player* player, int dx, int dy) {
    player->x += dx * player->speed;
    player->y += dy * player->speed;
}

// лечим игрока
void heal_player(Player* player, int heal) {
    if (player->health.current_health < player->health.max_health) {
        player->health.current_health += heal;
    }
    else printf("Player has maximum health points");
}

// колечим игрока
void damage_player(Player* player, int damage) {
    player->health.current_health -= damage;
    if (player->health.current_health <= 0) {
        printf("Player is dead");
        player->is_alive = false;
    }

}