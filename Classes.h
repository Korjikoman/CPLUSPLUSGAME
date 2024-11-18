#include <iostream>
#include <stdio.h>
#include <stdbool.h>

class Health // структура для представления здоровья игрока
{
private:
    int current_health;
    int max_health;
public:
    int getCurrentHealth() const { return current_health; }
    int getMaxHealth() const { return max_health; }
};

struct Potion // структура для представления зелий восстановления
{
    int x, y;
    int health_restore;
    bool collected;
};

struct Coin // структура для представления монеток
{
    int x, y;
    int value;
    bool collected;
};

struct Inventory // структура для представления инвенторя игрока
{
    int space; 
    int items_count;
    int current_element;
    int current_space;
    struct Item **inventory_items;
};

struct Monsters // структура для представления монстров
{
    int x, y;
    int damage;
    Health health;
    bool is_alive;
};

struct Player // структура для представления игрока
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

struct Item // структура для представления оружия
{
    const char *item_name;
    int x, y;
    int collected;
    int damage;
};


// PLAYER
void init_player(Player* player, int x, int y, int health, int speed, int damage, int inventory_space); // инициализация
void print_player(const Player* player); // вывод игрока
void move_player(Player* player, int dx, int dy); // перемещаем игрока
void heal_player(Player* player, int heal); // лечим игрока
bool player_is_dead(Player* player); // проверяем, умер ли игрок
void damage_player(Player* player, int damage); // наносим урон игроку 

// POTION
void init_potion(Potion* potion, int x, int y, int health_restore); // инициализация
void print_potion(const Potion* potion); // вывод зелья
void use_potion(Player* player, Potion* potion);  // используем зелье

// COIN
void init_coin(Coin* coin, int x, int y); // инициализация
void collect_coin(Player* player, Coin* coin); // собираем монетку
void print_coin(const Coin* coin);// вывод монетки

// INVENTORY    
void init_inventory(Inventory* inventory, int space); // инициализация
void print_inventory(Inventory* inventory); // вывод инвентаря
int inventory_add_item(Inventory* inventory, Item* item); // добавляем предмет в инвентарь

// MONSTER
void init_monster(Monsters* monster, int x, int y, int damage, int health); // инициализация
void print_monster(const Monsters* monster); // вывод характеристик монстра
void monster_attack(Player* player, Monsters* monster); // монстр атакует
void damage_monster(Monsters* monster, int amount); // наносим урон монстру
// ITEM
void init_item(Item* item, int x, int y, const char* item_name, int damage); // инициализация
void print_item(Item* item); // вывод характеристик оружия

//GAMEPLAY
void battle_with_monster(Player* player, Monsters* monster, Inventory* inventory); // функция сражения с монстром 
void use_potion(struct Player* player, struct Potion* potion); // используем зелье для восстановления здоровья