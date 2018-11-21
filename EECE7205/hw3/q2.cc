#include <iostream>

//recursive heap sort


int Left(int i)
{
    return 2*i+1;
}

int Right(int i)
{
    return 2*i+2;
}

int Parent(int i)
{
    return (i-1)/2;
}

template <class T>
void Swap(T & x,T & y)
{
    T tmp;
    tmp = x;
    x = y;
    y = tmp;
}

template <class T>
void Print(T a[],int size)
{
    int i;
    for(i=0;i<size;i++)
        std::cout<<a[i]<<"  ";
}



template <class T>
void MaxHeapify(T a[], int i,int size)
{
    int l,r,max;
    l = Left(i);
    r = Right(i);

    if(l<size  && a[l] > a[i])
        max = l;
    else
        max = i;
    if(r<size && a[r]>a[max])
        max = r;
    if(max != i) {
        Swap(a[i], a[max]);
        MaxHeapify(a, max, size);
    }
}

template <class T>
void MaxHeapify(int i,int size)
{
    int l;
    int r;
    int max;
    while(true)
    {
        l = Left(i);
        r = Right(i);
        max = i;
        if(l<size && i<l)
        {
            max = l;
        }
        if(r<size && max<r)
        {
            max = r;
        }
        if(max != i)
        {
            std::swap(i,max);
            i = max;
        }else{
            break;
        }
    }

}

template <class T>
void BuildMaxHeap(T a[],int size)
{
    int i;
    for(i=Parent(size - 1);i>=0;--i)
        MaxHeapify(a,i,size);
}

template <class T>
void HeapSort(T a[],int size)
{
    int i;
    BuildMaxHeap(a,size);
    for(i = size -1;i>0 ;--i)
    {
        Swap(a[0],a[i]);
        MaxHeapify(a,0,i);
    }
}

int main() {

    std::cout << "---------Before Sorting--------\n" << std::endl;
    int a[9] = {0,2,1,9,6,7,10,5,3};
    Print(a,9);
    std::cout<<"\n----------After Sorting--------------\n";
    HeapSort(a,9);
    Print(a,9);
    std::cout<<std::endl;    
    return 0;
}
