#include <string>
#include <vector>
#include <list>
class AdjList
{

private:
    std::vector<std::list<std::pair<int,int>>> list;
    int V, E;

public:
    AdjList(std::string src);
    AdjList(int, double, int, int);

    ~AdjList();
    void print();

    void primMST();
    void dijkstra(int src);

    void primMST_test();
    void dijkstra_test(int src);

};