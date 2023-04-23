#pragma once
#include "Circle.h"

class Cylinder : public Circle
{
protected:
	double h;
public:
	Cylinder(int x, int y, double r, double h);

	double get_h();

	void scale_h(int value);

	double calculateSquare();

	double calculateVolume();
};