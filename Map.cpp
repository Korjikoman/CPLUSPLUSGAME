#include "Map.h"
#include "Gameplay.h"

int Map::width = 50;
int Map::height = 50;

Map::Map() {
    std::cout << "How many monsters do you want: ";
    std::cin >> monsters_count;

    std::cout << "How many items do you want: ";
    std::cin >> items_count;

    std::cout << "How many potions do you want: ";
    std::cin >> potions_count;


    // Initializing objects, add it to the map
	Monsters* monsters = new Monsters[monsters_count];
    Item* items = new Item[items_count];
    Potion* potions = new Potion[potions_count];
    Coin* coins = new Coin[coins_count];
    moveObjectsRandomly(monsters, items, potions, coins);

	addPlayer(player);
    std::cout << "Map initialized successfully, objects added\n";
}

void Map::addPlayer(Player player) {
	player.movePlayer(0, 0);
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

void Map::moveObjectsRandomly(Monsters* monsters, Item* items, Potion* potions, Coin* coins) {
	static int coord[2];
	for (int i = 0; i < 2; i++) {
		coord[i] = rand() % 50;
	}

	for (int i = 0; i < monsters_count; i++) {
		monsters[i].changeX(rand() % 50);
		monsters[i].changeY(rand() % 50);
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

void Map::deleteObjects()
{

    delete[] monsters;
    delete[]potions;
    delete[] items;
    player.movePlayer(-1, -1);

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
    for (int i = 0; i < potions_count; i++) {
        coins[i].print_coin();
    }
}


void Map::checkCollisions() {
    Inventory inventory = player.getInventory();


    // ��������� ������������ � ���������
    for (int i = 0; i < monsters_count; i++) {
        if (player.getX() == monsters[i].getX() && player.getY() == monsters[i].getY()) {
            std::cout << "Player encountered a monster!\n";

            battle_with_monster(player, monsters[i],inventory);

        }
    }

    // ��������� ������������ � �������
    for (int i = 0; i < potions_count; i++) {
        if (player.getX() == potions[i].getX() && player.getY() == potions[i].getY()) {
            std::cout << "Player found a potion!\n";
            player.heal(potions[i].getHealthRestore());

        }
    }

    // ��������� ������������ � �������
    for (int i = 0; i < coins_count; i++) {
        if (player.getX() == coins[i].getX() && player.getY() == coins[i].getY()) {
            std::cout << "Player found a coin!\n";
            player.add_coins(5);

        }
    }

    // ��������� ������������ � �������
    for (int i = 0; i < items_count; i++) {
        if (player.getX() == items[i].getX() && items[i].getY() == items[i].getY()) {
            std::cout << "Player found a " << items[i].getName() << "!\n";

            inventory.inventoryAddItem(&items[i]);

        }
    }


}