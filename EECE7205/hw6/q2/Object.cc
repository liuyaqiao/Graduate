//
// Created by Yaqiao on 2018/3/15.
//

#include "Object.h"

bool Object::Equals(Object * object)
{
    return !Compare(object) && !object->Compare(this);
}

unsigned int Object::Hash(int j)
{
    return 0;
}

