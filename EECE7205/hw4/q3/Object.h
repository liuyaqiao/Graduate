//
// Created by Yaqiao on 2018/2/15.
//

#ifndef Q3_OBJECT_H
#define Q3_OBJECT_H


class Object{
public:
    virtual void Print(void) = 0;
    virtual bool Compare(Object *) = 0;
    virtual ~Object(){}
};



#endif //Q3_OBJECT_H
