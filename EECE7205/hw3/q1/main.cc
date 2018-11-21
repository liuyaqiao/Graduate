#include <iostream>
#include "Deque.h"
#include "Integer.h"


int main() {

    Deque deque(10);

    Object *o;
    std::cout<<"initial size = "<<deque.GetSize()<<" initial head = "<<deque.GetHead()<<" initial tail = "<<deque.GetTail()<<" initial length = "
             <<deque.GetLength()<<std::endl;
    std::cout<<std::endl;

    std::cout<<"delete element from the empty deque\n\n";

    deque.DeleteBack();
    deque.DeleteFront();

    std::cout<<"\nNow, we insert 1,2,3,4 from the head \n";
    deque.InsertFront(new Integer(1));
    deque.InsertFront(new Integer(2));
    deque.InsertFront(new Integer(3));
    deque.InsertFront(new Integer(4));


    std::cout<<"After InsertionFront\n";
    std::cout<<"size = "<<deque.GetSize()<<" head = "<<deque.GetHead()<<" tail = "<<deque.GetTail()<<" length = "<<deque.GetLength();
    std::cout<<"\nthe deque is \n";
    deque.Print();

    std::cout<<"\n\nNow, we insert 8,9 from the tail\n";

    deque.InsertBack(new Integer(8));
    deque.InsertBack(new Integer(9));

    std::cout<<"After InsertionBack\n";
    std::cout<<"size = "<<deque.GetSize()<<" head = "<<deque.GetHead()<<" tail = "<<deque.GetTail()<<" length = "<<deque.GetLength();
    std::cout<<"\nthe deque is \n";
    deque.Print();

    std::cout<<"\n\nNow, we delete an element from the front\n";
    o =  deque.DeleteFront();
    std::cout<<"the element =  ";
    o->Print();
    std::cout<<"\n";
    std::cout<<"size = "<<deque.GetSize()<<" head = "<<deque.GetHead()<<" tail = "<<deque.GetTail()<<" length = "<<deque.GetLength();
    std::cout<<"\nthe deque is \n";
    deque.Print();
 //   deque.Print();

    std::cout<<"\n\nNow, we delete an element from the back\n";
    o = deque.DeleteBack();
    std::cout<<"the element =  ";
    o->Print();
    std::cout<<"\n";
    std::cout<<"size = "<<deque.GetSize()<<" head = "<<deque.GetHead()<<" tail = "<<deque.GetTail()<<" length = "<<deque.GetLength();
    std::cout<<"\nthe deque is \n";
    deque.Print();

    std::cout<<"\n\nNow, we make the deque full\n";

    deque.InsertFront(new Integer(5));
    deque.InsertFront(new Integer(7));
    deque.InsertFront(new Integer(10));
    deque.InsertFront(new Integer(12));
    deque.InsertBack(new Integer(16));

    deque.InsertBack(new Integer(19));
    std::cout<<"size = "<<deque.GetSize()<<" head = "<<deque.GetHead()<<" tail = "<<deque.GetTail()<<" length = "<<deque.GetLength();
    std::cout<<"\nthe deque is \n";
    deque.Print();
    std::cout<<"\nTest finished!\nAll functions can be invoked successfully!\n";    


    for(int i=deque.GetHead();i<deque.GetHead()+deque.GetLength();i++)
        delete deque.Get(i%(deque.GetSize()));

    return 0;
}
