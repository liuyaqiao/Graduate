//
// Created by Yaqiao on 2018/2/11.
//

#include "Deque.h"
#include <iostream>

void Deque::InsertFront(Object *object)
{
    if(this->IsFull() == true)
    {
        std::cout<< "the deque is full, you cannot insert an element\n";
        return;
    }

    head = (head-1+size)%size;
    objects[head] = object;

}

void Deque::InsertBack(Object *object)
{
    if(this->IsFull() == true)
    {
        std::cout<< "the deque is full, you cannot insert an element\n";
        return;
    }
    objects[tail] = object;
    tail = (tail+1+size)%size;
}


Object* Deque::DeleteFront()
{
    if(this->IsEmpty() == true) {
        std::cout << "the deque is empty, you cannot delete any element!\n";
	return 0;    
	}

    Object* object;
    object = objects[head];
    head = (head+1+size)%size;
    return object;
}

Object* Deque::DeleteBack()
{
    if(this->IsEmpty() == true)
    {
        std::cout<<"the deque is empty, you cannot delete any element!!\n";
	return 0;    
}

    Object* object;
    object = objects[tail-1];
    tail = (tail-1+size)%size;
    return object;
}

int Deque::GetLength()
{
    return (tail+size-head)%size;
}

bool Deque::IsFull()
{
    if((tail+1-head+size)%size == 0)
        return true;
    return false;
}

bool Deque::IsEmpty()
{
    if(head == tail)
        return true;
    return false;
}

void Deque::Print()
{
    for(int i=head;i<(head+this->GetLength());i++)
    {

        objects[i%size]->Print();
    }
}
