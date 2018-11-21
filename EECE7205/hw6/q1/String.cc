//
// Created by Yaqiao on 2018/3/14.
//

#include <iostream>
#include "String.h"
String::String(std::string s)
{
    this->s = s;
}
void String::Print()
{
    std::cout << s << '\n';
}
bool String::Compare(Object *object)
{
    return s < dynamic_cast<String *>(object)->s;
}
unsigned int String::Hash()
{
    unsigned int i;
    unsigned int c;
    unsigned int hash;
    unsigned int prime;
    hash = 5381;
    prime = 16777619;
    for (i = 0; i < s.length(); i++)
    {
        c = s[i];
        hash = (hash ^ c) * prime;
    }
    return hash;
}
