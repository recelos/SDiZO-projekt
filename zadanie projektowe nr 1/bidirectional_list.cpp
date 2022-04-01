#include "bidirectional_list.h"
#include <iostream>

BidirectionalList::BidirectionalList()
{
    start = NULL;
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
        size=1;
    }
    else
    {    
    list_element * to_add = new list_element;
    to_add->value = value;
    to_add->next = start;
    start->previous = to_add;
    start = to_add;
    size++;
    }
}
void BidirectionalList::delete_beginning()
{
    if(start == NULL)
    {
        return;
    }
    else if (start->next == NULL)
    {
        delete start;
        start = NULL;
        size = 0;
    }
    else
    {
        start = start->next;
        delete start->previous;
        start->previous = NULL;
        size--;
    }
}

void BidirectionalList::delete_end()
{
    if(start == NULL)
    {
        std::cout << "Brak elementu do usuniecia\n";
        return;
    }
    else if (start->next == NULL)
    {
        delete start;
        start = NULL;
        size = 0;
    }
    else
    {

        list_element * temp = start;
        while(temp -> next)
            temp = temp -> next;
        temp -> previous -> next = NULL;
        temp = NULL;
        --size;
    }
}


void BidirectionalList::add_to_end(int value)
{
    if(start == NULL)
    {
        start = new list_element;
        start->value=value;
        start->previous=NULL;
        start->next=NULL;
        size = 1;
    }
    else
    {
        list_element * temp = start;

        while (temp->next)
            temp = temp->next;
        
        list_element * to_add = new list_element;
        temp->next = to_add;
        to_add->value = value;
        to_add->previous = temp;
        to_add->next = NULL;
        size++;
    }
}

void BidirectionalList::add_to_index(int index, int value)
{
    if((!start && index!=0) || ( index < 0 || index > size))
        std::cout << "Indeks wykracza poza zakres listy\n";

    else if(index==0)    
        add_to_beginning(value);
    
    else if (index==size)
        add_to_end(value);

    else
    {
        list_element * temp = start;
        for (int i = 1; i < index; i++)
            temp = temp -> next;
        
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
    {
        std::cout << "Indeks wykracza poza zakres listy\n";
    }
    else if(index==0)
    {
        delete_beginning();
    }
    else if (index==size-1)
    {
        delete_end();
    }
    else
    {
        list_element * temp = start;
        for (int i = 0; i < index - 1; i++)
            temp = temp -> next;

        list_element * news = temp -> next;

        temp -> next = news -> next;
        temp -> next -> previous = news;

        delete[] news;

        size--;

        if (size == 0)
        {
            delete start;
            start = new list_element;
            start -> next = NULL;
            start -> previous = NULL;
        }
        
    }
}



void BidirectionalList::search(int value)
{
    if(!start)
    {
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

    while(temp->next!=NULL){
        std::cout << temp -> value << " ";
        temp = temp -> next;
    }

    std::cout << temp -> value << " " << "rozmiar: " << size << std::endl;
}

int main(){
    BidirectionalList * list = new BidirectionalList();

    list -> add_to_beginning(4);
    list -> add_to_end(5);
    list -> add_to_end(6);
    list -> add_to_end(7);



    list -> add_to_index(2, 1);

    list -> print();


    list -> delete_at_index(0);
    list -> delete_at_index(0);

    list -> print();

    list -> add_to_beginning(1);
    list -> add_to_end(6);


    list -> print();

    // list->search(345);
    list->search(6);
}