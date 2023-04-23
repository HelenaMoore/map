#include "Parallelepiped.h"

Parallelepiped::Parallelepiped(int x1, int y1, int x2, int y2, int z1, int z2) : Rectangle(x1, y1, x2, y2)
{
	name = "Параллелепипед";
	this->z1 = z1; this->z2 = z2;
}

int Parallelepiped::get_z1() { return z1; }; int Parallelepiped::get_z2() { return z2; }

void Parallelepiped::shift_z(int value) { z1 += value; z2 += value; }
void Parallelepiped::scale_z(int value) { z2 *= value; }

void Parallelepiped::scaleAll(int value) { x2 *= value; y2 *= value; z2 *= value; }

int Parallelepiped::calculateSideC() { return abs(z1 - z2); }

int Parallelepiped::calculateSquare() 
{ 
	int a = calculateSideA(); 
	int b = calculateSideB();
	int c = calculateSideC(); 
	return (a * b + a * c + b * c) * 2;
}

int Parallelepiped::calculateVolume()
{
	int a = calculateSideA();
	int b = calculateSideB();
	int c = calculateSideC();
	return a * b * c;
}