
#include <iostream>
#include <stdio.h>
#include <stdbool.h>

#include "Classes.cpp"

int main()
{
    std::cout << "Hello World!\n";
}


// --------------------- PLAYER ----------------
 
void init_player(Player* player, int x, int y, int health, int speed, int damage) {
    // координаты
    player->x = x;
    player->y = y;
    // здоровье
    player->health.max_health = health;
    player->health.current_health = health;
    //рюкзак
    player->inventory.space = 4;
    player->inventory.items_count = 0;
    player->inventory.current_element = 0;
    // скорость перевижения и урон врагам 
    player->speed = speed;
    player->damage = damage;
    // возрождение
    player->is_alive = true;
    // сколько собрал монеток
    player->coins = 0;
}

void print_player(const Player* player) {
    printf("Player Position: (%d, %d)\n", player->x, player->y);
    printf("Health: %d/%d\n", player->health.current_health, player->health.max_health);
    printf("Speed: %d\n", player->speed);
    printf("Coins: %d\n", player->coins);

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

// --------------- COINS -----------------
void init_coin(Coin* coin, int x, int y) {
    coin->x = x;
    coin->y = y;
    coin->collected = false;
}


void print_coin(const Coin* coin) {
    printf("Coin Position: (%d, %d)\n", coin->x, coin->y);
    printf("Collected: %s\n", coin->collected ? "Yes" : "No");
}



// --------------- POTION ------------------------
void init_potion(Potion* potion, int x, int y, int health_restore) {
    potion->x = x;
    potion->y = y;
    potion->health_restore = health_restore;
    potion->collected = false;
}

void print_potion(const Potion* potion) {
    printf("Potion Position: (%d, %d)\n", potion->x, potion->y);
    printf("Collected: %s\n", potion->collected ? "Yes" : "No");
}


// ------------------- INVENTORY ---------------------
void init_inventory(Inventory* inventory, int space) {
    inventory->space = space;
    inventory->items_count = 0;
    inventory->current_element = 0;
}

void print_inventory(Inventory* inventory) {
    printf("Inventory space: %d\n", inventory->space);
    printf("We've got %d items here: %d\n", inventory->items_count);
    printf("Current element index [%d]\n", inventory->current_element);
}


// --------------- MONSTERS ------------------
void init_monster(Monsters* monster, int x, int y, const char* type, int damage, int health) {
    monster->x = x;
    monster->y = y;
    monster->type = type;
    monster->damage = damage;
    monster->health.max_health = health;
    monster->health.current_health = health;
    monster->is_alive = true;
}

void print_monster(Monsters* monster) {
    printf("Monster position: (%d;%d)\n", monster->x, monster->y);
    printf("Monster type: %s\n", monster->type);
    printf("Monster damage: %d\n", monster->damage);
    printf("Monster max health: %d\n", monster->health.max_health);
    printf("Monster health: %d\n", monster->health.current_health);
    printf("MONSTER IS READY TO KILL");
}

void manster_attack(Monsters* monster, Player* player) {
    if (monster->is_alive && player->is_alive) {
        printf("Monster attacked!");
        player->health.current_health -= 1;
        if (player->health.current_health <= 0) {
            printf("Player is dead");
            player->is_alive = false;
        }
    }
}

void damage_monster(Monsters* monster, int damage) {
    monster->health.current_health -= damage;
    if (monster->health.current_health <= 0) {
        printf("Monster is dead");
        monster->is_alive = false;
    }
}