#include <iostream>
#include "DoublyLinkedList.h"
#include "Integer.h"
#include "Object.h"
int main() {
    DoublyLinkedList Dlinkedlist;
    for(int i=1;i<=5;i++)
        Dlinkedlist.Insert(new Integer(i));
    Dlinkedlist.ListHead();
    Dlinkedlist.ListNext();
    Dlinkedlist.ListNext();
    Dlinkedlist.Insert(new Integer(1000));
    Dlinkedlist.ListPrev();
    Dlinkedlist.Remove();
    Dlinkedlist.Print();

    return 0;
}