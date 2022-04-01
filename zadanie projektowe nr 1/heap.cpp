#include <iostream>
#include "heap.h"

Heap::Heap()
{
    array = NULL;
    size = 0;
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

    build_max_heap();
}

void Heap::extract_max()
{
    int temp = array[size-1];
    array[size-1] = array[0];
    array[0] = temp;

    int * new_array = new int[size-1];
    for(int i = 0; i < size-1; i++)
        new_array[i] = array[i];
    delete[] array;

    array = new_array;
    size--;
    build_max_heap();

} 

void Heap::build_max_heap()
{
    int starting_index = (size / 2) - 1;
    for (int i = starting_index; i >= 0; i--)
        heapify(i);    
}


void Heap::heapify(int root_index)
{   
    int largest_index = root_index;
    int left_index = 2 * root_index + 1;
    int right_index = 2 * root_index + 2;
    if (left_index < size && array[left_index] > array[largest_index])
        largest_index = left_index;

    if (right_index < size && array[right_index] > array[largest_index])
        largest_index = right_index;

    if (largest_index != root_index) 
    {
        // zamiana miejscami korzenia i wiekszego elementu w przypadku
        // gdy wartosc ktoregos potomka jest wieksza od rodzica
        int temp = array[largest_index];
        array[largest_index] = array[root_index];
        array[root_index] = temp;
        heapify(largest_index);
    }
}


void Heap::search(int value)
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
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << "(" << i << ") ";
    }
    std::cout << std::endl;
}
int main()
{
    Heap * heap = new Heap();

    heap->add(4);
    heap->add(2);
    heap->add(3);
    heap->add(4);
    heap->add(12);
    heap->add(6);
    heap->add(7);
    heap->add(3);
    heap->add(3);
    heap->add(423);
    heap->add(111);
    heap->print();

    heap->search(1231);

    // heap->extract_max();
    // heap->print();
    
    // heap->extract_max();
    // heap->print();
    
    // heap->extract_max();
    // heap->print();
    return 0;
}