#pragma once
#include "Coin.h"
#include "Monsters.h"
#include "Potion.h"
#include "Player.h"
#include <iostream>
#include<cstdlib>


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

	int coins_count;
	int coin_index;


public:
	Map();
	// adding objects to map 
	void addPlayer(Player player);

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
	void moveObjectsRandomly(Monsters* monsters, Item* items, Potion* potions, Coin* coins);

	// deleting objects
	void deleteObjects();

};
