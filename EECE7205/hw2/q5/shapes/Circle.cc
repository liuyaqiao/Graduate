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
