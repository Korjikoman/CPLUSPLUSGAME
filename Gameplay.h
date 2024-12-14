#pragma once
#include "Potion.h"
#include "Coin.h"
#include "Exceptions.h"
#include "Player.h"
#include "Monsters.h"



// ------------------- GAMEPLAY FUNCTIONS --------------------------

void damagePlayer(Player& player, int damage);

void damageMonster(Monsters& monster, int damage);


void changeSettings();

void battle_with_monster(Player& player, Monsters& monster);

// используем зелье для восстановления здоровья
void use_potion(Player& player, Potion& potion);