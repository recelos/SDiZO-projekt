#include <iostream>
#include <ctime>
#include "heap.h"

Heap::Heap()
{
    array = NULL;
    size = 0;
}
Heap::~Heap()
{
    delete[] array;
}
void Heap::add(int value)
{
    int * new_array = new int[size+1];
    new_array[size] = value;
    for(int i = 0; i < size; i++)
        new_array[i] = array[i];
    size++;

    delete[] array;
    array = new_array;


    heapify(size-1);

}

void Heap::extract_max()
{
    if(size == 0)
    {
        std::cout << "Kopiec jes pusty";
        return;
    }
    if(size == 1)
    {
        delete [] array;
    }

    int temp = array[size-1];
    array[size-1] = array[0];
    array[0] = temp;

    int * new_array = new int[size-1];
    for(int i = 0; i < size-1; i++)
        new_array[i] = array[i];
    delete[] array;

    array = new_array;
    size--;
    heapify_root(0);
} 

void Heap::build_max_heap()
{
    int starting_index = (size / 2) - 1;
    for (int i = starting_index; i >= 0; i--)
        heapify_root(i);    
}


void Heap::heapify_root(int node)
{   
    int largest_index = node;
    int left_index = 2 * node + 1;
    int right_index = 2 * node + 2;
    if (left_index < size && array[left_index] > array[largest_index])
        largest_index = left_index;

    if (right_index < size && array[right_index] > array[largest_index])
        largest_index = right_index;

    if (largest_index != node) 
    {
        std::swap(array[largest_index], array[node]);
        heapify_root(largest_index);
    }
}


void Heap::heapify(int node)
{
    int parent = (node-1)/2;
    if (array[parent] > 0)
    {
        if (array[node] > array[parent])
        {
        int temp = array[parent];
        array[parent] = array[node];
        array[node] = temp;
        heapify(parent);
        }
    }
}


void Heap::search(int value)
{
    for (int i = 0; i < size; i++)
    {
        if(array[i] == value)
            return;
    }
}

void Heap::search_and_print(int value)
{
    for (int i = 0; i < size; i++)
    {
        if(array[i] == value)
        {
            std::cout << "Znaleziono wartosc: " << value << " na indeksie " << i << std::endl;
            return;
        }
    }
    std::cout << "Nie znaleziono elementu:"  << value << " w kopcu\n";    
}


void Heap::print()
{
    // do pietnasu wezlow wyswietla w postaci piramidy
    if (size <= 15 && size!=0)
    {
        for (int i = 0; i < 8; i++)
        {
            std::cout << " ";
        }
        std::cout << array[0] << std::endl;

        for (int i = 0; i < 7; i++) std::cout << " ";
        
        for (int i = 1; i < 3; i++)
        {
            if(i>=size) return;
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
        for (int i = 0; i < 5; i++) std::cout << " ";

        for (int i = 3; i < 7; i++)
        {
            if(i>=size) return;
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
        for (int i = 0; i < 2; i++) std::cout << " ";
    
        for (int i = 7; i < 15; i++)
        {
            if(i>=size) return;
            std::cout << array[i] << " ";
        }
        return;
    }
    
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << "(" << i << ") ";
    }
    std::cout << std::endl;
}

void Heap::fill_random(int quantity, int range)
{
    srand(time(0));
    for (int i = 0; i < quantity; i++)
    {
        int to_add = 1 + rand() % range;
        add(to_add);
    }
}