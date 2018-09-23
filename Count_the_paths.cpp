#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
vector<int> adj[MAX];
bool visited[MAX];
int path[MAX];
int T, V, E, start_index, end_index, ans;
void dfs(int v, int index)
{
	visited[v] = true;
	path[index++] = v;
	if(v == end_index)
	{
		ans++;
	}
	else
	{
		vector<int>::iterator itr;
		for(itr = adj[v].begin(); itr != adj[v].end(); itr++)
		{
			if(!visited[*itr])
			{
				dfs(*itr, index);
			}
		}
	}
	index--;
	visited[v] = false;
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		int u, v;
		for(int i = 0; i < MAX; i++)
		{
		    adj[i].clear();
		}
		scanf("%d %d", &V, &E);
		for(int i = 0; i < E; i++)
		{
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
		}
		memset(visited, false, sizeof(visited));
		memset(path, 0, sizeof(path));
		scanf("%d %d", &start_index, &end_index);
		ans = 0;
		dfs(start_index, 0);
		printf("%d\n", ans);
	}
	return 0;
}