#include "Circle.h"

Circle::Circle(std::string name,float radius)
	: Shape(name)
{
	this->radius = radius;
}

float Circle::getArea()
{
	return 3.1415926*radius*radius;
}