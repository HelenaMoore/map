#include "Figure.h"

Figure::Figure()
{
	name = "������";
}

Figure::Figure(std::string name)
{
	this->name = name;
}

std::string Figure::getName()
{
	return name;
}