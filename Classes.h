#include <iostream>
#include <stdio.h>
#include <stdbool.h>

struct Health
{
    int current_health;
    int max_health;
};

struct Potion
{
    int x, y;
    int health_restore;
    bool collected;
};

struct Coin
{
    int x, y;
    int value;
    bool collected;
};

struct Inventory
{
    int space; //
    int items_count;
    int current_element;
    int current_space;
    struct Item **inventory_items;
};

struct Monsters
{
    int x, y;
    int damage; // ���� ��������� ��������
    Health health;
    bool is_alive;
};

struct Player
{
    int x, y;
    Health health;
    int speed;
    int damage;
    Inventory inventory;
    Potion *potions;
    bool is_alive;
    int coins;
};

struct Item
{
    const char *item_name;
    int x, y;
    int collected;
    int damage;
};


// PLAYER
void init_player(Player* player, int x, int y, int health, int speed, int damage, int inventory_space);
void print_player(const Player* player);
void move_player(Player* player, int dx, int dy);
void heal_player(Player* player, int heal);
bool player_is_dead(Player* player);
void damage_player(Player* player, int damage);
// POTION
void init_potion(Potion* potion, int x, int y, int health_restore);
void print_potion(const Potion* potion);
void use_potion(Player* player, Potion* potion);
// COIN
void init_coin(Coin* coin, int x, int y);
void collect_coin(Player* player, Coin* coin);
void print_coin(const Coin* coin);
// INVENTORY
void init_inventory(Inventory* inventory, int space);
void print_inventory(Inventory* inventory);
int inventory_add_item(Inventory* inventory, Item* item);
// MONSTER
void init_monster(Monsters* monster, int x, int y, int damage, int health);
void print_monster(const Monsters* monster);
void monster_attack(Player* player, Monsters* monster);
void damage_monster(Monsters* monster, int amount);
// ITEM
void init_item(Item* item, int x, int y, const char* item_name, int damage);
void print_item(Item* item);
