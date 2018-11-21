//
// Created by Yaqiao on 2018/2/15.
//

#include "Vector.h"
#include "Integer.h"
#include <iostream>
#include <cstdlib>

Vector::Vector(int size)
{
    this->size = size;
    length = size;
    objects = new Object*[size];
    for(int i=0;i<size;i++)
    {
        objects[i] = new Integer(size-i);
    }
}

Vector::~Vector()
{
    delete objects;
}

int  Vector::GetLength()
{
    return length;
}

void Vector::Grow(void)
{
    int new_size = size * 2;
    int i;
    Object **new_object_array = new Object* [new_size];

    for(i=0; i <size ;i++)
        new_object_array[i] = objects[i];

    delete objects;
    objects = new_object_array;
    size = new_size;
}

void Vector::Insert(int index, Object *object)
{
    if(index < 0 || index > length)
        throw"Invalid index";

    if(length == size)
        Grow();

    for(int i = length - 1;i>=index;i--)
        objects[i+1] = objects[i];

    objects[index] = object;
    length++;
}

Object *Vector::Delete(int index)
{
    int i;
    Object *object;

    if(index < 0 || index >= length)
        throw "Invalid index";

    object = objects[index];
    for(i = index +1; i<length;i++)
        objects[i-1] = objects[i];

    length-- ;
    return object;
}

Object *Vector::Get(int index)
{
    if(index < 0||index >= length)
        throw"Invalid index";

    return objects[index];
}

void Vector::Exchange(int index1, int index2)
{
    if (index1 < 0 || index1 >= length)
        throw "Invalid index 1 ";
    if (index2 < 0 || index2 >= length)
        throw "Invalid index 2 ";

    std::swap(objects[index1],objects[index2]);
}

void Vector::Print()
{
    for (int i=0;i<length;i++)
        objects[i]->Print();
}

int Vector::QuickSortParition(int left, int right)
{
    int p = left;
    for(int now = left; now<right; now++){
        if(objects[now]->Compare(objects[right]))
        {
            Exchange(now,p);
            p++;
        }
    }
    Exchange(right,p);
    return p;
}

void Vector::QuickSort(int left, int right)
{
    if(left<right)
    {
        int p = QuickSortParition(left, right);
        QuickSort(left,p-1);
        QuickSort(p+1,right);
    }
}

void Vector::QuickSort()
{
    QuickSort(0,length-1);
  //  QuickSortRandomPivot(0,length-1);

}

int Vector::QuickSortParitionRandomPivot(int left, int right)
{
    int p = left;
    int pivot = 0;
    pivot = rand()%(right - left) + left;
    Exchange(pivot,right);
    for(int now = left; now<right; now++){

        if(objects[now]->Compare(objects[right]))
        {
            Exchange(now,p);
            p++;
        }
    }
    Exchange(right,p);
    return p;
}

void Vector::QuickSortRandomPivot(int left, int right) {
    if(left<right)
    {
        int p = QuickSortParitionRandomPivot(left,right);
        QuickSortRandomPivot(left,p-1);
        QuickSortRandomPivot(p+1,right);

    }
}
