//
// Created by Yaqiao on 2018/2/16.
//

#include "DoublyLinkedList.h"

void DoublyLinkedList::ListHead()
{
    current = head;
}

void DoublyLinkedList::ListTail()
{
    current = tail;

}

void DoublyLinkedList::ListNext()
{
    if(current == tail)
    {
        std::cout<<"\nit's current is tail now! It cannot move back!\n";
        return;
    }

    current = current->next;
}

void DoublyLinkedList::ListPrev()
{
    if(current == head) {
        std::cout<<"\nit's current is HeadNode now! It cannot move front!\n";
        return;
    }
        current = current->prev;
}

void DoublyLinkedList::Insert(Object *x)
{
    Node *node = new Node;
    node->data = x;

    if(current == head){
        if(current->next==0) {
            tail = node;
        }else
        {
            current->next->prev = node;
        }
        node->prev = current;
        node->next = current->next;
        current->next = node;
        current = node;
    }else if(current == tail){
        node->prev = current;
        node->next = 0;
        current->next = node;
        current = node;
        tail = node;
    } else{
        node->prev = current;
        node->next = current->next;
        current->next->prev = node;
        current->next = node;
        current = node;
    }
}

void DoublyLinkedList::Remove()
{
    Node* temp;
    temp = current;
    if(current == head)
    {
        std::cout<<"\nit's headNode,you cannot remove this\n";
        return;
    }else if(current == tail){
        current->prev->next = current->next;
        current = current->prev;
        tail = current;
    } else{
        current->next->prev = current->prev;
        current->prev->next = current->next;
        current = current->next;
        delete temp;
    }
}

void DoublyLinkedList::Print()
{
    Node* it;
    std::cout<<"\ntraversal from the head\n";
    for(it = head->next;it!=0;it=it->next)
    {
        it->data->Print();
    }

    std::cout<<"\nreverse traversal\n";

    for(it = tail;it!=head;it=it->prev)
    {
        it->data->Print();
    }
}
