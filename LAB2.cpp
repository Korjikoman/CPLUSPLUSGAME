#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "Classes.h" // здесь описаны все объекты

int MAX_STRING_LENGTH = 30;

void print_player_status(Player* player) {
    printf("Player position: (%d, %d), His health: %d/%d\n", player->x, player->y, player->health.current_health, player->health.max_health);
}



int main()
{
    // Создаем объекты структур
    Player player;

    Monsters monster1;
    Monsters monster2;

    Inventory inventory;

    Item item1;
    Item item2;
    Item item3;
    Item* item4 = (struct Item*)malloc(sizeof(struct Item));

    Coin coin;
    Potion potion;
    Health health;

    // Инициализируем объекты
    init_player(&player, 0, 0, 10, 1, 7, 10);
    init_inventory(&inventory, 10);
    init_potion(&potion, 3, 3, 4);
    init_coin(&coin, 2, 5);
    init_monster(&monster1, 14, 7, 3, 7);
    init_monster(&monster2, 15, 8, 2, 7);

    init_item(&item1, 5, 5, "Sword", 7);
    init_item(&item2, 6, 6, "Gun", 18);
    init_item(&item3, 7, 7, "Bow", 3);
    init_item(item4, 8, 8, "Shield", 2);

    

    // Добавление предметов в инвентарь
    inventory_add_item(&inventory, &item1);
    inventory_add_item(&inventory, &item2);
    inventory_add_item(&inventory, &item3);
    inventory_add_item(&inventory, item4);
    
    

    printf("\n\n");
    // Игровой цикл
    bool game_running = true;
    while (game_running) {
        printf("\n--- Game Menu ---\n");
        printf("1. Move Player\n");
        printf("2. Check Objects \n");
        printf("2. Exit Game\n");
        printf("Enter your choice: ");

        int choice;
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            print_player_status(&player);
            // Ввод координат от игрока
            int new_x, new_y;
            printf("Enter player coordinates (x y): ");
            scanf_s("%d %d", &new_x, &new_y);

            move_player(&player, new_x, new_y);

            // Проверка столкновений
            if (player.x == monster1.x && player.y == monster1.y) {
                battle_with_monster(&player, &monster1, &inventory);
            }
            else if (player.x == monster2.x && player.y == monster2.y) {
                battle_with_monster(&player, &monster2, &inventory);
            }
            if (player.x == potion.x && player.y == potion.y) {
                use_potion(&player, &potion);
            }
            if (player.x == -1 && player.y == -1) {
                use_potion(&player, &potion);
            }
            break;
        case 2:
            // Выводим инфу об объектах
            print_player(&player);
            print_potion(&potion);
            print_coin(&coin);
            print_monster(&monster1);
            print_monster(&monster2);
            // Инвентарь
            printf("\n");
            print_inventory(&inventory);
            break;
        case 3: 
            printf("Exit");
            game_running = false;
            break;
        }

       
        // Проверка состояния игрока
        if (player.health.current_health <= 0) {
            printf("Player has died. Game over.\n");
            break;
        }
    }

    
    return 0;
}

