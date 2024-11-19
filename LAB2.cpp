#include "LAB2.h"

int main()
{
    
    // Инициализируем объекты класса
    Player player;
    Inventory inventory = player.getInventory();
    int monsters_count;
    int items_count;
    int potion_count;

    std::cout << "How many monsters do you want: ";
    std::cin >> monsters_count;

    std::cout << "How many items do you want: ";
    std::cin >> items_count;

    std::cout << "How many potions do you want: ";
    std::cin >> potion_count;

    // Инициализировали монстров, переместили их в рандомные места
    Monsters* monsters = new Monsters[monsters_count];
    for (int i = 0; i < monsters_count; i++) {
        monsters[i].move_random();
    }

    Item* items = new Item[items_count];

    Potion* potions = new Potion[potion_count];

    Coin coin(3, 3, 5);


    printf("\n\n");


    // Игровой цикл
    bool game_running = true;
    while (game_running) {
        std::cout << "\n--- Game Menu ---\n";
        std::cout << "1. Move player\n";
        std::cout << "2. Show class objects\n";
        std::cout << "3. Exit game\n";
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            int dx, dy;
            std::cout << "Enter (x,y) to move the player: ";
            std::cin >> dx >> dy;
            player.movePlayer(dx, dy);
            checkCollisions(player, monsters, monsters_count, potions, potion_count, coin, inventory);
            break;
        case 2:
            showInitializedClasses(player, inventory, monsters, 
                monsters_count, items, items_count, potions, 
                potion_count, coin);
            break;
        case 3:
            game_running = false;
            std::cout << "Exiting the game. Goodbye!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    }

    
    return 0;
}

