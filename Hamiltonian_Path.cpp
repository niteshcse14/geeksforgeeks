#include <bits/stdc++.h>
#define MAX 10
int V, E, u, v;
bool adj[MAX][MAX];
bool hamCycle()
{
	/*
	int dp[V][1 << V];
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < V; i++)
	{
		dp[i][1 << i] = 1;
	}
	for(int i = 0; i < (1 << V); i++)
	{
		for(int j = 0; j < V; j++)
		{
			if(i & (1 << j))
			{
				for(int k = 0; k < V; k++)
				{
					if(i & (1 << k) && adj[k][j] && k != j && dp[k][i ^ (1 << j)])
					{
						dp[j][i] = 1;
						break;
					}
				}
			}
		}
	}
	*/
	int dp[V][1 << V];
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < V; i++)
	{
		dp[i][1 << i] = 1;
	}
	for(int i = 0; i < (1 << V); i++)
	{
		for(int j = 0; j < V; j++)
		{
			if(i & (1 << j))
			{
				for(int k = 0; k  <V; k++)
				{
					if(i & (1 << k) && k != j && adj[k][j] && dp[k][i ^ (1 << j)])
					{
						dp[j][i] = 1;
						break;
					}
				}
			}
		}
	}
	for(int i = 0; i < V; i++)
	{
		if(dp[i][(1 << V) - 1])
		{
			return true;
		}
	}
	return false;
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		memset(adj, 0, sizeof(adj));
		scanf("%d %d", &V, &E);
		for(int i = 0; i < E; i++)
		{
			scanf("%d %d", &u, &v);
			adj[u - 1][v - 1] = adj[v - 1][u - 1] = 1;
		}
		if(hamCycle())
		{
			printf("1\n");
		}
		else
		{
			printf("0\n");
		}
	}
	return 0;
}