#pragma once
#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <cstdlib> // ��� std::rand � std::srand
#include <ctime> 
class Health // ����� ��� ������������� �������� ������
{
private:
    int current_health;
    int max_health;
public:
    Health();
    Health(int max);

    int getCurrentHealth(); // �������� ������� ��������
    int getMaxHealth();
    void changeMaxHealthValue(int value);
    void heal(int healpoints); // ����� ������
    void changeHealthValue(int new_value); // �������� �������� �������� ��������
};