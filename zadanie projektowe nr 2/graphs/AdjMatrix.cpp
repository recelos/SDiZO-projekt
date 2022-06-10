#include "AdjMatrix.h"
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

AdjMatrix::AdjMatrix(std::string src)
{
    std::fstream file;

    file.open(src);

    if(file.good())
    {
        file >> E >> V;

        arr = new int*[V];
        
        for (int i = 0; i < V; i++)
            arr[i] = new int[V];

        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                arr[i][j] = INT_MAX;
        
        for (int i = 0; i < E; i++)
        {
            int first, second, weight;
            file >> first >> second >> weight;
            arr[first][second] = weight;
            arr[second][first] = weight;
        }        
        file.close();
    }
    else
    {
        arr = NULL;
        std::cout << "Blad\n";
    }
}

AdjMatrix::AdjMatrix(int v, double d, int low, int high)
{
    this->V = v;
    this->E = (int)(d*(V * (V-1)));


    arr = new int*[V];
    
    for (int i = 0; i < V; i++)
        arr[i] = new int[V];

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            arr[i][j] = INT_MAX;

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
        arr[prev][next] = weight;
		prev = next;
		visited.push_back(prev);
	}
    for (int i = V - 1; i < E; i++)
	{
		prev = rand() % V;
		next = rand() % V;
		while (prev == next)
			next = rand() % V;
		
		weight = rand() % high + low;
        arr[prev][next] = weight;
	}


}


void AdjMatrix::print()
{
    std::cout << "Graf przechowywany w macierzy: \n"; 
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i==j)
                std::cout << std::setw(4) << "x";
            else if (arr[i][j] == INT_MAX)
                std::cout << std::setw(4) << "*";
            else    
                std::cout << std::setw(4) << arr[i][j];
        }
            
        std::cout << "\n";
    }
    std::cout << std::endl;
}

bool isValidEdge(int a, int b, std::vector<bool> inMST)
{
    if (a == b)
        return false;
    if (inMST[a] == false && inMST[b] == false)
        return false;
    else if (inMST[a] == true && inMST[b] == true)
        return false;
    return true;      
}

void AdjMatrix::primMST()
{
    std::vector<bool> inMST(V, false);

    inMST[0] = true;

    int edges = 0, cost = 0;

    std::cout << "Prim MST\nEdge \t\tWeight\n";
    while (edges < V - 1)
    {
        int min = INT_MAX;
        int a = -1;
        int b = -1;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (arr[i][j] < min)
                {
                    if (isValidEdge(i, j, inMST))
                    {
                        min = arr[i][j];
                        a = i;
                        b = j;
                    }   
                }
            }
        }
        
        if (a != -1 && b != -1)
        {
            std::cout << "(" << a << ", " << b << ") \t\t" << min <<" \n";
            cost += min;
            edges++;
            inMST[b] = inMST[a] = true;
        }
    }
    std::cout << "MST = " << cost << "\n\n";
}
void AdjMatrix::primMST_test()
{
    std::vector<bool> inMST(V, false);

    inMST[0] = true;

    int edges = 0, cost = 0;

    while (edges < V - 1)
    {
        int min = INT_MAX;
        int a = -1;
        int b = -1;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (arr[i][j] < min)
                {
                    if (isValidEdge(i, j, inMST))
                    {
                        min = arr[i][j];
                        a = i;
                        b = j;
                    }   
                }
            }
        }
        
        if (a != -1 && b != -1)
        {
            cost += min;
            edges++;
            inMST[b] = inMST[a] = true;
        }
    }
}


int find(int i, std::vector<int> parent)
{
    while (parent[i] != i)
        i = parent[i];
    
    return i;
}

void join(int i, int j, std::vector<int> &parent)
{
    int a = find(i, parent);
    int b = find(j, parent);
    parent[a] = b;
}

void AdjMatrix::kruskalMST()
{
    std::vector<int> parent(V);

    int cost = 0;

    for (int i = 0; i < V; i++)
        parent[i] = i;
    
    int edges = 0;

    std::cout<<"Kruskal MST\nEdge \tWeight\n";
    while (edges < V - 1)
    {
        int min = INT_MAX;
        int a = -1;
        int b = -1;

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (find(i, parent) != find(j, parent) && arr[i][j] < min)
                {
                    min = arr[i][j];
                    a = i;
                    b = j;
                }
            }
        }
    join(a, b, parent);

    std::cout << "(" << a << ", " << b << ") \t" << min <<" \n";
    cost+=min;
    edges++;
    }

    std::cout << "MST = " << cost << "\n\n";
}
void AdjMatrix::kruskalMST_test()
{
    std::vector<int> parent(V);

    int cost = 0;

    for (int i = 0; i < V; i++)
        parent[i] = i;
    
    int edges = 0;

    while (edges < V - 1)
    {
        int min = INT_MAX;
        int a = -1;
        int b = -1;

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (find(i, parent) != find(j, parent) && arr[i][j] < min)
                {
                    min = arr[i][j];
                    a = i;
                    b = j;
                }
            }
        }
    join(a, b, parent);

    cost+=min;
    edges++;
    }

}

int AdjMatrix::minDistance(std::vector<int> dist, std::vector<bool> sptSet)
{
    int min = INT_MAX;
    int min_index;
    for (int i = 0; i < V; i++)
    {
        if (!sptSet[i] && dist[i] <= min)
        {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}


void printPath(std::vector<int> prev, int i)
{
    if(prev[i] == -1)
        return;
    printPath(prev, prev[i]);
    std::cout << i << " ";
}
void AdjMatrix::dijkstra(int src)
{
    std::vector<int> dist(V);

    std::vector<bool> visited(V, false);

    std::vector<int> prev(V, -1);

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
    }
    

    dist[src] = 0;


    for (int i = 0; i < V - 1; i++)
    {
        int u = minDistance(dist, visited);

        visited[u] = true;

        for (int j = 0; j < V; j++)
        {
            if (!visited[j] && arr[u][j] != INT_MAX && dist[u] + arr[u][j] < dist[j])
            {
                prev[j] = u;
                dist[j] = dist[u] + arr[u][j];
            }
            
        }
        
    }

    std::cout << "Dijkstra \nStart: " << src << std::endl;
    std::cout << "End \tDistance \tPath\n";
    for (int i = 0; i < V; i++)
    {
        std::cout << i << "| \t" << dist[i] << "\t\t" << src << " ";
        printPath(prev, i);
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
void AdjMatrix::dijkstra_test(int src)
{
    std::vector<int> dist(V);

    std::vector<bool> visited(V, false);

    std::vector<int> prev(V, -1);

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
    }
    

    dist[src] = 0;


    for (int i = 0; i < V - 1; i++)
    {
        int u = minDistance(dist, visited);

        visited[u] = true;

        for (int j = 0; j < V; j++)
        {
            if (!visited[j] && arr[u][j] != INT_MAX && dist[u] + arr[u][j] < dist[j])
            {
                prev[j] = u;
                dist[j] = dist[u] + arr[u][j];
            }   
        }
    }
}


void AdjMatrix::bellmanFord(int src)
{
    std::vector<int> dist(V, INT_MAX);

    std::vector<int> prev(V, -1);

    dist[src] = 0;

    for (int k = 0; k < V - 1; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i]!= INT_MAX && arr[i][j] != INT_MAX && dist[j] > (dist[i] + arr[i][j]))
                {
                    dist[j] = dist[i] + arr[i][j];
                    prev[j] = i;
                }
                
            }
            
        }
        
    }
    
    for (int k = 0; k < V-1; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (arr[i][j] != INT_MAX && dist[j] > (dist[i] + arr[i][j]))
                {
                    std::cout << "Cykl ujemny!\n";
                    return;
                }
            }
            
        }
        
    }
    
    std::cout << "Bellman-Ford \nStart: " << src << std::endl;
    std::cout << "End \tDistance \tPath\n";
    for (int i = 0; i < V; i++)
    {
        std::cout << i << "| \t" << dist[i] << "\t\t" << src << " ";
        printPath(prev, i);
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
}



void AdjMatrix::bellmanFord_test(int src)
{
    std::vector<int> dist(V, INT_MAX);

    std::vector<int> prev(V, -1);

    dist[src] = 0;

    for (int k = 0; k < V - 1; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i]!= INT_MAX && arr[i][j] != INT_MAX && dist[j] > (dist[i] + arr[i][j]))
                {
                    dist[j] = dist[i] + arr[i][j];
                    prev[j] = i;
                }
                
            }
            
        }
        
    }
    
    for (int k = 0; k < V-1; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (arr[i][j] != INT_MAX && dist[j] > (dist[i] + arr[i][j]))
                {
                    dist[j] = INT_MIN;
                    prev[j] = -1;
                }
            }
            
        }
        
    }
}

