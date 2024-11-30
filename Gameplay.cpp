#include "Gameplay.h"



// ------------------- GAMEPLAY FUNCTIONS --------------------------
void damagePlayer(Player& player, int damage) {

    if (!player.isAlive()) {
        printf("Monster is dead and cannot attack.\n");
        return;
    }

    player.changeHealthValue(player.getCurrentHealth() - damage);
    if (player.getCurrentHealth() <= 0) {
        player.is_dead();
        printf("Player is dead\n");
    }
}


void damageMonster(Monsters& monster, int damage) {
    monster.changeHealthValue(monster.getHealth() - damage);
    if (monster.getHealth() <= 0)
    {
        monster.changeHealthValue(0);
        monster.is_dead();
        std::cout << "Monster defeated!\n";
    }
}

// Функция, реализующая механику борьбы с монстром
void battle_with_monster(Player& player, Monsters& monster, Inventory& inventory)
{
    if (!monster.isAlive()) {
        printf("The monster is already dead.\n");
        return;
    }

    // Монстр атакует первым

    damagePlayer(player, monster.getDamage());
    printf("You are attacked by a monster! Your health: %d\n", player.getCurrentHealth());

    // Проверка, если игрок уже мёртв
    if (player.getCurrentHealth() <= 0) {
        std::cout << "You were killed by the monster! Game over.\n" << std::endl;
        player.is_dead();
        return;
    }

    int player_damage = 0;
    if (inventory.getItemsCount() > 0) {
        // Игрок выбирает оружие из инвентаря
        std::cout << "Choose a weapon from your inventory (enter slot number 1 " << inventory.getItemsCount() << "-): " << std::endl;
        int choice;
        scanf_s("%d", &choice);

        // Проверка валидности выбора
        if (choice < 1 || choice >  inventory.getItemsCount()) {
            std::cout << "Invalid choice. You lose your chance to attack!\n" << std::endl;
            return;
        }

        // Получаем урон выбранного оружия

        player_damage = inventory.getItem(choice - 1);
        std::cout << "You've chosen a weapon with damage: " << player_damage << std::endl;
    }
    else {
        std::cout << "You don't have any items\n";
        player_damage = player.getDamage();
    }


    // Битва
    while (monster.isAlive() && player.isAlive()) {
        // Игрок атакует монстра
        damageMonster(monster, player_damage);
        std::cout << "You attacked the monster! Monster's health: " << monster.getHealth() << std::endl;

        if (!monster.isAlive()) {
            monster.changeX(-1);
            monster.changeY(-1);
            break;
        }

        // Монстр атакует игрока
        damagePlayer(player, monster.getDamage());
        std::cout << "The monster fought back! Your health: " << player.getCurrentHealth() << std::endl;

        if (player.getCurrentHealth() <= 0) {
            player.is_dead();
            break;
        }
    }

    // Результат битвы
    if (!monster.isAlive() && player.isAlive()) {
        std::cout << "You killed the monster! You earned 5 coins!\n" << std::endl;
        player.add_coins(5);
    }
    else if (!player.isAlive()) {
        std::cout << "You were killed by the monster! Game over.\n" << std::endl;
    }
    else {
        std::cout << "ERROR: Unexpected condition in the battle.\n" << std::endl;
    }
    printf("\n\n");

}

// используем зелье для восстановления здоровья
void use_potion(Player& player, Potion& potion) {
    if (potion.isCollected() || potion.getHealthRestore() <= 0) return;

    std::cout << "Player found a potion! Restoring " << potion.getHealthRestore() << " health." << std::endl;

    player.changeHealthValue(player.getCurrentHealth() + potion.getHealthRestore());
    if (player.getCurrentHealth() > player.getMaxHealth()) {
        player.changeHealthValue(player.getMaxHealth());
    }
    potion.collect();
}
