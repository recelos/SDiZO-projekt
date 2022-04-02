#include <iostream>
#include "bidirectional_list.h"
#include "table.h"
#include "heap.h"


void test_table();
void test_list();
void test_heap();

int main()
{
    int run = 1;
    while(run)
    {
        int input;
        std::cout << "Wybierz strukture do testowania: \n";
        std::cout << "1. Tablica \n";
        std::cout << "2. Lista dwukierunkowa \n";
        std::cout << "3. Kopiec \n";
        std::cout << "4. Koniec programu \n";
        std::cin >> input;

        switch (input)
        {
        case 1:
            test_table();
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
    return 0;
}

void test_table()
{
    Table * table = new Table();
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
        table -> print();

        std::cin >> input;

        switch (input)
        {
            case 1:
                std::cout << "Podaj liczbe do dodania: ";
                int to_add1;
                std::cin >> to_add1;
                system("CLS");
                table -> add_to_beginning(to_add1);
                break;

            case 2:
                std::cout << "Podaj liczbe do dodania: ";
                int to_add2;
                std::cin >> to_add2;
                system("CLS");
                table -> add_to_end(to_add2);
                break;
            case 3:
                int to_add3;
                int index1;
                std::cout << "Podaj index: ";
                std::cin >> index1;
                std::cout << "Podaj liczbe do dodania: ";
                std::cin >> to_add3;
                system("CLS");
                table -> add_to_index(index1, to_add3);
                break;
            case 4:
                system("CLS");
                table -> delete_beginning();
                break;
            case 5:
                system("CLS");
                table -> delete_end();
                break;
            case 6:
                int index2;
                std::cout << "Podaj index: ";
                std::cin >> index2;
                system("CLS");
                table -> delete_at_index(index2);
                break;
            case 7:
                int to_find;
                std::cout << "Podaj wartosc: ";
                std::cin >> to_find;
                system("CLS");
                table -> search(to_find);
                break;
            case 8:
                int quantity, range;
                std::cout << "Podaj ilosc: ";
                std::cin >> quantity;
                std::cout << "Podaj zakres: ";
                std::cin >> range;
                system("CLS");
                table -> fill_random(quantity, range);                
                break;
            case 9:
                system("CLS");
                run = 0;
                break;
            default:
                break;
        }
        if(run == 0)
            delete table;
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
                list -> search(to_find);
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
                break;
            default:
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
                heap->search(to_find);
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
