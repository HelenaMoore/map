#pragma once
#include "Line.h"

class Rectangle : public Line
{
public:
	Rectangle(int x1, int y1, int x2, int y2);
	int calculateSideA();
	int calculateSideB();
	int calculateSquare();
};