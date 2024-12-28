#pragma once
#include "Item.h"
#include "Potion.h"
#include <algorithm>
#include <vector>


class Sorting {
public:
    Sorting() {
        std::cout << "Sorting object created.\n";
    }

    ~Sorting() {
        std::cout << "Sorting object destroyed.\n";
    }

    static void sortItems(std::vector<std::vector<Item*>>& inventory_items) {
        // Сортируем каждый ряд инвентаря
        for (auto& row : inventory_items) {
            std::sort(row.begin(), row.end(), [](Item* a, Item* b) {
                // Если оба элемента существуют, сортируем по урону
                if (a && b) {
                    return a->getDamage() < b->getDamage();
                }
                // Если один из элементов nullptr, он должен быть в конце
                return a != nullptr; // a идет перед b, если a не nullptr, а b nullptr
                });
        }
        std::cout << "Items sorted by damage.\n";
    }

    static void sortPotions(std::vector<Potion*>& inventory_potions) {
        // Сортируем зелья по количеству восстанавливаемого здоровья
        std::sort(inventory_potions.begin(), inventory_potions.end(), [](Potion* a, Potion* b) {
            if (a && b) {
                return a->getHealthRestore() > b->getHealthRestore(); // По убыванию
            }
            return a != nullptr; // Непустые элементы первыми
            });
        std::cout << "Potions sorted by health restore.\n";
    }
};