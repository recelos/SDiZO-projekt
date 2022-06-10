#include <iostream>
#include <windows.h>
#include <iomanip>
#include <time.h>
#include "heap_benchmark.h"
#include "heap.h"

long long int read_QPC1()
{
    LARGE_INTEGER count;
    QueryPerformanceCounter((LARGE_INTEGER*) &count);
    return ((long long int) count.QuadPart);
}


HeapBenchmark::HeapBenchmark(int data_quantity)
{
    std::cout << "Testy na kopcach:\n";
    heap_test_add(data_quantity);
    heap_test_extract_max(data_quantity);
    heap_test_search(data_quantity);
}

void HeapBenchmark::heap_test_add(int data_quantity)
{
    int results[100];

    for (int i = 0; i < 100; i++)
    {
    Heap * heap = new Heap();
    heap -> fill_random(data_quantity, data_quantity);

    long long int frequency, start, end, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    
    start = read_QPC1();
    heap -> add(333);
    end = read_QPC1();

    elapsed = end - start;
    results[i] = 1000000000.0 * elapsed / frequency;

    delete heap;

    }
    int result = 0;
    for (int i = 0; i < 100; i++)
    {
        result += results[i];
    }
    
    std::cout << "Test dodawania do kopca -- Czas w ns: " << result/100 << std::endl;    
}


void HeapBenchmark::heap_test_extract_max(int data_quantity)
{
    int results[100];

    for (int i = 0; i < 100; i++)
    {
    Heap * heap = new Heap();
    heap -> fill_random(data_quantity, data_quantity);

    long long int frequency, start, end, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    
    start = read_QPC1();
    heap -> extract_max();
    end = read_QPC1();

    elapsed = end - start;
    results[i] = 1000000000.0 * elapsed / frequency;

    delete heap;

    }
    int result = 0;
    for (int i = 0; i < 100; i++)
    {
        result += results[i];
    }
    
    std::cout << "Test usuwania z korzenia -- Czas w ns: " << result/100 << std::endl;  
}
void HeapBenchmark::heap_test_search(int data_quantity)
{
    int results[100];

    for (int i = 0; i < 100; i++)
    {
        Heap * heap = new Heap();
        heap -> fill_random(data_quantity, data_quantity);

        long long int frequency, start, end, elapsed;
        QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
        
        int to_search = data_quantity/2;
        
        start = read_QPC1();
        heap -> search(to_search);
        end = read_QPC1();

        elapsed = end - start;
        results[i] = 1000000000.0 * elapsed / frequency;

        delete heap;

    }
    int result = 0;
    for (int i = 0; i < 100; i++)
    {
        result += results[i];
    }
    
    std::cout << "Test szukania w kopcu -- Czas w ns: " << result/100 << std::endl;  
}