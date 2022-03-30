#include "bidirectional_list.h"
#include <iostream>

BidirectionalList::BidirectionalList()
{
    BidirectionalList::start = NULL;
    rozmiar = 0;
}

void BidirectionalList::add_to_beginning(int value)
{
    if(start == NULL){
        start = new list_element;
        start->value=value;
        start->previous=NULL;
        start->next=NULL;
        rozmiar=1;
    }

    list_element * to_add = new list_element;

    to_add->value = value;
    to_add->next = start;
    start->previous = to_add;
    start = to_add;
    ++rozmiar;
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
        rozmiar = 0;
    }
    else
    {
        start = start->next;
        delete start->previous;
        start->previous = NULL;
        rozmiar--;
    }
}

void BidirectionalList::delete_end()
{
    if(start == NULL)
    {
        return;
    }
    else if (start->next == NULL)
    {
        delete start;
        start = NULL;
        rozmiar = 0;
    }
    else
    {
        list_element * temp = start;
        while(temp -> next)
            temp = temp -> next;
        temp -> previous -> next = NULL;
        temp = NULL;
        --rozmiar;
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
        rozmiar = 1;
    }
    else
    {
        list_element * temp = start;

        while (temp->next)
        {
            temp = temp->next;
        }
        
        list_element * to_add = new list_element;
        temp->next = to_add;
        to_add->value = value;
        to_add->previous = temp;
        to_add->next = NULL;
        ++rozmiar;
    }
}

void BidirectionalList::search(int value)
{
    if(!start)
    {
        std::cout << "Lista jest pusta" << std::endl;
    }
    else
    {
        list_element * temp = start;
        unsigned counter = 0;
        while(temp->next)
        {
            if(temp->value == value) 
                counter++; 
            temp = temp->next;
        }
        if(temp->value == value) 
            counter++; 
        std::cout << "Znaleziono:" << counter << " elementow o wartosci " << value << std::endl;
    }
}

void BidirectionalList::print(){
    if(!start)  std::cout << "Lista jest pusta\n";

    list_element * temp = start;

    while(temp->next!=NULL){
        std::cout << temp->value << " ";
        temp = temp->next;
    }

    std::cout << temp->value << " " << "rozmiar: " << rozmiar << std::endl;
}

int main(){
    BidirectionalList * list = new BidirectionalList();
    list->add_to_end(5);
    list->add_to_end(4);
    list->add_to_end(2342);
    list->add_to_end(232342);  
    list->add_to_beginning(1);
    list->add_to_end(4);  
    list->add_to_beginning(2);
    list->search(232342);
    list->print();
    list->delete_beginning();
    list->delete_end();
    list->print();
}