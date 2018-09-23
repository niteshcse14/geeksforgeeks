#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 1;
int degree[MAX];
int level[MAX];
queue<int> q;
set<int> c;
vector<int> adj[MAX];
int T, N, u, v, max_level;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
		{
			adj[i].clear();
		}
		for(int i = 0; i < N - 1; i++)
		{
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for(int i = 0; i < N; i++)
		{
			vector<int>::iterator itr;
			for(itr = adj[i].begin(); itr != adj[i].end(); itr++)
			{
				degree[*itr]++;
			}
		}
		for(int i = 0; i < N; i++)
		{
			if(degree[i] == 1)
			{
				q.push(i);
			}
		}
		while(!q.empty())
		{
			int v = q.front();
			q.pop();
			vector<int>::iterator itr;
			for(itr = adj[v].begin(); itr != adj[v].end(); itr++)
			{
				degree[*itr]--;
				if(degree[*itr] == 1)
				{
					q.push(*itr);
					level[*itr] = level[v] + 1;
					max_level = max(max_level, level[*itr]);
				}
			}
		}
		for(int i = 0; i < N; i++)
		{
			if(max_level == level[i])
			{
				c.insert(i);
				printf("%d  ", i);
			}
		}
		printf("\n");
	}
}