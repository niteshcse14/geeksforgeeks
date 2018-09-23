#include <bits/stdc++.h>
using namespace std;
list<int> st;
class Graph
{
	int V;
	list<int>  *adj;
public:
	Graph(int V);
	void addEdge(int v, int u);
	void recursive_scc(bool *visited, int s);
};
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}
void Graph::addEdge(int v, int u)
{
	adj[v].push_back(u);
}
void Graph::recursive_scc(bool *visisted, int s)
{
	st.push_back(s);
}
int main()
{
	int V, E;
	int u, v;
	cin >> V >> E;
	Graph g(V);
	for(int i = 0 ; i < E; i++)
	{
		cin >> v >> u;
		g.addEdge(v, u);
	}
	bool *visited = new bool[V];
	for(int i = 0 ; i < V; i++)
	{
		visited[i] = false;
	}
	for(int i = 0; i < V; i++)
	{
		if(!visited[i])
		{
			g.recursive_scc(visited, i);
		}
	}
	return 0;
}