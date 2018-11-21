#include "Circle.h"

Circle::Circle(std::string name,float radius)
	: Shape(name)
{
	this->radius = radius;
}

void Circle::Print()
{
	std::cout<<"Circle with radius "<<radius<<'\n';

}

float Circle::getArea()
{
	return 3.1415926*radius*radius;
}
