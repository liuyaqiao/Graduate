//
// Created by liuyaqiao on 2018/2/7.
//

#include "Heap.h"


#include "Heap.h"

int Heap::Left(int i)
{
    return i*2+1;
}

int Heap::Right(int i)
{
    return i*2 +2 ;
}

int Heap::Parent(int i)
{
    return (i-1)/2 ;
}

void Heap::MaxHeapify(int i, int size)
{
    int l;
    int r;
    int max;

    l = Left(i);
    r = Right(i);

    if(l < size && Get(i)->Compare(Get(l)))
        max = l;
    else
        max = i;

    if(r<size && Get(max)->Compare(Get(r)))
        max = r;

    if(max != i)
    {
        Exchange(i,max);
        MaxHeapify(max,size);
    }
}

void Heap::BulidMaxHeap()
{
    for(int i = Parent(GetLength()-1); i>=0;i--)
        MaxHeapify(i,GetLength());
}

void Heap::HeapSort()
{
    BulidMaxHeap();
    for(int i=GetLength()-1;i>=1;i--)
    {
        Exchange(0,i);
        MaxHeapify(0,i);
    }
}