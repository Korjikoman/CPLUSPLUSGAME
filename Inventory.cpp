#include "Inventory.h"

// Inventory space is a static variable
int Inventory::space = 4;

Inventory::Inventory() : items_count(0), potions_count(0), current_element(0) {
    std::cout << "Initializing Inventory...\n";
 
    // ������ ���������
    inventory_items.resize(space / 2, std::vector<Item*>(space / 2, nullptr));  // 2D ������ ��� ���������
    inventory_potions.resize(space, nullptr);  // ������ ��� �����
}

int Inventory::getSpace() {
    return space;
}

void Inventory::changeSpace(int new_space) {
    space = new_space;
}

int Inventory::getCurrentElement() {
    return current_element;
}

int Inventory::getItemsCount() {
    return items_count;
}

int Inventory::getRow() {
    return items_count / (space / 2);  // ���� ������������, ��� ��������� ���������� ��� �������������
}

int Inventory::getCol() {
    return items_count % (space / 2);
}

void Inventory::clearInventory() {
    // ������� ��� �������� � ���������
    for (auto& row : inventory_items) {
        for (auto& item : row) {
            delete item;
            item = nullptr;
        }
    }

    // ������� ��� �����
    for (auto& potion : inventory_potions) {
        delete potion;
        potion = nullptr;
    }

    // ���������� ��������
    items_count = 0;
    potions_count = 0;
}

void Inventory::inventoryAddItem(Item* item) {
    if (items_count >= space) {
        std::cout << "Inventory is full!\n";
        return;
    }

    // ���� ��������� �����
    for (auto& row : inventory_items) {
        for (auto& slot : row) {
            if (slot == nullptr) {
                slot = item;
                items_count++;
                std::cout << "Item added\n";
                Sorting::sortItems(inventory_items);
                return;
            }
        }
    }

    std::cout << "No space left to add item\n";
}

void Inventory::inventoryAddPotion(Potion* potion) {
    if (potions_count >= space) {
        std::cout << "No space left for potions\n";
        return;
    }

    // ��������� � ������ ��������� ����
    for (size_t i = 0; i < inventory_potions.size(); ++i) {
        if (inventory_potions[i] == nullptr) {
            inventory_potions[i] = potion;
            potions_count++;
            std::cout << "Potion added\n";
            Sorting::sortPotions(inventory_potions);
            return;
        }
    }

    std::cout << "No space left for potions\n";
}

void Inventory::usePotion() {
    if (potions_count <= 0) {
        std::cout << "No potions left!\n";
        return;
    }

    // ���������� ��������� �����
    inventory_potions[potions_count - 1]->changeX(-1);
    inventory_potions[potions_count - 1]->changeY(-1);
    inventory_potions[potions_count - 1] = nullptr;

    potions_count--;
    Sorting::sortItems(inventory_items);

    std::cout << "Potion used! Potions left: " << potions_count << "\n";
}

int Inventory::getPotionsCount() {
    return potions_count;
}



std::ostream& operator<<(std::ostream& os, const Inventory& inventory) {
    os << "Inventory (in matrix form):\n";

    // ������� �������� � ���������
    for (const auto& row : inventory.inventory_items) {
        for (const auto& item : row) {
            if (item != nullptr) {
                os << item->getName() << " ";  // �������� ��� ��������
            }
            else {
                os << "[Empty] ";
            }
        }
        os << "\n";
    }

    // ������� �����
    os << "Potions:\n";
    for (const auto& potion : inventory.inventory_potions) {
        if (potion != nullptr) {
            os << "[Potion_" << potion->getHealthRestore() <<"] ";
        }
        else {
            os << "[Empty] ";
        }
    }
    os << "\n";

    return os;
}
