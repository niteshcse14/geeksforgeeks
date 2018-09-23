#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int T, V, E, u, v, uu, vv;
int adj[MAX][MAX];
bool is_safe(int v, int path[], int pos)
{
	if(adj[path[pos - 1]][v] == 0)
	{
		return false;
	}
	for(int i = 0; i < pos; i++)
	{
		if(path[i] == v)
		{
			return false;
		}
	}
	return true;
}
bool hamlCycle_Util(int path[], int pos)
{
	if(pos == V)
	{
		if(adj[path[pos - 1]][0] == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	for(int i = 0; i < V; i++)
	{
		if(is_safe(i, path, pos))
		{
			path[pos] = i;
			if(hamlCycle_Util(path, pos + 1))
			{
				return true;
			}
			path[pos] = -1;
		}
	}
	return false;
}
bool hamlCycle()
{
	int *path = new int[V];
	for(int i = 0; i < V; i++)
	{
		path[i] = -1;
	}
	path[0] = 0;
	if(hamlCycle_Util(path, 1))
	{
		return true;
	}
	return false;
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		memset(adj, 0, sizeof(adj));
		scanf("%d %d", &V, &E);
		for(int i = 0; i < E; i++)
		{
			scanf("%d %d", &uu, &vv);
			adj[uu][vv] = adj[vv][uu] = 1;
		}
		if(hamlCycle())
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}