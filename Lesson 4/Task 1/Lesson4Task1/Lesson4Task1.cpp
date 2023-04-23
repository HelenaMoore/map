#include <iostream>
#include "Figure.h"
#include "Line.h"
#include "Rectangle.h"
#include "Parallelepiped.h"
#include "Circle.h"
#include "Cylinder.h"

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");

    Line line(0, 0, 1, 4);
    Rectangle rectangle(0, 1, 2, 3);
    Parallelepiped parallelepiped(0, 1, 2, 3, 0, 8);
    Circle circle(0, 0, 6);
    Cylinder cylinder(0, 0, 3, 10);

    std::cout << "Объём параллелепипеда " << parallelepiped.calculateVolume();

    return 0;
}