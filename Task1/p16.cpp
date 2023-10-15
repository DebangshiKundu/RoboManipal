#include <iostream>
using namespace std;
struct edge
{
    edge *next;
    int dest, weigth;
};
struct vertex
{
    edge *head;
};
vertex v[10];
int adjMat[10][10];

void add(int scr, int dest, int w)
{
    edge *nn = new edge;
    nn->next = v[scr].head;
    nn->dest = dest;
    nn->weigth = w;
    v[scr].head = nn;
}
void adjacentMat(int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            adjMat[i][j] = 0;
    }
    for (i = 0; i < n; i++)
    {
        edge *current = v[i].head;
        while (current != NULL)
        {
            adjMat[i][current->dest] = current->weigth;
            adjMat[current->dest][i] = current->weigth;
            current = current->next;
        }
    }
    cout << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cout << adjMat[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}

void dijkstra(int source, int n)
{
    int dist[10], i, j, u, min = INT_MAX, v;
    bool visited[10] = {false};
    for (i = 0; i < n; i++)
        dist[i] = INT_MAX;
    dist[source] = 0;
    for (i = 0; i < n - 1; i++)
    {
        min = INT_MAX;
        for (j = 0; j < n; j++)
        {
            if (!visited[j] and dist[j] <= min)
            {
                u = j;
                min = dist[j];
            }
        }
        visited[u] = true;
        for (v = 0; v < n; v++)
        {
            if (!visited[v] and adjMat[u][v] != 0 and dist[v] > dist[u] + adjMat[u][v] and dist[u] != INT_MAX)
                dist[v] = dist[u] + adjMat[u][v];
        }
    }

    cout << "Dijkstra Algorithm:\n\n";
    cout << "Distance from " << source << " to all other vertices are :\n";
    for (i = 0; i < n; ++i)
        cout << "Vertex: " << i << " Distance: " << dist[i] << endl;

    cout << endl;
}
int findParent(int parent[], int i)
{
    if (parent[i] == i)
        return i;
    return findParent(parent, parent[i]);
}
void unionset(int parent[], int i, int j)
{
    int x = findParent(parent, i);
    int y = findParent(parent, j);
    parent[x] = y;
}
void pruskal(int n)
{
    int min = INT_MAX, i, j, u, v, parent[10], count = 0;
    for (i = 0; i < n; i++)
        parent[i] = i;
    cout << "\nThe Minimum Spanning Tree (Pruskal's Algorith) :\n";
    while (count < n - 1)
    {
        min = INT_MAX;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (min > adjMat[i][j] and adjMat[i][j] != 0 and findParent(parent, i) != findParent(parent, j))
                {
                    min = adjMat[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        unionset(parent, u, v);
        cout << u << " - " << v << " : "
             << "Weight: " << min << endl;
        count++;
    }
    cout << endl;
}

void prim(int n)
{
    bool visited[10] = {false};
    int parent[10];
    int key[10];
    int i, j, u, v, min = INT_MAX;
    for (i = 0; i < n; i++)
        key[i] = INT_MAX;
    key[0] = 0;
    parent[0] = -1;
    for (i = 0; i < n; i++)
    {
        min = INT_MAX;
        for (j = 0; j < n; j++)
        {
            if (!visited[j] and min >= key[j])
            {
                u = j;
                min = key[j];
            }
        }
        visited[u] = true;
        for (v = 0; v < n; v++)
        {
            if (!visited[v] and adjMat[u][v] != 0 and key[v] > adjMat[u][v])
            {
                parent[v] = u;
                key[v] = adjMat[u][v];
            }
        }
    }
    cout << "\nEdges in the Minimum Spanning Tree (Prim's Algorithm):\n";
    for (int i = 1; i < n; ++i)
    {
        cout << parent[i] << " - " << i << "  Weight: " << adjMat[i][parent[i]] << endl;
    }
    cout << endl;

}
    int main()
    {
        int n, scr, dest, w, m;
        cout << "Enter the number of vertex: ";
        cin >> n;
        cout << "Enter the number of edges: ";
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cout << "Enter edge " << i + 1 << "source, dest, weight: ";
            cin >> scr >> dest >> w;
            add(scr, dest, w);
        }
        adjacentMat(n);
        int source;
        cout << "Enter the source node: ";
        cin >> source;
        dijkstra(source, n);

        pruskal(n);

        prim(n);
    }
