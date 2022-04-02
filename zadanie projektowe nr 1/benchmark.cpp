#include <iostream>
#include <windows.h>
#include <iomanip>
#include "benchmark.h"
#include "table.h"
#include "heap.h"
#include "bidirectional_list.h"

long long int read_QPC()
{
    LARGE_INTEGER count;
    QueryPerformanceCounter((LARGE_INTEGER*) &count);
    return ((long long int) count.QuadPart);
}

void Benchmark::table_test()
{

}


void Benchmark::list_test_search(int data_quantity)
{
    BidirectionalList * list = new BidirectionalList();


    list -> fill_random(data_quantity, data_quantity);

    long long int frequency, start, end, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    start = read_QPC();

    list -> search(1000);

    end = read_QPC();

    elapsed = end - start;

    std::cout << "Czas w ns: " << 1000000000.0 * elapsed / frequency;
}
void Benchmark::heap_test()
{

}


int main()
{
    Benchmark * bm = new Benchmark();
    bm -> list_test_search(10000);
    return 0;
}