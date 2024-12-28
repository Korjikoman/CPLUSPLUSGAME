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
        // ��������� ������ ��� ���������
        for (auto& row : inventory_items) {
            std::sort(row.begin(), row.end(), [](Item* a, Item* b) {
                // ���� ��� �������� ����������, ��������� �� �����
                if (a && b) {
                    return a->getDamage() < b->getDamage();
                }
                // ���� ���� �� ��������� nullptr, �� ������ ���� � �����
                return a != nullptr; // a ���� ����� b, ���� a �� nullptr, � b nullptr
                });
        }
        std::cout << "Items sorted by damage.\n";
    }

    static void sortPotions(std::vector<Potion*>& inventory_potions) {
        // ��������� ����� �� ���������� ������������������ ��������
        std::sort(inventory_potions.begin(), inventory_potions.end(), [](Potion* a, Potion* b) {
            if (a && b) {
                return a->getHealthRestore() > b->getHealthRestore(); // �� ��������
            }
            return a != nullptr; // �������� �������� �������
            });
        std::cout << "Potions sorted by health restore.\n";
    }
};