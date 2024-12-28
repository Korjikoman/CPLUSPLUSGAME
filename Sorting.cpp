#include "Sorting.h"

bool compareItemsByName(Item* a, Item* b) {
    // Обрабатываем случаи, когда один или оба элемента равны nullptr
    if (a == nullptr) return false; // nullptr всегда в конце
    if (b == nullptr) return true;  // a не nullptr, поэтому он должен быть перед b
    // Сортировка по имени (можно изменить на getDamage() для сортировки по урону)
    return a->getName() < b->getName();
}


Sorting::Sorting()
{
    inventory = nullptr;
}

void Sorting::sortItems() {
    // Получаем 2D массив с предметами из инвентаря
    auto& items = inventory->getInventoryItems();  // Используем указатель на inventory

    // Перебираем все строки
    for (int i = 0; i < inventory->getRow(); ++i) {
        // Сортируем каждый ряд в инвентаре по имени
        std::sort(items[i].begin(), items[i].end(), compareItemsByName);
    }
    std::cout << "Items sorted by name.\n";
}

void Sorting::sortPotions() {
    // Получаем массив зелий из инвентаря
    std::vector<Potion*>potions = inventory->getInventoryPotions();  // Используем указатель на inventory

    // Сортируем массив зелий по восстановлению здоровья (healthRestore)
    std::sort(begin(potions), end(potions), [](Potion* a, Potion* b) {
        if (a && b) {
            return a->getHealthRestore() > b->getHealthRestore();  // Сортировка по убыванию здоровья
        }
        return false;
        });
    std::cout << "Potions sorted by health restore.\n";
}