#include <bits/stdc++.h>
using namespace std;
int const MAX = 1000;
typedef pair<int, int> iPair;
bool visited[MAX][MAX];
int res;
class Graph
{
	list<iPair> *adj;
	int V, E;
public:
	Graph(int V, int E);
	void add_edge(int u, int v, int w);
	int dfs(int u, int v, int sum);
};
Graph::Graph(int V, int E)
{
	this->V = V;
	this->E = E;
	adj = new list<iPair>[V];
}
void Graph::add_edge(int u, int v, int weight)
{
	adj[u].push_back(make_pair(v, weight));
}
int Graph::dfs(int u, int v, int sum)
{
	if(v != -1)
	{
		visited[u][v] = true;
	}
	list<pair<int, int> >::iterator itr;
	for(itr = adj[u].begin(); itr != adj[u].end(); itr++)
	{
		int f = (*itr).first;
		int w = (*itr).second;
		if(!visited[u][f])
		{
			sum = max(sum, sum + w);
			dfs(f, -1, sum);
		}
	}
}
int main()
{
	int T, V, E, u, v, weight;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &V, &E);
		Graph graph(V, E);
		for(int i = 0; i < E; i++)
		{
			scanf("%d %d %d", &u, &v, &weight);
			graph.add_edge(u, v, weight);
			visited[u][v] = false;
		}
		int sum = 0;
		printf("%d\n", graph.dfs(0, -1, &sum));
	}
	return 0;
}