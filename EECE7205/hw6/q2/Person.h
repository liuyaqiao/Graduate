//
// Created by Yaqiao on 2018/3/15.
//


#ifndef Q2_PERSON_H
#define Q2_PERSON_H

#include <iostream>
#include "Object.h"
#include "String.h"

class Person {
public:
    String first;
    String last;
    std::string email;
    int age;
    Person(std::string first, std::string last, int age, std::string email);
    void Print();
    bool Compare(Object *);
};


#endif //Q2_PERSON_H
