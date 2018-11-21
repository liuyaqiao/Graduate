//
// Created by Yaqiao on 2018/2/23.
//

#ifndef BINARYTREE_INTEGER_H
#define BINARYTREE_INTEGER_H

#include "Object.h"

class Integer : public Object
{
public:
    int value;
    Integer(int value);
    void Print();
    bool Compare(Object *other);
};


#endif //BINARYTREE_INTEGER_H
