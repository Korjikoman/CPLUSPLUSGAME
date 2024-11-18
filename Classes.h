#include <iostream>
#include <stdio.h>
#include <stdbool.h>

class Health // структура для представления здоровья игрока
{
private:
    int current_health;
    int max_health;
public:
    Health(int current, int max);
    int getCurrentHealth() const;
    int getMaxHealth() const;
};

class Potion // структура для представления зелий восстановления
{
    private:
        int x, y;
        int health_restore;
        bool collected;
    public:
    Potion(int px, int py, int restore);

    bool isCollected() const;
    void collect();
    void print_potion();
    int getRestoreAmount();
    int getX();
    int getY();

};

class Coin // структура для представления монеток
{
    private:
        int x, y;
        int value;
        bool collected;
    public:
    int getX();
    int getY();
    int getValue();
    Coin(int px, int py);
    void print_coin();
    void collect_coin(Player& player);

};

class Inventory // структура для представления инвенторя игрока
{
    private:
        int space; 
        int items_count;
        int current_element;
        int current_space;
        struct Item **inventory_items;

    public: 
    Inventory(int space); // инициализация
    
    void print_inventory(); // вывод инвентаря
    int inventory_add_item(Item& item); 
};

class Monsters // структура для представления монстров
{
    private:
        int x, y;
        int damage;
        Health health;
        bool is_alive;
    public:

Monsters(int x, int y, int damage, int health); // инициализация
void print_monster(); // вывод характеристик монстра
void monster_attack(Player& player); // монстр атакует
void damage_monster(int amount);


};

class Player // структура для представления игрока
{
    private:
        int x, y;
        Health health;
        int speed;
        int damage;
        Inventory inventory;
        Potion *potions;
        bool is_alive;
        int coins;
    public:

    Player(int x, int y, int health, int speed, int damage, int inventory_space); // инициализация
void print_player(); // вывод игрока
void move_player(int dx, int dy); // перемещаем игрока
void heal_player( int heal); // лечим игрока
bool player_is_dead(); // проверяем, умер ли игрок
void damage_player(int damage); // наносим урон игроку 


};

class Item // структура для представления оружия
{
    private:
        const char *item_name;
        int x, y;
        int collected;
        int damage;
    public:
    Item(int x, int y, const char* item_name, int damage); // инициализация
    void print_item(Item* item); // вывод характеристик оружия
};


//GAMEPLAY
void battle_with_monster(Player* player, Monsters* monster, Inventory* inventory); // функция сражения с монстром 
void use_potion(struct Player* player, struct Potion* potion); // используем зелье для восстановления здоровья