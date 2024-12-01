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

// �������, ����������� �������� ������ � ��������
void battle_with_monster(Player& player, Monsters& monster)
{
    if (!monster.isAlive()) {
        printf("The monster is already dead.\n");
        return;
    }

    // ������ ������� ������

    damagePlayer(player, monster.getDamage());
    printf("You are attacked by a monster! Your health: %d\n", player.getCurrentHealth());

    // ��������, ���� ����� ��� ����
    if (player.getCurrentHealth() <= 0) {
        std::cout << "You were killed by the monster! Game over.\n" << std::endl;
        player.is_dead();
        return;
    }

    int player_damage = 0;
    if (player.getItemsCount() > 0) {
        // ����� �������� ������ �� ���������
        std::string itemName;
        std::cout << "Enter the name of the item: ";
        std::cin >> itemName;
        
        Item* item = player.getItem(itemName);
        
        if (item != nullptr) {
            player_damage = item->getDamage();
            std::cout << "You've chosen a weapon " << item->getName() << " with damage : " << player_damage << std::endl;

        }
        else {
            std::cout << "Cannot find a weapon\n";
            player_damage = player.getDamage();
            std::cout << "Your damage: " << player_damage << "\n";;
        }
    }
    else {
        std::cout << "You don't have any items\n";
        player_damage = player.getDamage();
    }


    // �����
    while (monster.isAlive() && player.isAlive()) {
        // ����� ������� �������
        damageMonster(monster, player_damage);
        std::cout << "You attacked the monster! Monster's health: " << monster.getHealth() << std::endl;

        if (!monster.isAlive()) {
            monster.changeX(-1);
            monster.changeY(-1);
            break;
        }

        // ������ ������� ������
        damagePlayer(player, monster.getDamage());
        std::cout << "The monster fought back! Your health: " << player.getCurrentHealth() << std::endl;

        if (player.getCurrentHealth() <= 0) {
            player.is_dead();
            break;
        }
    }

    // ��������� �����
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

// ���������� ����� ��� �������������� ��������
void use_potion(Player& player, Potion& potion) {
    if (potion.isCollected() || potion.getHealthRestore() <= 0) return;

    std::cout << "Player found a potion! Restoring " << potion.getHealthRestore() << " health." << std::endl;

    player.changeHealthValue(player.getCurrentHealth() + potion.getHealthRestore());
    if (player.getCurrentHealth() > player.getMaxHealth()) {
        player.changeHealthValue(player.getMaxHealth());
    }
    potion.collect();
}

void changeSettings()
{
    int choice;
    std::cout << "GAME SETTINGS\n";
    std::cout << "Select which setting you would like to change:\n";
    std::cout << "1) Player's maximum health\n";
    std::cout << "2) Maximum inventory space\n";
    std::cout << "3) Amount of health restored by potions\n";
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        int health;
        std::cout << "Enter new health value:";
        std::cin >> health;
        Health::setMaxHealth(health);
        std::cout << "The player's new max health value is: " << Health::getMaxHealth() << "\n";
        break;
    
    case 2:
        int space;
        std::cout << "Enter new max inventory space: ";
        std::cin >> space;
        Inventory::changeSpace(space);
        std::cout << "The new max inventory space value is: " << Inventory::getSpace() << "\n";
        break;
    case 3:
        int restore;
        std::cout << "Enter new restored health value:";
        std::cin >> restore;
        Potion::setHealthRestore(restore);
        std::cout << "The new value of the player's maximum health:" << Potion::getHealthRestore() << "\n";
        break;

    default:
        break;
    }
}

