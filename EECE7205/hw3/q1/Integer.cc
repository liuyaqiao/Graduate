//
// Created by Yaqiao on 2018/2/11.
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