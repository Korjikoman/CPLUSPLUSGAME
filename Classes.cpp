#include <stdio.h>
#include "Classes.h"


// ------------- Player -----------------
void init_player(Player* player, int x, int y, int health, int speed, int damage, int inventory_space)
{
    // координаты
    player->x = x;
    player->y = y;
    // здоровье
    player->health.getMaxHealth() = health;
    player->health.getCurrentHealth() = health;
    // рюкзак
    player->inventory.space = inventory_space;
    player->inventory.items_count = 0;
    player->inventory.current_element = 0;
    // скорость перевижения и урон врагам
    player->speed = speed;
    player->damage = damage;
    // возрождение
    player->is_alive = true;
    // монетки
    player->coins = 0;
}

// выводим характеристики игрока
void print_player(const Player* player)
{
    printf("Player Position: (%d, %d)\n", player->x, player->y);
    printf("Health: %d/%d\n", player->health.getCurrentHealth(), player->health.getMaxHealth());
    printf("Speed: %d\n", player->speed);
    printf("Player inventory space: %d, items count: %d\n", player->inventory.space, player->inventory.items_count);
}

// перемещение игрока
void move_player(Player* player, int x, int y)
{
    player->x = x * player->speed;
    player->y = y * player->speed;
    printf("Player moved to (%d, %d)\n", player->x, player->y);
}

// лечим игрока
void heal_player(Player* player, int heal)
{
    if (player->health.getCurrentHealth() < player->health.getMaxHealth())
    {
        player->health.getCurrentHealth() += heal;
        printf("Player's health: %d\n", player->health.getCurrentHealth());
    }
    else
        printf("Player has maximum health points\n");
}

// проверям, умер ли игрок
bool player_is_dead(Player* player)
{
    if (player->health.getCurrentHealth() <= 0)
    {
        player->health.getCurrentHealth() = 0;
        player->is_alive = false;
        return true;
    }
    return false;
}

// колечим игрока
void damage_player(Player* player, int damage)
{
    player->health.getCurrentHealth() -= damage;
    if (player_is_dead(player))
    {
        printf("Player is dead\n");
    }
}

// ------------ Potion ------------------------
void init_potion(Potion* potion, int x, int y, int health_restore)
{
    potion->x = x;
    potion->y = y;
    potion->health_restore = health_restore;
    potion->collected = false;
}

void print_potion(const Potion* potion)
{
    printf("Potion Position: (%d, %d)\n", potion->x, potion->y);
    printf("Health Restore: %d\n", potion->health_restore);
    printf("Collected: %s\n", potion->collected ? "Yes" : "No");
}


// ------------Coin ------------------------
void init_coin(Coin* coin, int x, int y)
{
    coin->x = x;
    coin->y = y;
    coin->collected = false;
}

void print_coin(const Coin* coin)
{
    printf("Coin Position: (%d, %d)\n", coin->x, coin->y);
    printf("Collected: %s\n", coin->collected ? "Yes" : "No");
}

// собираем монетку
void collect_coin(Player* player, Coin* coin)
{
    if (!coin->collected)
    {
        coin->collected = true;
        player->coins += 1;
        printf("Coin collected! Total coins: %d\n", player->coins);
    }
}

// ------------Inventory ------------------------
void init_inventory(Inventory* inventory, int space)
{
    inventory->space = inventory->current_space = space;
    inventory->items_count = 0;
    inventory->current_element = 0;
    inventory->inventory_items = (struct Item**)malloc(inventory->space * sizeof(struct Item**));
}

void print_inventory(Inventory* inventory)
{
    printf("Inventory space: %d\n", inventory->space);
    printf("Your inventory:\n");
    if (inventory->items_count == 0) printf("Ther's nothing in it\n");
    for (int i = 0; i < inventory->items_count; i++)
    {
        printf("  Item %d: %s\n", i + 1, inventory->inventory_items[i]->item_name);
    }
    printf("Inventory current element: %d\n", inventory->current_element);
}

int inventory_add_item(Inventory* inventory, Item* item)
{
    if (inventory->items_count >= inventory->space)
    {
        printf("Inventory is full! Cannot add item '%s'.\n", item->item_name);
        return 0; // Не удалось добавить предмет
    }

    // Добавление предмета в массив строк
    inventory->inventory_items[inventory->items_count] = item;
    inventory->items_count++;
    inventory->current_space--; // Уменьшаем свободное место
    item->collected = 1;        // Помечаем предмет как собранный
    printf("Item '%s' added to inventory.\n", item->item_name);
    return 0;
}

// ------------Monsters ------------------------
void init_monster(Monsters* monster, int x, int y, int damage, int health)
{
    monster->x = x;
    monster->y = y;
    monster->damage = damage;
    monster->health.getCurrentHealth() = health;
    monster->is_alive = true;
}

void print_monster(const Monsters* monster)
{
    printf("Monster Position: (%d, %d)\n", monster->x, monster->y);
    printf("Damage: %d\n", monster->damage);
    printf("Health: %d\n", monster->health.getCurrentHealth());
    printf("Is Alive: %s\n", monster->is_alive ? "Yes" : "No");
}

void monster_attack(Player* player, Monsters* monster)
{
    if (monster->is_alive && player->health.getCurrentHealth() > 0)
    {
        damage_player(player, monster->damage);
        printf("Monster attacked! Player health: %d/%d\n", player->health.getCurrentHealth(), player->health.getMaxHealth());
    }
}

void damage_monster(Monsters* monster, int amount)
{
    monster->health.getCurrentHealth() -= amount;
    if (monster->health.getCurrentHealth() <= 0)
    {
        monster->health.getCurrentHealth() = 0;
        monster->is_alive = false;
        printf("Monster defeated!\n");
    }
}

//--------------- ITEMS ------------------------------------
void init_item(Item* item, int x, int y, const char* item_name, int damage)
{
    item->x = x;
    item->y = y;
    item->item_name = item_name;
    item->damage = damage;
}

void print_item(Item* item)
{
    printf("Item Position: (%d, %d)\n", item->x, item->y);
    printf("Item damage: %d\n", item->damage);
    printf("Is item collected: %s\n", item->collected ? "Yes" : "No");
}

// ------------------- GAMEPLAY FUNCTIONS --------------------------
void battle_with_monster(Player* player, Monsters* monster, Inventory* inventory)
{
    if (!monster->is_alive) {
        printf("The monster is already dead.\n");
        return;
    }

    // Монстр атакует первым
    damage_player(player, monster->damage);
    printf("You are attacked by a monster! Your health: %d\n", player->health.getCurrentHealth());

    // Проверка, если игрок уже мёртв
    if (player->health.getCurrentHealth() <= 0) {
        printf("You were killed by the monster! Game over.\n");
        player->is_alive = false;
        return;
    }

    // Игрок выбирает оружие из инвентаря
    printf("Choose a weapon from your inventory (enter slot number 1-%d): ", inventory->items_count);
    int choice;
    scanf_s("%d", &choice);

    // Проверка валидности выбора
    if (choice < 1 || choice > inventory->items_count) {
        printf("Invalid choice. You lose your chance to attack!\n");
        return;
    }

    // Получаем урон выбранного оружия
    int player_damage = inventory->inventory_items[choice-1]->damage;
    printf("You've chosen a weapon with damage: %d\n", player_damage);

    // Битва
    while (monster->is_alive && player->is_alive) {
        // Игрок атакует монстра
        damage_monster(monster, player_damage);
        printf("You attacked the monster! Monster's health: %d\n", monster->health.getCurrentHealth());

        if (!monster->is_alive) {
            break;
        }

        // Монстр атакует игрока
        damage_player(player, monster->damage);
        printf("The monster fought back! Your health: %d\n", player->health.getCurrentHealth());

        if (player->health.getCurrentHealth() <= 0) {
            player->is_alive = false;
            break;
        }
    }

    // Результат битвы
    if (!monster->is_alive && player->is_alive) {
        printf("You killed the monster! You earned 5 coins!\n");
        player->coins += 5;
    }
    else if (!player->is_alive) {
        printf("You were killed by the monster! Game over.\n");
    }
    else {
        printf("ERROR: Unexpected condition in the battle.\n");
    }
    printf("\n\n");

}

// используем зелье для восстановления здоровья
void use_potion(struct Player* player, struct Potion* potion) {
    if (potion->collected || potion->health_restore <= 0) return;

    printf("Player found a potion! Restoring %d health.\n", potion->health_restore);
    player->health.getCurrentHealth() += potion->health_restore;
    if (player->health.getCurrentHealth() > player->health.getMaxHealth()) {
        player->health.getCurrentHealth() = player->health.getMaxHealth();
    }
    potion->collected = true;
}