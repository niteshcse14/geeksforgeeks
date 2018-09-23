#include <bits/stdc++.h>
using namespace std;
class Graph
{
	vector<int> *adj;
	int V;
	bool path_or_not(int v, int u, bool visited[]);
public:
	Graph(int V);
	void addEdge(int v, int u);
	void path_or_not_Util(int start);
};
Graph::Graph(int V)
{
	this->V = V;
	adj = new vector<int>[V];
}
void Graph::addEdge(int v, int u)
{
	adj[v].push_back(u);
	adj[u].push_back(v);
}
bool Graph::path_or_not_Util()
{
	for(int i = adj[])
}
void Graph::path_or_not(int start)
{
	bool *visited = new bool[V];
	memset(visited, false, sizeof(visited));
	path_or_not_Util(start, visited);
}
int main()
{
	int T, N, E, v, u;
	cin >> T;
	while(T--)
	{
		cin >> N, E;
		Graph g(N);
		for(int i = 0; i < E; i++)
		{
			cin >> v >> u;
			g.addEdge(v, u);
		}
		cin >> v >> u;
		if(g.path_or_not_Util(v, u))
		{
			cout << "TRUE\n";
		}
		else
		{
			cout << "FALSE\n";
		}
	}
	return 0;
}
//Find_if_there_is_a_path_between_two_vertices_in_a_directed_graph.cpp