#include <iostream>
#include <cstdlib>
#include "Tree.h"
#include "Integer.h"
#include <time.h>
#include <sys/time.h>

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
    srand((unsigned)time(NULL));
    int a[size];
    for(int i=0;i<size;++i)
	    a[i]= i;
    for(int j=size-1;j>=1;--j)
    	std::swap(a[j],a[rand()%j]);

    Tree tree;
    Integer* t[size];
    double begin_time,end_time;
    begin_time = getTime();
    
    for(int i=0;i<size;i++)
    {
	t[i] = new Integer(a[i]);
	tree.Insert(t[i],t[i]);
    }
    end_time = getTime();
    std::cout<<"\nthe time is  "<<(end_time-begin_time)<<"\n";
    tree.getHeight();

    for(int i=0;i<size;i++)
        delete t[i];
    return 0;
}
