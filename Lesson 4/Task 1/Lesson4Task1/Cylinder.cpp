#define _USE_MATH_DEFINES
#include "Cylinder.h"

Cylinder::Cylinder(int x, int y, double r, double h) : Circle(x, y, r)
{
	name = "Цилиндр";
	this->h = h;
}

double Cylinder::get_h() { return h; }

void Cylinder::scale_h(int value) { h *= value; }

double Cylinder::calculateSquare() { return M_PI * r * r * 2 + 2 * r * h; }

double Cylinder::calculateVolume() { return M_PI * r * r * h; }