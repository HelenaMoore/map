#pragma once
#include "Rectangle.h"

class Parallelepiped : public Rectangle
{
protected:
	int z1; int z2;
public:
	Parallelepiped(int x1, int y1, int x2, int y2, int z1, int z2);

	int get_z1(); int get_z2();

	void shift_z(int value);
	void scale_z(int value);

	void scaleAll(int value);

	int calculateSideC();

	int calculateSquare();

	int calculateVolume();
};