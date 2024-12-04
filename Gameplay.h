#pragma once
#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <cstdlib> // ƒл€ std::rand и std::srand
#include <ctime> 

#include "Player.h"
#include "Monsters.h"
#include "Potion.h"
#include "Coin.h"
#include "Exceptions.h"


// ------------------- GAMEPLAY FUNCTIONS --------------------------

void damagePlayer(Player& player, int damage);

void damageMonster(Monsters& monster, int damage);


void changeSettings();

void battle_with_monster(Player& player, Monsters& monster);

// используем зелье дл€ восстановлени€ здоровь€
void use_potion(Player& player, Potion& potion);