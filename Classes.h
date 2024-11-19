#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <string>


class Health // класс для представления здоровья игрока
{
private:
    int current_health;
    int max_health;
public:
    Health();
    Health(int max);

    int getCurrentHealth();
    int getMaxHealth();
    void changeMaxHealthValue(int value);
    void heal(int healpoints);
    void changeHealthValue(int new_value);
};


class Item // класс для представления оружия
{

private:
    std::string item_name;
    int x, y;
    bool collected;
    int damage;

public:
    // инициализация
    Item();


    std::string getName() const;
    int getDamage();
    bool isCollected();
    void Collected();

    // вывод характеристик оружия
    void print_item();

};


class Inventory // класс для представления инвентаря игрока
{
private:
    int space;
    int items_count;
    int current_element;
    Item* inventory_items;

public:
    Inventory();
    Inventory(int inv_space);

    ~Inventory(); 

    int getSpace(); 
    void changeSpace(int new_space); 
    int getCurrentElement(); 
    int getItemsCount(); 

    void print_inventory();
    int inventoryAddItem(Item& item);
    

    int getItem(int idx); 

};


class Player // класс для представления игрока
{

private:
    int x, y;
    Health health;
    int speed;
    int damage;
    Inventory inventory;
    int potions_count;

    bool is_alive;
    int coins;

public:
    // инициализация
    Player();

    // перемещаем игрока
    void movePlayer(int dx, int dy);

    // проверяем, умер ли игрок
    bool isAlive();
    Inventory getInventory();

    void add_coins(int value);
    int get_coins();
    int getX(); 
    int getY(); 
    int getspeed(); 
    void printPlayer();
   

    int getCurrentHealth(); 

    int getMaxHealth();
    void changeHealthValue(int new_value);

    void heal(int value);

    void is_dead();

};


class Monsters // класс для представления монстров
{
private:
    int x, y;
    int damage;
    Health health;
    bool is_alive;

public:
    Monsters();
    // инициализация
    Monsters(int m_x, int m_y, int m_damage, int m_health);
    int getX() const; 
    int getY() const; 
    int getDamage() const; 
    int getHealth(); 

    void changeHealthValue(int value);
    bool isAlive() const;
    // вывод характеристик монстра
    void printMonster();
    void move(int dx, int dy);


    void is_dead();

    void move_random();
};


class Potion // класс для представления зелий восстановления
{
private:
    int x, y;
    int health_restore;
    bool collected;
public:
    Potion();
    Potion(int px, int py, int restore);

    bool isCollected() const; 
    void collect();
    int getX() const; 
    int getY() const;
    int getHealthRestore() const; 
    void print_potion();
 
    void move(int dx, int dy); 


};


class Coin // структура для представления монеток
{
private:
    int x, y;
    int value;
    bool collected;
public:
    Coin(int px, int py, int val);

    int getX() const;
    int getY() const;
    int getValue() const;
    void print_coin();
    bool is_collected();
    void collect_coin(Player& player, int value);



};



// ------------------- GAMEPLAY FUNCTIONS --------------------------
void damagePlayer(Player& player, int damage);

void damageMonster(Monsters& monster, int damage);


void battle_with_monster(Player& player, Monsters& monster, Inventory& inventory);

// используем зелье для восстановления здоровья
void use_potion(Player& player, Potion& potion);


void checkCollisions(Player& player, Monsters* monster, int monsters_count,
    Potion* potions, int potion_count,
    Coin& coin, Inventory& inventory);

void showInitializedClasses(Player& player, Inventory& inventory, Monsters* monsters,
    int monsters_count, Item* items, int items_count, Potion* potions,
    int potions_count, Coin& coin);