#include "bidirectional_list.h"
#include <iostream>
#include <ctime>


BidirectionalList::BidirectionalList()
{
    start = NULL;
    end = NULL;
    size = 0;
}

void BidirectionalList::add_to_beginning(int value)
{
    if(start == NULL)
    {
        start = new list_element;
        start->value=value;
        start->previous=NULL;
        start->next=NULL;
        end = start;
        size=1;
    } 
    else
    {    
    list_element * to_add = new list_element;
    to_add -> value = value;
    to_add -> next = start;
    start -> previous = to_add;
    start = to_add;
    size++;
    }
}
void BidirectionalList::delete_beginning()
{
    if(size == 0)
        return;

    list_element * temp = start -> next;

    if(size > 1)
    {
        temp -> previous = NULL;
        start = temp;
    }  
    else
    {
        start = NULL;
        end = NULL;
    }
    size--;
}

void BidirectionalList::delete_end()
{
    if(size == 0)
        return;
    
    list_element * temp = end -> previous;

    if(size > 1)
    {
        temp -> next = NULL;
        end = temp;
    }  
    else
    {
        start = NULL;
        end = NULL;
    }
    size--;

}


void BidirectionalList::add_to_end(int value)
{
    if(start == NULL)
    {
        start = new list_element;
        start->value=value;
        start->previous=NULL;
        start->next=NULL;
        end = start;
        size = 1;
    }
    else
    {       
        list_element * to_add = new list_element;
        end -> next = to_add;
        to_add -> value = value;
        to_add -> previous = end;
        to_add -> next = NULL;
        end = to_add;
        size++;
    }
}

void BidirectionalList::add_to_index(int index, int value)
{
    if((!start && index!=0) || ( index < 0 || index > size))
        return;

    else if(index==0)    
        add_to_beginning(value);
    
    else if (index==size)
        add_to_end(value);

    else
    {
        list_element * temp;
        if(index < (size / 2))
        {
            temp = start;
            for (int i = 1; i < index; i++)
                temp = temp -> next;
            

        }
        else
        {
            temp = end;
            for (int i = 0; i < size - index; i++)
                temp = temp -> previous;
        }
        
        list_element * to_add = new list_element;
        to_add -> value = value;
        to_add -> next = temp -> next;
        to_add -> previous = temp;

        temp -> next -> previous = to_add;
        temp -> next = to_add;

        size++;
    }
}
void BidirectionalList::delete_at_index(int index)
{
    if(( index < 0 || index >= size))
        return;

    else if(index==0)
        delete_beginning();

    else if (index==size-1)
        delete_end();

    else
    {
        list_element * temp = start;
        for (int i = 0; i < index - 1; i++)
            temp = temp -> next;

        list_element * news = temp -> next;

        temp -> next = news -> next;
        temp -> next -> previous = news;


        size--;

        if (size == 0)
        {
            start = new list_element;
            start -> next = NULL;
            start -> previous = NULL;
        }
        
    }
}



void BidirectionalList::search(int value)
{
    if(!start)
        return;

    else
    {
        list_element * temp = start;
        int i = 0;
        while(temp->next)
        {
            if(temp->value == value)
                return;

            temp = temp->next;
            i++;
        }
        if(temp->value == value)
            return;
    }
}
void BidirectionalList::search_and_print(int value)
{
    if(!start)
    {
        return;
        std::cout << "Lista jest pusta\n" << std::endl;
    }
    else
    {
        list_element * temp = start;
        int i = 0;
        while(temp->next)
        {
            if(temp->value == value)
            {
                std::cout << "Znaleziono element " << value << " na indeksie: " << i << std::endl;
                return;
            } 
            temp = temp->next;
            i++;
        }
        if(temp->value == value)
        {
            std::cout << "Znaleziono element " << value << " na indeksie: " << i << std::endl;
            return;
        }
        std::cout << "Nie znaleziono elementu " << value << " w liscie\n";
    }
}



void BidirectionalList::print()
{
    if(!start)
    {
        std::cout << "Lista jest pusta\n";
        return;
    }  

    list_element * temp = start;

    std::cout << "L: ";

    int i = 0;
    while(temp->next!=NULL)
    {
        std::cout << temp -> value << "(" << i++ << ") ";
        temp = temp -> next;
    }

    std::cout << temp -> value <<"(" << i++ << ") "<< "rozmiar: " << size << std::endl;
}

void BidirectionalList::print_inverted()
{
    if(!start)
    {
        std::cout << "Lista jest pusta\n";
        return;
    }  

    std::cout << "L: ";
    list_element * temp = end;
    while(temp->previous!=NULL)
    {
        std::cout << temp -> value << " ";
        temp = temp -> previous;
    }

    std::cout << temp -> value << " " << "rozmiar: " << size << std::endl;
}
void BidirectionalList::fill_random(int quantity, int range)
{
    srand(time(0));
    for (int i = 0; i < quantity; i++)
    {
        int to_add = 1 + rand() % range;
        add_to_end(to_add);
    }
}