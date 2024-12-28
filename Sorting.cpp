#include "Sorting.h"

bool compareItemsByName(Item* a, Item* b) {
    // ������������ ������, ����� ���� ��� ��� �������� ����� nullptr
    if (a == nullptr) return false; // nullptr ������ � �����
    if (b == nullptr) return true;  // a �� nullptr, ������� �� ������ ���� ����� b
    // ���������� �� ����� (����� �������� �� getDamage() ��� ���������� �� �����)
    return a->getName() < b->getName();
}


Sorting::Sorting()
{
    inventory = nullptr;
}

void Sorting::sortItems() {
    // �������� 2D ������ � ���������� �� ���������
    auto& items = inventory->getInventoryItems();  // ���������� ��������� �� inventory

    // ���������� ��� ������
    for (int i = 0; i < inventory->getRow(); ++i) {
        // ��������� ������ ��� � ��������� �� �����
        std::sort(items[i].begin(), items[i].end(), compareItemsByName);
    }
    std::cout << "Items sorted by name.\n";
}

void Sorting::sortPotions() {
    // �������� ������ ����� �� ���������
    std::vector<Potion*>potions = inventory->getInventoryPotions();  // ���������� ��������� �� inventory

    // ��������� ������ ����� �� �������������� �������� (healthRestore)
    std::sort(begin(potions), end(potions), [](Potion* a, Potion* b) {
        if (a && b) {
            return a->getHealthRestore() > b->getHealthRestore();  // ���������� �� �������� ��������
        }
        return false;
        });
    std::cout << "Potions sorted by health restore.\n";
}