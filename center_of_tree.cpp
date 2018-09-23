#include <bits/stdc++.h>
using namespace std;
int const MAX = 1e6 + 1;
vector<int> adj[MAX];
int N, T, u, v, index = 0;
int arr[MAX];
void dfs(int v, bool visited[])
{
	visited[v] = true;
	vector<int>::iterator itr;
	for(itr = adj[v].begin(); itr != adj[v].end(); itr++)
	{
		if(!visited[*itr])
		{
			dfs(*itr, visited);
		}
	}
	arr[index] = v;
	index++;
}
int main()
{
	scanf("%d", &N);
	bool visited[N];
	visited[0] = false;
	for(int i = 1; i < N; i++)
	{
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
		visited[i] = false;
	}
	dfs(0, visited);
	for(int i = 0; i < index; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
	return 0;
}