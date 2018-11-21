#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
//shape.h  include twice


int main()
{
	Rectangle *r1,*r2;
	Square *s1;
	s1 = new Square("My square", 7);
	r1 = new Rectangle("My rectangle 1",12,5);
	r2 = new Rectangle("My rectangle 2",20,10);
	r1->Draw();
	delete r1;
	r2->Draw();
	delete r2;
	s1->Draw();
	delete s1;
	return 0;
}
