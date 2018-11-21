//
// Created by liuyaqiao on 2018/2/7.
//

#ifndef SHAPES_VECTOR_H
#define SHAPES_VECTOR_H

#include "shape.h"

class Vector {
    Shape **objects;
    int size;
    int length;

    void Grow();

public:
    Vector(int size = 5);
    ~Vector();

    int GetLength();
    void Insert(int index, Shape *object);
    Shape *Delete(int index);
    Shape *Get(int index);
    void Exchange(int index1,int index2);
    void Print(void);
};


#endif //SHAPES_VECTOR_H
