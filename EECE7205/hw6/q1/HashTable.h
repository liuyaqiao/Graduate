//
// Created by Yaqiao on 2018/3/10.
//

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

#include "Object.h"

class HashTable {
    struct Node
    {
        Object *key;
        Object *data;
        Node *next;
    };

    Node **nodes;
    int length;
    int size;
    static const float max_load_factor;

    void Grow();

public:
    HashTable(int size = 10);
    ~HashTable();

    void Print();
    void Insert(Object *key, Object *data);
    Object *Search(Object *key);
    Object *Delete(Object *key);
    Object *Succ(Object *key);
};


#endif //HASHTABLE_HASHTABLE_H
