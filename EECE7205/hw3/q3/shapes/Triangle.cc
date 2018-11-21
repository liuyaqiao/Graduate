//
// Created by liuyaqiao on 2018/2/7.
//

#include "Triangle.h"
#include "math.h"

Triangle::Triangle(std::string name, float a, float b, float c)
    :Shape(name)
{
    this->a = a;
    this->b = b;
    this->c = c;
}

float Triangle::getArea()
{
    int p;
    p = 0.5*(a+b+c);
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

