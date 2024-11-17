#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Classes.cpp"

int MAX_STRING_LENGTH = 30;

// PLAYER
void init_player(Player* player, int x, int y, int health, int speed, int damage, int inventory_space);
void print_player(const Player *player);
void move_player(Player *player, int dx, int dy);
void heal_player(Player *player, int heal);
bool player_is_dead(Player *player);
void damage_player(Player *player, int damage);
// POTION
void init_potion(Potion *potion, int x, int y, int health_restore);
void print_potion(const Potion *potion);
void use_potion(Player *player, Potion *potion);
// COIN
void init_coin(Coin *coin, int x, int y);
void collect_coin(Player *player, Coin *coin);
void print_coin(const Coin *coin);
// INVENTORY
void init_inventory(Inventory *inventory, int space);
void print_inventory(Inventory *inventory);
int inventory_add_item(Inventory *inventory, Item *item);
// MONSTER
void init_monster(Monsters *monster, int x, int y, int damage, int health);
void print_monster(const Monsters *monster);
void monster_attack(Player *player, Monsters *monster);
void damage_monster(Monsters *monster, int amount);
// ITEM
void init_item(Item *item, int x, int y, const char *item_name, int damage);
void print_item(Item *item);

int main()
{
    // Создаем объекты структур
    Player player;

    Monsters monster1;
    Monsters monster2;

    Inventory inventory;

    Item item1;
    Item item2;
    Item item3;

    Coin coin;
    Potion potion;
    Health health;

    // Инициализируем объекты
    
    init_inventory(&inventory, 10);
    init_potion(&potion, 3, 3, 4);
    init_coin(&coin, 2, 5);
    init_player(&player, 0, 0, 10, 3, 7, 10);
    init_monster(&monster1, 14, 7, 5, 15);
    init_monster(&monster2, 15, 8, 2, 10);

    init_item(&item1, 5, 5, "Sword", 7);
    init_item(&item2, 6, 6, "Gun", 18);
    init_item(&item3, 7, 7, "Bow", 3);

    // Выводим инфу об объектах
    print_player(&player);
    print_potion(&potion);
    print_coin(&coin);
    print_inventory(&inventory);
    print_monster(&monster1);
    print_item(&item2);

    // Добавление предметов в инвентарь
    inventory_add_item(&inventory, &item1);
    inventory_add_item(&inventory, &item2);
    inventory_add_item(&inventory, &item3);

    // Печать содержимого инвентаря
    printf("Inventory contents:\n");
    for (int i = 0; i < inventory.items_count; i++)
    {
        printf("  Item %d: %s\n", i + 1, inventory.inventory_items[i]);
    }

    return 0;
}

// ------------- Player -----------------
void init_player(Player *player, int x, int y, int health, int speed, int damage, int inventory_space)
{
    // координаты
    player->x = x;
    player->y = y;
    // здоровье
    player->health.max_health = health;
    player->health.current_health = health;
    // рюкзак
    player->inventory.space = inventory_space;
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
void print_player(const Player *player)
{
    printf("Player Position: (%d, %d)\n", player->x, player->y);
    printf("Health: %d/%d\n", player->health.current_health, player->health.max_health);
    printf("Speed: %d\n", player->speed);
    printf("Player inventory space: %d, items count: %d\n", player->inventory.space, player->inventory.items_count);
}

// перемещение игрока
void move_player(Player *player, int dx, int dy)
{
    player->x += dx * player->speed;
    player->y += dy * player->speed;
    printf("Player moved to (%d, %d)\n", player->x, player->y);
}

// лечим игрока
void heal_player(Player *player, int heal)
{
    if (player->health.current_health < player->health.max_health)
    {
        player->health.current_health += heal;
        printf("Player's health: %d\n", player->health.current_health);
    }
    else
        printf("Player has maximum health points\n");
}

// проверям, умер ли игрок
bool player_is_dead(Player *player)
{
    if (player->health.current_health <= 0)
    {
        player->health.current_health = 0;
        player->is_alive = false;
        return true;
    }
    return false;
}

// колечим игрока
void damage_player(Player *player, int damage)
{
    player->health.current_health -= damage;
    if (player_is_dead(player))
    {
        printf("Player is dead\n");
    }
}

// ------------ Potion ------------------------
void init_potion(Potion *potion, int x, int y, int health_restore)
{
    potion->x = x;
    potion->y = y;
    potion->health_restore = health_restore;
    potion->collected = false;
}

void print_potion(const Potion *potion)
{
    printf("Potion Position: (%d, %d)\n", potion->x, potion->y);
    printf("Health Restore: %d\n", potion->health_restore);
    printf("Collected: %s\n", potion->collected ? "Yes" : "No");
}

void use_potion(Player *player, Potion *potion)
{
    if (!potion->collected)
    {
        heal_player(player, potion->health_restore);
        potion->collected = true;
        printf("Potion used! Health restored to %d/%d\n", player->health.current_health, player->health.max_health);
    }
}

// ------------Coin ------------------------
void init_coin(Coin *coin, int x, int y)
{
    coin->x = x;
    coin->y = y;
    coin->collected = false;
}

void print_coin(const Coin *coin)
{
    printf("Coin Position: (%d, %d)\n", coin->x, coin->y);
    printf("Collected: %s\n", coin->collected ? "Yes" : "No");
}

void collect_coin(Player *player, Coin *coin)
{
    if (!coin->collected)
    {
        coin->collected = true;
        player->coins += 1;
        printf("Coin collected! Total coins: %d\n", player->coins);
    }
}

// ------------Inventory ------------------------
void init_inventory(Inventory *inventory, int space)
{
    inventory->space = inventory->current_space = space;
    inventory->items_count = 0;
    inventory->current_element = 0;
    inventory->inventory_items = (char **)malloc(inventory->space * sizeof(char *));
}

void print_inventory(Inventory *inventory)
{
    printf("Inventory space: %d\n", inventory->space);
    printf("Inventory intems: %d\n", inventory->items_count);
    printf("Inventory current element: %d\n", inventory->current_element);
}

int inventory_add_item(Inventory *inventory, Item *item)
{
    if (inventory->items_count >= inventory->space)
    {
        printf("Inventory is full! Cannot add item '%s'.\n", item->item_name);
        return 0; // Не удалось добавить предмет
    }

    // Добавление предмета в массив строк
    inventory->inventory_items[inventory->items_count] = _strdup(item->item_name);
    inventory->items_count++;
    inventory->current_space--; // Уменьшаем свободное место
    item->collected = 1;        // Помечаем предмет как собранный
    printf("Item '%s' added to inventory.\n", item->item_name);
}

// ------------Monsters ------------------------
void init_monster(Monsters *monster, int x, int y, int damage, int health)
{
    monster->x = x;
    monster->y = y;
    monster->damage = damage;
    monster->health.current_health = health;
    monster->is_alive = true;
}

void print_monster(const Monsters *monster)
{
    printf("Monster Position: (%d, %d)\n", monster->x, monster->y);
    printf("Damage: %d\n", monster->damage);
    printf("Health: %d\n", monster->health.current_health);
    printf("Is Alive: %s\n", monster->is_alive ? "Yes" : "No");
}

void monster_attack(Player *player, Monsters *monster)
{
    if (monster->is_alive && player->health.current_health > 0)
    {
        damage_player(player, monster->damage);
        printf("Monster attacked! Player health: %d/%d\n", player->health.current_health, player->health.max_health);
    }
}

void damage_monster(Monsters *monster, int amount)
{
    monster->health.current_health -= amount;
    if (monster->health.current_health <= 0)
    {
        monster->health.current_health = 0;
        monster->is_alive = false;
        printf("Monster defeated!\n");
    }
}

//--------------- ITEMS ------------------------------------
void init_item(Item *item, int x, int y, const char *item_name, int damage)
{
    item->x = x;
    item->y = y;
    item->item_name = item_name;
    item->damage = damage;
}

void print_item(Item *item)
{
    printf("Potion Position: (%d, %d)\n", item->x, item->y);
    printf("Item damage: %d\n", item->damage);
    printf("Is item collected: %s\n", item->collected ? "Yes" : "No");
}
