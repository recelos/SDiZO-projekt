#include "table.h"
#include <iostream>

Table::Table()
{
    start = NULL;
    size = 0;
}

void Table::add_to_beginning(int value)
{
    int * temp = new int[size+1];
    temp[0] = value;

    for(int i = 0; i < size; i++)
    {
        temp[i+1] = start[i];
    }

    delete start;
    start = temp;

    size++;
}

void Table::add_to_end(int value)
{
    int * temp = new int[size+1];
    temp[size] = value;

    for(int i = 0; i < size; i++)
    {
        temp[i] = start[i];
    }

    delete start;
    start = temp;

    size++;
}


void Table::add_to_index(int index, int value)
{
    if(index < 0 || index > size)
        std::cout << "Indeks wykracza poza zakres tablicy" << std::endl;
    else
    {
        int * temp = new int[size + 1];

        temp[index] = value;

        for(int i=0; i< index; i++)
            temp[i] = start[i];

        for(int i = index; i < size; i++)
            temp[i+1] = start[i];

        delete start;

        start = temp;

        size++;
        
    }   
}


void Table::delete_beginning()
{
    if(size == 0)
        std::cout << "Brak elementu do usuniecia\n";
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

void Table::delete_end()
{
    if(size == 0)
        std::cout << "Brak elementu do usuniecia\n";
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
void Table::delete_at_index(int index)
{
    if(index < 0 || index > size || size == 0)
        std::cout << "Brak elementu do usuniecia\n";
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


void Table::search(int value)
{
    int * temp = start;
    for (int i = 0; i < size; i++)
    {
        if(temp[i] == value)
        {
            std::cout << "Znaleziono element " << value << " na indeksie: " << i << std::endl;
            return;
        }
    }
    std::cout << "Nie znaleziono elementu " << value << " w tablicy\n";
}


void Table::print()
{
    int * temp = start;
    for(int i=0; i<size; i++)
    {
        std::cout << temp[i] << " "; 
    }
    std::cout << "rozmiar tablicy: " << size << std::endl;
}

int main()
{
    Table * table = new Table();

    table->add_to_beginning(4);
    table->print();
    table->add_to_beginning(2);
    table->print();
    table->add_to_end(7);
    table->print();

    table->add_to_beginning(1);
    table->print();

    table->add_to_index(0, 5);
    

    table->print();

    table->delete_at_index(2);
    table->print();

    table->search(7);

    return 0;
}