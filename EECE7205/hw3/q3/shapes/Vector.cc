//
// Created by liuyaqiao on 2018/2/7.
//

#include "Vector.h"
#include <iostream>
#include <cstdlib>

Vector::Vector(int size)
{
    this->size = size;
    length = 0;
    objects = new Shape*[size];
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
    Shape **new_object_array = new Shape* [new_size];

    for(i=0; i <size ;i++)
        new_object_array[i] = objects[i];

    delete objects;
    objects = new_object_array;
    size = new_size;
}

void Vector::Insert(int index, Shape *Shape)
{
    if(index < 0 || index > length)
        throw"Invalid index";

    if(length == size)
        Grow();

    for(int i = length - 1;i>=index;i--)
        objects[i+1] = objects[i];

    objects[index] = Shape;
    length++;
}

Shape *Vector::Delete(int index)
{
    int i;
    Shape *Shape;

    if(index < 0 || index >= length)
        throw "Invalid index";

    Shape = objects[index];
    for(i = index +1; i<length;i++)
        objects[i-1] = objects[i];

    length-- ;
    return Shape;
}

Shape *Vector::Get(int index)
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