#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 1e9;

void dijkstra(int start, int **graph, int n)
{
    int *dist = new int[n];
    bool *visited = new bool[n];

    for (int i = 0; i < n; ++i)
    {
        dist[i] = graph[start][i];
        visited[i] = false;
    }

    dist[start] = 0;
    visited[start] = true;

    for (int i = 0; i < n - 1; ++i)
    {
        int u = -1;
        for (int j = 0; j < n; ++j)
        {
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
            {
                u = j;
            }
        }
        visited[u] = true;

        for (int v = 0; v < n; ++v)
        {
            if (graph[u][v] != -1)
            {
                dist[v] = min(dist[v], dist[u] + graph[u][v]);
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        cout << "Shortest distance from vertex " << start << " to vertex " << i << " is " << dist[i] << endl;
    }
}

int main()
{
    int n, start;
    cout << "Enter the number of nodes: ";
    cin >> n;

    // Dynamically allocate memory for the 2D array
    int **graph = new int *[n];
    for (int i = 0; i < n; ++i)
    {
        graph[i] = new int[n];
    }

    // Enter the vertices
    cout << "Enter the adjacency matrix(enter -1 for infinity): " << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> graph[i][j];
            if (graph[i][j] == -1)
                graph[i][j] = INF;
        }
    }

    cout << "Enter the starting vertex: ";
    cin >> start;

    dijkstra(start, graph, n);

    return 0;
}