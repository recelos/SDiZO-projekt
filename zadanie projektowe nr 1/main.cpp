#include <iostream>
#include "bidirectional_list.h"
#include "array.h"
#include "heap.h"
#include "array_benchmark.h"
#include "heap_benchmark.h"
#include "list_benchmark.h"

void test_array();
void test_list();
void test_heap();
void benchmark();
void test();

int main()
{
    int run = 1;


    while (run)
    {
    std::cout << "1. Testy czasowe\n";
    std::cout << "2. Testy reczne\n";
    std::cout << "3. Koniec programu\n";

    int input;
    std::cin >> input;

    system("CLS");

    if(input == 1)
        benchmark();
    if(input==2)
        test();       
    if(input==3)
        run = 0;
    }
    return 0;
}

void test_array()
{
    Array * array = new Array();
    int run = 1;
    while (run)
    {
        std::cout << "\n\n";
        int input;
        std::cout << "Dostepne operacje: \n";
        std::cout << "1. Dodaj na poczatek tablicy\n";
        std::cout << "2. Dodaj na koniec tablicy\n";
        std::cout << "3. Dodaj na konkretny index w tablicy\n";
        std::cout << "4. Usun z poczatku tablicy\n";
        std::cout << "5. Usun z konca tablicy\n";
        std::cout << "6. Usun z konkretnego indexu w tablicy\n";
        std::cout << "7. Wyszukaj w tablicy\n";
        std::cout << "8. Wypelnij losowo\n";
        std::cout << "9. Wroc\n\n";
        array -> print();

        std::cin >> input;

        switch (input)
        {
            case 1:
                std::cout << "Podaj liczbe do dodania: ";
                int to_add1;
                std::cin >> to_add1;
                system("CLS");
                array -> add_to_beginning(to_add1);
                break;

            case 2:
                std::cout << "Podaj liczbe do dodania: ";
                int to_add2;
                std::cin >> to_add2;
                system("CLS");
                array -> add_to_end(to_add2);
                break;
            case 3:
                int to_add3;
                int index1;
                std::cout << "Podaj index: ";
                std::cin >> index1;
                std::cout << "Podaj liczbe do dodania: ";
                std::cin >> to_add3;
                system("CLS");
                array -> add_to_index(index1, to_add3);
                break;
            case 4:
                system("CLS");
                array -> delete_beginning();
                break;
            case 5:
                system("CLS");
                array -> delete_end();
                break;
            case 6:
                int index2;
                std::cout << "Podaj index: ";
                std::cin >> index2;
                system("CLS");
                array -> delete_at_index(index2);
                break;
            case 7:
                int to_find;
                std::cout << "Podaj wartosc: ";
                std::cin >> to_find;
                system("CLS");
                array -> search_and_print(to_find);
                break;
            case 8:
                int quantity, range;
                std::cout << "Podaj ilosc: ";
                std::cin >> quantity;
                std::cout << "Podaj zakres: ";
                std::cin >> range;
                system("CLS");
                array -> fill_random(quantity, range);                
                break;
            case 9:
                system("CLS");
                run = 0;
                break;
            default:
                system("CLS");
                break;
        }
        if(run == 0)
            delete array;
    }
}
void test_list()
{
    BidirectionalList * list = new BidirectionalList();

    int run = 1;
    while (run)
    {
        std::cout << "\n\n";
        int input;
        std::cout << "Dostepne operacje: \n";
        std::cout << "1. Dodaj na poczatek listy\n";
        std::cout << "2. Dodaj na koniec listy\n";
        std::cout << "3. Dodaj na konkretny index w liscie\n";
        std::cout << "4. Usun z poczatku listy\n";
        std::cout << "5. Usun z konca listy\n";
        std::cout << "6. Usun z konkretnego indexu w liscie\n";
        std::cout << "7. Wyszukaj w liscie\n";
        std::cout << "8. Wyswietl odwrotnie\n";
        std::cout << "9. Wypelnij losowo\n";
        std::cout << "10. Wroc\n\n";
        list -> print();

        std::cin >> input;

        switch (input)
        {
            case 1:
                std::cout << "Podaj liczbe do dodania: ";
                int to_add1;
                std::cin >> to_add1;
                system("CLS");
                list -> add_to_beginning(to_add1);
                break;

            case 2:
                std::cout << "Podaj liczbe do dodania: ";
                int to_add2;
                std::cin >> to_add2;
                system("CLS");
                list -> add_to_end(to_add2);
                break;
            case 3:
                int to_add3;
                int index1;
                std::cout << "Podaj index: ";
                std::cin >> index1;
                std::cout << "Podaj liczbe do dodania: ";
                std::cin >> to_add3;
                system("CLS");
                list -> add_to_index(index1, to_add3);
                break;
            case 4:
                system("CLS");
                list -> delete_beginning();
                break;
            case 5:
                system("CLS");
                list -> delete_end();
                break;
            case 6:
                int index2;
                std::cout << "Podaj index: ";
                std::cin >> index2;
                system("CLS");
                list -> delete_at_index(index2);
                break;
            case 7:
                int to_find;
                std::cout << "Podaj wartosc: ";
                std::cin >> to_find;
                system("CLS");
                list -> search_and_print(to_find);
                break;
            case 8:
                system("CLS");
                list -> print_inverted();
                break;
            case 9:
                int quantity, range;
                std::cout << "Podaj ilosc: ";
                std::cin >> quantity;
                std::cout << "Podaj zakres: ";
                std::cin >> range;
                system("CLS");
                list -> fill_random(quantity, range);
                break;
            case 10:
                run = 0;
                system("CLS");
                break;
            default:
                system("CLS");
                break;
        }
        if (run == 0)
            delete list;
    }
}
void test_heap()
{
    Heap * heap = new Heap();
    int run = 1;

    while (run)
    {
        std::cout << "\n\n";
        int input;
        std::cout << "Dostepne operacje: \n";
        std::cout << "1. Dodaj do kopca\n";
        std::cout << "2. Usun z korzenia\n";
        std::cout << "3. Wyszukaj w kopcu\n";
        std::cout << "4. Wypelnij losowo\n";
        std::cout << "5. Wroc\n\n";
        heap -> print();
        std::cout << std::endl;
        std::cin >> input;
        switch (input)
        {
            case 1:
                int to_add;
                std::cout << "Podaj wartosc: ";
                std::cin >> to_add;
                system("CLS");
                heap->add(to_add);
                break;
            case 2:
                system("CLS");
                heap -> extract_max();
                break;
            case 3:
                int to_find;
                std::cout << "Podaj wartosc: ";
                std::cin >> to_find;
                system("CLS");
                heap->search_and_print(to_find);
                break;
            case 4:
                int quantity, range;
                std::cout << "Podaj ilosc: ";
                std::cin >> quantity;
                std::cout << "Podaj zakres: ";
                std::cin >> range;
                system("CLS");
                heap -> fill_random(quantity, range);
                break;
            case 5:
                run =  0;
                system("CLS");
                break;
            default:
                system("CLS");
                break;
        }
        if (run == 0)
        {
            delete heap;
        }
        
    }
}


void test()
{
    int run = 1;
    while(run)
    {
        int input;
        std::cout << "Wybierz strukture do testowania: \n";
        std::cout << "1. Tablica \n";
        std::cout << "2. Lista dwukierunkowa \n";
        std::cout << "3. Kopiec \n";
        std::cout << "4. Wroc \n";
        std::cin >> input;

        system("CLS");

        switch (input)
        {
        case 1:
            test_array();
            break;
        case 2:
            test_list();
            break;
        case 3:
            test_heap();
            break;
        case 4:
            run = 0;
            break;
        default:
            break;
        }

    }

}


void benchmark()
{
    std::cout << "Podaj liczbe elementow: ";
    int input;
    std::cin >> input;
    
    ArrayBenchmark * ab = new ArrayBenchmark(input);
    delete ab;

    HeapBenchmark * hb = new HeapBenchmark(input);
    delete hb;

    ListBenchmark * lb = new ListBenchmark(input);
    delete lb;

}