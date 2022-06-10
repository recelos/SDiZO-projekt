#include <iostream>
#include "MatrixBenchmark.h"
#include "ListBenchmark.h"


int main()
{
    int v;
    double d;

    std::cout << "Podaj liczbe wierzcholkow: ";

    std::cin >> v;

    std::cout << "Podaj gestosc: ";

    std::cin >> d;


    // MatrixBenchmark * mb = new MatrixBenchmark(v, d);

    // mb -> test_prim();
    // mb -> test_kruskal();
    // mb -> test_dijkstra();
    // mb -> test_bellmanford();

    ListBenchmark * lb = new ListBenchmark(v, d);
    lb -> test_prim();
    lb -> test_dijkstra();

    return 0;
}