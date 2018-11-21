//
// Created by liuyaqiao on 2018/2/7.
//

#ifndef SHAPES_HEAP_H
#define SHAPES_HEAP_H

#include "Vector.h"

class Heap : public Vector
{
    int Left(int i);
    int Right(int i);
    int Parent(int i);
public:
    void MaxHeapify(int i, int size);
    void BulidMaxHeap();
    void HeapSort();
};


#endif //SHAPES_HEAP_H
