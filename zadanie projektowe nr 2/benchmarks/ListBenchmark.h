#include "../graphs/AdjList.h"

class ListBenchmark
{
    private:
        AdjList * list;
    public:
        ListBenchmark(int v, double d);
        void test_prim();
        void test_dijkstra();

};