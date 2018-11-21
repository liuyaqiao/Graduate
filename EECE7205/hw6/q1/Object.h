//
// Created by Yaqiao on 2018/3/10.
//

#ifndef HASHTABLE_OBJECT_H
#define HASHTABLE_OBJECT_H


class Object {
public:
    virtual void Print(void) = 0;
    virtual bool Compare(Object *) = 0;
    virtual unsigned int Hash();
    virtual bool Equals(Object *);
};


#endif //HASHTABLE_OBJECT_H
