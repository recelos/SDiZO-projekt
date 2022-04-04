#include <iostream>
#include <windows.h>
#include <iomanip>
#include <time.h>
#include "array_benchmark.h"
#include "array.h"

long long int read_QPC()
{
    LARGE_INTEGER count;
    QueryPerformanceCounter((LARGE_INTEGER*) &count);
    return ((long long int) count.QuadPart);
}

ArrayBenchmark::ArrayBenchmark(int data_quantity)
{
    std::cout << "Testy na tablicach\n";
    array_test_add_to_beggining(data_quantity);
    array_test_add_to_end(data_quantity);
    array_test_add_to_index(data_quantity);
    array_test_delete_beggining(data_quantity);
    array_test_delete_end(data_quantity);
    array_test_delete_at_index(data_quantity);
    array_test_search(data_quantity);
}


void ArrayBenchmark::array_test_add_to_beggining(int data_quantity)
{

    int results[100];

    for (int i = 0; i < 100; i++)
    {
    Array * array = new Array();
    array -> fill_random(data_quantity, data_quantity);

    long long int frequency, start, end, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    
    start = read_QPC();
    array -> add_to_beginning(333);
    end = read_QPC();

    elapsed = end - start;
    results[i] = 1000000000.0 * elapsed / frequency;

    delete array;

    }
    int result = 0;
    for (int i = 0; i < 100; i++)
    {
        result += results[i];
    }
    
    std::cout << "Test dodawania na poczatek -- Czas w ns: " << result/100 << std::endl;
}
void ArrayBenchmark::array_test_add_to_end(int data_quantity)
{
    int results[100];

    for (int i = 0; i < 100; i++)
    {
    Array * array = new Array();
    array -> fill_random(data_quantity, data_quantity);

    long long int frequency, start, end, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    
    start = read_QPC();
    array -> add_to_end(333);
    end = read_QPC();

    elapsed = end - start;
    results[i] = 1000000000.0 * elapsed / frequency;

    delete array;

    }
    int result = 0;
    for (int i = 0; i < 100; i++)
    {
        result += results[i];
    }
    
    std::cout << "Test dodawania na koniec -- Czas w ns: " << result/100 << std::endl;
}
void ArrayBenchmark::array_test_add_to_index(int data_quantity)
{
    int results[100];

    for (int i = 0; i < 100; i++)
    {
        Array * array = new Array();
        array -> fill_random(data_quantity, data_quantity);

        long long int frequency, start, end, elapsed;
        QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
        
        int to_add = data_quantity/2;

        start = read_QPC();
        array -> add_to_index(to_add, 333);
        end = read_QPC();

        elapsed = end - start;
        results[i] = 1000000000.0 * elapsed / frequency;
        delete array;
    }
    int result = 0;
    for (int i = 0; i < 100; i++)
    {
        result += results[i];
    }
    
    std::cout << "Test dodawania na srodek -- Czas w ns: " << result/100 << std::endl;
}
void ArrayBenchmark::array_test_delete_beggining(int data_quantity)
{

    int results[100];

    for (int i = 0; i < 100; i++)
    {
    Array * array = new Array();
    array -> fill_random(data_quantity, data_quantity);

    long long int frequency, start, end, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    
    start = read_QPC();
    array -> delete_beginning();
    end = read_QPC();

    elapsed = end - start;
    results[i] = 1000000000.0 * elapsed / frequency;

    delete array;

    }
    int result = 0;
    for (int i = 0; i < 100; i++)
    {
        result += results[i];
    }
    
    std::cout << "Test usuwania z poczatku -- Czas w ns: " << result/100 << std::endl;
}
void ArrayBenchmark::array_test_delete_end(int data_quantity)
{

    int results[100];

    for (int i = 0; i < 100; i++)
    {
    Array * array = new Array();
    array -> fill_random(data_quantity, data_quantity);

    long long int frequency, start, end, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    
    start = read_QPC();
    array -> delete_end();
    end = read_QPC();

    elapsed = end - start;
    results[i] = 1000000000.0 * elapsed / frequency;

    delete array;

    }
    int result = 0;
    for (int i = 0; i < 100; i++)
    {
        result += results[i];
    }
    
    std::cout << "Test usuwania z konca -- Czas w ns: " << result/100 << std::endl;
}
void ArrayBenchmark::array_test_delete_at_index(int data_quantity)
{
    int results[100];

    for (int i = 0; i < 100; i++)
    {
        Array * array = new Array();
        array -> fill_random(data_quantity, data_quantity);

        long long int frequency, start, end, elapsed;
        QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
        
        int to_delete = data_quantity/2;

        start = read_QPC();
        array -> delete_at_index(to_delete);
        end = read_QPC();

        elapsed = end - start;
        results[i] = 1000000000.0 * elapsed / frequency;
        delete array;
    }
    int result = 0;
    for (int i = 0; i < 100; i++)
    {
        result += results[i];
    }
    
    std::cout << "Test usuwania z srodka -- Czas w ns: " << result/100 << std::endl;
}




void ArrayBenchmark::array_test_search(int data_quantity)
{
    int results[100];

    for (int i = 0; i < 100; i++)
    {
        Array * array = new Array();
        array -> fill_random(data_quantity, data_quantity);

        long long int frequency, start, end, elapsed;
        QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
        

        int to_search = data_quantity/2;

        start = read_QPC();
        array -> search(to_search);
        end = read_QPC();

        elapsed = end - start;
        results[i] = 1000000000.0 * elapsed / frequency;

        delete array;

    }
    int result = 0;
    for (int i = 0; i < 100; i++)
    {
        result += results[i];
    }
    
    std::cout << "Test szukania -- Czas w ns: " << result/100 << std::endl;
}
