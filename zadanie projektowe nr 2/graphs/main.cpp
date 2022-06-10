#include "AdjMatrix.h"
#include "AdjList.h"
#include <iostream>

int main()
{
    std::cout << "Wybierz sposob przechowywania grafu:\n";
    std::cout << "1. Macierz sasiedztwa\n";
    std::cout << "2. Lista sasiedztwa\n";
    int graf;
    std::cin >> graf;
    int v;
    double d;

    int low, high;

    std::cout << "Podaj liczbe wierzcholkow: ";
    std::cin >> v;
    std::cout << "Podaj gestosc: ";
    std::cin >> d;

    std::cout << "Podaj dolny zakres: ";
    std::cin >> low;
    std::cout << "Podaj gorny zakres: ";
    std::cin >> high;    



    switch (graf)
    {
    case 1:
    {
        AdjMatrix * matrix = new AdjMatrix(v, d, low, high);
        matrix -> print();
        matrix -> primMST();
        matrix -> kruskalMST();
        matrix -> dijkstra(0);
        matrix -> bellmanFord(0);
    }
        break;
    case 2:
    {
        AdjList * list = new AdjList(v, d, low, high);
        list -> print();
        list -> primMST();
        list -> dijkstra(0);
    }
        break;
    default:
        break;
    }


    return 0;
}
