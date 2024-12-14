#pragma once
#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <cstdlib> // ��� std::rand � std::srand
#include <ctime> 
#include <vector>

class Object // ����� ��� ������������� ��������. �������� ������������ � ������� Player and Monster 
{
private:
	int x, y;
	int health;
	static int maxHealth;

	int damage;
	bool is_alive;
public:
	Object();
	Object(int x, int y, int health, int damage);
	
	static void setMaxHealth(int value);
	void setHealth(int value);
	bool isAlive();
	void isDead();
	void changeHealthValue(int new_value);
	int getCurrentHealth();
	static int getMaxHealth();
	void heal(int value);

	int& getX();
	int& getY();
	void setX(int value);
	void setY(int value);
	
	int getDamage();
	void setDamage(int value);
	
};