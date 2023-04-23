#pragma once
#include "Figure.h"

class Line : public Figure
{
protected:
	int x1; int y1;
	int x2; int y2;
public:
	Line(int x1, int y1, int x2, int y2);
	Line();

	int get_x1(); int get_y1();
	int get_x2(); int get_y2();

	void shift_x(int value); void shift_y(int value);

	void scale_x(int value); void scale_y(int value);

	void scaleAll(int value);
};