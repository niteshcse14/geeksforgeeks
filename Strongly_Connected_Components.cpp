#include <bits/stdc++.h>
using namespace std;
int ans = 0;
class Graph
{
	int V;
	list<int> *adj;
public:
	Graph(int V);
	void addEdge(int u, int v);
	void dfs(int v, bool visited[]);
	Graph transpose();
	void print();
	void printSCC();
	void fill_order(int v, bool visited[], stack<int> &stack);
};
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}
void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
}
void Graph::dfs(int v, bool visited[])
{
	cout << v << " ";
	visited[v] = true;
	list<int>::iterator itr;
	for(itr = adj[v].begin(); itr != adj[v].end(); itr++)
	{
		if(!visited[*itr])
		{
			dfs(*itr, visited);
		}
	}
}
void Graph::fill_order(int v, bool visited[], stack<int> &stack)
{
	visited[v] = true;
	list<int>::iterator itr;
	for(itr = adj[v].begin(); itr != adj[v].end(); itr++)
	{
		if(!visited[*itr])
		{
			fill_order(*itr, visited, stack);
		}
	}
	stack.push(v);
}
Graph Graph::transpose()
{
	Graph graph(V);
	for(int i = 0; i < V; i++)
	{
		list<int>::iterator itr;
		for(itr = adj[i].begin(); itr != adj[i].end(); itr++)
		{
			graph.adj[*itr].push_back(i);
		}
	}
	return graph;
}
void Graph::printSCC()
{
	stack<int> stack;
	bool *visited = new bool[V];
	for(int i = 0; i < V; i++)
	{
		visited[i] = false;
	}
	for(int i = 0; i < V; i++)
	{
		if(!visited[i])
		{
			fill_order(i, visited, stack);
		}
	}
	Graph  graph = transpose();
	for(int i = 0; i < V; i++)
	{
		visited[i] = false;
	}
	while(stack.empty() == false)
	{
		int v = stack.top();
		stack.pop();
		if(visited[v] == false)
		{
			graph.dfs(v, visited);
			printf("\n");
		}
	}
}
int main()
{
	int T, V, E, u, v;
	cin >> T;
	while(T--)
	{
		cin >> V >> E;
		Graph graph(V);
		for(int i = 0; i < E; i++)
		{
			cin >> u >> v;
			graph.addEdge(u, v);
		}
		graph.printSCC();
	}
	return 0;
}