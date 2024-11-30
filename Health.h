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
    int max_health;
public:
    Health();
    Health(int max);

    int getCurrentHealth(); // получаем текущее здоровьу
    int getMaxHealth();
    void changeMaxHealthValue(int value);
    void heal(int healpoints); // лечим объект
    void changeHealthValue(int new_value); // изменяем значение текущего здоровья
};