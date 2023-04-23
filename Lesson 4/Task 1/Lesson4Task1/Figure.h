#pragma once
#include <string>

class Figure
{
protected:
	std::string name;
	Figure(std::string name);
public:
	Figure();
	std::string getName();
};