//
// Created by Yaqiao on 2018/3/10.
//

#include "Object.h"

bool Object::Equals(Object * object)
{
    return !Compare(object) && !object->Compare(this);
}

unsigned int Object::Hash()
{
    return 0;
}