#include "Map.h"


int Map::width = 50;
int Map::height = 50;
int Map::coins_count = 7;

Map::Map() {
    std::cout << "How many monsters do you want";
    monsters_count = safeInt(1, 10);

    std::cout << "How many items do you want";
    items_count = safeInt(1, 10);

    std::cout << "How many potions do you want";
    potions_count = safeInt(1, 10);

    // Initializing objects, add it to the map
	monsters = new Monsters[monsters_count];
    items = new Item[items_count];
    potions = new Potion[potions_count];
    coins = new Coin[coins_count];
    moveObjectsRandomly();

    std::cout << "Map initialized successfully, objects added\n";
}

Player& Map::getPlayer() {
    return player;
}


void Map::moveObjectsRandomly() {

	for (int i = 0; i < monsters_count; i++) {
		monsters[i].setX(rand() % 50);
		monsters[i].setY(rand() % 50);
	}

	for (int i = 0; i < items_count; i++) {
		items[i].changeX(rand() % 50);
		items[i].changeY(rand() % 50);
	}

	for (int i = 0; i < monsters_count; i++) {
		potions[i].changeX(rand() % 50);
		potions[i].changeY(rand() % 50);
	}

	for (int i = 0; i < coins_count; i++) {
		coins[i].changeX(rand() % 50);
		coins[i].changeY(rand() % 50);
	}
    for (int i = 0; i < potions_count; i++) {
        potions[i].changeX(rand() % 50);
        potions[i].changeY(rand() % 50);
    }
}


Map::~Map()
{
    delete[] monsters;
    delete[] items;    delete[] potions;
    delete[] coins;
    player.movePlayer(-1, -1);

}

void Map::movePlayer(int dx, int dy) {
    if (player.getspeed() == 2) player.movePlayer(dx, dy).movePlayer(dx, dy);
    else player.movePlayer(dx, dy);
}

void Map::showInitializedClasses() {
    std::cout << "------------------Player:\n";
    std::cout << player << "\n";
    Inventory inventory = player.getInventory();
    std::cout << "------------------Player's inventory:\n";
    std::cout << inventory;

    std::cout << "------------------Monsters:\n";
    for (int i = 0; i < monsters_count; i++) {
        std::cout << monsters[i];
    }

    std::cout << "------------------Items:\n";
    for (int i = 0; i < items_count; i++) {
        std::cout << items[i];
    }
    std::cout << "------------------Potions:\n";
    for (int i = 0; i < potions_count; i++) {
        std::cout << potions[i];
    }

    std::cout << "------------------Coins:\n";
    for (int i = 0; i < coins_count; i++) {
        std::cout << coins[i];
    }
}


void Map::checkCollisions() {
    // Проверка столкновений с монстрами
    CollisionsChecker<Monsters> monsterChecker(player, monsters, monsters_count, [](Player& player, Monsters& monster) {
        std::cout << "Player encountered a monster!\n";
        battle_with_monster(player, monster);
    });
    monsterChecker.checkCollisions();

    // Проверка столкновений с зельями
    CollisionsChecker<Potion> potionChecker(player, potions, potions_count, [](Player& player, Potion& potion) {
        std::cout << "Player found a potion!\n";
        player.heal();
    });
    potionChecker.checkCollisions();

    // Проверка столкновений с монетами
    CollisionsChecker<Coin> coinChecker(player, coins, coins_count, [](Player& player, Coin& coin) {
        std::cout << "Player found a coin!\n";
        player.add_coins(5);
    });
    coinChecker.checkCollisions();

    // Проверка столкновений с оружием
    CollisionsChecker<Item> itemChecker(player, items, items_count, [](Player& player, Item& item) {
        std::cout << "Player found a " << item.getName() << "!\n";
        player.addItems(&item);  // Add item to player (assuming this works correctly)
    });
    itemChecker.checkCollisions();
}