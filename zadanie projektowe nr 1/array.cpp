#include "array.h"
#include <iostream>

Array::Array()
{
    start = NULL;
    size = 0;
}
Array::~Array()
{
    delete[] start;
}


void Array::add_to_beginning(int value)
{
    int * temp = new int[size+1];
    temp[0] = value;

    for(int i = 0; i < size; i++)
        temp[i+1] = start[i];

    delete[] start;
    start = temp;

    size++;
}

void Array::add_to_end(int value)
{
    int * temp = new int[size+1];
    temp[size] = value;

    for(int i = 0; i < size; i++)
        temp[i] = start[i];

    delete[] start;
    start = temp;

    size++;
}


void Array::add_to_index(int index, int value)
{
    if(index < 0 || index > size)
        return;


    else
    {
        int * temp = new int[size + 1];

        temp[index] = value;

        for(int i=0; i< index; i++)
            temp[i] = start[i];

        for(int i = index; i < size; i++)
            temp[i+1] = start[i];

        delete[] start;
        start = temp;
        size++;
    }   
}


void Array::delete_beginning()
{
    if(size == 0)
        std::cout << "Brak elementu do usuniecia\n\n";

    else
    {
        int * temp = new int[size-1];

        for (int i = 0; i < size; i++)
            temp[i] = start[i+1];
        

        delete[] start;
        start = temp;
        size--;
    }
}

void Array::delete_end()
{
    if(size == 0)
        return;

    else
    {
        int * temp = new int[size-1];

        for (int i = 0; i < size-1; i++)
            temp[i] = start[i];
        
        delete[] start;
        start = temp;
        size--;
    }
}
void Array::delete_at_index(int index)
{
    if(index < 0 || index >= size || size == 0)
        return;

    else
    {
        int * temp = new int[size-1];

        for (int i = 0; i < index; i++)
            temp[i] = start[i];
        
        for (int i = index; i < size - 1; i++)
            temp[i] = start[i+1];

        delete[] start;
        start = temp;
        size--;   
    }
}


void Array::search(int value)
{
    int * temp = start;
    for (int i = 0; i < size; i++)
    {
        if(temp[i] == value)
            return;
    }
}
void Array::search_and_print(int value)
{
    int * temp = start;
    for (int i = 0; i < size; i++)
    {
        if(temp[i] == value)
        {
            std::cout << "Znaleziono element " << value << " na indeksie: " << i << std::endl << std::endl;
            return;
        }
    }
    std::cout << "Nie znaleziono elementu " << value << " w tablicy\n\n";
}

void Array::print()
{
    int * temp = start;
    std::cout << "T: ";
    for(int i=0; i<size; i++)
    {
        std::cout << temp[i] << "(" << i << ") "; 
    }
    std::cout << "\nrozmiar tablicy: " << size << std::endl;
}

void Array::fill_random(int quantity, int range)
{
    srand(time(0));
    for (int i = 0; i < quantity; i++)
    {
        int to_add = 1 + rand() % range;
        add_to_end(to_add);
    }
}