#pragma once
#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <cstdlib> // Для std::rand и std::srand
#include <ctime> 
class Health // класс для представления здоровья игрока
{
private:
    int current_health;
    static int max_health;
public:
    Health();
    static void setMaxHealth(int new_size);

    int getCurrentHealth(); // получаем текущее здоровья
    static int getMaxHealth();
    void heal(int healpoints); // лечим объект
    void changeHealthValue(int new_value); // изменяем значение текущего здоровья
};