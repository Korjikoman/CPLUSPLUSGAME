#pragma once
#include <iostream>

class Coordinates {
public:
	Coordinates(int x, int y) : x{ x }, y{ y } {}
	void location() const {
		std::cout << "(" << x << "; " << y << ")\n";
	}
	virtual int getX()  = 0;
	virtual int getY()  = 0;

protected:
	int x;
	int y;

};