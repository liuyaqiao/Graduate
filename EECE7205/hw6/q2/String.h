//
// Created by Yaqiao on 2018/3/15.
//

#ifndef Q2_STRING_H
#define Q2_STRING_H

#include "Object.h"

class String : public Object{
public:
    std::string s;
    String();
    String(std::string s);
    void Print();
    bool Compare(Object *object);
    unsigned int Hash(int j);

};


#endif //Q2_STRING_H
