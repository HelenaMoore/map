#include "Rectangle.h"
#include <cmath>

Rectangle::Rectangle(int x1, int y1, int x2, int y2) : Line(x1, y1, x2, y2)
{
	name = "Прямоугольник";
}

int Rectangle::calculateSideA() { return abs(x1 - x2); }
int Rectangle::calculateSideB() { return abs(y1 - y2); }

int Rectangle::calculateSquare() { return calculateSideA() * calculateSideB(); }