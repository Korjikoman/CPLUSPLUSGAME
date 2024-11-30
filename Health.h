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
    static int max_health;
public:
    Health();
    static void setMaxHealth(int new_size);

    int getCurrentHealth(); // �������� ������� ��������
    static int getMaxHealth();
    void heal(int healpoints); // ����� ������
    void changeHealthValue(int new_value); // �������� �������� �������� ��������
};