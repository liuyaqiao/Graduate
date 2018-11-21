//
// Created by Yaqiao on 2018/3/15.
//

#ifndef Q2_HASHTABLE_H
#define Q2_HASHTABLE_H

#include <iostream>
#include <cstdlib>
#include "Object.h"

class Hashtable {
    struct Node
    {
        Object *key;
        Object *data;
        bool removed;
        Node() {
            this->key = NULL;
            this->data = NULL;
            this->removed = false;
        }
    };

    Node **nodes;
    int length;
    int size;
    static const float max_load_factor;
public:
    Hashtable(int size = 10);
    ~Hashtable();

    void Print();
    void Insert(Object *key, Object *data);
    Object *Search(Object *key);
    Object *Delete(Object *key);
};


#endif //Q2_HASHTABLE_H


