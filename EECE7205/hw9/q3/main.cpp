#include <iostream>
#include <atomic>
#include <thread>
// Number of iterations to run producer and consumer
const int num_iter = 100000;
// Maximum and minimum value recorded for 'x'
int max;
int min;
// Global variable 'x'. You can declare it as 'std::atomic<int>' and just as
// 'int', and compare the output of the program in both cases.
std::atomic<int> x;
//int x;

void producer()
{
    for (int i = 0; i < num_iter; i++)
    {
        x++;
        if (x > max)
            max = x;
    }
}

void consumer()
{
    for (int i = 0; i < num_iter; i++)
    {
        x--;
        if (x < min)
            min = x;
    }
}

int main()
{

    std::thread t(consumer);
    producer();
    t.join();
    std::cout << "Final value of x is " << x << '\n';
    std::cout << "Maximum value of x is " << max << '\n';
    std::cout << "Minimum value of x is " << min << '\n';
    return 0;
}