#include "shape.h"

Shape::Shape(std::string name)
{
	this->name = name;
}

void Shape::Print()
{
	std::cout<<"Shape "<<name<<"\n";
}

float Shape::getArea()
{
	return -1;
}

std::string Shape::getName()
{
	return name;
}

void Shape::Draw()
{
}
