//
// Created by Yaqiao on 2018/2/16.
//
#ifndef Q3_DOUBLYLINKEDLIST_H
#define Q3_DOUBLYLINKEDLIST_H

#include "Object.h"
#include <iostream>
struct Node{
    Node *next;
    Node *prev;
    Object *data;
public:
    Node()
    {
        next = 0;
        prev = 0;
    }
};


class DoublyLinkedList {
    Node * head;
    Node * current;
    Node * tail;

public:
    DoublyLinkedList()
    {
        ///////////////////////headnode
        Node *HeadNode = new Node;
        this->head = HeadNode;
        this->current = HeadNode;
        this->tail = 0;
    }

    void ListHead();
    void ListTail();
    void ListNext();
    void ListPrev();
    void Insert(Object *x);
    void Remove();
    void Print();
};


#endif //Q3_DOUBLYLINKEDLIST_H
