#pragma once
#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
using namespace std;

class Potion // класс для представления зелий восстановления
{

private:
    int x, y;
    static int health_restore;
    bool collected;
public:
    Potion();

    bool isCollected() const;
    void collect();
    int getX() const;
    int getY() const;
    static int getHealthRestore();
    static void setHealthRestore(int value);


    void move(int dx, int dy);
    void move_random();

    void changeX(int value);
    void changeY(int value);

    // Перегрузка оператора + для объединения двух зелий
    friend const Potion operator+(const Potion& potion1, const Potion& potion2);

    Potion& operator++();

    // Перегрузка постфиксного оператора ++
    Potion operator++(int);

    friend ostream& operator<<(ostream& os, Potion& potion);

};