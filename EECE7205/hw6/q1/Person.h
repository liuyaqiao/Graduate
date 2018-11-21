//
// Created by Yaqiao on 2018/3/14.
//

#ifndef HASHTABLE_PERSON_H
#define HASHTABLE_PERSON_H

#include <iostream>
#include "Object.h"
#include "String.h"

class Person : public Object
{
public:
    String first;
    String last;
    std::string email;
    int age;
    Person(std::string first, std::string last, int age, std::string email);
    void Print();
    bool Compare(Object *);
};


#endif //HASHTABLE_PERSON_H
