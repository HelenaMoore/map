#pragma once
#include "Figure.h"

class Circle : public Figure
{
protected:
	int x; int y;
	int r;
public:
	Circle(int x, int y, double r);
	Circle();

	int get_x(); int get_y(); int get_r();

	void shift_x(int value); void shift_y(int value);

	void scale_r(int value);

	double calculateSquare();
};