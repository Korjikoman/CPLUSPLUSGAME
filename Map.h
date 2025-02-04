#pragma once
#include "Coin.h"
#include "Monsters.h"
#include "Potion.h"
#include "Player.h"
#include "Gameplay.h"
#include "Exceptions.h"
#include "CollisionsChecker.h"

#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <memory>

class Map
{
private:
	// size of a map (static variables)
	static int width;
	static int height;


	Coin* coins;
	Monsters* monsters;
	Potion* potions;

	Player player;
	
	Item* items;
	int monsters_count;
	int monster_index;
	int items_count;
	int item_index;

	int potions_count;
	int potion_index;

	static int coins_count;
	int coin_index;


public:
	Map();
	~Map();
	// adding objects to map 

	/* 
	void addMonster(Monsters monster);
	void addCoin(Coin coin);
	void addPotion(Potion potion);
	void addItem(Item item); */


	// print objects on a map
	void showInitializedClasses();

	// check if player's coordinates matches with object's coordinates
	void checkCollisions();

	// random coordinates
	void moveObjectsRandomly();


	Player& getPlayer();

	void movePlayer(int dx, int dy);
	void addPlayer(Player& newPlayer);
	
};
