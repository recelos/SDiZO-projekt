#include "MatrixBenchmark.h"
#include <time.h>
#include <windows.h>
#include <iostream>
long long int read_QPC()
{
    LARGE_INTEGER count;
    QueryPerformanceCounter((LARGE_INTEGER*) &count);
    return ((long long int) count.QuadPart);
}

MatrixBenchmark::MatrixBenchmark(int v, double d)
{
    this->matrix = new AdjMatrix(v, d);
}

void MatrixBenchmark::test_prim()
{
    int results[5];

    for (int i = 0; i < 5; i++)
    {
    long long int frequency, start, end, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    
    start = read_QPC();
    matrix -> primMST_test();
    end = read_QPC();

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
void MatrixBenchmark::test_kruskal()
{
    int results[5];

    for (int i = 0; i < 5; i++)
    {
    long long int frequency, start, end, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    
    start = read_QPC();
    matrix -> kruskalMST_test();
    end = read_QPC();

    elapsed = end - start;
    results[i] = 1000000.0 * elapsed / frequency;
    }
    int result = 0;
    for (int i = 0; i < 5; i++)
    {
        result += results[i];
    }
    
    std::cout << "Test algorytmu Kruskala -- Czas w mikrosekundach: " << result/5 << std::endl;    
}
void MatrixBenchmark::test_dijkstra()
{
    int results[5];

    for (int i = 0; i < 5; i++)
    {
    long long int frequency, start, end, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    
    start = read_QPC();
    matrix -> dijkstra_test(0);
    end = read_QPC();

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
void MatrixBenchmark::test_bellmanford()
{
    int results[5];

    for (int i = 0; i < 5; i++)
    {
    long long int frequency, start, end, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    
    start = read_QPC();
    matrix -> bellmanFord_test(0);
    end = read_QPC();

    elapsed = end - start;
    results[i] = 1000000.0 * elapsed / frequency;
    }
    int result = 0;
    for (int i = 0; i < 5; i++)
    {
        result += results[i];
    }
    
    std::cout << "Test algorytmu Kruskala -- Czas w mikrosekundach: " << result/5 << std::endl;    
}