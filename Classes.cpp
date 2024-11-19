#include "Classes.h"

Health::Health() : current_health(0), max_health(0) {}
Health::Health(int max) {
    current_health = max_health = max;

}

int Health::getCurrentHealth()
{
    return current_health;
}

int Health::getMaxHealth() { return max_health; }
void Health::changeMaxHealthValue(int value) {
    max_health = value;
}
void Health::heal(int healpoints) {
    current_health += healpoints;
    if (current_health > max_health) {
        current_health = max_health;
    }
}
void Health::changeHealthValue(int new_value) {
    current_health = new_value;
}



Item::Item() {
    std::cout << "Initializing Item...\n";

    std::cout << "Enter the name of the item: ";
    std::cin.ignore(); // Очищаем буфер
    std::getline(std::cin, item_name);

    std::cout << "Enter the x-coordinate of the item: ";
    std::cin >> x;

    std::cout << "Enter the y-coordinate of the item: ";
    std::cin >> y;

    std::cout << "Enter the damage of the item: ";
    std::cin >> damage;

    collected = false; // По умолчанию предмет не собран

    std::cout << "Item initialized successfully!\n";
}


std::string Item::getName() const { return item_name; }
int Item::getDamage() { return damage; }
bool Item::isCollected() { return collected; }
void Item::Collected() { collected = true; }

// вывод характеристик оружия
void Item::print_item() {
    printf("Item Position: (%d, %d)\n", x, y);
    printf("Item damage: %d\n", damage);
    printf("Is item collected: %s\n", collected ? "Yes" : "No");
}




Inventory::Inventory() : space(0), items_count(0), current_element(0) {}
Inventory::Inventory(int inv_space) {
        space = inv_space;
        items_count = 0;
        current_element = 0;
        inventory_items = new Item[space];

    }

Inventory::~Inventory() {
    delete[] inventory_items;
}

int Inventory::getSpace() { return space; }
void Inventory::changeSpace(int new_space) {
    space = new_space;
}
int Inventory::getCurrentElement() { return current_element; }
int Inventory::getItemsCount() { return items_count; }


void Inventory::print_inventory()
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

int Inventory::inventoryAddItem(Item& item)
{
    if (items_count >= space)
    {
        printf("Inventory is full! Cannot add item '%s'.\n", item.getName());
        return 0; // Не удалось добавить предмет
    }

    // Добавление предмета в массив строк
    inventory_items[items_count] = item;
    items_count++;

    item.Collected();   // Помечаем предмет как собранный
    std::cout << "Item " << item.getName() << " added to inventory.\n";
    return 0;
}

int Inventory::getItem(int idx) {
    return inventory_items[idx].getDamage();
}



    // инициализация
Player::Player()
    {
        int p_health, inventory_space;
        std::cout << "Initializing player...\n";

        std::cout << "Enter the initial x-coordinate of the player: ";
        std::cin >> x;

        std::cout << "Enter the initial y-coordinate of the player: ";
        std::cin >> y;

        std::cout << "Enter the initial health of the player: ";
        std::cin >> p_health;
        health.changeHealthValue(p_health);
        health.changeMaxHealthValue(p_health);

        std::cout << "Enter the speed of the player: ";
        std::cin >> speed;

        std::cout << "Enter the damage of the player: ";
        std::cin >> damage;

        std::cout << "Enter the inventory space of the player: ";
        std::cin >> inventory_space;
        inventory.changeSpace(inventory_space);

        potions_count = 0; // Инициализация по умолчанию
        is_alive = true;   // Игрок жив при создании
        coins = 0;         // Начальное количество монет

        std::cout << "Player initialized successfully!\n";
    }

    // перемещаем игрока
    void Player::movePlayer(int dx, int dy) {
        x = dx * speed;
        y = dy * speed;
        printf("Player moved to (%d, %d)\n", x, y);
    }

    // проверяем, умер ли игрок
    bool Player::isAlive() {
        return is_alive;

    }
    Inventory Player::getInventory() {
        return inventory;
    }

    void Player::add_coins(int value) { coins += value; }
    int Player::get_coins() { return coins; }
    int Player::getX() { return x; }
    int Player::getY() { return y; }
    int Player::getspeed() { return speed; }
    void Player::printPlayer()
    {
        printf("Player Position: (%d, %d)\n", x, y);
        printf("Health: %d/%d\n", health.getCurrentHealth(), health.getMaxHealth());
        printf("Speed: %d\n", speed);
        printf("Player inventory space: %d, items count: %d\n", inventory.getSpace(), inventory.getItemsCount());
    } // вывод игрока

    int Player::getCurrentHealth() {
        return health.getCurrentHealth();
    }

    int Player::getMaxHealth() {
        return health.getMaxHealth();
    }
    void Player::changeHealthValue(int new_value) {
        health.changeHealthValue(new_value);
    }

    void Player::heal(int value) {
        health.heal(value);
    }

    void Player::is_dead() { is_alive = false; }




Monsters::Monsters() : x(0), y(0), health(10), damage(2), is_alive(true) {}
    // инициализация
Monsters::Monsters(int m_x, int m_y, int m_damage, int m_health) :
        x(m_x), y(m_y), health(m_health), damage(m_damage), is_alive(true)
    {}
    int Monsters::getX() const { return x; }
    int Monsters::getY() const { return y; }
    int Monsters::getDamage() const { return damage; }
    int Monsters::getHealth() { return health.getCurrentHealth(); }

    void Monsters::changeHealthValue(int value) {
        health.changeHealthValue(value);
    }
    bool Monsters::isAlive() const { return is_alive; }
    // вывод характеристик монстра
    void Monsters::printMonster() {
        printf("Monster Position: (%d, %d)\n", x, y);
        printf("Damage: %d\n", damage);
        printf("Health: %d\n", health.getCurrentHealth());
        printf("Is Alive: %s\n", is_alive ? "Yes" : "No");
    }

    void Monsters::move(int dx, int dy) {
        x = dx;
        y = dy;

    }
    

    void Monsters::is_dead() { is_alive = false; }
    
    void Monsters::move_random() {
        int dx = std::rand() % 15 + 1; // Случайное смещение по x: от -5 до 5
        int dy = std::rand() % 15 + 1; // Случайное смещение по y: от -5 до 5
        move(dx, dy);
    }



    Potion::Potion() : x(0), y(0), health_restore(4), collected(false) {}
    Potion::Potion(int px, int py, int restore)
    {
        x = px;
        y = py;
        health_restore = restore;
        collected = false;
    }

    bool Potion::isCollected() const { return collected; }
    void Potion::collect() { collected = true; };
    int Potion::getX() const { return x; }
    int Potion::getY() const { return y; }
    int Potion::getHealthRestore() const { return health_restore; }
    void Potion::print_potion()
    {
        printf("Potion Position: (%d, %d)\n", x, y);
        printf("Health Restore: %d\n", health_restore);
        printf("Collected: %s\n", collected ? "Yes" : "No");
    }
    void Potion::move(int dx, int dy) {
    
    }

    Coin::Coin(int px, int py, int val)
        : x(px), y(py), value(val), collected(false) {}
    
    int Coin::getX() const { return x; }
    int Coin::getY() const { return y; }
    int Coin::getValue() const{ return value; }
    void Coin::print_coin() {
        std::cout << "Coin Position: (" << getX() << ", " << getY() << ")\n";
        std::cout << "Collected: " << (is_collected() ? "Yes" : "No") << "\n";

    }
    bool Coin::is_collected() {
        if (collected == true) return true;
        return false;
    }
    void Coin::collect_coin(Player& player, int value) {
        if (!collected)
        {
            collected = true;
            player.add_coins(value);
            printf("Coin collected! Total coins: %d\n", player.get_coins());
        }
    }






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

    // Монстр атакует первым

    damagePlayer(player, monster.getDamage());
    printf("You are attacked by a monster! Your health: %d\n", player.getCurrentHealth());

    // Проверка, если игрок уже мёртв
    if (player.getCurrentHealth() <= 0) {
        std::cout << "You were killed by the monster! Game over.\n" << std::endl;
        player.is_dead();
        return;
    }

    // Игрок выбирает оружие из инвентаря
    std::cout << "Choose a weapon from your inventory (enter slot number 1-%d): " << inventory.getItemsCount() << std::endl;
    int choice;
    scanf_s("%d", &choice);

    // Проверка валидности выбора
    if (choice < 1 || choice >  inventory.getItemsCount()) {
        std::cout << "Invalid choice. You lose your chance to attack!\n" << std::endl;
        return;
    }

    // Получаем урон выбранного оружия
    int player_damage = inventory.getItem(choice - 1);
    std::cout << "You've chosen a weapon with damage: " << player_damage << std::endl;


    // Битва
    while (monster.isAlive() && player.isAlive()) {
        // Игрок атакует монстра
        damageMonster(monster, player_damage);
        std::cout << "You attacked the monster! Monster's health: " << monster.getHealth() << std::endl;

        if (!monster.isAlive()) {
            break;
        }

        // Монстр атакует игрока
        damagePlayer(player, monster.getDamage());
        std::cout << "The monster fought back! Your health: %d" << player.getCurrentHealth() << std::endl;

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
        std::cout <<  "ERROR: Unexpected condition in the battle.\n" << std::endl;
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



void checkCollisions(Player& player, Monsters* monster, int monsters_count,
    Potion* potions, int potion_count,
    Coin& coin, Inventory& inventory) {
    // Проверяем столкновения с монстрами
    for (int i = 0; i < monsters_count; i++) {
        if (player.getX() == monster[i].getX() && player.getY() == monster[i].getY()) {
            std::cout << "Player encountered a monster!\n";
            battle_with_monster(player, monster[i], inventory);
            return;
        }
    }

    // Проверяем столкновения с зельями
    for (int i = 0; i < potion_count; i++) {
        if (player.getX() == potions[i].getX() && player.getY() == potions[i].getY()) {
            std::cout << "Player found a potion!\n";
            player.heal(potions[i].getHealthRestore());
            return;
        }
    }

    // Проверяем столкновения с монетой
    if (player.getX() == coin.getX() && player.getY() == coin.getY()) {
        std::cout << "Player found a coin!\n";
        player.add_coins(coin.getValue()); 
        return;
    }
}

void showInitializedClasses(Player& player, Inventory& inventory, Monsters* monsters, 
    int monsters_count, Item* items, int items_count, Potion* potions, 
    int potions_count, Coin& coin) {
    std::cout << "------------------Player:\n";
    player.printPlayer();
    
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

    std::cout << "------------------Coin:\n";
    coin.print_coin();

}
