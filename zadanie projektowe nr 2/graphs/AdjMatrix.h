#include <string>
#include <vector>
class AdjMatrix
{
private:
    int V, E;

    int** arr;

    int minKey(std::vector<int> key, std::vector<bool> mstSet);

    int minDistance(std::vector<int> dist, std::vector<bool> sptSet);

public:
    AdjMatrix(std::string src);
    AdjMatrix(int, double, int, int);
    ~AdjMatrix();

    void primMST();
    void kruskalMST();
    void dijkstra(int src);
    void bellmanFord(int src);

    void primMST_test();
    void kruskalMST_test();
    void dijkstra_test(int src);
    void bellmanFord_test(int src);

    void print();
};