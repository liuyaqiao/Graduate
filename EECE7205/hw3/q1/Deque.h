//
// Created by Yaqiao on 2018/2/11.
//

#ifndef HW3_DEQUE_DEQUE_H
#define HW3_DEQUE_DEQUE_H

#include "Object.h"

class Deque {
    Object **objects;
    int head;
    int tail;
    int size;
public:
    int GetHead(){ return head;}
    int GetTail(){ return tail;}
    Deque(int size = 5)
    {
        this->size = size;
        tail = 0;
        head = 0;
        objects = new Object*[size];
    }
    void InsertFront(Object *object);
    void InsertBack(Object *object);
    Object* DeleteFront();
    Object* DeleteBack();

 //   void Insertion(int index, Object* object);
 //   Object* Delete(int index);
    int GetLength();
    int GetSize(){return size;}
    bool IsFull();//there is a space position in array which is different with the IsEmpty()
    bool IsEmpty();
    void Print();
    Object* Get(int index)
    {return objects[index];}

};


#endif //HW3_DEQUE_DEQUE_H
