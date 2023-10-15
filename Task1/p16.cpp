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

    cout<<endl;
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
}