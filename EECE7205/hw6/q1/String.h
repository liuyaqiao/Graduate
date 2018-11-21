//
// Created by Yaqiao on 2018/3/14.
//

#ifndef HASHTABLE_STRING_H
#define HASHTABLE_STRING_H
#include "Object.h"

class String : public Object{
public:
    std::string s;
    String();
    String(std::string s);
    void Print();
    bool Compare(Object *object);
    unsigned int Hash();

};


#endif //HASHTABLE_STRING_H
