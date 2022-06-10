#include "../graphs/AdjMatrix.h"

class MatrixBenchmark
{
    private:
        AdjMatrix * matrix;
    public:
        MatrixBenchmark(int v, double d);
        void test_prim();
        void test_kruskal();
        void test_dijkstra();
        void test_bellmanford();

};