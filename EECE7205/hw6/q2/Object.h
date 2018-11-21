//
// Created by Yaqiao on 2018/3/15.
//

#ifndef Q2_OBJECT_H
#define Q2_OBJECT_H


class Object {
public:
    virtual void Print(void) = 0;
    virtual bool Compare(Object *) = 0;
    virtual unsigned int Hash(int j);
    virtual bool Equals(Object *);
};


#endif //Q2_OBJECT_H
