#include "Line.h"

Line::Line(int x1, int y1, int x2, int y2) : Figure()
{
	name = "Линия";
	this->x1 = x1; this->y1 = y1; this->x2 = x2; this->y2 = y2;
}

Line::Line() {}

int Line::get_x1() { return x1; }; int Line::get_y1() { return y1; }
int Line::get_x2() { return x2; }; int Line::get_y2() { return y2; }

void Line::shift_x(int value) { x1 += value; x2 += value; }
void Line::shift_y(int value) { y1 += value; y2 += value; }

void Line::scale_x(int value) { x2 *= value; }
void Line::scale_y(int value) { y2 *= value; }

void Line::scaleAll(int value) { x2 *= value; y2 *= value; }