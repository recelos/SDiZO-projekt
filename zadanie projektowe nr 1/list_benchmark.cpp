#include <iostream>
#include <windows.h>
#include <iomanip>
#include <time.h>
#include "list_benchmark.h"
#include "bidirectional_list.h"

long long int read_QPC2()
{
    LARGE_INTEGER count;
    QueryPerformanceCounter((LARGE_INTEGER*) &count);
    return ((long long int) count.QuadPart);
}

ListBenchmark::ListBenchmark(int data_quantity)
{
    std::cout << "Testy na listach\n";
    list_test_add_to_beggining(data_quantity);
    list_test_add_to_end(data_quantity);
    list_test_add_to_index(data_quantity);
    list_test_delete_beggining(data_quantity);
    list_test_delete_end(data_quantity);
    list_test_delete_at_index(data_quantity);
    list_test_search(data_quantity);
}
void ListBenchmark::list_test_add_to_beggining(int data_quantity)
{
    int results[100];

    for (int i = 0; i < 100; i++)
    {
    BidirectionalList * list = new BidirectionalList();
    list -> fill_random(data_quantity, data_quantity);

    long long int frequency, start, end, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    
    start = read_QPC2();
    list -> add_to_beginning(333);
    end = read_QPC2();

    elapsed = end - start;
    results[i] = 1000000000.0 * elapsed / frequency;

    delete list;

    }
    int result = 0;
    for (int i = 0; i < 100; i++)
    {
        result += results[i];
    }
    
    std::cout << "Test dodawania na poczatek -- Czas w ns: " << result/100 << std::endl;
}
void ListBenchmark::list_test_add_to_end(int data_quantity)
{
    int results[100];

    for (int i = 0; i < 100; i++)
    {
    BidirectionalList * list = new BidirectionalList();
    list -> fill_random(data_quantity, data_quantity);

    long long int frequency, start, end, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    
    start = read_QPC2();
    list -> add_to_end(333);
    end = read_QPC2();

    elapsed = end - start;
    results[i] = 1000000000.0 * elapsed / frequency;

    delete list;

    }
    int result = 0;
    for (int i = 0; i < 100; i++)
    {
        result += results[i];
    }
    
    std::cout << "Test dodawania na koniec -- Czas w ns: " << result/100 << std::endl;
}
void ListBenchmark::list_test_add_to_index(int data_quantity)
{
    int results[100];

    for (int i = 0; i < 100; i++)
    {
        BidirectionalList * list = new BidirectionalList();
        list -> fill_random(data_quantity, data_quantity);

        long long int frequency, start, end, elapsed;
        QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
        
        int to_add = data_quantity/2;

        start = read_QPC2();
        list -> add_to_index(to_add, 333);
        end = read_QPC2();

        elapsed = end - start;
        results[i] = 1000000000.0 * elapsed / frequency;
        delete list;
    }
    int result = 0;
    for (int i = 0; i < 100; i++)
    {
        result += results[i];
    }
    
    std::cout << "Test dodawania na srodek -- Czas w ns: " << result/100 << std::endl;
}
void ListBenchmark::list_test_delete_beggining(int data_quantity)
{

    int results[100];

    for (int i = 0; i < 100; i++)
    {
    BidirectionalList * list = new BidirectionalList();
    list -> fill_random(data_quantity, data_quantity);

    long long int frequency, start, end, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    
    start = read_QPC2();
    list -> delete_beginning();
    end = read_QPC2();

    elapsed = end - start;
    results[i] = 1000000000.0 * elapsed / frequency;

    delete list;

    }
    int result = 0;
    for (int i = 0; i < 100; i++)
    {
        result += results[i];
    }
    
    std::cout << "Test usuwania z poczatku -- Czas w ns: " << result/100 << std::endl;
}
void ListBenchmark::list_test_delete_end(int data_quantity)
{

    int results[100];

    for (int i = 0; i < 100; i++)
    {
    BidirectionalList * list = new BidirectionalList();
    list -> fill_random(data_quantity, data_quantity);

    long long int frequency, start, end, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    
    start = read_QPC2();
    list -> delete_end();
    end = read_QPC2();

    elapsed = end - start;
    results[i] = 1000000000.0 * elapsed / frequency;

    delete list;

    }
    int result = 0;
    for (int i = 0; i < 100; i++)
    {
        result += results[i];
    }
    
    std::cout << "Test usuwania z konca -- Czas w ns: " << result/100 << std::endl;
}
void ListBenchmark::list_test_delete_at_index(int data_quantity)
{
    int results[100];

    for (int i = 0; i < 100; i++)
    {
        BidirectionalList * list = new BidirectionalList();
        list -> fill_random(data_quantity, data_quantity);

        long long int frequency, start, end, elapsed;
        QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
        
        int to_delete = data_quantity/2;

        start = read_QPC2();
        list -> delete_at_index(to_delete);
        end = read_QPC2();

        elapsed = end - start;
        results[i] = 1000000000.0 * elapsed / frequency;
        delete list;
    }
    int result = 0;
    for (int i = 0; i < 100; i++)
    {
        result += results[i];
    }
    
    std::cout << "Test usuwania z srodka -- Czas w ns: " << result/100 << std::endl;
}




void ListBenchmark::list_test_search(int data_quantity)
{
    int results[100];

    for (int i = 0; i < 100; i++)
    {
        BidirectionalList * list = new BidirectionalList();
        list -> fill_random(data_quantity, data_quantity);

        long long int frequency, start, end, elapsed;
        QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
        
        int to_search = data_quantity/2;

        start = read_QPC2();
        list -> search(to_search);
        end = read_QPC2();

        elapsed = end - start;
        results[i] = 1000000000.0 * elapsed / frequency;

        delete list;

    }
    int result = 0;
    for (int i = 0; i < 100; i++)
    {
        result += results[i];
    }
    
    std::cout << "Test szukania -- Czas w ns: " << result/100 << std::endl;
}