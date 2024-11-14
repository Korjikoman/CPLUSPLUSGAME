
#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Classes.cpp"

int MAX_STRING_LENGTH = 30;

int main()
{
    std::cout << "Hello World!\n";
}


// ------------- Player -----------------
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
    // монетки  
    player->coins = 0;
}

// выводим характеристики игрока
void print_player(const Player *player) {
    printf("Player Position: (%d, %d)\n", player->x, player->y);
    printf("Health: %d/%d\n", player->health.current_health, player->health.max_health);
    printf("Speed: %d\n", player->speed);
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
    if (player_is_dead(player)) {
        printf("Player is dead");
    }

}



// передвижение игрока
void move_player(Player *player, int dx, int dy) {
    player->x += dx * player->speed;
    player->y += dy * player->speed;
}

// проверям, умер ли игрокg
bool player_is_dead(Player *player){
    if(player->health.current_health <= 0 ){
        player->health.current_health = 0;
        player->is_alive = false;
        return true;
    }
    return false;
}


// ------------Potion ------------------------
void init_potion(Potion *potion, int x, int y, int health_restore) {
    potion->x = x;
    potion->y = y;
    potion->health_restore = health_restore;
    potion->collected = false;
}

void print_potion(const Potion *potion) {
    printf("Potion Position: (%d, %d)\n", potion->x, potion->y);
    printf("Health Restore: %d\n", potion->health_restore);
    printf("Collected: %s\n", potion->collected ? "Yes" : "No");
}

void use_potion(Player *player, Potion *potion) {
    if (!potion->collected) {
        heal_player(player, potion->health_restore);
        potion->collected = true;
        printf("Potion used! Health restored to %d/%d\n", player->health.current_health, player->health.max_health);
    }
}

// ------------Coin ------------------------
void init_coin(Coin *coin, int x, int y) {
    coin->x = x;
    coin->y = y;
    coin->collected = false;
}

void print_coin(const Coin *coin) {
    printf("Coin Position: (%d, %d)\n", coin->x, coin->y);
    printf("Collected: %s\n", coin->collected ? "Yes" : "No");
}

void collect_coin(Player *player, Coin *coin) {
    if (!coin->collected) {
        coin->collected = true;
        player->coins += 1;
        printf("Coin collected! Total coins: %d\n", player->coins);
    }
}

// ------------Inventory ------------------------
void init_inventory(Inventory *inventory, int space){
    inventory->space =  inventory->current_space = space;
    inventory->items_count = 0;    
    inventory->current_element = 0;
    inventory->inventory_items = (char**)malloc(inventory->space * sizeof(char*));

}

void print_inventory(Inventory *inventory){
    printf("Inventory space: %d\n", inventory->space);
    printf("Inventory intems: %d\n", inventory->items_count);
    printf("Inventory current element: %d\n", inventory->current_element);
}

void inventory_add_item(Inventory *inventory, char *item_name){
    inventory->inventory_items[inventory->current_space + 1] = (char*)malloc(MAX_STRING_LENGTH + 1 * sizeof(char));
    strcpy(inventory->inventory_items[inventory->current_space], item_name);
}

// ------------Monsters ------------------------
void init_monster(Monsters *monster, int x, int y, int damage, int health) {
    monster->x = x;
    monster->y = y;
    monster->damage = damage;
    monster->health.current_health = health;
    monster->is_alive = true;
}

void print_monster(const Monsters *monster) {
    printf("Monster Position: (%d, %d)\n", monster->x, monster->y);
    printf("Damage: %d\n", monster->damage);
    printf("Health: %d\n", monster->health);
    printf("Is Alive: %s\n", monster->is_alive ? "Yes" : "No");
}

void monster_attack(Player *player, Monsters *monster) {
    if (monster->is_alive && player->health.current_health > 0) {
        damage_player(player, monster->damage);
        printf("Monster attacked! Player health: %d/%d\n", player->health.current_health, player->health.max_health);
    }
}

void damage_monster(Monsters *monster, int amount) {
    monster->health.current_health -= amount;
    if (monster->health.current_health <= 0) {
        monster->health.current_health = 0;
        monster->is_alive = false;
        printf("Monster defeated!\n");
    }
}

// ------------------- Menu ------------------------
void menu_init(Menu *menu){
    menu->selected_option = 0;
    menu->highest_score = 0;
}

