#include "ListBenchmark.h"
#include <time.h>
#include <windows.h>
#include <iostream>
long long int read_QPC1()
{
    LARGE_INTEGER count;
    QueryPerformanceCounter((LARGE_INTEGER*) &count);
    return ((long long int) count.QuadPart);
}

ListBenchmark::ListBenchmark(int v, double d)
{
    this->list = new AdjList(v, d);
}

void ListBenchmark::test_prim()
{
    int results[5];

    for (int i = 0; i < 5; i++)
    {
    long long int frequency, start, end, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    
    start = read_QPC1();
    list -> primMST_test();
    end = read_QPC1();

    elapsed = end - start;
    results[i] = 1000000.0 * elapsed / frequency;
    }
    int result = 0;
    for (int i = 0; i < 5; i++)
    {
        result += results[i];
    }
    
    std::cout << "Test algorytmu Prima -- Czas w mikrosekundach: " << result/5 << std::endl;    
}
void ListBenchmark::test_dijkstra()
{
    int results[5];

    for (int i = 0; i < 5; i++)
    {
    long long int frequency, start, end, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    
    start = read_QPC1();
    list -> dijkstra_test(0);
    end = read_QPC1();

    elapsed = end - start;
    results[i] = 1000000.0 * elapsed / frequency;
    }
    int result = 0;
    for (int i = 0; i < 5; i++)
    {
        result += results[i];
    }
    
    std::cout << "Test algorytmu Dijkstry -- Czas w mikrosekundach: " << result/5 << std::endl;    
}