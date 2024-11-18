#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <stdbool.h>

class Health;
class Player;
class Monsters;
class Item;
class Coin;
class Potion;
class Inventory;

class Health // класс дл€ представлени€ здоровь€ игрока
{
private:
    int current_health;
    int max_health;
public:
    Health(int current, int max) {
        current_health = current;
        max_health = max;
    }

    int getCurrentHealth() const {
        return current_health;
    }
    int getMaxHealth() const { return max_health; }
    void heal(int healpoints) {
        current_health += healpoints;
        if (current_health > max_health) {
            current_health = max_health;
        }
    }
    void changeHealthValue(int new_value) {
        current_health = new_value;
    }
};


class Item // класс дл€ представлени€ оружи€
{

private:
    std::string item_name;
    int x, y;
    bool collected;
    int damage;

public:
    // инициализаци€
   /* Item(int it_x, int it_y, const char* it_item_name, int it_damage) {
        x = it_x;
        y = it_y;
        item_name = it_item_name;
        damage = it_damage;
    }*/
    Item() : x(0), y(0), item_name("Unknown"), damage(0) {}
    Item(int it_x, int it_y, const char* it_item_name, int it_damage) : x(it_x), y(it_y), item_name(it_item_name), damage(it_damage) {}

    std::string getName() const { return item_name; }
    int getDamage() { return damage; }
    bool isCollected() { return collected; }
    void Collected() { collected = true; }

    // вывод характеристик оружи€
    void print_item(Item* item) {
        printf("Item Position: (%d, %d)\n", item->x, item->y);
        printf("Item damage: %d\n", item->damage);
        printf("Is item collected: %s\n", item->collected ? "Yes" : "No");
    }

};


class Inventory // класс дл€ представлени€ инвентар€ игрока
{
private:
    int space;
    int items_count;
    int current_element;
    struct Item* inventory_items;

public:
    Inventory(int inv_space) {
        space = inv_space;
        items_count = 0;
        current_element = 0;
        inventory_items = new Item[space];

    }

    ~Inventory() {
        delete[] inventory_items;
    }

    int getSpace() { return space; }
    int getCurrentElement() { return current_element; }
    int getItemsCount() { return items_count; }


    void print_inventory()
    {
        printf("Inventory space: %d\n", space);
        printf("Your inventory:\n");
        if (items_count == 0) printf("Ther's nothing in it\n");
        for (int i = 0; i < items_count; i++)
        {
            std::cout << "  Item " << i + 1 << ": " << inventory_items[i].getName() << std::endl;
        }
        std::cout << "Inventory current element: " << current_element << std::endl;
    }

    int inventoryAddItem(Item& item)
    {
        if (items_count >= space)
        {
            printf("Inventory is full! Cannot add item '%s'.\n", item.getName());
            return 0; // Ќе удалось добавить предмет
        }

        // ƒобавление предмета в массив строк
        inventory_items[items_count] = item;
        items_count++;

        item.Collected();   // ѕомечаем предмет как собранный
        std::cout << "Item " << item.getName() << " added to inventory.\n";
        return 0;
    }

    int getItem(int idx) {
        return inventory_items[idx].getDamage();
    }

};


class Player // класс дл€ представлени€ игрока
{

private:
    int x, y;
    Health health;
    int speed;
    int damage;
    Inventory inventory;
    int potions_count;
    Potion* potions;
    bool is_alive;
    int coins;

public:
    // инициализаци€
    Player(int p_x, int p_y, int p_health, int p_speed, int p_dmg, int p_inventory_space) :
        x(p_x), y(p_y), health(p_health, p_health), speed(p_speed), damage(p_dmg), inventory(p_inventory_space), potions_count(0)
    {}

    // перемещаем игрока
    void movePlayer(int dx, int dy) {
        x = x * speed;
        y = y * speed;
        printf("Player moved to (%d, %d)\n", x, y);
    }

    // провер€ем, умер ли игрок
    bool isAlive() {
        return is_alive;

    }



    void add_coins(int value) { coins += value; }
    int get_coins() { return coins; }
    int getX() { return x; }
    int getY() { return y; }
    int getspeed() { return speed; }
    void printPlayer()
    {
        printf("Player Position: (%d, %d)\n", x, y);
        printf("Health: %d/%d\n", health.getCurrentHealth(), health.getMaxHealth());
        printf("Speed: %d\n", speed);
        printf("Player inventory space: %d, items count: %d\n", inventory.getSpace(), inventory.getItemsCount());
    } // вывод игрока

    //void addPotion(const Potion& potion) {
    //    potions[potions_count++] = potion; // ƒобавл€ем зелье в массив
    //}
    int getCurrentHealth() const {
        return health.getCurrentHealth();
    }

    int getMaxHealth() const {
        return health.getMaxHealth();
    }
    void changeHealthValue(int new_value) {
        health.changeHealthValue(new_value);
    }

    

    void is_dead() { is_alive = false; }

};


class Monsters // класс дл€ представлени€ монстров
{
private:
    int x, y;
    int damage;
    Health health;
    bool is_alive;

public:
    // инициализаци€
    Monsters(int m_x, int m_y, int m_damage, int m_health) :
        x(m_x), y(m_y), health(m_health, m_health), damage(m_damage)
    {}
    int getX() const { return x; }
    int getY() const { return y; }
    int getDamage() const { return damage; }
    int getHealth() { return health.getCurrentHealth(); }

    void changeHealthValue(int value) {
        health.changeHealthValue(value);
    }
    bool isAlive() const { return is_alive; }
    // вывод характеристик монстра
    void printMonster() {
        printf("Monster Position: (%d, %d)\n", x, y);
        printf("Damage: %d\n", damage);
        printf("Health: %d\n", health.getCurrentHealth());
        printf("Is Alive: %s\n", is_alive ? "Yes" : "No");
    }

    // наносим урон игроку 
    

    void is_dead() { is_alive = false; }


};


class Potion // класс дл€ представлени€ зелий восстановлени€
{
private:
    int x, y;
    int health_restore;
    bool collected;
public:
    Potion(int px, int py, int restore)
    {
        x = px;
        y = py;
        health_restore = restore;
        collected = false;
    }

    bool isCollected() const { return collected; }
    void collect() { collected = true; };
    int getX() const { return x; }
    int getY() const { return y; }
    int getHealthRestore() const { return health_restore; }
    void print_potion(const Potion* potion)
    {
        printf("Potion Position: (%d, %d)\n", potion->x, potion->y);
        printf("Health Restore: %d\n", potion->health_restore);
        printf("Collected: %s\n", potion->collected ? "Yes" : "No");
    }



};



// класс дл€ представлени€ монеток
class Coin // структура дл€ представлени€ монеток
{
private:
    int x, y;
    int value;
    bool collected;
public:
    Coin(int px, int py, int val)
        : x(px), y(py), value(val), collected(false) {}
    
    int getX() const { return x; }
    int getY() const { return y; }
    int getValue() const{ return value; }
    void print_coin() {
        std::cout << "Coin Position: (" << getX() << ", " << getY() << ")\n";
        std::cout << "Collected: " << (is_collected() ? "Yes" : "No") << "\n";

    }
    bool is_collected() {
        if (collected == true) return true;
        return false;
    }
    void collect_coin(Player& player, int value) {
        if (!collected)
        {
            collected = true;
            player.add_coins(value);
            printf("Coin collected! Total coins: %d\n", player.get_coins());
        }
    }



};




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


void battle_with_monster(Player& player, Monsters& monster, Inventory& inventory)
{
    if (!monster.isAlive()) {
        printf("The monster is already dead.\n");
        return;
    }

    // ћонстр атакует первым

    damagePlayer(player, monster.getDamage());
    printf("You are attacked by a monster! Your health: %d\n", player.getCurrentHealth());

    // ѕроверка, если игрок уже мЄртв
    if (player.getCurrentHealth() <= 0) {
        std::cout << "You were killed by the monster! Game over.\n" << std::endl;
        player.is_dead();
        return;
    }

    // »грок выбирает оружие из инвентар€
    std::cout << "Choose a weapon from your inventory (enter slot number 1-%d): " << inventory.getItemsCount() << std::endl;
    int choice;
    scanf_s("%d", &choice);

    // ѕроверка валидности выбора
    if (choice < 1 || choice >  inventory.getItemsCount()) {
        std::cout << "Invalid choice. You lose your chance to attack!\n" << std::endl;
        return;
    }

    // ѕолучаем урон выбранного оружи€
    int player_damage = inventory.getItem(choice - 1);
    std::cout << "You've chosen a weapon with damage: " << player_damage << std::endl;


    // Ѕитва
    while (monster.isAlive() && player.isAlive()) {
        // »грок атакует монстра
        damageMonster(monster, player_damage);
        std::cout << "You attacked the monster! Monster's health: " << monster.getHealth() << std::endl;

        if (!monster.isAlive()) {
            break;
        }

        // ћонстр атакует игрока
        damagePlayer(player, monster.getDamage());
        std::cout << "The monster fought back! Your health: %d" << player.getCurrentHealth() << std::endl;

        if (player.getCurrentHealth() <= 0) {
            player.is_dead();
            break;
        }
    }

    // –езультат битвы
    if (!monster.isAlive() && player.isAlive()) {
        std::cout << "You killed the monster! You earned 5 coins!\n" << std::endl;
        player.add_coins(5);
    }
    else if (!player.isAlive()) {
        std::cout << "You were killed by the monster! Game over.\n" << std::endl;
    }
    else {
        std::cout <<  "ERROR: Unexpected condition in the battle.\n" << std::endl;
    }
    printf("\n\n");

}

// используем зелье дл€ восстановлени€ здоровь€
void use_potion(Player& player, Potion& potion) {
    if (potion.isCollected() || potion.getHealthRestore() <= 0) return;

    std::cout << "Player found a potion! Restoring " << potion.getHealthRestore() << " health." << std::endl;

    player.changeHealthValue(player.getCurrentHealth() + potion.getHealthRestore());
    if (player.getCurrentHealth() > player.getMaxHealth()) {
        player.changeHealthValue(player.getMaxHealth());
    }
    potion.collect();
}

int main() {
    return 0;
}