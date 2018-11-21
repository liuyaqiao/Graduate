//
// Created by liuyaqiao on 2018/2/7.
//

#ifndef SHAPES_TRIANGLE_H
#define SHAPES_TRIANGLE_H

#include "shape.h"

class Triangle : public Shape
{
    float a,b,c;
public:
    Triangle(std::string name,float a,float b, float v);
    float getArea();
};


#endif //SHAPES_TRIANGLE_H
