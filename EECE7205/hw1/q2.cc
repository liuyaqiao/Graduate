#include <iostream>
#include <cstdlib>
#include <time.h> 

using namespace std;

//merge sort algorithm

template <class T>
int getArrayLen(T& array)
{
return (sizeof(array) / sizeof(array[0]));
}

void merge(int *A, int left1, int right1, int left2, int right2)
{
int n=0;
int *x = new int [right2-left1+1];
while(left1 <= right1 || left2 <= right2)
{
	if(left2>right2 || (left1<=right1 && A[left1]<A[left2]))
		{
		x[n] = A[left1];
		left1 ++;	
		}
	else{
		x[n] = A[left2];
		left2++;
		}
	n++;
}

while(n>0)
{
A[right2] = x[n-1];
n--;
right2--;
}
delete [] x;
}

void mergeSortRec(int *A, int left, int right)
{
int n;
n = right -left + 1;
if(n>1)
	{
	mergeSortRec(A,left,left+n/2-1);
	mergeSortRec(A,left+n/2,right);
	merge(A,left,left+n/2-1,left+n/2,right);
	}
}

void print_vector(int *A, int n)
{
int i;
cout<<"array is"<<endl;
for(i=0;i<n;i++)
	cout<<A[i]<<" ";
cout<<endl;
}

void merge_sort(int *A,int len)
{
mergeSortRec(A, 0, len-1);
}

int main(int argc, char * argv[])
{
int i,len;
char *a;
a = argv[1];
len = atoi(a);
int *array = new int[len];
for(i=0;i<len;i++)
	array[i]=len-i; 	
cout<<"The original ";
print_vector(array, len);
merge_sort(array,len);
cout<<"The current ";
print_vector(array,len);
delete array;

}
