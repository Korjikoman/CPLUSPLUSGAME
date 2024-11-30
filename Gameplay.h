#pragma once
#include "Player.h"
#include "Monsters.h"
#include "Potion.h"
#include "Coin.h"

#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <cstdlib> // ��� std::rand � std::srand
#include <ctime> 

// ------------------- GAMEPLAY FUNCTIONS --------------------------
void damagePlayer(Player& player, int damage);

void damageMonster(Monsters& monster, int damage);


void battle_with_monster(Player& player, Monsters& monster, Inventory& inventory);

// ���������� ����� ��� �������������� ��������
void use_potion(Player& player, Potion& potion);
