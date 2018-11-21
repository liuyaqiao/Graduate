#include <iostream>
#include <cstdlib>
#include "Tree.h"
#include "Integer.h"
#include<sys/time.h>
double getTime()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    double sec = (double)tv.tv_sec;         // get sec
    double usec = (double)tv.tv_usec;       // get usec
    return sec * 1000000 + usec;            // return time
}

int main(int argc, char* argv[]) {
    int size;
    size = atoi(argv[1]);
    double begin_time,end_time;
    begin_time = getTime();
    Tree tree;
    Integer* t[size];
    for(int i=0;i<size;i++)
    {
        t[i] = new Integer(i);
        tree.Insert(t[i],t[i]);
    }
    end_time = getTime();
    std::cout<<"\nthe time is  "<<(end_time-begin_time)<<"\n";
    std::cout<<"\nthe height is\n";
    std::cout<<tree.getHeight();

    //std::cout << "Listing tree...\n";
    //tree.Print();
    for(int i=0;i<size;i++)
        delete t[i];

    return 0;
}
