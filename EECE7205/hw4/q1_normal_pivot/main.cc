#include <iostream>
#include <cstdlib>
#include "Vector.h"
#include "Integer.h"


int main(int argc, char * argv[]) {
    char *a;
    int size;
    a = argv[1];
    size = atoi(a);
    Vector vector(size);
    vector.Print();
    std::cout<<"--------------------\n";
    vector.QuickSort();
    std::cout<<"\n--------------------\n";
    vector.Print();
    return 0;
}
