#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape
{
	std::string name;

public:
	Shape(std::string name);
	virtual void Print();
	
	//return the area of a shape. The "= 0" suffix indicates that this is
	//a Pure VIRTUAL FUNCTION. THIS MEANS THAT 'SHAPE' is an abstract class
	//which involves:
	//
	//-Class 'shape' cannot be instantiated directly.
	//-Every child class must implement function getArea();
	//
	virtual float getArea();
	//virtual float getArea()=0;
	std::string getName();
	virtual void Draw();
	virtual bool Compare(Shape *other);
};



#endif 
