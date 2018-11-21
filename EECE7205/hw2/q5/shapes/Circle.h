#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape
{
	float radius;
public:
	Circle(std::string name, float radius);   //name is mandotoy
	//Print
	void Print();
};

#endif
