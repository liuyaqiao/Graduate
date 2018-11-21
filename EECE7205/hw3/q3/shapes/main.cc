#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Heap.h"
#include "Triangle.h"
// /shape.h  include twice


int main()
{
	Rectangle *r1,*r2;
	Square *s1,*s2,*s3;
	Circle *c1,*c2,*c3;
    Triangle *t1,*t2;
	s1 = new Square("My Square 1", 7);
	r1 = new Rectangle("My Rectangle 1",12,5);
	r2 = new Rectangle("My Rectangle 2",20,10);
	c1 = new Circle("My Circle 1",5);
	c2 = new Circle("My Circle 2",6);
    c3 = new Circle("My Circle 3", 7);
    t1 = new Triangle("My Triangle 1",3,4,5);
    t2 = new Triangle("My Triangle 2",10,8,15);
    s2 = new Square("My square 2", 10);
    s3 = new Square("My square 3", 14);




	Heap heap;
	heap.Insert(0,r1);
	heap.Insert(1,s1);
	heap.Insert(2,r2);
	heap.Insert(3,c1);
	heap.Insert(4,c2);
    heap.Insert(5,t1);
    heap.Insert(6,c3);
    heap.Insert(7,t2);
    heap.Insert(8,s2);
    heap.Insert(9,s3);

    std::cout<<"---------------------------------Before Heap Sorting-------------------------------------------\n";
	heap.Print();
	heap.HeapSort();
    std::cout<<"---------------------------------After Heap Sorting-------------------------------------------\n";
	heap.Print();




	//r1->Draw();
	delete r1;
	//r2->Draw();
	delete r2;
	//s1->Draw();
	delete s1;



	return 0;
}
