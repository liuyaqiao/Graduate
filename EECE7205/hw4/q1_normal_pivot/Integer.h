//
// Created by Yaqiao on 2018/2/15.
//

#ifndef Q1_INTEGER_H
#define Q1_INTEGER_H

#include "Object.h"

class Integer : public Object
{
public:
    int value;
    Integer(int value);
    void Print(void);
    bool Compare(Object *object);
};


#endif //Q1_INTEGER_H
