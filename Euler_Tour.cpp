#include <bits/stdc++.h>
using namespace std;
int const MAX = 1e5;
vector<int> adj[MAX];
int euler[MAX];
int parent[MAX];
int depth[MAX];
bool visited[MAX];
int ind = 0;
void add_edge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void dfs(int u, int prev, int dep, bool visited[])
{
	parent[u] = prev;
	euler[ind++] = u;
	depth[u] = dep;
	visited[u] = true;
	vector<int>::iterator itr;
	for(itr = adj[u].begin(); itr != adj[u].end(); itr++)
	{
		if(!visited[*itr])
		{
			dfs(*itr, u, dep + 1, visited);
		}
	}
	euler[ind++] = euler[parent[u]];
}
int main()
{
	int u, v, V;
	scanf("%d", &V);
	for(int i = 0; i < V - 1; i++)
	{
		scanf("%d %d", &u, &v);
		add_edge(u, v);
	}
	dfs(1, -1, 0, visited);
	for(int i = 0; i < ind - 1; i++)
	{
		printf("%d ", euler[i]);
	}
	printf("\n");
	/*
	for(int i = 0; i < V; i++)
	{
		printf("%d ", depth[i]);
	}
	printf("\n");
	*/
	return 0;
}