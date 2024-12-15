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

//void Map::addPlayer(Player& newPlayer)
//{
//    players.push_back(newPlayer); // Добавляем нового игрока в массив
//    std::cout << "Player " << newPlayer.getName() << " added to the map." << std::endl;
//}

Player& Map::getPlayer() {
    return player;
}
//void Map::addMonster(Monsters monster) {
//	if (monster_index < monsters_count) {
//		monsters[monster_index + 1] = monster;
//		std::cout << "Monster added successfully!\n";
//	}
//	else {
//		std::cout << "Cannot add new monster, error!\n";
//	}
//}
//void Map::addCoin(Coin coin) {
//	if (monster_index < monsters_count) {
//		monsters[monster_index + 1] = monster;
//		std::cout << "Monster added successfully!\n";
//	}
//	else {
//		std::cout << "Cannot add new monster, error!\n";
//	}
//}
//void Map::addPotion(Potion potion) {
//	if (monster_index < monsters_count) {
//		monsters[monster_index + 1] = monster;
//		std::cout << "Monster added successfully!\n";
//	}
//	else {
//		std::cout << "Cannot add new monster, error!\n";
//	}
//}
//
//void Map::addItem(Item item) {
//	if (item_index < items_count) {
//		items[item_index + 1] = item;
//		std::cout << "Item added successfully!\n";
//	}
//	else {
//		std::cout << "Cannot add new item, error!\n";
//	}
//	}
//}

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
    player.printPlayer();
    Inventory inventory = player.getInventory();
    std::cout << "------------------Player's inventory:\n";
    inventory.print_inventory();

    std::cout << "------------------Monsters:\n";
    for (int i = 0; i < monsters_count; i++) {
        monsters[i].printMonster();
    }

    std::cout << "------------------Items:\n";
    for (int i = 0; i < items_count; i++) {
        items[i].print_item();
    }
    std::cout << "------------------Potions:\n";
    for (int i = 0; i < potions_count; i++) {
        potions[i].print_potion();
    }

    std::cout << "------------------Coins:\n";
    for (int i = 0; i < coins_count; i++) {
        coins[i].print_coin();
    }
}


void Map::checkCollisions() {


    // Проверяем столкновения с монстрами
    for (int i = 0; i < monsters_count; i++) {
        if (player.getX() == monsters[i].getX() && player.getY() == monsters[i].getY()) {
            std::cout << "Player encountered a monster!\n";

            battle_with_monster(player, monsters[i]);

        }
    }

    // Проверяем столкновения с зельями
    for (int i = 0; i < potions_count; i++) {
        if (player.getX() == potions[i].getX() && player.getY() == potions[i].getY()) {
            std::cout << "Player found a potion!\n";
            player.addPotion(potions[i]);
            potions[i].collect();

        }
    }

    // Проверяем столкновения с монетой
    for (int i = 0; i < coins_count; i++) {
        if (player.getX() == coins[i].getX() && player.getY() == coins[i].getY()) {
            std::cout << "Player found a coin!\n";
            coins[i].collect_coin(player, 5);
            player.add_coins(5);

        }
    }

    // Проверяем столкновения с оружием
    for (int i = 0; i < items_count; i++) {
        if (player.getX() == items[i].getX() && player.getY() == items[i].getY()) {
            std::cout << "Player found a " << items[i].getName() << "!\n";

            player.addItems(&items[i]);
            
        }
    }


}

