//
// Created by Yaqiao on 2018/2/21.
//

#ifndef BINARYTREE_OBJECT_H
#define BINARYTREE_OBJECT_H

#include <iostream>

class Object
{
public:
    virtual ~Object(){}
    virtual void Print(void) = 0;
    virtual bool Compare(Object *) = 0;
};


#endif //BINARYTREE_OBJECT_H
