//
// Created by Yaqiao on 2018/2/15.
//

#ifndef Q1_VECTOR_H
#define Q1_VECTOR_H

#include "Object.h"

class Vector {
    Object **objects;
    int size;
    int length;

    void Grow();

public:
    Vector(int size = 5);
    ~Vector();

    int GetLength();
    void Insert(int index, Object *object);
    Object *Delete(int index);
    Object *Get(int index);
    void Exchange(int index1, int index2);
    void Print(void);
    void QuickSort(int left, int right);
    int QuickSortParition(int left, int right);
    void QuickSort();
    void QuickSortRandomPivot(int left, int right);
    int QuickSortParitionRandomPivot(int left, int right);
};


#endif //Q1_VECTOR_H
