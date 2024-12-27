#pragma once
#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <cstdlib> // ƒл€ std::rand и std::srand
#include <ctime> 
#include <vector>
#include "Coordinates.h"
using namespace std;


class Object: public Coordinates // класс дл€ представлени€ объектов. явл€етс€ родительским к классам Player and Monster 
{
private:
	int health;
	static int maxHealth;

	int damage;
	

protected:
	bool is_alive;
	std::string name; // »м€ объекта
public:
	Object();
	Object(int x, int y, int health, int damage);
	
	static void setMaxHealth(int value);
	void setHealth(int value);
	bool isAlive();

	void virtual isDead();
	void isDead_notVirtual();

	void changeHealthValue(int new_value);
	int getCurrentHealth();
	static int getMaxHealth();
	void heal(int value);

	int getX() override;
	int getY() override;
	void setX(int value);
	void setY(int value);
	
	int getDamage();
	void setDamage(int value);
	std::string getName();
	friend std::ostream& operator<<(std::ostream& os, Object& obj) {
		os << "Name: " << obj.name << "\n";
		os << "Position: (" << obj.x << ", " << obj.y << ")\n";
		os << "Health: " << obj.health << "/" << obj.maxHealth << "\n";
		os << "Damage: " << obj.damage << "\n";

		return os;
	}
};