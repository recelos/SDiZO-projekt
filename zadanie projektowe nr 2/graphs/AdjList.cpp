#include "AdjList.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>

AdjList::AdjList(std::string src)
{
    std::fstream file;

    file.open(src);

    if (file.good())
    {
        file >> E >> V;
        list.resize(V, std::list<std::pair<int,int>>(0));
        while (!file.eof())
        {
            int wp, wk, weight;
            file >> wp >> wk >> weight;
            list[wp].push_back(std::make_pair(wk, weight));
            list[wk].push_back(std::make_pair(wp, weight));
        }
        file.close();
    }
    else
        std::cout << "Blad\n";
    
}

AdjList::AdjList(int v, double d, int low, int high)
{
    this->V = v;
    this->E = d*((V * (V-1)));


	list.resize(V, std::list< std::pair<int,int> >(0));

    std::vector<int> visited;
    int prev = 0, j = 0, next, weight;

    visited.push_back(prev);

	for (int i = 0; i < V - 1; i++)
	{
		next = rand() % V;
		while (j < visited.size())
		{
			if (next == visited[j])
			{
				next = (next + 1) % V;
				j = 0;
			}
			else
				j++;
		}
		j = 0;
		weight = rand() % high + low;
        list[prev].push_back(std::make_pair(next, weight));
		prev = next;
		visited.push_back(prev);
	}
    for (int i = V - 1; i < E; i++)
	{
		prev = rand() % V;
		next = rand() % V;
		while (prev == next)
		{
			next = rand() % V;
		}
		weight = rand() % high + low;
        list[prev].push_back(std::make_pair(next, weight));
	}

}

void AdjList::print()
{
    std::cout << "Graf przechowywany w liscie sasiedztwa: \n";
    for (int i = 0; i < list.size(); i++)
    {
        int nodes = list[i].size();
        std::cout << i;

        if (nodes > 0)
        {
            auto iterator = list[i].begin();
            while (iterator != list[i].end())
            {
                std::cout << " ->" << (*iterator).first << ":" << (*iterator).second;
                iterator++;
            }
        }
        else
            std::cout <<" Brak";    
        
        std::cout<<std::endl;
    }
    std::cout << std::endl;
}

void AdjList::primMST()
{
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<>> queue;

    std::vector<int> key(V, INT_MAX);
    std::vector<int> parent(V, 1);
    std::vector<bool> inMST(V, false);

    queue.push(std::make_pair(0, 0));

    int weight = 0;
    key[0] = 0;

    while (!queue.empty())
    {
		int vertex = queue.top().second;
		queue.pop();

		inMST[vertex] = true;

		for (auto it = list[vertex].begin(); it != list[vertex].end(); ++it)
		{
			int v = it->first;
			int weight = it->second;

			if (!inMST[v] && key[v] > weight)
			{
				key[v] = weight;
				queue.push(std::make_pair(key[v], v));
				parent[v] = vertex;
			}
		}
    }
    std::cout << "Prim MST\nEdge\t\t\tWeight\n";
    for (int i = 1; i < V; i++)
	{
		std::cout << "(" << parent[i] << ", " << i << ")\t\t\t" << key[i] << std::endl;
		weight += key[i];
	}
	std::cout << "MST: " << weight << "\n\n";
}
void AdjList::primMST_test()
{
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<>> queue;

    std::vector<int> key(V, INT_MAX);
    std::vector<int> parent(V, 1);
    std::vector<bool> inMST(V, false);

    queue.push(std::make_pair(0, 0));

    int weight = 0;
    key[0] = 0;

    while (!queue.empty())
    {
		int vertex = queue.top().second;
		queue.pop();

		inMST[vertex] = true;

		for (auto it = list[vertex].begin(); it != list[vertex].end(); ++it)
		{
			int v = it->first;
			int weight = it->second;

			if (!inMST[v] && key[v] > weight)
			{
				key[v] = weight;
				queue.push(std::make_pair(key[v], v));
				parent[v] = vertex;
			}
		}
    }
}


void AdjList::dijkstra(int src)
{
	std::priority_queue< std::pair<int, int>, std::vector <std::pair<int, int>>, std::greater<> > queue;

	std::vector<int> dist(V, INT_MAX);
	std::vector<int> path(V);
	std::vector<int> prev(V, -1);
	std::vector<bool> visited(V, false);

	queue.push(std::make_pair(0, src));
	dist[src] = 0;

	while (!queue.empty())
	{
		int vertex = queue.top().second;
		queue.pop();
		visited[vertex] = true;

		for (auto it = list[vertex].begin(); it != list[vertex].end(); ++it)
		{
			int v = it->first;
			int weight = it->second;

			if (!visited[v] && dist[v] > dist[vertex] + weight)
			{
				dist[v] = dist[vertex] + weight;
				prev[v] = vertex;
				queue.push(std::make_pair(dist[v], v));
			}
		}
	}
	


    std::cout << "Dijkstra \nStart: " << src << std::endl;
    std::cout << "End \tDistance \tPath\n";
	int iterator = 0;
	for (int i = 0; i < V; i++)
	{
		std::cout << i << "| \t";

        std::cout << dist[i] << "\t\t";
		for (int j = i; j > -1; j = prev[j])
		{
			path[iterator++] = j;
		}

		while (iterator)
		{
			std::cout << path[--iterator] << " ";
		}
        std::cout << std::endl;
	} 
    std::cout << std::endl;
}
void AdjList::dijkstra_test(int src)
{
	std::priority_queue< std::pair<int, int>, std::vector <std::pair<int, int>>, std::greater<> > queue;

	std::vector<int> dist(V, INT_MAX);
	std::vector<int> path(V);
	std::vector<int> prev(V, -1);
	std::vector<bool> visited(V, false);

	queue.push(std::make_pair(0, src));
	dist[src] = 0;

	while (!queue.empty())
	{
		int vertex = queue.top().second;
		queue.pop();
		visited[vertex] = true;

		for (auto it = list[vertex].begin(); it != list[vertex].end(); ++it)
		{
			int v = it->first;
			int weight = it->second;

			if (!visited[v] && dist[v] > dist[vertex] + weight)
			{
				dist[v] = dist[vertex] + weight;
				prev[v] = vertex;
				queue.push(std::make_pair(dist[v], v));
			}
		}
	}
}