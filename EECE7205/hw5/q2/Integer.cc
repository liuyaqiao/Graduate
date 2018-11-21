//
// Created by Yaqiao on 2018/2/23.
//

#include "Integer.h"
#include <iostream>

Integer::Integer(int value)
{
    this->value = value;

}

void Integer::Print()
{
    std::cout<<value<<"  ";
}

bool Integer::Compare(Object *other)
{
    return value < dynamic_cast<Integer *>(other)->value;
}