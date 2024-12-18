#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int INF = 1e9;

int n = 4;
int graph[4][4] = {
    {0, 2, 1, INF},
    {2, 0, INF, 3},
    {1, INF, 0, 1},
    {INF, 3, 1, 0}};

void dijkstra(int start)
{
    int dist[1000];
    bool visited[1000];
    memset(visited, false, sizeof visited);
    for (int i = 0; i < n; ++i)
    {
        dist[i] = INF;
    }
    dist[start] = 0;
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
            if (graph[u][v] != INF)
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
    dijkstra(0);
    return 0;
}
