#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int block_size;
int depth[MAXN];
int parent[MAXN];
int jump_parent[MAXN];
vector<int> adj[MAXN];
void addEdge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
int naiveLCA(int u, int v)
{
	if(u == v)
	{
		return u;
	}
	if(depth[u] > depth[v])
	{
		swap(u, v);
	}
	v = parent[v];
	return naiveLCA(u, v);
}
void dfs(int curr, int prev)
{
	parent[curr] = prev;
	depth[curr] = depth[prev] + 1;
	if(depth[curr] % block_size == 0)
	{
		jump_parent[curr] = parent[curr];
	}
	else
	{
		jump_parent[curr] = jump_parent[prev];
	}
	for(int i = 0; i < adj[curr].size(); i++)
	{
		if(adj[curr][i] != prev)
		{
			dfs(adj[curr][i], curr);
		}
	}
}
int LCASQRT(int u, int v)
{
	while(jump_parent[u] != jump_parent[v])
	{
		if(depth[u] > depth[v])
		{
			swap(u, v);
		}
		v = jump_parent[v];
	}
	return naiveLCA(u, v);
}
void preprocess(int height)
{
	block_size = sqrt(height);
	depth[0] = -1;
	dfs(1, 0);
}
int main()
{
	addEdge(1,2);
    addEdge(1,3);
    addEdge(1,4);
    addEdge(2,5);
    addEdge(2,6);
    addEdge(3,7);
    addEdge(4,8);
    addEdge(4,9);
    addEdge(9,10);
    addEdge(9,11);
    addEdge(7,12);
    addEdge(7,13);
    int height = 4;
    preprocess(height);
    cout << "LCA(11,8) : " << LCASQRT(11,8) << endl;
    cout << "LCA(3,13) : " << LCASQRT(3,13) << endl;
	return 0;
}