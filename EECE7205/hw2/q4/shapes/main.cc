#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
//shape.h  include twice


int main()
{
	int i;
	Shape  *s[3];
	Square *sq;
	Circle *c;
	Rectangle *r;
	
	sq = new Square("My Square ",1.1);
	r = new Rectangle("My Rectangle ",2.2,3.3);
	c = new Circle("My Circle",5.5);
	
	s[0] = sq;
	s[1] = r;
	s[2] = c;	

	for(i=0;i<3;i++)
		std::cout<<"the area of "<<s[i]->getName()<<" is "<<s[i]->getArea()<<'\n';

	delete sq;
	delete c;
	delete r;	

	return 0;
}
