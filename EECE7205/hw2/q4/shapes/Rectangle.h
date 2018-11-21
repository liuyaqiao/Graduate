#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle : public Shape
{
	protected: float width;
	float height;
public:
	Rectangle(std::string name,float width,float height);
	float getArea();
	void Draw();

}; 


#endif
