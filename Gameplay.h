#pragma once
#include "Player.h"
#include "Monsters.h"
#include "Potion.h"
#include "Coin.h"

#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <cstdlib> // ƒл€ std::rand и std::srand
#include <ctime> 

// ------------------- GAMEPLAY FUNCTIONS --------------------------
void damagePlayer(Player& player, int damage);

void damageMonster(Monsters& monster, int damage);


void battle_with_monster(Player& player, Monsters& monster, Inventory& inventory);

// используем зелье дл€ восстановлени€ здоровь€
void use_potion(Player& player, Potion& potion);


void checkCollisions(Player& player, Monsters* monster, int monsters_count,
    Potion* potions, int potion_count,
    Coin& coin, Inventory& inventory, Item* items, int items_count);

void showInitializedClasses(Player& player, Inventory& inventory, Monsters* monsters,
    int monsters_count, Item* items, int items_count, Potion* potions,
    int potions_count, Coin& coin);