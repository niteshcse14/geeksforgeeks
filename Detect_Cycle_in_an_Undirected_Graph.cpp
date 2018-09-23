#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int V, E, u, v, flag = 0;
		cin>>V>>E;
		list<int> adj[V];
		for(int i = 0; i < E; i++)
		{
			cin>>u>>v;
			adj[u].push_back(v);
		}
		vector<bool> visited(V, false);
		vector<int> parent(V, -1);
		for(int i = 0; i < V; i++)
		{
			list<int>::iterator itr;
			for(itr = adj[i].begin(); itr != adj[i].end(); itr++)
			{
				if(visited[*itr] == false)
				{
					parent[*itr] = i;
					visited[*itr] = true;
				}
				else if(*itr != parent[i])
				{
					flag = 1;
					break;
				}
			}
			if(flag == 1)
			{
				break;
			}
		}
		if(flag == 1)
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
//Detect_Cycle_in_an_Undirected_Graph.cpp