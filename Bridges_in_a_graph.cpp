#include <bits/stdc++.h>
using namespace std;
#define NIL - 1
class Graph
{
    int V;
    list<int> *adj;
    void bridgeUtil(int v, bool visited[], int disc[], int low[], int parent[]);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void bridge();
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
void Graph::bridgeUtil(int u, bool visited[], int disc[], int low[], int parent[])
{
    static int time = 0;
    visited[u] = true;
    printf("start From %d\n", u);
    disc[u] = low[u] = ++time;
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;
        //printf("%d  %d   ", u, v);
        if (!visited[v])
        {
            parent[v] = u;
            bridgeUtil(v, visited, disc, low, parent);
            low[u]  = min(low[u], low[v]);
            printf("%d   %d   Unvisited  low[%d]   %d   disc[%d]   %d\n", u, v, u, low[u], v, low[v]);
            if (low[v] > disc[u])
              cout << u <<" " << v << endl;
        }
        else if (v != parent[u])
        {
        	printf("%d   %d   Udapted  low[%d]  %d By min of low[%d]   %d disc[%d]   %d\n", u, v, u, low[u], u, low[u], v, disc[v]);
            low[u]  = min(low[u], disc[v]);
        }
        else
        {
        	printf("%d\n", v);
        }
    }
}
void Graph::bridge()
{
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];
    for (int i = 0; i < V; i++)
    {
        parent[i] = NIL;
        visited[i] = false;
    }
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            bridgeUtil(i, visited, disc, low, parent);
}
int main()
{
	Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.bridge();
	return 0;
}