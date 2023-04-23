#define _USE_MATH_DEFINES
#include "Circle.h"

Circle::Circle(int x, int y, double r) : Figure()
{
	name = "Окружность";
	this->x = x; this->y = y; this->r = r;
}

Circle::Circle() {}

int Circle::get_x() { return x; }; int Circle::get_y() { return y; }; int Circle::get_r() { return r; }

void Circle::shift_x(int value) { x += value;}
void Circle::shift_y(int value) { y += value;}

void Circle::scale_r(int value) { r *= value; }

double Circle::calculateSquare() { return M_PI * r * r; }