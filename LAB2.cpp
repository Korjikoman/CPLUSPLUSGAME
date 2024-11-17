#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "Classes.h" // здесь описаны все объекты

int MAX_STRING_LENGTH = 30;

void print_player_status(Player* player) {
    printf("Позиция игрока: (%d, %d), Его здоровье: %d/%d\n", player->x, player->y, player->health.current_health, player->health.max_health);
}

void battle_with_monster(Player* player, Monsters* monster, Inventory* inventory);
void use_potion(struct Player* player, struct Potion* potion);

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
    
    init_inventory(&inventory, 10);
    init_potion(&potion, 3, 3, 4);
    init_coin(&coin, 2, 5);
    init_player(&player, 0, 0, 10, 3, 7, 10);
    init_monster(&monster1, 14, 7, 5, 15);
    init_monster(&monster2, 15, 8, 2, 10);

    init_item(&item1, 5, 5, "Меч", 7);
    init_item(&item2, 6, 6, "Пистолет", 18);
    init_item(&item3, 7, 7, "Лук", 3);
    init_item(item4, 8, 8, "Щит", 2);

    // Выводим инфу об объектах
    print_player(&player);
    print_potion(&potion);
    print_coin(&coin);
    print_monster(&monster1);
    print_item(&item2);

    // Добавление предметов в инвентарь
    inventory_add_item(&inventory, &item1);
    inventory_add_item(&inventory, &item2);
    inventory_add_item(&inventory, &item3);
    inventory_add_item(&inventory, item4);
    
    // Инвентарь
    print_inventory(&inventory);

    
    // Основной цикл игры
    while (true) {
        print_player_status(&player);

        // Ввод координат от игрока
        int new_x, new_y;
        printf("Введите координаты игрока (x y): ");
        scanf_s("%d %d", &new_x, &new_y);

        move_player(&player, new_x, new_y);

        // Проверка столкновений
        if (player.x == monster1.x && player.y == monster1.y ) {
            battle_with_monster(&player, &monster1, &inventory);
        }
        else if (player.x == monster2.x && player.y == monster2.y) {
            battle_with_monster(&player, &monster2, &inventory);
        }
        if (player.x == potion.x && player.y == potion.y) {
            use_potion(&player, &potion);
        }

        // Проверка состояния игрока
        if (player.health.current_health <= 0) {
            printf("Player has died. Game over.\n");
            break;
        }
    }

    // Освобождение памяти
    for (int i = 0; i < player.inventory.items_count; i++) {
        free(player.inventory.inventory_items[i]);
    }
    free(player.inventory.inventory_items);
    return 0;
}

